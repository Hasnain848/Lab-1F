#include<stdio.h>
void triangle(int n,int b);
int main(){
triangle(4,1);
}
void triangle(int n,int b){
     if(n<b)
     return ;

     for(int i=n;i>0;i--){
        printf("*");
     }
    printf("\n");
   return triangle(n-1,b);

}