#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "extras.h"

int boyerMoore (FILE *file, char *userWord)
{
	int m,n;
	int table2[256];
	char word[512];
	int i;
	int j;
	int flag = 0;

    struct timeb startTime;
    struct timeb endTime;
    float delta;


	m = strlen(userWord);
	
	boyerMoore2(userWord, m, table2);

	ftime(&startTime);
	while(!feof(file))
	{
		while (fgets(word, 512, file) != NULL)
		{
			n = strlen(word);
			i =0 ;
			    while(i <= (n - m))
			    {
			        j = m-1;
			        while((j >= 0) && (userWord[j] == word[i+j]))
					{
						j--;						
					}
				        
			        if (j < 0)
			        {
			            flag++;
			            if (i+m < n)
			            {
			            	i = i + m-table2[(int)word[i+m]];
			            }
			            else
			            {
			            	i = 1;
			            }
			        }			 
			        else
			        {
			            i = i + max(1, j-table2[(int)word[i+j]]);
			        }
			        
			    }

		}
	}
	ftime(&endTime);
	delta = (endTime.time - startTime.time)*1000 + (endTime.millitm - startTime.millitm);
	printf("Number found: %d\n", flag);
	printf("Boyer-Moore Execution time: %fmS\n", delta);
	return 0;
}

void boyerMoore2( char *str, int size, int table2[256])
{
    int i;
    int j;

    for (i = 0; i < 256; i++)
	{
         table2[i] = -1;
	} 
 
    for (j = 0; j < size; j++)
    {
        table2[(int)str[j]] = j;
    }
}

int max (int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}