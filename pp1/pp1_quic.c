
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

FILE *fp;

uint32_t poc, poc1, pocet;
uint16_t temp, num[100000];

clock_t start, end;
double cpu_time_used;

void quick_first (int argc, char* argv[]);
void quick_second (int argc, char* argv[]);
void quick_third (int argc, char* argv[]);

int cmpfunc (const void * a, const void * b) {
   return ( *(uint16_t*)a - *(uint16_t*)b );
}

int cmpfunc_reverse (const void * a, const void * b) {
   return ( *(uint16_t*)b - *(uint16_t*)a );  
}

int main(int argc, char *argv[]) {
	quick_second(argc, argv);
	return 0;
}


void quick_first (int argc, char* argv[])
{
    fp = fopen(argv[1],"rb");
	pocet = atoi(argv[2]);

	start = clock();
	
	fread(&num, 100000, sizeof(uint16_t), fp);

	qsort(num, pocet, sizeof(uint16_t), cmpfunc);
	
	end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas : %f\n\n", cpu_time_used);
	
	printf("Stlac enter");
	getchar();
}

void quick_second (int argc, char* argv[])
{
	fp = fopen(argv[1],"rb");
	pocet = atoi(argv[2]);
	
	fread(&num, 100000, sizeof(uint16_t), fp);

	start = clock();
	
	qsort(num, pocet, sizeof(uint16_t), cmpfunc);
	
	end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas na triedenie: %f\n\n", cpu_time_used);
	
	fclose(fp);

	printf("Stlac enter");
	getchar();
}

void quick_third (int argc, char* argv[])
{
    fp = fopen(argv[1],"rb");
	pocet = atoi(argv[2]);
	
	fread(&num, 100000, sizeof(uint16_t), fp);

	start = clock();
	
	qsort(num, pocet, sizeof(uint16_t), cmpfunc_reverse);
	
	end = clock();
    
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas na triedenie: %f\n\n", cpu_time_used);
	
	fclose(fp);

	printf("Stlac enter");
	getchar();
}