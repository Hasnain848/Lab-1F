#include<stdio.h>
int use_array_to_pointer(double *array,double *array2,double *merge,int size,int size2);
int main (){
int s1,s2;

double merge[100];
printf("Enter the size of first array: ");
scanf("%d",&s1);
double array[s1];
for(int i=0;i<s1;i++){
    printf("Element %d: ",i+1);
    scanf("%lf",&array[i]);
}
printf("Enter the size of Second array: ");
scanf("%d",&s2);
double array2[s2];
for(int i=0;i<s2;i++){
    printf("Element %d: ",i+1);
    scanf("%lf",&array2[i]);
}
int mergesize=use_array_to_pointer(array,array2,merge,s1,s2);
printf("Final Result:");
for(int i=0;i<mergesize;i++){
    printf("%.1lf ,",merge[i]);
}

}
int use_array_to_pointer(double *array,double *array2,double *merge,int size,int size2){
//int size=sizeof(array)/sizeof(array[0]);
//int size2=sizeof(array2)/sizeof(array2[0]);
double temparray[100];
int counter=0;
for(int i=0;i<size-1;i++){//asscending array
for(int j=1;j<size-i-1;j++){
 if(array[j]>array[j+1]){
      double temp=array[j];
      array[j]=array[j+1];
      array[j+1]=temp;
    }
}
   
}
for(int i=0;i<size2-1;i++){//asscending array
for(int j=1;j<size2-i-1;j++){
 if(array2[j]>array2[j+1]){
      double temp=array2[j];
      array2[j]=array2[j+1];
      array2[j+1]=temp;
    }
}}
for(int i=0;i<size;i++){
  temparray[i]=array[i];
  counter++;
}
for(int i=0;i<size2;i++){
  temparray[counter]=array2[i];
  counter++;
}
  int mergeCounter = 0;
    for (int i = 0; i < counter; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < mergeCounter; j++) {
            if (temparray[i] == merge[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            merge[mergeCounter++] = temparray[i];
        }
    }
for(int i=0;i<mergeCounter-1;i++){//asscending array
for(int j=1;j<mergeCounter-i-1;j++){
 if(merge[j]>merge[j+1]){
      double temp=merge[j];
      merge[j]=merge[j+1];
      merge[j+1]=temp;
    }
}
   
}
return mergeCounter;
}
