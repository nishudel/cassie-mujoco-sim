//This program converts the available halpha to h~d's 
//for all the math functions to be used
#include<math.h>
#include<stdio.h>
#include<stdlib.h>



double * htoq(double * ha)
		{
			//creating h~d from ha
			static double hd[9];
		 
			hd[0]=ha[0];	
			hd[1]=ha[1];
			hd[2]=ha[2];
			hd[3]=acos(1.8896*pow(ha[3],2)-1.0017)-0.035;
			hd[4]=ha[4]-hd[0];
			hd[5]=ha[5];
			hd[6]=ha[6]+hd[2]+0.1+acos((0.9448*(pow(ha[7],2))-0.0284)/ha[7]);
			hd[7]=acos(1.8896*pow(ha[7],2)-1.0017)-0.035;
			hd[8]=ha[8]+hd[2]-1.1;
	
			//creating q from h~d

			//the configurations-first 5 - stance leg next 5-swing leg
			static double q[10];
			
			//equating the h~d to h~0	
			double q_roll =hd[0];
			double q_2_st =hd[1];
			double q_pitch=hd[2];
			double q_ll_st=hd[3];	
			double q_lr_sw=hd[4];
			double q_2_sw =hd[5];
			double q_lp_sw=hd[6];
			double q_ll_sw=hd[7];
			double q_fp_sw=hd[8];


			// order of q- q1 q2 q3 q4 q7- look at jessie's paper for def. 
			// we are controlling only the torso orientation, stance and swing leg 
			// engths, swing leg orientation, and swing foot pitch angle
			// stance leg config
			q[0]=0;
			q[1]=q_2_st;
			q[2]=0;
			q[3]=acos( (pow(q_ll_st,2)-0.5301)/0.5292)-0.035;
			q[4]=0;
			// swing leg config
			q[5]=q_lr_sw-q_roll;
			q[6]=q_2_sw;
			q[8]=acos( (pow(q_ll_sw,2)-0.5301)/0.5292)-0.035;
			q[7]=q_lp_sw+q_pitch-0.1+ acos( (0.5*(cos(q[7]+0.035)+0.5292))/(sqrt(0.5292*cos(q[7]+0.035)+0.5301)));
			q[9]=q_fp_sw+q_pitch-1.1;

			//This configuration needs to be given to mujoco simulation immediately
			return q;

		}



double * add_smlnk_params(double* q,int flag)
		{

			/*NOTE: It is assumed initially the error in desired velocity of joints i.e q~dot is zero*/  
			/* An array to hold the input */
			static double in[119];
			/*This will hold the cnofigurations in order of right leg first and then left leg*/
			static double q1[10];
			
			/*flag=1 implies right leg stance flag=0 implies left leg stance*/ 
			if(flag==1)	
				{	for(int k=0;k<10;k=k+1)
						q1[k]=q[k];
				}

			else 
				{
					q1[0]=q[5];
					q1[1]=q[6];
					q1[2]=q[7];
					q1[3]=q[8];
					q1[4]=q[9];
					q1[5]=q[0];
					q1[6]=q[1];
					q1[7]=q[2];
					q1[8]=q[3];
					q1[9]=q[4];
				}

			/*task_pd-left leg: these are being ignored currently*/
			for (int i=0;i<30;i++)
				{
					in[i]=0;
				}

			/*motor_pd-left leg: motor_torque-left leg-zero by default*/
			/*motor_pd-left leg: kp target values-zero by default*/
			/*motor_pd-left leg: kd target values-zero by default*/
			for (int i=30;i<45;i++)
				{
					in[i]=0;
				}
			/*using the configuration obtained from the above fn as kp target*/
			in[35]=q1[5];
			in[36]=q1[6];
			in[37]=q1[7];
			in[38]=q1[8];
			in[39]=q1[9];
			/*motor_pd-left leg: kp gains for walking*/
			in[45]=400;
			in[46]=200;
			in[47]=500;
			in[48]=500;
			in[49]=10;
			
			/*motor_pd-left leg: kd gains for walking*/
			in[50]=10;
			in[51]=4;
			in[52]=15;
			in[53]=15;
			in[54]=2;

			/*task_pd-right leg: these are being ignored currently*/
			for (int i=55;i<85;i++)
				{
					in[i]=0;
				}
		
			/*motor_pd-right leg: motor_torque-left leg-zero by default*/
			/*motor_pd-right leg: kp target values-zero by default*/
			/*motor_pd-right leg: kd target values-zero by default*/
			for (int i=85;i<100;i++)
				{
					in[i]=0;
				}
			/*using the configuration obtained from the above fn as kp target*/
			in[90]=q1[1];
			in[91]=q1[2];
			in[92]=q1[3];
			in[93]=q1[4];
			in[94]=q1[5];
			/*motor_pd-right leg: kp gains for walking*/
			in[100]=400;
			in[101]=200;
			in[102]=500;
			in[103]=500;
			in[104]=10;
			
			/*motor_pd-rightleg: kd gains for walking*/
			in[105]=10;
			in[106]=4;
			in[107]=15;
			in[108]=15;
			in[109]=2;
			
			/*telemetry data: these are being ignored currently*/
			for (int i=110;i<119;i++)
				{
					in[i]=0;
				}
			
			
			return in;

			
		}











