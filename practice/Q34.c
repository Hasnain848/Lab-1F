#include<stdio.h>
#include<string.h>
int main(){
	char inputstring[]="AC17D68DE";
	int checkarray[]={5, -2, 23, 27, 14, 17, 18, 20, 10};
	int size=strlen(inputstring);
	char duplicatearray[size];
	int count=0,inputvalue;
	strcpy(duplicatearray,inputstring);
	char changeString[] = "FASTNUCES";
	while(count<=size){
		
		printf("string= %s\n",duplicatearray);
		
		if(count==size)
		break;
		
		printf("Enter the value to change:");
		scanf("%d",&inputvalue);
		
		if(inputvalue==checkarray[count]){
			duplicatearray[count]=changeString[count];
			count++;
		}
		else{
			strcpy(duplicatearray,inputstring);
			printf("Wrong guess string revert:\n");
			count=0;
		}
	}
	
	
}