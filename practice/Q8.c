#include<stdio.h>
void recursion(int *array,int size){
	int i=0;
	if(size<=0)
	return;
	else{
	printf("%d",array[i]);
	i++;
	return  recursion(array+1, size -1);
		
	}
	
}
int main(){
	int array[]={1,2,3,4,5};
	recursion(array,5);
}