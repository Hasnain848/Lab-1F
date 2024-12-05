#include<stdio.h>
int main(){
	int n;
	printf("Entert the size of array:");
	scanf("%d",&n);
	int array[n];
	for(int i=0;i<n;i++){
		printf("Element %d:",i+1);
		scanf("%d",&array[i]);
	}
	int *ptr=&array,sum=0;
	for(int i=0;i<n;i++){
		sum+=*(ptr+i);
	}
	printf("sum: %d",sum);
	
}