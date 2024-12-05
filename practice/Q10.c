#include<stdio.h>
#include<string.h>
char* revstring(char *str,char *revstr,int size){
	//char revstr[size];
    static int i=0;
	if(size<0){
	revstr[i]='\0';//
	return revstr;}
	else{
		revstr[i]=str[size];
		i++;
		return revstring(str,revstr,size-1);
	}
}
int main(){
	char str[]="Hasnainaaja";
	int size=strlen(str);
	char revstr[size+1];
	printf("reverse string: %s",revstring(str,revstr,size-1));
}