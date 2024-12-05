#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
void Add_Categories();
void Add_Products();
void Generate_final_result();
int main(){
	int c;
	int end=1;
	while(end){
	system("cls");
	printf("1.Add Categories\n");
	printf("2.Add Products\n");
	printf("3.Generate final result\n");
	printf("0.Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&c);
	switch(c){
		case 1:Add_Categories();break;
		case 2:Add_Products();break;
		case 3:Generate_final_result();break;
		case 0:printf("Exiting");end=0;break;
	}
}
}
void Add_Categories(){
	system("cls");
	FILE *fptr=fopen("categories.txt","a");
	if(fptr==NULL){
		printf("Error");
		return;
	}
	char name[50];
	int id;
	printf("Enter the new category Name: ");
	scanf(" %[^\n]",&name);
	printf("Enter the new category ID: ");
	scanf(" %d",&id);
	
	fprintf(fptr,"%s %d\n",name,id);
	
	fclose(fptr);
	printf("The categoery %s has been added",name);
	getch();
	
	
}
void Add_Products(){
	system("cls");
	FILE *fptr=fopen("product.txt","a");
	if(fptr==NULL){
		printf("Error");
		return;
	}
	char name[50];
	float price;
	int id;
	printf("Enter the product name:");
	scanf(" %[^\n]",&name);
	printf("Enter the product price:");
	scanf(" %f",&price);
	printf("Enter the product category id:");
	scanf(" %d",&id);
	fprintf(fptr,"%s %f %d",name,price,id);
	fclose(fptr);
	printf("The product %s has been added\n",name);
	getch();
	
	
	
}
void Generate_final_result(){
	system("cls");
	FILE *fptr1=fopen("categories.txt","r");
	FILE *fptr2=fopen("product.txt","r");
	FILE *fptr3=fopen("final.txt","w");
	if(fptr1==NULL|| fptr2==NULL|| fptr3==NULL){
		return;
	}
	char categories[100][50];
	int categoryid[100],i=0;
	
	while(fscanf(fptr1,"%s %d",categories[i],&categoryid[i])!=EOF){
		i++;
	}
	fclose(fptr1);
	
	char product[50];
	int productid;
	float productprice;
	while(fscanf(fptr2,"%s %f %d",product,&productprice,&productid)!=NULL){
		for(int j=0;j<i;i++){
		if(productid==categoryid[i]){
			fprintf(fptr3,"%s %s %f",categories[i],product,productprice);
			break;
			
		}
			
		}
	}
	
  fclose(fptr2);
    fclose(fptr3);

    printf("Final report generated successfully.\n");
    getch();
}