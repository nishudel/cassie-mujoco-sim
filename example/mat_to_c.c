#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"
#include <matrix.h>
#include <mex.h>
#include "mat_to_c.h"
#include "../include/cassiemujoco.h"
#include "../include/simulink_to_mujoco.h"
#define  BUFSIZE 256



void input( void)
{
	Engine *ep;

	
	
	char buffer[BUFSIZE+1];
	if (!(ep = engOpen(NULL)))
	{
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		//return EXIT_FAILURE;
	}
	
	cassie_sim_t *c = cassie_sim_init();
	cassie_vis_t *v = cassie_vis_init();

	state_out_t y;
	pd_in_t u = {0};
	double t[801]={0};
	for( int i=0;i<801;i++)
	{
		t[i+1]=t[i]+0.00125;
	}
	
	double* temp=NULL;
	double* check_T=NULL;
	double flag=0;
	cassie_sim_hold(c);

// do{
	flag=0;
	for(int i=0;i<801;i++)
	{
		mxArray *T=NULL,*M_input=NULL,*	Check_T=NULL;
		T = mxCreateDoubleMatrix(2, 1, mxREAL);
		double T_c[2]={t[i],flag};
		double *ptr0=mxGetPr(T);
		memcpy((void *)(ptr0), (void *)T_c, sizeof(T_c));
		engPutVariable(ep, "T", T);
		engEvalString(ep,"input=zeros(20,1);");
		engEvalString(ep,"input=cassie_input(T);");
		M_input = engGetVariable(ep,"input");
		double *input=(double*)(mxGetData(M_input));
		temp=add_smlnk_params(input);
		memcpy(&u,temp,sizeof(u));
		cassie_sim_step_pd(c, &y, &u);
		mxDestroyArray(Check_T);
		mxDestroyArray(T);
		mxDestroyArray(M_input);
		
	}

	flag=1;
	for(int i=0;i<801;i++)
	{
		mxArray *T=NULL,*M_input=NULL,*Check_T=NULL;
		T = mxCreateDoubleMatrix(2, 1, mxREAL);
		double T_c[2]={t[i],flag};
		double *ptr1=mxGetPr(T);
/*		for(int m=0;m<2;m++)
		{
			memcpy((ptr1+m), T_c[m], sizeof(T_c));
		}
*/		//Check_T= engGetVariable(ep,"T");
		memcpy((void *)(ptr1), (void *)T_c, sizeof(T_c));
		double *check_T=(double*)(mxGetData(T));
/*		for(int m=0;m<2;m++)
		{
			printf("flag %lf %lf \n",flag,check_T[m]);
			
		}
*/

		engPutVariable(ep, "T", T);
		engEvalString(ep,"input=zeros(20,1);");
		engEvalString(ep,"input=cassie_input(T);");
		M_input = engGetVariable(ep,"input");
		double *input=(double*)(mxGetData(M_input));
		int count=0;
/*		for(int m=0;m<20;m++)
		{
			printf("flag %lf %lf \n",flag,*input);
			input++;
			count++;
		}
*/		printf("%d\n",count);
		temp=add_smlnk_params(input);
		memcpy(&u,temp,sizeof(u));
		cassie_sim_step_pd(c, &y, &u);
		mxDestroyArray(Check_T);
		mxDestroyArray(T);
		mxDestroyArray(M_input);
	
	}
	
 //}while(cassie_vis_draw(v, c));
	pd_in_t u1 = {0};

 	do {
        	cassie_sim_step_pd(c, &y, &u1);
    	} while (cassie_vis_draw(v, c));

/*	mxDestroyArray(Check_T);
	mxDestroyArray(T);
	mxDestroyArray(M_input);	
*/	engClose(ep);
//	return 0;
}






/*

//	mxArray *T=NULL,*M_input=NULL;
//	char buffer[BUFSIZE+1];
	T = mxCreateDoubleMatrix(2, 1, mxREAL);
	memcpy((void *)mxGetPr(T), (void *)t, sizeof(t));
	engPutVariable(ep, "T", T);
//	engEvalString(ep, "cd home/nishanth/Documents/cassie-mujoco-sim-master/BRL-test-folder/");
	engEvalString(ep,"input=zeros(20,1);");
	engEvalString(ep,"input=cassie_input(T);");
	M_input = engGetVariable(ep,"input");
	double *input=(double*)(mxGetData(M_input));
	
	mxDestroyArray(T);
	mxDestroyArray(M_input);	
	engClose(ep);
	
	return input;

} 
*/
