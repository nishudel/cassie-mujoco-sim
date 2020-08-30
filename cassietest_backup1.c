// I had calculated the trajectory on intervals of 0.0005 secs which is the time after which the simulation is performed. This code reads data from .txt file and plays it as it is


#include "cassiemujoco.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<simulink_to_mujoco.h>

#include <string.h>

#include <time.h> 


void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
}


int main(void)
{

	
	cassie_sim_t *c = cassie_sim_init();
	cassie_vis_t *v = cassie_vis_init();
	
	state_out_t y;
	
	//The input for cassie in every simulation
	pd_in_t u = {0};
	double *temp=NULL;
	double *time=NULL;
	cassie_sim_hold(c);

	

	
	FILE * file;
	file = fopen("A1.txt","r");
	double ** stance_1=malloc(20*sizeof(double *));
	for(int k=0;k<20;k=k+1)
	{
		stance_1[k]=malloc(801*sizeof(double));
	}
	for(int j=0;j<801;j=j+1)
	{
		for(int i=0;i<20;i=i+1)
		{	//storing ....
			if(!fscanf(file,"%lf%*[^\n]%*c",&stance_1[i][j]))
			break;
		}
        }
	double traj_1[20][801];
	for(int j=0;j<801;j=j+1)
	{
		for(int i=0;i<20;i=i+1)
		{	traj_1[i][j]=stance_1[i][j];
			//printf("%lf \n",traj_1[i][j]);	
		}
        }
	
	free(stance_1);
	fclose(file);
	
	file = fopen("B1.txt","r");
	double ** stance_2=malloc(20*sizeof(double *));
	for(int k=0;k<20;k=k+1)
	{
		stance_2[k]=malloc(801*sizeof(double));
	}
	for(int j=0;j<801;j=j+1)
	{
		for(int i=0;i<20;i=i+1)
		{	//storing ....
			if(!fscanf(file,"%lf%*[^\n]%*c",&stance_2[i][j]))
			break;
		}
        }
	double traj_2[20][801];
	for(int j=0;j<801;j=j+1)
	{
		for(int i=0;i<20;i=i+1)
		{	traj_2[i][j]=stance_2[i][j];
			//printf("%lf \n",traj_2[i][j]);	
		}
        }
	
	free(stance_2);
	fclose(file);

//giving input to MuJoCo

	int step_count=0;

	pd_in_t u1={0};
   	do {
        	cassie_sim_step_pd(c, &y, &u1);
		step_count++;    	
	} while (step_count<20);

	do{

	for(int j =0;j<801;j++)
	{	
		double input1[20]={0};
		for(int i=0;i<20;i++)
		{
			input1[i]=traj_1[i][j];
		}
		temp=add_smlnk_params(input1);
		memcpy(&u,temp,sizeof(u));
		//time=cassie_sim_time(c);
		//printf("time before simulation : %lf  \n",*time);
		cassie_sim_step_pd(c, &y, &u);
		//time=cassie_sim_time(c);
		//printf("time after simulation : %lf  \n",*time);
		//delay(1);	
		
	}

	for(int j =0;j<801;j++)
	{	
		double input2[20]={0};
		for(int i=0;i<20;i++)
		{
			input2[i]=traj_2[i][j];
		}
		temp=add_smlnk_params(input2);
		memcpy(&u,temp,sizeof(u));
		//time=cassie_sim_time(c);
		//printf("time before simulation : %lf  \n",*time);
		cassie_sim_step_pd(c, &y, &u);
		//time=cassie_sim_time(c);
		//printf("time after simulation : %lf  \n",*time);
		//delay(1);
	}
	
	step_count++;
		
	}while(step_count<100);

//	}while(cassie_vis_draw(v, c));
/*	pd_in_t u1={0};
   	do {
        	cassie_sim_step_pd(c, &y, &u1);
    	} while (cassie_vis_draw(v, c));
*/ 	
	return 0;
}























/*void main(void)
{


		
	//Reading the input
	FILE * file;
	file = fopen("params_bez_v_m025.txt","r");
	
*/	/* allocating memory for right leg stance halpha*/
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
			printf("%lf \n",params[i][j]);		
		
		}
	}
	fclose(file);

}
/*		//cassie_sim_hold(c);
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

































