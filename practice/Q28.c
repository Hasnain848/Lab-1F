#include<stdio.h>
int power(int base, int exponent);
int main(){
	int base=5;
	int exponent=2;
	printf("Result: %d",power(base,exponent));
}
int power(int base, int exponent){
static	int result=1;
	if(exponent==0)
	return result;
	
	result*=base;
	return power(base,exponent-1);
}
