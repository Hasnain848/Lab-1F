#include<stdio.h>
int findMax(int* arr, int size);
int main(){
int arr[]={1,100,3,4,5,34};
int size=sizeof(arr)/sizeof(arr[0]);
	printf("max: %d",findMax(arr,size));
}
int findMax(int* arr, int size){
static	int max =0;
	
	if(size<0)
	return max;
	
	if(arr[size]>max)
	max=arr[size];
	
	return findMax(arr,size-1);
}