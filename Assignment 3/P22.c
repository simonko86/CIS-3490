#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

#include "extras.h"
void horspool3(char *p, int m);
int table[512];

void horspool3(char *p, int m)
{


	for(int i=0;i<512;i++)
	{
		table[i]=m;
 	}

 	for(int j=0;j<m-2;j++)
  	{
  		table[(int)p[j]]=m-1-j;
	}
	return;
}

int horspool (FILE *file, char *p)
{
	char t[500]; 
	int n,m;
	int count2 = 0;
	int check;

    struct timeb startTime;
    struct timeb endTime;
    float delta;

	m = strlen(p);
	horspool3(p,m);

	ftime(&startTime);
	while(!feof(file))
	{
		while (fgets(t, 500, file) != NULL)
		{
			n = strlen(t);
 			check = horspool2(m,n,p,t);
 			if (check != -1)
 			{
 				count2++;
 				//printf("%d\n", count2);
 			}
 		}
 	}
 	ftime(&endTime);

	delta = (endTime.time - startTime.time)*1000 + (endTime.millitm - startTime.millitm);
	printf("Number found:%d\n",count2 );
	printf("Horspool Execution time: %fmS\n", delta);
	return 0;
}

int horspool2(int m,int n,char *p,char *t)
{
	int i;
	int k;

	i = m-1;
	//printf("%s\n",t );
    while(i<=n-1)
    {
    k=0;
        while(k<=m-1 && p[m-1-k]==t[i-k])
        {
            k++;
        }
        if(k==(m))
        {
            //printf("%d\n",i-m+2 );
            return (i-m+2);
            //flag = 1;
            //break;
        }
        else
        {
            i=i+table[(int)t[i]];
        }
    }
	return -1;
}
