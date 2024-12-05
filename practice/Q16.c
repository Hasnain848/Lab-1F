#include<stdio.h>
#include<string.h>
char *recursiveRev(char *array,int size);
int main(){
	char str[]="hasnain",*ptr;
	int size=strlen(str)-1;
	ptr=recursiveRev(str,size);
	
		printf("%s",ptr);
	
}
char *recursiveRev(char *array,int size){
	static char revstr[100];
	static int i=0;
	if(size<0){
	revstr[i]='\0';
	return revstr;
	}
	
	else{
		revstr[i]=array[size];
		i++;
		
		return recursiveRev(array,size-1);
	}
}