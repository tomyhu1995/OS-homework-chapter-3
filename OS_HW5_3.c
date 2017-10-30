#include <stdio.h>
#include <stdlib.h>

#define len 8

#define alpha 0.5

int main(int argc, char const *argv[])
{
	int guess[len] = {0};
	guess[0] = 10;
	int real_burst[len] = {0,6,4,6,4,13,13,13};
	int i;

	FILE *f = fopen("data_HW5_3_guess.txt", "w");
	FILE *f_2 = fopen("data_HW5_3_real.txt", "w");
	
	if (f == NULL || f_2 == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	for(i = 1; i < len; i++){
		guess[i] = alpha * real_burst[i] + (1 - alpha) * guess[i-1];
	}

	for(i = 0; i < len; i++){
		fprintf(f, "%d %d\n", i, guess[i]);
		fprintf(f_2, "%d %d\n", i, real_burst[i]);
	}

	fclose(f);
	fclose(f_2);


	return 0;
}