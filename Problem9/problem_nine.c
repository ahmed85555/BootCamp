/*********************************************************************************
 *
 *  problem_ten.h
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
/****************************[Problem Description]****************************************************
 *
 * Given a number "N" find four integer numbers a, b, c and d such that b, c and d are prime numbers,
 * and a & N are odd knowing that a^3 + b^3 + c^3 + d^3 = N and a <= b <= c <= d
 *
 * Sample Input: N = 161
 * Sample Output: Numbers are 1, 2, 3 and 5
 *
 * @return: Array containing a, b, c and d respectively that satisfy the equation
 *
 * Note: 1 <= N <= 10^18
 *
 *******************************************************************************************************/
#include <stdio.h>
#include "problem_nine.h"

int* findPrimeNumbers(int N){
	/* Your Code Goes here*/
	int i=0;
	char flaga=0;
	char flagb=0;
	char flagc=0;
	char flagd=0;
	static int arr[4];
	int a=1 ,b=2,c=3,d=5;
	while(1)
	{

	if(((a*a*a)+(b*b*b)+(c*c*c)+(d*d*d))==N){
		arr[0]=a;
		arr[1]=b;
		arr[2]=c;
		arr[3]=d;
	}
	else{

		flaga=1;
	}
	if(flaga==1){
		a+=2;
		flagb=1;
		flaga=0;
	}else if(flagb==1){

	}else if(flagc==1){


	}else{


	}


	}
}


void findPrimeNumbers_test(void){
	int* ptrToPrimes = findPrimeNumbers(161);
	printf("The numbers are: %d, %d, %d and %d\n",ptrToPrimes[0],ptrToPrimes[1],ptrToPrimes[2],ptrToPrimes[3]);
}
