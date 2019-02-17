/*
 * Author: Ahmed Nofal, Avelabs Embedded R&D software team
 */

/* solution for bonus challenge */

#include <stdio.h>
#include <limits.h>
#define INT_MAX  2147483647
#define INT_MIN -2147483648
void Detect_Overflow(char operator, int x, int a){
    int z=0;
    if(operator=='+')
    {
        if((a>0) && (x>INT_MAX-a)){
            printf("overflow \n");
        }
       else if((a<0) && (x<INT_MIN-a)){
        printf("underflow\n");
       }else{
         printf("x + a = %d",x+a);
       }
    }
    if(operator=='-'){
    if((a>0) && (x<INT_MIN+a) ){
        printf("overflow\n");
    }
    else if((a<0) && (x >INT_MAX-a ) ){
        printf("underflow\n");
    }
    else{
        printf("x -a = %d",x-a);
    }
    }
    if(operator=='*'){
     z = x * a;
    if ((a > 0) && (x>0)&&(z / x != a)) {
    printf("overflow\n");
    }
    else if ((a < 0) && (x<0)&&(z / x != a)) {
    printf("overflow\n");
    }
    else if ((a < 0) && (x>0)&&(z / x != a)) {
    printf("underflow\n");
    }
    else if ((a > 0) && (x<0)&&(z / x != a)) {
    printf("underflow\n");
    }
    else{
    printf("x * a = %d",z);
    }
    }
}
int main(void){
	int a1 = INT_MAX, b1 = 1; /* Overflow test for addition */
	int a2 = INT_MIN, b2 = -1; /* Underflow test for addition */
	int a3 = INT_MIN, b3 = INT_MIN - INT_MAX; /* Overflow test for subtraction */
	int a4 = INT_MIN - 10, b4 = INT_MIN; /* Underflow test for subtraction */
	int a5 = INT_MAX, b5 = INT_MAX;
	int a6 = INT_MIN, b6 = INT_MIN;
	Detect_Overflow('+',a1 ,b1);
	Detect_Overflow('+',a2 ,b2);
	Detect_Overflow('-',a3 ,b3);
	Detect_Overflow('-',a4 ,b4);
	Detect_Overflow('*',a5 ,b5);
	Detect_Overflow('*',a6 ,b6);
}
