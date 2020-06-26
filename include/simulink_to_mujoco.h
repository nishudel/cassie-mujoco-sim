//#include"simulink_to_mujoco.c"

/*The following function extracts the configuration
  from trajectory given by halpha*/
double * htoq(double* ha);

/*The following function utilises the available 
  configurations to make use of the simulink
  parameters to generate an input readable by MuJoCo
  flag=1 implies right leg stance flag=0 implies
  left leg stance */
double * add_smlnk_params(double* q,int flag);

