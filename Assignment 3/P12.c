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

int quicksort(FILE *file, int user, int numberAttempt)
{
	char word[255];
	long int array[60000][15] = {0};
	long int newArray[60000] = {0};
	
	long int userNumbers[15] = {0};
	long int newuserNumbers = 0; 
	
	int number;
	int digit;
	int i = 0;
	int j = 0;
	int l;
	char* firstPart;

	int zero,one,two,three,four,five,six,seven,eight,nine;
	int count = 0;

    struct timeb startTime;
    struct timeb endTime;
    float delta;

    if (numberAttempt == 0)
    {
		while(!feof(file))
		{
			while(fgets(word, 255,file) != NULL)
			{
				firstPart = strtok(word, " ");
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

				l = 1;
				for (int k = l; k < l+zero; ++k)
				{
					array[i][k] = 0;
				}
				l = l+ zero;
				for (int k = l; k < l+one; ++k)
				{
					array[i][k] = 1;
				}
				l = l + one;
				for (int k = l; k < l+two; ++k)
				{
					array[i][k] = 2;
				}
				l = l+two;
				for (int k = l; k < l+three; ++k)
				{
					array[i][k] = 3;
				}
				l = l+ three;
				for (int k = l; k < l+four; ++k)
				{
					array[i][k] = 4;
				}
				l = l+ four;
				for (int k = l; k < l+five; ++k)
				{
					array[i][k] = 5;
				}
				l = l+five;
				for (int k = l; k < l+six; ++k)
				{
					array[i][k] = 6;
				}
				l = l+six;
				for (int k = l; k < l+seven; ++k)
				{
					array[i][k] = 7;
				}
				l = l+seven;
				for (int k = l; k < l+eight; ++k)
				{
					array[i][k] = 8;
				}
				l = l+eight;
				for (int k = l; k < l+nine; ++k)
				{
					array[i][k] = 9;
				}
				l += nine;
				array[i][11] = zero+one+two+three+four+five+six+seven+eight+nine;
				
				if (array[i][11] == 10)
				{
					newArray[i] = ((array[i][1]*1000000000)+(array[i][2]*100000000)+(array[i][3]*10000000)+
					(array[i][4]*1000000)+(array[i][5]*100000)+(array[i][6]*10000)+
					(array[i][7]*1000)+(array[i][8]*100)+(array[i][9]*10)+(array[i][10]));
				}

				if (array[i][11] == 9)
				{
					newArray[i] = ((array[i][1]*100000000)+(array[i][2]*10000000)+(array[i][3]*1000000)+
					(array[i][4]*100000)+(array[i][5]*10000)+(array[i][6]*1000)+
					(array[i][7]*100)+(array[i][8]*10)+(array[i][9]));
				}

				if (array[i][11] == 8)
				{
					newArray[i] = ((array[i][1]*10000000)+(array[i][2]*1000000)+(array[i][3]*100000)+
					(array[i][4]*10000)+(array[i][5]*1000)+(array[i][6]*100)+
					(array[i][7]*10)+(array[i][8]));
				}

				if (array[i][11] == 7)
				{
					newArray[i] = ((array[i][1]*1000000)+(array[i][2]*100000)+(array[i][3]*10000)+
					(array[i][4]*1000)+(array[i][5]*100)+(array[i][6]*10)+
					(array[i][7]));
				}

				zero=one=two=three=four=five=six=seven=eight=nine=0;


				firstPart = strtok(NULL, " ");
				while (firstPart != NULL)
				{
					i++;
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

					l = 1;
					for (int k = l; k < l+zero; ++k)
					{
						array[i][k] = 0;
					}
					l = l+ zero;
					for (int k = l; k < l+one; ++k)
					{
						array[i][k] = 1;
					}
					l = l + one;
					for (int k = l; k < l+two; ++k)
					{
						array[i][k] = 2;
					}
					l = l+two;
					for (int k = l; k < l+three; ++k)
					{
						array[i][k] = 3;
					}
					l = l+ three;
					for (int k = l; k < l+four; ++k)
					{
						array[i][k] = 4;
					}
					l = l+ four;
					for (int k = l; k < l+five; ++k)
					{
						array[i][k] = 5;
					}
					l = l+five;
					for (int k = l; k < l+six; ++k)
					{
						array[i][k] = 6;
					}
					l = l+six;
					for (int k = l; k < l+seven; ++k)
					{
						array[i][k] = 7;
					}
					l = l+seven;
					for (int k = l; k < l+eight; ++k)
					{
						array[i][k] = 8;
					}
					l = l+eight;
					for (int k = l; k < l+nine; ++k)
					{
						array[i][k] = 9;
					}
					l += nine;
					array[i][11] = zero+one+two+three+four+five+six+seven+eight+nine;
					if (array[i][11] == 10)
					{
					newArray[i] = ((array[i][1]*1000000000)+(array[i][2]*100000000)+(array[i][3]*10000000)+
					(array[i][4]*1000000)+(array[i][5]*100000)+(array[i][6]*10000)+
					(array[i][7]*1000)+(array[i][8]*100)+(array[i][9]*10)+(array[i][10]));
					}

					if (array[i][11] == 9)
					{
						newArray[i] = ((array[i][1]*100000000)+(array[i][2]*10000000)+(array[i][3]*1000000)+
						(array[i][4]*100000)+(array[i][5]*10000)+(array[i][6]*1000)+
						(array[i][7]*100)+(array[i][8]*10)+(array[i][9]));
					}

					if (array[i][11] == 8)
					{
						newArray[i] = ((array[i][1]*10000000)+(array[i][2]*1000000)+(array[i][3]*100000)+
						(array[i][4]*10000)+(array[i][5]*1000)+(array[i][6]*100)+
						(array[i][7]*10)+(array[i][8]));
					}

					if (array[i][11] == 7)
					{
						newArray[i] = ((array[i][1]*1000000)+(array[i][2]*100000)+(array[i][3]*10000)+
						(array[i][4]*1000)+(array[i][5]*100)+(array[i][6]*10)+
						(array[i][7]));
					}

					zero=one=two=three=four=five=six=seven=eight=nine=0;

					firstPart = strtok(NULL, " ");			
				}

			}
		}
		mergesort(newArray,0,60000-1);    	
    }
	ftime(&startTime);
	userNumbers[0] = user;
	number = user;
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
	l = 1;
	for (int k = l; k < l+zero; ++k)
	{
		userNumbers[k] = 0;
	}
	l = l+ zero;
	for (int k = l; k < l+one; ++k)
	{
		userNumbers[k] = 1;
	}
	l = l + one;
	for (int k = l; k < l+two; ++k)
	{
		userNumbers[k] = 2;
	}
	l = l+two;
	for (int k = l; k < l+three; ++k)
	{
		userNumbers[k] = 3;
	}
	l = l+ three;

	for (int k = l; k < l+four; ++k)
	{
		userNumbers[k] = 4;
	}
	l = l+ four;
	for (int k = l; k < l+five; ++k)
	{
		userNumbers[k] = 5;
	}
	l = l+five;
	for (int k = l; k < l+six; ++k)
	{
		userNumbers[k] = 6;
	}
	l = l+six;
	for (int k = l; k < l+seven; ++k)
	{
		userNumbers[k] = 7;
	}
	l = l+seven;
	for (int k = l; k < l+eight; ++k)
	{
		userNumbers[k] = 8;
	}
	l = l+eight;
	for (int k = l; k < l+nine; ++k)
	{
		userNumbers[k] = 9;
	}
	l += nine;
	userNumbers[11] = zero+one+two+three+four+five+six+seven+eight+nine;	

	if (userNumbers[11] == 10)
	{
	newuserNumbers = ((userNumbers[1]*1000000000)+(userNumbers[2]*100000000)+(userNumbers[3]*10000000)+
	(userNumbers[4]*1000000)+(userNumbers[5]*100000)+(userNumbers[6]*10000)+
	(userNumbers[7]*1000)+(userNumbers[8]*100)+(userNumbers[9]*10)+(userNumbers[10]));
	}

	if (userNumbers[11] == 9)
	{
		newuserNumbers = ((userNumbers[1]*100000000)+(userNumbers[2]*10000000)+(userNumbers[3]*1000000)+
		(userNumbers[4]*100000)+(userNumbers[5]*10000)+(userNumbers[6]*1000)+
		(userNumbers[7]*100)+(userNumbers[8]*10)+(userNumbers[9]));
	}

	if (userNumbers[11] == 8)
	{
		newuserNumbers = ((userNumbers[1]*10000000)+(userNumbers[2]*1000000)+(userNumbers[3]*100000)+
		(userNumbers[4]*10000)+(userNumbers[5]*1000)+(userNumbers[6]*100)+
		(userNumbers[7]*10)+(userNumbers[8]));
	}

	if (userNumbers[11] == 7)
	{
		newuserNumbers = ((userNumbers[1]*1000000)+(userNumbers[2]*100000)+(userNumbers[3]*10000)+
		(userNumbers[4]*1000)+(userNumbers[5]*100)+(userNumbers[6]*10)+
		(userNumbers[7]));
	}



	for (int k = 0; k < 60000; ++k)
	{
		if (newuserNumbers == newArray[k])
		{
			count++;
		}
	}
	ftime(&endTime);
	delta = (endTime.time - startTime.time)*1000 + (endTime.millitm - startTime.millitm);
	printf("Presort Execution time: %fmS\n", delta);

	return 0;
}

void mergesort(long int array[],int i, int j)
{
	int middle;

	if (i<j)
	{
		middle = (i+j)/2;
		mergesort(array,i,middle);
		mergesort(array,middle+1,j);
		merge(array,i,middle+1,j);
	}
	return ;
}

void merge (long int array[], int low, int mid, int high)
{
	int i;
	int midA;
	int k;
	int lowA;
	int temp[60000];
	

	lowA = low;
	i = low;
	midA = mid;

	while((lowA < mid) && (midA < high+1))
	{
		if (array[lowA] <= array[midA])
		{
			temp[i]=array[lowA];
			lowA++;
		}
		else
		{
			temp[i]=array[midA];
			midA++;
		}
		i++;
	}

	if(lowA > mid-1)
	{
		for (k=midA; k < high+1; k++)
		{
			temp[i] = array[k];
			i++;
		}
	}
	else
	{
		for (k=lowA; k < mid+1; k++)
		{
			temp[i] = array[k];
			i++;
		}
	}

	for (k = low; k < high+1; k++)
	{
		array[k] = temp[k];
	}
}