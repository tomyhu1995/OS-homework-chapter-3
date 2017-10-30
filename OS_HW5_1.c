#include <stdio.h>
#include <stdlib.h>

int isAllzero(int *process_burst_time, int len){
	int flag = 0;
	int i = 0;
	for(i = 0; i < len; i++){
		if(process_burst_time[i] > 0){
			flag = 1;
			break;
		}else{
			flag = 0;
		}
	}

	return flag;
}

int turnarround_time(int *input, int len){
	int i;
	int flag = 0;
	int offset = 0;
	int start;
	int end;
	for(i = 0; i < len; i++){
		if(flag == 0 && input[i] == 1){
			start = i;
			break;
		}else{
			offset++;
		}
	}

	flag = 0;
	for(i = len-1; i >= 0; i--){
		if(flag == 0 && input[i] == 1){
			end = i;
			break;
		}
	}

	return end - start + 1 + offset;
}

int main(int argc, char const *argv[])
{
	FILE *f = fopen("data_HW5_1.txt", "w");
	
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	int input;
	int len = 0;
	int quantum, Max_quantum;
	int tmp[300] = {0};
	printf("Please enter process burst time, 0 for terminate : ");
	while(scanf("%d", &input) != EOF && input != 0){
		tmp[len++] = input;
		printf("Please enter process burst time, 0 for terminate : ");
	}
	
	printf("Please enter the max quantum: ");
	scanf("%d", &Max_quantum);
	
	for(quantum = 1; quantum <= Max_quantum; quantum ++){
		int process_burst_time[300] = {0};
		int time_slice[4][100] = {0};
		int turnarround_time_sum = 0;
		int i = 0;
		int index = 0;

		for(i = 0; i < len; i++){
			process_burst_time[i] = tmp[i];
		}

		while(isAllzero(process_burst_time, 4)){
		for(i = 0; i < len; i++){
				if(process_burst_time[i] > 0){
					int k, process_use = 0; 
					for(k = index; k < index + quantum && process_burst_time[i] > 0; k++){
						time_slice[i][k] = 1;
						process_burst_time[i]--;
						process_use++;
					}
					//printf("index = %d\n", index);
					index += process_use;
					
					//printf("process_burst_time[%d] = %d\n", i, process_burst_time[i]);
				}
			}
		}

		/*for(i = 0; i < len; i++){
			int j;
			for(j = 0; j < 30; j++){
				printf("%d ", time_slice[i][j]);
			}
			printf("\n");
		}

		printf("\n");*/

		for(i = 0; i < len; i++){
			//printf("turnarround_time = %d\n", turnarround_time(time_slice[i], 100));
			turnarround_time_sum += turnarround_time(time_slice[i], 100);
		}
		//printf("turnarround_time_sum = %d\n", turnarround_time_sum);
		printf("%d %.2f\n", quantum, (float)turnarround_time_sum / len);
		fprintf(f, "%d %.2f\n", quantum, (float)turnarround_time_sum / len);
	}
	
	fclose(f);
	return 0;
}




