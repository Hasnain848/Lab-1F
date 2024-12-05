#include<stdio.h>
#include<string.h>
int countVowels(char* str);

int main(){
	char str[]="aeiouaeiouaeiou";
	printf("Count: %d",countVowels(str));
}
int countVowels(char* str){
static	int count=0;
	
	if(*str=='\0')
		return count;
	
	if(*str=='a'||*str=='e'||*str=='i'||*str=='o'||*str=='u'||*str=='A'||*str=='E'||*str=='I'||*str=='O'||*str=='U')
	count++;
	return countVowels(str+1);
}