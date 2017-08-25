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

int bruteforce(FILE *file, int user)
{

	char word[255];
	int array[60000][15] = {0};
	int numbers[15] = {0};
	int i = 0;
	int j = 0;
	int number;
	int digit;
	int count = 0;
	char* firstPart;
	char* secondPart;
	char* thirdPart;
	char* fourthPart;
	char* finalPart;
	int zero,one,two,three,four,five,six,seven,eight,nine;

    struct timeb startTime;
    struct timeb endTime;
    float delta;
	ftime(&startTime);
	while(!feof(file))
	{
		while (fgets(word,255,file) != NULL)
		{
			firstPart = strtok(word, " ");
			j = 1;
			number = atoi(firstPart);
			array[i][0] = number;
			while (number > 0)
			{
				digit = number % 10;
				j++;

				switch(digit){
					case 0:
						zero++;
					break;
					case 1:
						one++;
					break;
					case 2:
						two++;
					break;
					case 3:
						three++;
					break;
					case 4:
						four++;
					break;
					case 5:
						five++;
					break;
					case 6:
						six++;
					break;
					case 7:
						seven++;
					break;
					case 8:
						eight++;
					break;
					case 9:
						nine++;
					break;
				}
				number /= 10;
			}
			array[i][1] = zero;
			array[i][2] = one;
			array[i][3] = two;
			array[i][4] = three;
			array[i][5] = four;
			array[i][6] = five;
			array[i][7] = six;
			array[i][8] = seven;
			array[i][9] = eight;
			array[i][10] = nine;
			array[i][11] = zero+one+two+three+four+five+six+seven+eight+nine;
			zero=one=two=three=four=five=six=seven=eight=nine=0;
			i++;

			secondPart = strtok(NULL, " ");
			j = 1;
			number = atoi(secondPart);
			array[i][0] = number;
			while (number > 0)
			{
				digit = number % 10;
				j++;

				switch(digit){
					case 0:
						zero++;
					break;
					case 1:
						one++;
					break;
					case 2:
						two++;
					break;
					case 3:
						three++;
					break;
					case 4:
						four++;
					break;
					case 5:
						five++;
					break;
					case 6:
						six++;
					break;
					case 7:
						seven++;
					break;
					case 8:
						eight++;
					break;
					case 9:
						nine++;
					break;
				}
				number /= 10;
			}
			array[i][1] = zero;
			array[i][2] = one;
			array[i][3] = two;
			array[i][4] = three;
			array[i][5] = four;
			array[i][6] = five;
			array[i][7] = six;
			array[i][8] = seven;
			array[i][9] = eight;
			array[i][10] = nine;
			array[i][11] = zero+one+two+three+four+five+six+seven+eight+nine;
			zero=one=two=three=four=five=six=seven=eight=nine=0;
			i++;

			thirdPart = strtok(NULL, " ");
			j = 1;
			number = atoi(thirdPart);
			array[i][0] = number;
			while (number > 0)
			{
				digit = number % 10;
				j++;

				switch(digit){
					case 0:
						zero++;
					break;
					case 1:
						one++;
					break;
					case 2:
						two++;
					break;
					case 3:
						three++;
					break;
					case 4:
						four++;
					break;
					case 5:
						five++;
					break;
					case 6:
						six++;
					break;
					case 7:
						seven++;
					break;
					case 8:
						eight++;
					break;
					case 9:
						nine++;
					break;
				}
				number /= 10;
			}
			array[i][1] = zero;
			array[i][2] = one;
			array[i][3] = two;
			array[i][4] = three;
			array[i][5] = four;
			array[i][6] = five;
			array[i][7] = six;
			array[i][8] = seven;
			array[i][9] = eight;
			array[i][10] = nine;
			array[i][11] = zero+one+two+three+four+five+six+seven+eight+nine;
			zero=one=two=three=four=five=six=seven=eight=nine=0;
			i++;

			fourthPart = strtok(NULL, " ");
			j = 1;
			number = atoi(fourthPart);
			array[i][0] = number;
			while (number > 0)
			{
				digit = number % 10;
				j++;

				switch(digit){
					case 0:
						zero++;
					break;
					case 1:
						one++;
					break;
					case 2:
						two++;
					break;
					case 3:
						three++;
					break;
					case 4:
						four++;
					break;
					case 5:
						five++;
					break;
					case 6:
						six++;
					break;
					case 7:
						seven++;
					break;
					case 8:
						eight++;
					break;
					case 9:
						nine++;
					break;
				}
				number /= 10;
			}
			array[i][1] = zero;
			array[i][2] = one;
			array[i][3] = two;
			array[i][4] = three;
			array[i][5] = four;
			array[i][6] = five;
			array[i][7] = six;
			array[i][8] = seven;
			array[i][9] = eight;
			array[i][10] = nine;
			array[i][11] = zero+one+two+three+four+five+six+seven+eight+nine;
			zero=one=two=three=four=five=six=seven=eight=nine=0;
			i++;

			finalPart = strtok(NULL, " ");
			j = 1;
			number = atoi(finalPart);
			array[i][0] = number;
			while (number > 0)
			{
				digit = number % 10;
				j++;

				switch(digit){
					case 0:
						zero++;
					break;
					case 1:
						one++;
					break;
					case 2:
						two++;
					break;
					case 3:
						three++;
					break;
					case 4:
						four++;
					break;
					case 5:
						five++;
					break;
					case 6:
						six++;
					break;
					case 7:
						seven++;
					break;
					case 8:
						eight++;
					break;
					case 9:
						nine++;
					break;
				}
				number /= 10;
			}
			array[i][1] = zero;
			array[i][2] = one;
			array[i][3] = two;
			array[i][4] = three;
			array[i][5] = four;
			array[i][6] = five;
			array[i][7] = six;
			array[i][8] = seven;
			array[i][9] = eight;
			array[i][10] = nine;
			array[i][11] = zero+one+two+three+four+five+six+seven+eight+nine;
			zero=one=two=three=four=five=six=seven=eight=nine=0;
			i++;
		}
	}

	numbers[0] = user;

	zero=one=two=three=four=five=six=seven=eight=nine=0;

	while (user > 0)
	{
		digit = user % 10;
		switch(digit){
			case 0:
				zero++;
			break;
			case 1:
				one++;
			break;
			case 2:
				two++;
			break;
			case 3:
				three++;
			break;
			case 4:
				four++;
			break;
			case 5:
				five++;
			break;
			case 6:
				six++;
			break;
			case 7:
				seven++;
			break;
			case 8:
				eight++;
			break;
			case 9:
				nine++;
			break;
		}
		user /= 10;
	}
	numbers[1] = zero;
	numbers[2] = one;
	numbers[3] = two;
	numbers[4] = three;
	numbers[5] = four;
	numbers[6] = five;
	numbers[7] = six;
	numbers[8] = seven;
	numbers[9] = eight;
	numbers[10] = nine;
	numbers[11] = zero+one+two+three+four+five+six+seven+eight+nine;
	zero=one=two=three=four=five=six=seven=eight=nine=0;
	printf("Permutations: \n");
	
	for (int k = 0; k < i; ++k) //loop through set of numbers
	{
		if (numbers[11] == array[k][11]) //if they don't match in length
		{
			if ((numbers[1] == array[k][1]) && (numbers[2] == array[k][2]) && (numbers[3] == array[k][3]) &&
				(numbers[4] == array[k][4]) && (numbers[4] == array[k][4]) && (numbers[5] == array[k][5]) &&
				(numbers[6] == array[k][6]) && (numbers[7] == array[k][7]) && (numbers[8] == array[k][8]) &&
				(numbers[9] == array[k][9]) && (numbers[10] == array[k][10]))
			{
				printf("%d\n",array[k][0]);
				count++;
			}
		}	
	}
	ftime(&endTime);
	delta = (endTime.time - startTime.time)*1000 + (endTime.millitm - startTime.millitm);
	printf("Number of permutations is: %d\n", count);
	printf("Brute force Execution time: %fmS\n", delta);
	return 0;
}



