#include<stdio.h>
int main(){
    int frequency[256]={0},i=0;
    FILE *fptr=fopen("sample.txt","r");
      if(fptr==NULL){
    printf("Error");
    return 0;
  }
char c[100];
while ((c[i] = fgetc(fptr)) != EOF){
    frequency[c[i]]++;
     i++;
     if (i >= 100) { 
            printf("Buffer limit reached. Stopping further reads.\n");
            break;
        }
   
}
for(int j=0;j<i;j++){
    if(frequency[c[j]]>0){
    printf("%c = %d \n",c[j],frequency[c[j]]);
    frequency[c[j]]=0;
    }
}
fclose(fptr);
}