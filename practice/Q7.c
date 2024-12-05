#include<stdio.h>
int fabonacchi(int n){
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
else	
	return fabonacchi(n-2)+fabonacchi(n-1);
}
int main(){
	int n=6;
printf("%d",fabonacchi(n));	
}