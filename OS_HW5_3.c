#include <stdio.h>
#include <stdlib.h>

#define len 100

int main(int argc, char const *argv[])
{
	int guess[len] = {0};
	int real_burst[len] = {0};
	int i = 0;
	int length = 1;
	float alpha;

	do{
		int tmp;
		printf("Please enter real CPU burst time, enter -1 for terminate input: ");
		scanf("%d", &tmp);
		if(tmp != -1){
			real_burst[length++] = tmp;
		}else{
			break;
		}
	}while(1);

	printf("Please enter the value of alpha: ");
	scanf("%f", &alpha);

	printf("Please enter the first value of guessing: ");
	scanf("%d", &guess[0]);

	FILE *f = fopen("data_HW5_3_guess.txt", "w");
	FILE *f_2 = fopen("data_HW5_3_real.txt", "w");
	
	if (f == NULL || f_2 == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	for(i = 1; i < length; i++){
		guess[i] = alpha * real_burst[i] + (1.0 - alpha) * guess[i-1];
	}

	for(i = 0; i < length; i++){
		fprintf(f, "%d %d\n", i, guess[i]);
		fprintf(f_2, "%d %d\n", i, real_burst[i]);
	}

	fclose(f);
	fclose(f_2);


	return 0;
}