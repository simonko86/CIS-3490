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
This algorithm splits the the array into 2
recursively, until there are only 2 elements
remaining in an array. It then sorts them into
ascending order and merges them back together.
*/
int mergesort(int array[],int i, int j)
{
	int middle;
	int inversion = 0;

	if (i<j)
	{
		middle = (i+j)/2;
		inversion = mergesort(array,i,middle);
		inversion = inversion + mergesort(array,middle+1,j);
		inversion = inversion + merge(array,i,middle+1,j);
	}
	return inversion;
}
int merge (int array[], int low, int mid, int high)
{
	int i;
	int midA;
	int k;
	int lowA;
	int temp[50000];
	int inversion = 0;
	

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
			inversion = inversion + mid - lowA;
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

	return inversion;
}
