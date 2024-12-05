#include<stdio.h>
int recursiveSum(int* arr, int size);
int main(){
	int arr[]={1,2,3,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("sum: %d",recursiveSum(arr,size));
}
int recursiveSum(int* arr, int size){
	static int sum=0;
	if(size<0)
	return sum;
	sum+=arr[size];
	return recursiveSum(arr,size-1);
	
}