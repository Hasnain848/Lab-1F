#include<stdio.h>
int* reverseArray(int* arr, int start, int end);
int main(){
	int arr[]={1,2,3,4,5};
	int end=sizeof(arr)/sizeof(arr[0]);
    int *arr2=reverseArray(arr,0,end-1);
    for(int i=0;i<end;i++){
    printf("%d,",arr2[i]);
    	
	}
}
int* reverseArray(int* arr, int start, int end){
	if(start>end)
	return arr;
	int temp;
	temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	return reverseArray(arr,start +1,end -1);
}