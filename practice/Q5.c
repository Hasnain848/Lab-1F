#include<stdio.h>
int main(){
	int n;
	
	printf("Enter the size of 2d matrice: ");
	scanf("%d",&n);
	int array[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("Element 1 of row %d and colom %d: ",i+1,j+1);
			scanf("%d",&array[i][j]);
		}
	}
	int sum1=0,sum2=0,sum3=0,sum4=0;
	int total;
	for(int i=0;i<n;i++){
		sum1+=array[0][i];//first row
		sum2+=array[i][0];//first colom
		sum3+=array[n-1][i];//last row
		sum4+=array[i][n-1];//last colom
}
total=sum1+sum2+sum3+sum4;
printf("Sum=%d",total);
}