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
This algorithm uses recursive programming to find the convex hull
of a set of x y coordinates
The coordinates are sorted in the main program increasing order of x
A line from smallest x to largest x is found and the max value of upper
and lower hulls are calculated
This is then recursive, eventually finding all convex hulls

*/


int mergeHull(int start, int count, float array2x[],float array2y[])
{

	float a,b,c;
	int k = 0;
	int l = 0;
	int convex = 0;
	float blah;
	float temparrayx[30000];
	float temparrayy[30000];
	float temparray2x[30000];
	float temparray2y[30000];

	float maxX, maxY, maxX2, maxY2;


	int counted;
	count = 10;

	//find upper and lower hulls
	//straight line between pstart and pmax
	a = array2y[count] - array2y[start]; //y2-y1
	b = array2x[start] - array2x[count]; //x1-x2
	c = ((array2x[start]*array2y[count]) - (array2x[count]*array2y[start])); //x1*y2 - x2*y1

	for (int j = 0; j < count; ++j)
	{
		blah = ((a*array2x[j])+(b*array2y[j])-c);
		if (blah > 0)
		{
			//upper hull
			temparrayx[k] = array2x[j];
			temparrayy[k] = array2y[j];
			k++;
			//store into temp array
			//find pmax of that temp array if no pmax, then quit
		}	
		else if (blah < 0)
		{
			//lower hull
			temparray2x[l] = array2x[j];
			temparray2y[l] = array2y[j];
			l++;
		}
	}
	printf("%d %d \n", k ,l);

	//find pmax of temp array
	if (k != 0)
	{
		maxY = pmax(temparrayy,temparrayx,k);
	}
	else
	{
		return convex; //or break;
	}
	printf("%f\n", maxY);

	for (int m = 0; m < count; m++)//go through and find the xcoordinate that matches the y
	{
		if (maxY == temparrayy[m])
		{
			maxX = temparrayx[m];
		}
	}

	counted = 0;
	for (int i = 0; i < count; ++i)
	{
		if((maxX != temparrayx[i]) && (maxY != temparrayy[i]))//
		{
			counted++;
		}
	}

	convex = convex + mergeHull(0,k,temparrayx, temparrayy);

	if (l != 0)
	{
		maxY2 = pmax(temparray2y,temparray2x,l);
	}
	else
	{
		return convex; //or break;
	}
	for (int m = 0; m < count; m++)
	{
		if (maxY2 == temparrayy[m])
		{
			maxX2 = temparrayx[m];
		}
	}
	counted = 0;
	for (int i = 0; i < count; ++i)
	{
		if((maxX2 != temparray2x[i]) && (maxY2 != temparray2y[i]))//
		{
			counted++;
		}
	}

	convex = convex + mergeHull(l,count,temparray2x,temparray2x);
	return convex;
}

float pmax(float array2y[], float array2x[], int count)
{
	float temp = 0;
	float calc;


	for (int i = 0; i < count; ++i)
	{
		calc = (array2y[i]*array2y[i]) + (array2x[i]*array2x[i]);
		if (temp < calc)
		{
			temp = array2y[i];
		}
	}
	return temp;
}