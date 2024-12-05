#include<stdio.h>
void recpattern(int i,int j);

int main(){
recpattern( 4,0);
}
void recpattern(int i,int j){

    if(i==0)
    return;

    if(j<i)
    {
        printf("*");
        recpattern( i,j+1);
    }
    else{
        printf("\n");
         recpattern( i-1,j);
    }
}