/* program to interpolate the trajectories linearly*/

/* Assume that I have a matrix with the halpas at 10 instances 
   for right stance and left stance each*/



double ** halpha=malloc(18*sizeof(double *));
for(int k=0;k<18;k=k+1)
	{
		halpha[k]=malloc(10*sizeof(double));
	}

// call the function to return the above stated trajectory
// halpha=callfunction();
// Assume that halpha already has the data in it and we linearly interpolate 

// The known Halpha parameters are placed at an equal time width of delta_t sec
double delta_t=0.4;


/* Linear interpolation: lets take 3 values between each halpha at 
   intervals of delta_t/10 this is stored in ha*/

double t_int=delta_t/4;
double ** ha=malloc(18*sizeof(double *));
for(int k=0;k<18;k=k+1)
	{
		halpha[k]=malloc(37*sizeof(double));
	}


t1=0;
t2=0.4;
{

k=0;
y1=halpha(i,j);
y2=halpha(i,j+1);
t=t1;
y=y1+(t-t1)*(y2-y1)/(t2-t1);
ha(i,k)=y;
k++;
t1=t1+t_int;
}
t2=t2+delta_t;
}

