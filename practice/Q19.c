#include<stdio.h>
int is_palindrome(char *str,int start,int end);
int main(){
	char str[]="Hasnain";
	int length=0;
	while(str[length]!='\0'){
		length++;
	}
	if(is_palindrome(str,0,length-1)){
		printf("Palindrome");
	}
	else
	printf("Not palindrome");
}
int is_palindrome(char *str,int start,int end){
	
	if(start>end)
	return 1;
	
	if(str[start]!=str[end])
	return 0;
	
	return is_palindrome(str,start +1,end -1);
}