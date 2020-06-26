//code part to simulate cassie in a for loop with an input in one loop and another in a different loop
#include "cassiemujoco.h"
//#include "control_params.h"
#include<time.h>
#include<string.h>
#include<stdio.h>




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

//    pd_in_t *u = control_input():
    
    
 /*   pd_in_t *u;	
    pd_in_t leg11={0};
    pd_in_t leg12={0};
    pd_in_t leg1={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,10,10,10,10,10,10,10,10,10};  
   

    pd_in_t leg2={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,10,10,10,10,10,10,10,10,10};
    memcpy(&leg11,&leg1,sizeof(pd_in_t));

    u=&leg11;


    // Storing start time 
    clock_t start_time = clock(); 
 

    memcpy(&leg11,&leg1,sizeof(pd_in_t));
    u=&leg11;	

    do{
  
    

        cassie_sim_step_pd(c, &y, u);

	}while (clock() < start_time + 20000); 

    cassie_sim_free(c);

    memcpy(&leg12,&leg2,sizeof(pd_in_t));

    u=&leg12;
          
    do{
  
    
	cassie_sim_step_pd(c, &y, u);

	}while (clock() < start_time + 500000); 

    cassie_sim_free(c);
*/

	cassie_sim_hold(c);
    do {
	//double *qpos=cassie_sim_qpos(c);
        //double *qvel=cassie_sim_qvel(c); 
       
    
        cassie_sim_step_pd(c, &y,&u);
    } while (cassie_vis_draw(v, c));

 
*/
    return 0;
}
