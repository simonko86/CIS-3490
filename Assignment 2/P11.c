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

/*
This program loops through two element
at a time, and then swaps the elements
if i > j
*/
int bruteforce(int array[], int count)
{
	int inversion = 0;
	for (int i = 0; i < count; ++i)
	{
		for (int j = i+1; j < count; ++j)
		{

			if (array[i] > array[j])
			{
				inversion++;
			}
		}
	}
	return inversion;
}