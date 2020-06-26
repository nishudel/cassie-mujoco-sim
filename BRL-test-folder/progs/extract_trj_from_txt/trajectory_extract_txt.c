/* c program to extract the hAlpha data from a txt file*/


#include<stdio.h>
#include<stdlib.h>

int main(void)
{
 
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
				printf("%lf\n",ha_r[i][j]);
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
					printf("%lf\n",ha_l[i][j]);
				}
		}
	}

printf("%lf\n",ha_l[8][9]);
//free(ha_l);

fclose(file);




return 0;
}


