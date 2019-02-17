/*
 * AUTHOR: Ahmed Nofal, Avelabs Embedded R&D software team
 */
#include <stdio.h>
/* Complete the function below to detect the endianness of the machine*/
void Detect_Endianness(void){
	int x=0x9010;
	char* ptr=&x;

	if((*ptr)==90 )
	{
		printf("Big endian\n");
	}
	else{
		printf("Little endian\n");
	}
}

int main(void){
	Detect_Endianness();
}
