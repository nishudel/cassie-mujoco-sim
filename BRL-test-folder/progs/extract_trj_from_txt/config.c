// The following is a function that converts the h~d into q's( confitguration of cassie)

// Assuming right is at stance and left is at swing initially and then vice versa
// This takes h~d as an input and generates the corresponding q as the output

#include<math.h>
#include<stdio.h>
#include<stdlib.h>

//the configurations-first 5 - stance leg next 5-swing leg
double ** q=malloc(10*sizeof(double *));
double ** h~d=malloc(9*sizeof(double *));

//equating the h~d to h~0
q_roll =&h~d(0);
q_2_st =&h~d(1);
q_pitch=&h~d(2);
q_ll_st=&h~d(3);
q_lr_sw=&h~d(4);
q_2_sw =&h~d(5);
q_lp_sw=&h~d(6);
q_ll_sw=&h~d(7);
q_fp_sw=&h~d(8);


// order of q- q1 q2 q3 q4 q7- look at jessie's paper for def. 
// we are controlling only the torso orientation, stance and swing leg 
// engths, swing leg orientation, and swing foot pitch angle
// stance leg config
&q(0)=0;
&q(1)=q_2_st;
&q(2)=0;
&q(3)=acos( (pow(q_ll_st,2)-0.5301)/0.5292)-0.035;
&q(4)=0;
// swing leg config
&q(5)=q_lr_sw-q_roll;
&q(6)=q_2_sw;
&q(8)=acos( (pow(q_ll_sw,2)-0.5301)/0.5292)-0.035;
&q(7)=q_lp_sw+q_pitch-0.1+ acos( (0.5*(cos(&q(7)+0.035)+0.5292))/(sqrt(0.5292*cos(&q(7)+0.035)+0.5301));
&q(9)=q_fp_sw+q_pitch-1.1;

//This configuration needs to be given to mujoco simulation immediately

