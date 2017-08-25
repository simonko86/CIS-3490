
#ifndef __SKO01_extras__ //Header guards incase header is already read
#define __SKO01_extras__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>


int bruteforce(FILE *file, int user);

int quicksort(FILE *file, int user, int numberAttempt);
void mergesort(long int array[],int i, int j);
void merge (long int array[], int low, int mid, int high);

int bruteforce2(FILE *file, char *userWord);

int horspool (FILE *file, char *p);
int horspool2(int m,int n,char *p,char *t);

int boyerMoore (FILE *file, char *userWord);
void boyerMoore2( char *str, int size, int badchar[256]);
int max (int a, int b);


#endif