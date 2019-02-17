/*********************************************************************************
 *
 *  problem_one.c
 *  Author: Ahmed Nofal, Avelabs Embedded software R&D crew
 *
 ********************************************************************************/
#include <stdio.h>
#include "problem_one.h"

/****************************[Problem Description]*********************************
 *
 * Given an array that is circularly rotated and sorted in an ascending order and
 * the rotation is clock wise, find the number of rotations in the array.
 *
 * Sample Input:  arr = [8, 9, 10, 2, 5, 6]
 * Sample Output: The Array is rotated 3 times
 *
 * Sample Input:  arr = [2, 5, 6, 8, 9, 10]
 * Sample Output: The array is rotated 0 times
 *
 ********************************************************************************/

/*********************************************************************************
 *
 * Function: findRotationCount
 * @param: arr[], Array that the function should find the number of rotations in.
 * @param: arr_size, Size of the array
 * Description: Function to find the number of times the array is rotated
 *
 ********************************************************************************/
int findRotationCount(int arr[], int arr_size) {
	/* Your code goes here  */
	int i;
	char flag=0;
	int NumOfRotations=0;
	int temp=0;
	while(1)
	{
	for(i=0;i<arr_size;i++){
		if(arr[i]>arr[i+1]){
			flag=1;
		}
	}
	if(flag==1){
		NumOfRotations++;
		temp=arr[0];
		arr[0]=arr[arr_size-1];
		arr[arr_size-1]=arr[0];
		for(i=arr_size;i>2;i--)
		{
		temp=arr[arr_size-1];
		arr[i-1]=arr[i-2];
		arr[arr_size-2]=temp;
		}
		flag=0;

	}
	else{
		break;

	}
	}
	return NumOfRotations;
}


/*********************************************************************************
 *
 * findRotationCount_Test function to test your code
 *
 ********************************************************************************/
void findRotationCount_Test(void)
{
	int arr[] = { 8, 9, 10, 2, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int count = findRotationCount(arr, n);
	printf("The array is rotated %d times\n", count);
}
