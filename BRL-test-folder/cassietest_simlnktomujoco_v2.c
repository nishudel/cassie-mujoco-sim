#include "cassiemujoco.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<simulink_to_mujoco.h>
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


int main(void)
	{
		cassie_sim_t *c = cassie_sim_init();
		cassie_vis_t *v = cassie_vis_init();
	
		state_out_t y;
	
		//The input for cassie in every simulation
		pd_in_t u = {0};
		
		//Reading the input
		FILE * file;
		file = fopen("params_bez.txt","r");
		
		/* allocating memory for right leg stance halpha*/

		double ** alpha_1=malloc(10*sizeof(double *));
		for(int k=0;k<10;k=k+1)
			{
				alpha_1[k]=malloc(6*sizeof(double));
			}

		for(int i=0;i<10;i=i+1)
			{
				for(int j=0;j<6;j=j+1)
					{	//storing ....
						if(!fscanf(file,"%lf",&alpha_1[i][j]))
						break;
						printf("%lf\n",alpha_1[i][j]);
					}
			}


		double ** alpha_3=malloc(10*sizeof(double *));
		for(int k=0;k<10;k=k+1)
			{
				alpha_3[k]=malloc(6*sizeof(double));
			}

		for(int i=0;i<10;i=i+1)
			{
				for(int j=0;j<6;j=j+1)
					{	//storing ....
						if(!fscanf(file,"%lf",&alpha_3[i][j]))
						break;
						printf("%lf\n",alpha_3[i][j]);
					}
			}	

		//cassie_sim_hold(c);
		double *q;
		double *qdot;
		double params[10][6];

		for( int i=0;i<10;i=i+1)
			{
				for(int j=0;j<6;j=j+1)
					{
						params[i][j]=alpha_1[i][j];
					}
			}

		//We are not using ha here as ha and q are the same essentially 
//		double *ha;
		double *input;
		int flag=1;
                double * pos;
		
		double* t;
		double t_minus;

		do{
			t= cassie_sim_time(c);
			
			//printf("time now is :%lf \n",*t);	
			

			if(*t<=0.4)
				{
					
					q=qd(*t/0.4,params);
					qdot=qddot(*t/0.4,params);
					input=add_smlnk_params(q,qdot,flag);
					memcpy(&u,input,sizeof(u));	
					cassie_sim_step_pd(c, &y,&u);
				}
						
			else
				{
					//u={0};			
					cassie_sim_step_pd(c, &y,&u);

				}
		} while (cassie_vis_draw(v, c));




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

































