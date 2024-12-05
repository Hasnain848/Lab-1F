#include<stdio.h>
void swaped(int *aPtr, int *bPtr, int *cPtr);
int main(){
	int a,b,c;
	printf("Enter the a: ");
	scanf("%d",&a);
	printf("Enter the b: ");
	scanf("%d",&b);
	printf("Enter the c: ");
	scanf("%d",&c);
	 int *aPtr=&a,*bPtr=&b,*cPtr=&c;
	 swaped(aPtr,bPtr,cPtr);
	 printf("a=%d\nb=%d\nc=%d",*aPtr,*bPtr,*cPtr);
	 
}
void swaped(int *aPtr, int *bPtr, int *cPtr){
	int temp=*bPtr;
	*bPtr=*aPtr;
	*aPtr=*cPtr;
	*cPtr=temp;
}