#include "cassiemujoco.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<simulink_to_mujoco.h>
#include "mat_to_c.h"
#include <string.h>

//#include <time.h> 

/*
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
}*/


void main(void)
{

	
/*	cassie_sim_t *c = cassie_sim_init();
	cassie_vis_t *v = cassie_vis_init();
	
	state_out_t y;
	
	//The input for cassie in every simulation
	pd_in_t u = {0};
	cassie_sim_hold(c);

	double t[81]={0};
	for( int i=0;i<80;i++)
	{
		t[i+1]=t[i]+0.0125;
	}
	double* temp=NULL;
	double flag=0;
	double *in=NULL;
	for(int i=0;i<81;i++)
	{
		double T[2]={t[i],flag};
		in=input(T);
		temp=add_smlnk_params(in);
		memcpy(&u,temp,sizeof(u));
		//cassie_sim_step_pd(c, &y, &u);

	}	
	flag=1;

	for(int i=0;i<81;i++)
	{
		double T[2]={t[i],flag};
		in=input(T);
		temp=add_smlnk_params(in);
		memcpy(&u,temp,sizeof(u));
		//cassie_sim_step_pd(c, &y, &u);

	}
*/


	//int out=0;
//	out=
	input();


//	return 0;
}


























		
	//Reading the input
//	FILE * file;
//	file = fopen("params_bez_v_m025.txt","r");
	
	/* allocating memory for right leg stance halpha*/
/*	double ** alpha_1=malloc(10*sizeof(double *));
	for(int k=0;k<10;k=k+1)
	{
		alpha_1[k]=malloc(6*sizeof(double));
	}
	for(int j=0;j<6;j=j+1)
	{
		for(int i=0;i<10;i=i+1)
		{	//storing ....
			if(!fscanf(file,"%lf%*[^\n]%*c",&alpha_1[i][j]))
			break;
		}
        }

	double *q;
	double params[10][6];
	for( int i=0;i<10;i=i+1)
	{
		for(int j=0;j<6;j=j+1)
		{	params[i][j]=alpha_1[i][j];
			//printf("%lf \n",params[i][j]);		
		
		}
	}
	fclose(file);


		//cassie_sim_hold(c);
		//double *q;
		double *qdot;
		//copying the stored values into params array
		
//We are not using ha here as ha and q are the same essentially 
//		double *ha;
		double *input;
		int flag=1;
                double * pos;
		
		double* t;
		double t_minus;

		do{
			t= cassie_sim_time(c);
			
			if(*t<=0.0005)
				{	q=qd(*t/0.4,params);
					
					if (*t<=0.02 || *t>=0.39)
					{ 
						printf("Q at time stamp: %lf \n",*t);
						for (int k=0;k<=10;k=k+1)
							{
								printf("%lf \n",q[k]);
	
							}
					
					}
					qdot=qddot(*t/0.4,params);
					input=add_smlnk_params(q,qdot,flag);
					//printf("Below is the input \n");
					/*for (int k=35;k<=44;k=k+1)
						{
							printf("u %lf %lf \n",*t,input[k]);

						}
					*/
					/*for (int k=90;k<=99;k=k+1)
						{
							printf("u %lf %lf \n",*t,input[k]);

						}	
					*/
/*					memcpy(&u,input,sizeof(u));	
					cassie_sim_step_pd(c, &y,&u);
				}
						
			/*else
				{
					//u={0};			
					cassie_sim_step_pd(c, &y,&u);

				}
*/ /*	} while (cassie_vis_draw(v, c));




	}


/*int main(void)
{
    cassie_sim_t *c = cassie_sim_init();
    cassie_vis_t *v = cassie_vis_init();

    state_out_t y;
    pd_in_t u = {0};
    cassie_sim_hold(c);
    do {
        cassie_sim_step_pd(c, &y, &u);
    } while (cassie_vis_draw(v, c));

    return 0;
}

*/

































