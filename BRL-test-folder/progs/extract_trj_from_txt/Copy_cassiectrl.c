#include "cassiemujoco.h"
#include<stdio.h>
#include<math.h>

int main(void)
{
    cassie_sim_t *c = cassie_sim_init();
    cassie_vis_t *v = cassie_vis_init();

    state_out_t y;

    //The input for cassie in every simulation
    pd_in_t u = {0};
    
    int i=0;
   
    //test input as an element of struct pd_in_t
//pd_in_t leg1=
//{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,5,0,0,0,0,5,0,0,0,0,8,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,10,0,10,0,0,5,0,5,0,0,5,0,5,0,0,8,0,8,0,0,4,0,4,0,0,1,1,1,1,1,1,1,1,1};
  
    pd_in_t leg1= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,100,100,100,1000*cos(i),100,0,0,0,5,0,0,0,0,5,0,0,0,0,8,0,0,0,0,4,0,1,1,1,1,1,1,1,1,1};
  

    u=leg1;

    /*Holds cassie at the current point, if this function was called inside the loop,cassie will gradually go down with each iteration-probably because we provide it input at the beginning of each iteration and ust before that, only gravity acts*/
    cassie_sim_hold(c);

    do {i++;
	
        printf("%f\n",u.telemetry[5]);
    
        cassie_sim_step_pd(c, &y,&u);
    } while (cassie_vis_draw(v, c));

 
    return 0;
}
