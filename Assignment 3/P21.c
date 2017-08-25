/*Simon Ko
0906762
CIS3490 A2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "extras.h"

int bruteforce2(FILE *file, char *userWord)
{

	int lengthUserWord;
	int lengthWord;
	int token = 0;
	int count2 = 0;
	char word[512];
	int j = 0;

    struct timeb startTime;
    struct timeb endTime;
    float delta;


	userWord[strlen(userWord)] = '\0';


	ftime(&startTime);
	while(!feof(file))
	{
		while (fgets(word, 512, file) != NULL)
		{
			word[strlen(word)] = '\0';
			lengthWord = strlen(word);
			lengthUserWord = strlen(userWord);
			for (int i = 0; i < lengthWord; ++i)
			{
					if (word[i] == userWord[j])
					{
						token++;
						j++;
					}
					else if (word[i] != userWord[j])
					{
						token = 0;
						j = 0;
					}
					if (token == lengthUserWord-1)
					{
						count2++;
						j = 0;
					}
			}
		}
	}
	ftime(&endTime);
	delta = (endTime.time - startTime.time)*1000 + (endTime.millitm - startTime.millitm);
	printf("Number found: %d\n",count2 );
	printf("Brute force Execution time: %fmS\n", delta);
	return 0;
}
