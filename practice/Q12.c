#include<stdio.h>
int function(int array[],int size,int target,int currentindex);
int main(){
	int array[]={1,2,3,4,5,6};
	int target=2;
	int size=sizeof(array)/sizeof(array[0]);
	int currentindex=1;
	
	if(function(array,size,target,currentindex)){
		printf("Found");
	}
	else{
		printf("Not found");
	}
}
int function(int array[],int size,int target,int currentindex){
	if(currentindex==size)
	 return 0;
	 else{
	 	if(array[currentindex]==target){
	 		return 1;
		 }
		function(array,size,target,currentindex+1);
	 }
}