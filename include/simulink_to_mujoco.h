//#include"simulink_to_mujoco.c"



/* it return the factorial of a number*/	
int factorial(int a);
/* This fuunction takes in the tau- parameter and 
   the bezzier coefficients as the input and it returns 
   the desired (qd) joint configurations
*/
double* qd( double T, double params[10][6]);


/* This fuunction takes in the tau- parameter and 
   the bezzier coefficients as the input and it returns 
   the desired (qd_dot) joint velocities
*/
double* qddot(double T, double params[10][6]);

/*The following function extracts the configuration
  from trajectory given by halpha*/
//double * htoq(double* ha);

/*The following function utilises the available 
  qd and qd_dot to make use of the simulink
  parameters to generate an input readable by MuJoCo
  flag=1 implies right leg stance flag=0 implies
  left leg stance */
double * add_smlnk_params(double* q,double* qd,int flag);
//double * add_smlnk_params(double* q,int flag);

