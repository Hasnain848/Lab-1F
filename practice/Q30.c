#include<stdio.h>

int main(){
int n,sum=0,sum1=0;
printf("Enter the size of array(odd): ");
scanf("%d",&n);
if( n % 2==0){
    printf("Enter the odd nuber please");
  return 0;
}
int array[n][n];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("Element of row %d and colom %d: ",i+1,j+1);
        scanf("%d",&array[i][j]);
        if(i==j){
            sum+=array[i][j];
        }
        if((i+j)==n-1){
        sum1+=array[i][j];}
    }
}
printf("Sum: %d",sum+sum1);
}