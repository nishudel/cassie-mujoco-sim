#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double time[8000];
double left_hip_angle [8000];
double left_knee_spring_angle [8000];
double left_toe_angle [8000];
double right_hip_angle [8000];
double right_knee_spring_angle [8000];
double right_toe_angle [8000];
double let_hip_qvel [8000];
double left_knee_spring_qvel [8000];
double left_toe_qvel [8000];
double right_hip_qvel [8000];
double right_knee_spring_qvel [8000];
double right_toe_qvel [8000];

int main(void) 
	{
		FILE *fp = fopen("trajectory_RL.csv", "r");

		if (!fp)
			{
				printf("Can't open file\n");
		        	return 0;
			}

		char buf[4096];
    		int row_count = 0;
		int field_count = 0;
		while (fgets(buf, 4096, fp) && (row_count-1)<=8000)
			{
        			field_count = 0;
        			row_count++;
				char *ptr;
        			if (row_count == 1) {
					continue;
        			}

				char *field = strtok(buf, ",");
		        	while (field) {
					
		        		if (field_count == 1) {
		                		left_hip_angle[row_count-1]=strtod(field, &ptr);
		            		}
		            		if (field_count == 2) {
		                		left_knee_spring_angle[row_count-1]=strtod(field, &ptr);
					}
				        if (field_count == 3) {
				                left_toe_angle[row_count-1]=strtod(field, &ptr);
					}
        		   		if (field_count == 4) {
                				right_hip_angle [row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 5) {
                				right_knee_spring_angle[row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 6) {
                				right_toe_angle[row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 7) {
                				let_hip_qvel [row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 8) {
                				left_knee_spring_qvel[row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 9) {
                				left_toe_qvel [row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 10) {
                				right_hip_qvel[row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 11) {
                				right_knee_spring_qvel[row_count-1]=strtod(field, &ptr);
            				}
        		   		if (field_count == 12) {
                				right_toe_qvel [row_count-1]=strtod(field, &ptr);
            				}

	

            				printf("%lf\n", left_hip_angle[row_count-1]);
            				field = strtok(NULL, ",");
	
            				field_count++;
        				}
        				//printf("\n");
    			}

    		printf("The number of rows:%d\n", row_count);

    		fclose(fp);

   		return 0;
	}
