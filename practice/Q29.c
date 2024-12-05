#include<stdio.h>
#include<windows.h>
#include<conio.h>

//#define MAX_PLAYER 100
struct Playerrecord {
	int playerId;
	char Name[51];
	int Higestkill;
	int Higestdeath;

};
void Add_newplayer(struct Playerrecord **data,int*numplayer,int *maxplayer);
void UpdatePlayerrecord(struct Playerrecord *data,int numplayer);
void Read_playerrecord(struct Playerrecord *data,int *numplayer,int maxplayer);
int main() {
	struct Playerrecord *data=NULL;
	int numplayer = 0, choice, maxplayer ;
	printf("Enter the initial number of player: ");
	scanf("%d",&maxplayer);
	
	data=(struct Playerrecord*)malloc(maxplayer*sizeof(struct Playerrecord));
	if(data==NULL){
		printf("Error");
		return 0;
	}
	
	



	while (1) {
		system("cls");
		printf("1. Add New Player\n2. Update Player Record\n3. Read Player Records\n0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				Add_newplayer(&data, &numplayer,&maxplayer);
				break;
			case 2:
				UpdatePlayerrecord(data, numplayer);
				break;
			case 3:
				Read_playerrecord(data, &numplayer,maxplayer);
				break;
			case 0:
				printf("Exiting...\n");
				return 0;
			default:
				printf("Invalid choice. Please try again.\n");
				break;
		}
	}

	return 0;
}
void Add_newplayer(struct Playerrecord **data,int*numplayer,int *maxplayer) {
	system("cls");
	if(*numplayer>*maxplayer) {
	*maxplayer *=2;}
	*data=(struct Playerrecord*)realloc(*data,*maxplayer*sizeof(struct Playerrecord));
	if(*data==NULL){
		printf("Error");
		return ;
	}

	printf("Enter the New player Details: \n");
	printf("PLayer Id: ");
	scanf("%d",&(*data)[*numplayer].playerId);
	printf("Name: ");
	scanf(" %50[^\n]",&(*data)[*numplayer].Name);
	printf("Higest Kill: ");
	scanf("%d",&(*data)[*numplayer].Higestkill);
	printf("Higest deaths: ");
	scanf("%d",&(*data)[*numplayer].Higestdeath);
	(*numplayer)++;
	printf("\nPlayer addead succefully:");

	FILE *fptr= fopen("player2.dat","wb");
	if(fptr!=NULL) {
		fwrite(*data,sizeof(struct Playerrecord),*numplayer,fptr);
		fclose(fptr);
	} else {
		printf("Error:");
		return;
	}
	getch();


}
void UpdatePlayerrecord(struct Playerrecord *data,int numplayer){
	system("cls");
	int found =0;
	int newid;
	printf("Enter player Id:");
	scanf("%d",&newid);
	for(int i=0; i<numplayer; i++) {
		if(data[i].playerId==newid) {
			found=1;
			printf("Current higest kill : %d\n ",data[i].Higestkill);
			printf("Enter new higest kill: ");
			scanf("%d",&data[i].Higestkill);
			printf("Current Highest Deaths: %d\n", data[i].Higestdeath);
			printf("Enter new Highest Deaths: ");
			scanf("%d", &data[i].Higestdeath);
			printf("Player record updated successfully.\n");

			FILE *fptr=fopen("player2.dat","wb");
			if(fptr!=NULL) {
				fwrite(data,sizeof(struct Playerrecord),numplayer,fptr);
				fclose(fptr);
			} else {
				printf("Error:");
				return;
			}
			break;
		}
	}
	if (!found) {
		printf("Player with ID %d not found.\n", newid);
	}
	getch();
}
void Read_playerrecord(struct Playerrecord *data,int *numplayer,int maxplayer) {
	system("cls");
	FILE *fptr=fopen("player2.dat","rb");
	if(fptr!=NULL) {
		*numplayer=fread(data,sizeof(struct Playerrecord),maxplayer,fptr);
		fclose(fptr);
	} else {
		printf("Error opening file player2.dat for reading.\n");
		*numplayer = 0;
		return;
	}
	int max=0,index=-1;
	for(int i=0; i<*numplayer; i++) {
		if(data[i].Higestkill>max) {
			max=data[i].Higestkill;
			index=i;
		}
	}
	if(index!=-1) {
		printf("Player with the highest kills: %s (%d kills)\n",
		       data[index].Name, data[index].Higestkill);
	} else {
		printf("No player records found.\n");
	}
	float maxratio=0.0;
	for(int i=0; i<*numplayer; i++) {
		if(data[i].Higestdeath>0) {
			float killperdeath=(float)data[i].Higestkill/data[i].Higestdeath;
			if(killperdeath>maxratio) {
				maxratio=killperdeath;
			}
		}
	}
	printf("Highest kills per death ratio: %.2f\n", maxratio);

	getch();

}
