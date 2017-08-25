/*Simon Ko
0906762
CIS3490 A2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "P11.h"
#include "P12.h"
#include "P21.h"
#include "P22.h"

/*
This main program reads and parses both
text files provided and executes all four
algorithms. It provides execution time as well
as number of inversions or complex hull
*/
int main(int argc, char const *argv[])
{
	FILE *file;
	char word[255];
	int array[50000] = {0};
	int i = 0;
	char* firstPart;
	char* secondPart;
	char* thirdPart;
	char* fourthPart;
	char* finalPart;

	char* fifthPart;
	char* sixthPart;
	int inversion = 0;
	int inversion2 = 0;

	float array2x[30000] = {0};
	float array2y[30000] = {0};

	int convex = 0;
	int convex2 = 0;

    struct timeb startTime;
    struct timeb endTime;
    struct timeb startTime2;
    struct timeb endTime2;
    struct timeb startTime3;
    struct timeb endTime3;
    struct timeb startTime4;
    struct timeb endTime4;

    float delta;
    float delta2;
    float delta3;
    float delta4;

	float temp;
	float temp2;

	if ((argc > 3) || (argc < 3))
	{
		printf("incorrect args\nshould be ./A2 data_1.txt data_2.txt\n");
		return (-1);
	}
	file = fopen(argv[1], "r");
	while(!feof(file))
	{
		while (fgets(word, 255, file) != NULL)
		{
			firstPart = strtok(word, " ");
			array[i] = atoi(firstPart);
			i++;
			secondPart = strtok(NULL, " ");
			array[i] = atoi(secondPart);
			i++;
			thirdPart = strtok(NULL, " ");
			array[i] = atoi(thirdPart);
			i++;
			fourthPart = strtok(NULL, " ");
			array[i] = atoi(fourthPart);
			i++;
			finalPart = strtok(NULL, " ");
			array[i] = atoi(finalPart);
			i++;
		}
	}
	fclose(file);


	int count = i;

	//printf("%d\n",count );
	//Brute force search algorithm
	ftime(&startTime2);
	inversion2 = bruteforce(array, count);
	ftime(&endTime2);


	//Merge sort algorithm
	ftime(&startTime);
	inversion = mergesort(array,0,count-1);
	ftime(&endTime);


	delta = (endTime.time - startTime.time)*1000 + (endTime.millitm - startTime.millitm);
	delta2 = (endTime2.time - startTime2.time)*1000 + (endTime2.millitm - startTime2.millitm);

	printf("\nBrute force\nExecution time: %fmS. Inversion count: %d\n",delta2, inversion2);
	printf("\nMerge sort\nExecution time: %fmS. Inversion count: %d\n",delta, inversion);
	printf("\n");

	file = fopen(argv[2], "r");
	i = 0;
	while(!feof(file))
	{
		while (fgets(word, 255, file) != NULL)
		{
			fifthPart = strtok(word, " ");
			array2x[i] = atof(fifthPart);
			sixthPart = strtok(NULL, " ");
			array2y[i] = atof(sixthPart);
			i++;
		}
	}
	fclose(file);
	count = i;

	ftime(&startTime3);
	convex = bruteforceConvex(count, array2x, array2y);
	ftime(&endTime3);
	//count = 20;
//sort into increasing values of x
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if(i != j)
			{
				if ((array2x[i] < array2x[j]) || ((array2x[i] == array2x[j]) && (array2y[i] < array2y[j])))
				{ //swap i and j around for x
					temp = array2x[i];
					array2x[i] =  array2x[j];
					array2x[j] = temp;
					//swap i and j around for y
					temp2 = array2y[i];
					array2y[i] =  array2y[j];
					array2y[j] = temp2;
				}

			}
		}
	}

	ftime(&startTime4);
	convex2 = mergeHull(0, count, array2x,array2y);
	ftime(&endTime4);


	delta3 = (endTime3.time - startTime3.time)*1000 + (endTime3.millitm - startTime3.millitm);
	delta4 = (endTime3.time - startTime3.time)/1000 + (endTime3.millitm - startTime3.millitm);
	printf("\nBrute force\nExecution time: %fmS. Convex count: %d\n",delta3,convex);
	printf("\nQuickhull\nExecution time: %fmS. Convex count: %d\n",delta4,convex);
	printf("\n");

	return 0;
}


