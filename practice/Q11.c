#include<stdio.h>
void bubblesort(int array[],int size);
int main(){int size;
	int array[]={15,45,35,19,78,90,32};
	printf("Enter the size of array you want: ");
	scanf("%d",&size);
	for(int i=0;i<size;i++){
		printf("element %d : ",i+1);
		scanf("%d",&array[i]);
	}
	
  printf("Original array:\n");
  for(int i=0;i<size;i++){
  	printf("%d,",array[i]);
  }
  bubblesort(array,size);
  printf("\nSorted array:\n");
  for(int j=0;j<size;j++){
  	printf("%d,",array[j]);
  }
  
}
void bubblesort(int array[],int size){
	if(size==1){
	return ;
	}
	else{
		for(int i=0;i<size-1;i++){
			if(array[i]>array[i+1]){
				int temp=array[i];
				array[i]=array[i+1];
				array[i+1]=temp;
			}
		}
		bubblesort(array,size-1);
		
	}
}