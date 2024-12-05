#include<stdio.h>
#include<windows.h>
struct Playerrecord{
int playerId;
char Name[50];
int Higestkill;
int Higestdeath;

};
void Add_newplayer(struct Playerrecord data);
void UpdatPlayerrecord(struct Playerrecord data);
void Read_playerrecord();
int main(){
 struct Playerrecord data;

int end=1;
while(end){
    system("cls");
    int choice;
    printf("1.Add New Player\n2.Update layer record.\n3.Read Player record.\n0.Exit\n");
    printf("Enter your choice");
    scanf("%d",&choice);
    // if (scanf("%d", &choice) != 1) {
    //         printf("Invalid input. Please enter a number.\n");
            
    //         // Clear input buffer
    //         while (getchar() != '\n');
            
    //         // Pause to let user read the error message
    //         printf("Press Enter to continue...");
    //         while (getchar() != '\n');
    //         continue;
    //     }
    switch (choice)
    {
    case 1: Add_newplayer(data); break;
    case 2: UpdatPlayerrecord(data);break;
  
  //1  case 3: Read_playerrecord();break;
    case 0: printf("\nExiting");end=0;break;
    default:
    printf("\nInvalid choice\n");
        break;
    }
}


}
void Add_newplayer(struct Playerrecord data){
    system("cls");
 
    FILE *fptr=fopen("player.txt","a");
    if(fptr==NULL){
   printf("error");
   return;
    }
    printf("Enter the New Player Details:\n");
    printf("player ID: ");
    scanf("%d",&data.playerId);
    printf("Name: ");
    scanf(" %[^\n]",&data.Name);
    printf("Higestkill: ");
    scanf("%d",&data.Higestkill);
    printf("Higestdeath: ");
    scanf("%d",&data.Higestdeath);
     fprintf(fptr,"Player Id :%d \nName: %s \nHighestkill : %d \nHigestdeath: %d \n ",data.playerId,data.Name,data.Higestkill,data.Higestdeath);

    fclose(fptr);
    printf("Successfully added");
    getchar();
}
void UpdatPlayerrecord(struct Playerrecord data){
    int neplay,nehigh;
    char c;
    printf("Enter the playerId to update: ");
    scanf("%d",&neplay);
    printf("enter (y) for kill and (n) for death:");
    scanf("%c",&c);
   
  
    FILE *fptr = fopen("player.txt","a+");
    if(fptr==NULL){
   printf("error");
   return;
    }
    while(fscanf(fptr,"Player Id :%d \nName: %s \nHighestkill : %d \nHigestdeath: %d \n ",&data.playerId,&data.Name,&data.Higestkill,&data.Higestdeath)==4){
        if(data.playerId==neplay){
            switch (c)
            {
            case 'y':
              printf("Enter you new highscore: ");
              scanf("%d",&nehigh);
            data.Higestkill=nehigh;
                break;
            case 'n':
              printf("Enter you new Deaths: ");
               scanf("%d",&nehigh);
            data.Higestdeath=nehigh;
            break;
            default:printf("invalid option:");
                return;
            }
        }
    }
    fprintf(fptr,"Player Id :%d \nName: %s \nHighestkill : %d \nHigestdeath: %d \n ",data.playerId,data.Name,data.Higestkill,data.Higestdeath);
    fclose(fptr);

    printf("\nSuccessfully added");
    getchar();
}