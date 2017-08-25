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
This program uses brute force to find the convex hull of 
a given x and y coordinates.  The first two for loops calculate
the line of two coordinates, while the third for loops goes through
every other element to find out if it lies on one side of the line or
the other
If all the numbers are on one side, the x and y coordinates are stored
in a temp array. If they are already stored, then they are not stored.
*/


int bruteforceConvex(int count,float array2x[],float array2y[])
{
	int counted;
	int tokenA;
	int tokenB;
	float blah;
	float a,b,c;
	int i,j,k,l;
	float tempx[30] = {0};
	float tempy[30] = {0};
	int convex = 0;

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; j++)
		{
			
			if (i != j)
			{
				counted = 0;
				tokenA = 0;
				tokenB = 0;	

				a = array2y[j] - array2y[i]; //y2-y1
				b = array2x[i] - array2x[j]; //x1-x2
				c = ((array2x[i]*array2y[j]) - (array2x[j]*array2y[i])); //x1*y2 - x2*y1
				for (k = 0; k < count; k++)
				{
					if ((k != i) && (k != j))
					{
						counted++;
						blah = ((a*array2x[k])+(b*array2y[k])-c);
						if (blah > 0)
						{
							tokenA++;
						}

						if (blah < 0)
						{
							tokenB++;
						}

						if((tokenA > 1) && (tokenB > 1))
						{
							break;
						}

					}
				}

				if ((tokenA == counted) || (tokenB == counted)) //if it is a convex hull
				{
					for (l = 0; l <= 30; l++) //go through the temp list
					{
						//put i and j in if checking
						if ((tempy[l] == array2y[j]) && (tempx[l] == array2x[j])) // if there is a match then break out
						{
							break;
						}
						else if(((tempy[l] != array2y[j]) && (tempx[l] != array2x[j])) && (tempy[l] == 0))
						{
							tempx[l] = array2x[j]; //
							tempy[l] = array2y[j];
							break;
						}
					}
					for (l = 0; l <= 30; l++) //go through the temp list
					{
						if ((tempy[l] == array2y[i]) && (tempx[l] == array2x[i])) // if there is a match then break out
						{
							break;
						}
						else if(((tempy[l] != array2y[i]) && (tempx[l] != array2x[i])) && (tempy[l] == 0))
						{
							tempx[l] = array2x[i]; //
							tempy[l] = array2y[i];
							break;
						}
					}

				}

					
			}
		}
	}
	for (i = 0; i < 30; ++i)
	{
		if (tempx[i] != 0)
		{
			convex++;
			printf("%.1lf,%.1lf\n", tempx[i],tempy[i]);
		}
	}
	return convex;
}