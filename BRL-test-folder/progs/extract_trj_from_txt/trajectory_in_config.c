//This program converts the available halpha to h~d's 
//for all the math functions to be used
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{


/*The following code is just to get the data from the txt file into an array
This will be a separte module in the future*/
 
FILE * file;
file = fopen("trajectory.txt","r");

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
printf("%lf\n",ha_r[0][0]);
//free(ha_r);



/* allocating memory for left leg stance halpha*/
double ** ha_l=malloc(9*sizeof(double *));
for(int k=0;k<9;k=k+1)
	{
		ha_l[k]=malloc(10*sizeof(double));
	}
if (ha_l == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 

else
	{

	for(int i=0;i<9;i=i+1)
		{
			for(int j=0;j<10;j=j+1)
				{	//storing ....
					if(!fscanf(file,"%lf",&ha_l[i][j]))
					break;
					//printf("%lf\n",ha_l[i][j]);
				}
		}
	}

printf("%lf\n",ha_l[8][9]);
//free(ha_l);

fclose(file);


//data has been stored in an array

// y=h~0 - h~d
// we find h~d from the given hd
//we find the q's by equating h~0 and h~d

//h~d
//creating h~d for each column of ha_l and ha_r
double ** h~dl=malloc(9*sizeof(double *));
for(int k=0;k<9;k=k+1)
	{
		h~dl[k]=malloc(10*sizeof(double));
	}


for (int j=0;j<10;j++)
	{
		&h~dl[0][j]=&ha_l[0][j];	
		&h~dl[1][j]=&ha_l[1][j];
		&h~dl[2][j]=&ha_l[2][j];
		&h~dl[3][j]=acos(1.8896*pow(&ha_l[3][j],2)-1.0017)-0.035;
		&h~dl[4][j]=&ha_l[4][j]-&h~dl[0][j];
		&h~dl[5][j]=&ha_l[5][j];
		&h~dl[6][j]=&ha_l[6][j]+&h~dl[2][j]+0.1+acos((0.9448*(pow(&ha_l[7][j],2))-0.0284)/&ha_l[7][j]);
		&h~dl[7][j]=acos(1.8896*pow(&ha_l[7][j],2)-1.0017)-0.035;
		&h~dl[8][j]=&ha_l[8][j]+&h~dl[2][j]-1.1;
	}


double ** h~dr=malloc(9*sizeof(double *));
for(int k=0;k<9;k=k+1)
	{
		h~dr[k]=malloc(10*sizeof(double));
	}
for (int j=0;j<10;j++)
	{
		&h~dr[0][j]=&ha_l[0][j];	
		&h~dr[1][j]=&ha_l[1][j];
		&h~dr[2][j]=&ha_l[2][j];
		&h~dr[3][j]=acos(1.8896*pow(&ha_l[3][j],2)-1.0017)-0.035;
		&h~dr[4][j]=&ha_l[4][j]-&h~dr[0][j];
		&h~dr[5][j]=&ha_l[5][j];
		&h~dr[6][j]=&ha_l[6][j]+&h~dr[2][j]+0.1+acos((0.9448*(pow(&ha_l[7][j],2))-0.0284)/&ha_l[7][j]);
		&h~dr[7][j]=acos(1.8896*pow(&ha_l[7][j],2)-1.0017)-0.035;
		&h~dr[8][j]=&ha_l[8][j]+&h~dr[2][j]-1.1;
	}







return 0;
}





