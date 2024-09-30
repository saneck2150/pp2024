#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

FILE *fp;

uint32_t poc, poc1, pocet;
uint16_t temp, num[100000];

clock_t start, end;
double cpu_time_used;

void ul1 (int argc, char* argv[]);
void ul2 (long long int n);
void ul3 (int argc, char* argv[]);

int main(int argc, char* argv[])
{
    ul1(argc, argv);
    return 0;
}

void ul1 (int argc, char* argv[])
{
    fp = fopen(argv[1],"rb");	
	pocet = atoi(argv[2]);

	fread(&num, 100000, sizeof(uint16_t), fp);

	// Start timing after the data is read
	start = clock();

    uint32_t max1 = 0;
    uint32_t max2 = 0;

	for (poc = 0; poc < pocet - 1; poc++){

		if (num[poc] > max1)  // Pre bod A
        {
            max2 = max1;
            max1 = num[poc];
        }
        
        // if (num[poc] >= max1) // Pre bod B
        // {
        //     max2 = max1;
        //     max1 = num[poc];
        // }   
	}

	// Stop timing after sorting is complete
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas na triedenie: %f\n\n", cpu_time_used);
	
	fclose(fp);

	printf("Press enter");
	getchar();
}

void ul2 (long long int n)
{
    printf("Sum of 1 to n integers = %llu \n", n*(n+1)/2); 
}

void ul3 (int argc, char* argv[])
{
     fp = fopen(argv[1],"rb");	
	pocet = atoi(argv[2]);

	fread(&num, 100000, sizeof(uint16_t), fp);

	// Start timing after the data is read
	start = clock();

    uint32_t array[65535];

	for (poc = 0; poc < pocet - 1; poc++){
        array[num[poc]]++;
	}

	// Stop timing after sorting is complete
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Spotrebovany cas na triedenie: %f\n\n", cpu_time_used);
	
	fclose(fp);

	printf("Press enter");
	getchar();
}