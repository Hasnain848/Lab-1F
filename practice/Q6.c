#include<stdio.h>
int sum(int n){
	if(n==1)
	return 1;
	
	return n+sum(n-1);
}
int main(){
	int n=5;
	int sum1=sum(n);
	printf("%d",sum1);
}