#include<stdio.h>
int sum(int n){
static sum1=0;	
	if(n==0)
	return sum1;
	else{
		sum1+=n%10;
		return sum(n/10);
	}
}
int main(){
	int n=123456;
    // int sum1=0;
	printf("%d",sum(n));
}