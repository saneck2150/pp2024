
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

FILE *fp;

uint32_t poc, poc1, pocet;
uint16_t temp, num[100000];

clock_t start, end;
double cpu_time_used;

void bublesort_first (int argc, char* argv[]); // First meserment
void bublesort_second (int argc, char* argv[]); // Second mesurment
void bublesort_third (int argc, char* argv[]); // Sort from Max to Min

int main(int argc, char *argv[]) {
	
	bublesort_second(argc, argv);
	return 0;
}

void bublesort_first (int argc, char* argv[])
{
	fp = fopen(argv[1],"rb");	
	pocet = atoi(argv[2]);

	start = clock();

	fread(&num, 100000, sizeof(uint16_t), fp);

	for (poc = 0; poc < pocet - 1; poc++)
	for (poc1 = 0; poc1 < pocet - poc - 1; poc1++) {
		
		if (num[poc1] > num[poc1 + 1] ) {
			
				temp = num[poc1];
				num[poc1] = num[poc1 + 1];
				num[poc1 + 1] = temp;
		}
	}
	end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas : %f\n\n", cpu_time_used);
	
	printf("Press enter");
	getchar();
	
}

void bublesort_second (int argc, char* argv[])
{
	fp = fopen(argv[1],"rb");	
	pocet = atoi(argv[2]);

	fread(&num, 100000, sizeof(uint16_t), fp);

	// Start timing after the data is read
	start = clock();

	for (poc = 0; poc < pocet - 1; poc++)
		for (poc1 = 0; poc1 < pocet - poc - 1; poc1++) {
			if (num[poc1] > num[poc1 + 1] ) {
				temp = num[poc1];
				num[poc1] = num[poc1 + 1];
				num[poc1 + 1] = temp;
			}
		}

	// Stop timing after sorting is complete
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas na triedenie: %f\n\n", cpu_time_used);
	
	fclose(fp);

	printf("Press enter");
	getchar();
}

void bublesort_third (int argc, char* argv[])
{
	fp = fopen(argv[1],"rb");	
	pocet = atoi(argv[2]);

	fread(&num, 100000, sizeof(uint16_t), fp);

	start = clock();

	for (poc = 0; poc < pocet - 1; poc++)
		for (poc1 = 0; poc1 < pocet - poc - 1; poc1++) {
			if (num[poc1] < num[poc1 + 1] ) {  
				temp = num[poc1];
				num[poc1] = num[poc1 + 1];
				num[poc1 + 1] = temp;
			}
		}

	end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas na triedenie: %f\n\n", cpu_time_used);
	
	fclose(fp);

	printf("Press enter");
	getchar();
}