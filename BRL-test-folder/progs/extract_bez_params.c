#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main(void)
	{
		//Reading the input
		FILE * file;
		file = fopen("params_bez.txt","r");
		
		/* allocating memory for right leg stance halpha*/

		double ** alpha_1=malloc(10*sizeof(double *));
		for(int k=0;k<10;k=k+1)
			{
				alpha_1[k]=malloc(6*sizeof(double));
			}

		for(int i=0;i<10;i=i+1)
			{
				for(int j=0;j<6;j=j+1)
					{	//storing ....
						if(!fscanf(file,"%lf",&alpha_1[i][j]))
						break;
						printf("%lf\n",alpha_1[i][j]);
					}
			}


		double ** alpha_3=malloc(10*sizeof(double *));
		for(int k=0;k<10;k=k+1)
			{
				alpha_3[k]=malloc(6*sizeof(double));
			}

		for(int i=0;i<10;i=i+1)
			{
				for(int j=0;j<6;j=j+1)
					{	//storing ....
						if(!fscanf(file,"%lf",&alpha_3[i][j]))
						break;
						printf("%lf\n",alpha_3[i][j]);
					}
			}



	}
