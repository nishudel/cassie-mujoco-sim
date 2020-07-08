//This program converts the available halpha to h~d's 
//for all the math functions to be used
#include<math.h>
#include<stdio.h>
#include<stdlib.h>




	
int factorial(int a)
	{
    		int f = 1, i;
   		if (a == 0)
		    {
		        return(f);
		    }
		else
		    {
        		for (i = 1; i <= a; i=i+1)
				{
        			    f = f * i;
				}
    		     }
  		return(f);
	}


double* qd( double T, double params[10][6])
	{

		static double q[10]={0};

		//This is tau in the paper: T= t-t_/t_step 
		//Note : t_step=0.400 sec
		double t=T; 		

		//The following is the evaluation of h_alpha at any given tau:
		for (int i=0;i<10;i=i+1)
			{
				for(int j=0;j<6;j=j+1)
					{
						double ncr=factorial(5)/(factorial(j)*factorial(5-j));
						q[i]=q[i]+ params[i][j]*ncr*pow(t,j)*pow((1-t),(5-j)); 			

					}
			}					
		return q;				
			
	} 

double* qddot(double T, double params[10][6])
	{
		static double qdot[10]={0};
		//This is tau in the paper: T= t-t_/t_step
		//Note : t_step=0.400 sec
		double t=T;
		double t_step=0.4;
		//The following is the evaluation of qddot at any given tau:
		for (int i=0;i<10;i=i+1)
			{
				for(int k=0;k<6;k=k+1)
					{
						double ncr=factorial(5)/(factorial(k)*factorial(5-k));
						qdot[i]=qdot[i]+ (params[i][k]*ncr*(k*pow(t,k-1)*pow((1-t),(5-k)) - (5-k)*pow(t,k)*pow((1-t),(5-k-1))))/t_step;

		

					}
			}					
		return qdot;

	}

double * hdtoqd(double * hd)
	{
		static double q[10];

		//roll=abduction
		//pitch=flexion
		//yaw=rotation
		double y_hip_abduction_left=hd[0];
		double y_hip_rotation_left=hd[1];
		double y_hip_flexion_left=hd[2];
		double y_knee_joint_left=hd[3];
		double y_toe_joint_left=hd[4];
		double y_hip_abduction_right=hd[5];
		double y_hip_rotation_right=hd[6];
		double y_hip_flexion_right=hd[7];
		double y_knee_joint_right=hd[8];
		double y_toe_joint_right=hd[9];


		q[0]= y_hip_abduction_left;
		q[1]= y_hip_rotation_left;
		q[2]= y_hip_flexion_left;
		q[3]= y_knee_joint_left;
		q[4]= y_toe_joint_left;
		q[5]= y_hip_abduction_right;
		q[6]= y_hip_rotation_right;
		q[8]= y_hip_flexion_right;
		q[7]= y_knee_joint_right;
		q[9]= y_toe_joint_right;

		
			/*//creating h~d from ha
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
			*/
			
			//This configuration needs to be given to mujoco simulation immediately
		return q;
			

	}

double * add_smlnk_params(double* q,double* qd,int flag)
		{

			/*NOTE: It is assumed initially the error in desired velocity of joints i.e q~dot is zero*/  
			/* An array to hold the input */
			static double in[119];
			/*This will hold the cnofigurations in order of right leg first and then left leg*/
			static double q1[10];
			static double q1dot[10];
			/*flag=1 implies right leg stance flag=0 implies left leg stance*/ 
			if(flag==1)	
				{	for(int k=0;k<10;k=k+1)
						{	q1[k]=q[k];
							q1dot[k]=qd[k];				
						}					
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

					q1dot[0]=qd[5];
					q1dot[1]=qd[6];
					q1dot[2]=qd[7];
					q1dot[3]=qd[8];
					q1dot[4]=qd[9];
					q1dot[5]=qd[0];
					q1dot[6]=qd[1];
					q1dot[7]=qd[2];
					q1dot[8]=qd[3];
					q1dot[9]=qd[4];

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
			in[40]=q1dot[5];
			in[41]=q1dot[6];
			in[42]=q1dot[7];
			in[43]=q1dot[8];
			in[44]=q1dot[9];
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
			in[90]=q1[0];
			in[91]=q1[1];
			in[92]=q1[2];
			in[93]=q1[3];
			in[94]=q1[4];
			in[95]=q1dot[0];
			in[96]=q1dot[1];
			in[97]=q1dot[2];
			in[98]=q1dot[3];
			in[99]=q1dot[4];


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











