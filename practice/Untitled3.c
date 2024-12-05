#include<stdio.h>
struct data {
	int Teamid;
	char Name[50];
	int Totalwins;
	int totalloss;

};
void Add_a_new_team();
void Teamrecord();
int main() {
	struct data d1;
	
Add_a_new_team(d1);
updaterecord(d1);
 Teamrecord();
}
void Add_a_new_team(struct data data1) {
	
	printf("Enter the Team Id: ");
	scanf("%d",&data1.Teamid);
	printf("Enter the Team Name: ");
	scanf(" %[^\n]",&data1.Name);
	printf("Enter Total Wins: ");
	scanf("%d",&data1.Totalwins);
	printf("Enter the Total Loss: ");
	scanf("%d",&data1.totalloss);

	FILE *fptr=fopen("data.txt","a");
	if(fptr==NULL) {
		printf("Error");
		return ;
	}
    fwrite(&data1,sizeof(struct data),1,fptr);
    fclose(fptr);

}
void updaterecord(struct data data1){
	int n,s;
	printf("Enter the team id: ");
	scanf("%d",&n);
	printf("Enter (1)win or (2)loss: ");
	scanf("%d",&s);
	FILE *fptr=fopen("data.txt","r");
	if(fptr==NULL){
		printf("plese first add");
		return;
		}
		
	while(fread(&data1,sizeof(struct data),1,fptr)){
		if(data1.Teamid==n){
			switch(s){
				case 1:
					data1.Totalwins++;
					break;
				case 2 :
					data1.totalloss++;
					break;
				default: printf("errror");break;
			}
		
		}
	}
	
	
}
void Teamrecord(){
	struct data d1[100];
	int i=0;
	FILE *fptr=fopen("data.txt","r");
	if(fptr==NULL){
		printf("Error");
		return;	
	}
	while(fread(&d1[i],sizeof(struct data),1,fptr)){
		i++;
	}
	int size=i;
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(d1[j].Totalwins<d1[j+1].Totalwins){
				struct data temp=d1[j];
				d1[j]=d1[j+1];
				d1[j+1]=temp;
			}
		}
	}
	for(int i=0;i<size;i++){
		printf("Highest win team\n");
		printf("Team%d\n",i+1);
		printf("Id:%d\n",d1[i].Teamid);
		printf("Name:%s\n",d1[i].Name);
		printf("Wins:%d\n",d1[i].Totalwins);
		printf("Loss:%d\n",d1[i].totalloss);
	}
	
}