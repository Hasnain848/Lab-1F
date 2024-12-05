/*Write a program to copy the contents of one file to another. (Create a File with some
dummy data, The data is not required to be formatted)*/
#include<stdio.h>
int main(){
    char buffer[50];
FILE *fptr=fopen("sample.txt","r");
FILE *fptr2=fopen("result.txt","w");
  if(fptr==NULL||fptr2==NULL){
    printf("Error");
    return 0;
  }
fscanf(fptr,"%s",&buffer);
fprintf(fptr2,"%s",buffer);
fclose(fptr);
fclose(fptr2);
}