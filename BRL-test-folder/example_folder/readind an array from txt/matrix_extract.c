/* an example to  read  a matrix stored in a txt file*/
/*%Lf-long double*/
#include<stdio.h>
#include<stdlib.h>


int main(void)
{
 
FILE * file;
file = fopen("exp.txt","r");

/* allocate memory to store the matrix*/
long double ** mat=malloc(11*sizeof(long double*)); 

for(int k=0;k<11;k=k+1)
	{
		mat[k]=malloc(2*sizeof(long double));
	}

for(int i=0;i<11;i=i+1)
	{
		for(int j=0;j<2;j=j+1)
			{
				if(!fscanf(file,"%Lf",&mat[i][j]))
				break;
				//printf("%Lf\n",mat[i][j]);
			}
	}

printf("%Lf\n",mat[10][1]);


fclose(file);



return 0;
}
