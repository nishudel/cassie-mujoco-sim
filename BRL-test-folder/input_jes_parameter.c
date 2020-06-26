/* This uses the parameters that are being used in Jessie's paper for feedback control of cassie*/

#include<stdio.h>
/* An array to hold the input */
double in[119];

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
