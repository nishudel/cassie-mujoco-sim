#include "cassiemujoco.h"
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<simulink_to_mujoco.h>
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

		//Reading the input
		FILE * file;
		file = fopen("trajectory.txt","r");
		//file = fopen("trajectory_1to6.txt","r");

		/* allocating memory for right leg stance halpha*/

		double ** ha_r=malloc(9*sizeof(double *));
		for(int k=0;k<9;k=k+1)
			{
				ha_r[k]=malloc(10*sizeof(double));
			}

		for(int i=0;i<9;i=i+1)
			{
				for(int j=0;j<10;j=j+1)
					{	//storing ....
						if(!fscanf(file,"%lf",&ha_r[i][j]))
						break;
						//printf("%lf\n",ha_r[i][j]);
					}
			}

		//this is for the matrix below the last read matrix
		double ** ha_r2=malloc(9*sizeof(double *));
		for(int k=0;k<9;k=k+1)
			{
				ha_r2[k]=malloc(10*sizeof(double));
			}

		for(int i=0;i<9;i=i+1)
			{
				for(int j=0;j<10;j=j+1)
					{	//storing ....
						if(!fscanf(file,"%lf",&ha_r2[i][j]))
						break;
						//printf("%lf\n",ha_r2[i][j]);
					}
			}
				

		//cassie_sim_hold(c);
		double *q;
		double *ha;
		double *input;
		int flag=1;
                double * pos;


/*

 double * state;
 state = cassie_sim_qpos(c);
 for(loop = 0; loop < sizeof(state); loop++)
      printf("%d ", state[loop]);




*/

/*
//Checking the traj
		for (int j=0;j<10;j=j+1)
				{	
					//printf("done \n");
					double temp[9];
					for( int k=0;k<9;k=k+1)
						{
							temp[k]=ha_r2[k][j];
						}	
					ha=temp;
				 	q=htoq(ha);
					input=add_smlnk_params(q,flag);
					memcpy(&u,input,sizeof(u));	
					cassie_sim_step_pd(c, &y,&u);
					pos = cassie_sim_qpos(c);
					for(int loop = 0; loop < sizeof(state); loop++)
      						printf("%d ", pos[loop]);
					delay(5); 
									
				}

		for (int j=0;j<10;j=j+1)
				{
			
					double temp[9];
					for( int k=0;k<9;k=k+1)
						{
							temp[k]=ha_r[k][j];
						}	
					ha=temp;
				 	q=htoq(ha);
					input=add_smlnk_params(q,0);
					memcpy(&u,input,sizeof(u));	
					cassie_sim_step_pd(c, &y,&u);
					delay(10); 					
				}


		do{
			pd_in_t z={0};
			cassie_sim_step_pd(c, &y,&z);
		} while (cassie_vis_draw(v, c));



*/
		
		do {		
			//ha_r
			for (int j=0;j<10;j=j+1)
				{
			
					double temp[9];
					for( int k=0;k<9;k=k+1)
						{
							temp[k]=ha_r[k][j];
						}	
					ha=temp;
				 	q=htoq(ha);
					input=add_smlnk_params(q,flag);
					memcpy(&u,input,sizeof(u));	
					cassie_sim_step_pd(c, &y,&u);
					//delay(1); 					
				}
			
			//ha_r2
			for (int j=0;j<10;j=j+1)
				{
					printf("done \n");
					double temp[9];
					for( int k=0;k<9;k=k+1)
						{
							temp[k]=ha_r2[k][j];
						}	
					ha=temp;
				 	q=htoq(ha);
					input=add_smlnk_params(q,flag);
					memcpy(&u,input,sizeof(u));	
					cassie_sim_step_pd(c, &y,&u);
					//delay(1); 					
				}
			//pd_in_t z={0};
			//cassie_sim_step_pd(c, &y,&z);
		} while (cassie_vis_draw(v, c));
		

	}
	



































