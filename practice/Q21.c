#include<stdio.h>
int stringLength(char* str);
int main(){
	char str[]="Hasnain";
	printf("size:%d",stringLength(str));
}
int stringLength(char* str){
	static int length=0;
	
	if(str[length]=='\0')
	return length;
	
	length++;
	return stringLength(str);
}