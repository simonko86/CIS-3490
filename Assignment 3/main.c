/*Simon Ko
0906762
CIS3490 A3
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "extras.h"

#define MAX 300


int main(int argc, char const *argv[])
{
	FILE *file;
	FILE *file2;
	int choice;
	int choice2;
	char userWord[25];
	int userNum;
	int numAttempts = 0;

	if(argc > 3)
	{
		printf("Incorrect args\nShould be ./A3 data_4.txt data_5.txt\n");
		return -1;
	}

	while(1)
	{
		printf("What execution do you want? \n");
		printf("1 For permutation search\n");
		printf("2 For string search \n");
		printf("3 To exit \n");
		scanf("%d", &choice);

		if (choice == 1)
		{
			printf("Enter the number:\n");
			scanf("%d", &userNum);

			file = fopen(argv[1], "r");
			bruteforce(file, userNum);
			fclose(file);

			file = fopen(argv[1], "r");
			quicksort(file, userNum, numAttempts);
			fclose(file);
			numAttempts++;
		}
		else if (choice == 2)
		{
			printf("Enter the search string:\n");
			scanf("%s", userWord);	

			printf("1 To include horspool, 2 to not include\n");
			scanf("%d",&choice2);
			
			if (choice2 == 1)
			{
				file2 = fopen(argv[2], "r");
				bruteforce2(file2, userWord);
				fclose(file2);

				file2 = fopen(argv[2], "r");
				horspool(file2, userWord);
				fclose(file2);

				file2 = fopen(argv[2], "r");			
				boyerMoore(file2, userWord);
				fclose(file2);
			
			}
			else if (choice2 == 2)
			{
				file2 = fopen(argv[2], "r");
				bruteforce2(file2, userWord);
				fclose(file2);

				file2 = fopen(argv[2], "r");			
				boyerMoore(file2, userWord);
				fclose(file2);
			}
			else
			{
				printf("incorrect option\n");
			}
			
		}
		else if (choice == 3)
		{
			return 0;
		}
		else
		{
			printf("incorrect choice\n");
		}


		
	}

	return 0;
}








