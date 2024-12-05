#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 100
#define FILENAME "player.dat"

struct PlayerRecord {
    int playerId;
    char name[51];
    int highestKills;
    int highestDeaths;
};

void addNewPlayer(struct PlayerRecord records[], int *numPlayers, int maxPlayers) {
    if (*numPlayers >= maxPlayers) {
        printf("Maximum number of players reached. Cannot add more.\n");
        return;
    }

    printf("Enter new player details:\n");
    printf("Player ID: ");
    scanf("%d", &records[*numPlayers].playerId);
    printf("Name (max 50 characters): ");
    scanf(" %50[^\n]", records[*numPlayers].name);
    printf("Highest Kills: ");
    scanf("%d", &records[*numPlayers].highestKills);
    printf("Highest Deaths: ");
    scanf("%d", &records[*numPlayers].highestDeaths);

    (*numPlayers)++;
    printf("New player added successfully.\n");

    // Save the updated player records to the file
    FILE* fp = fopen(FILENAME, "wb");
    if (fp != NULL) {
        fwrite(records, sizeof(struct PlayerRecord), *numPlayers, fp);
        fclose(fp);
    } else {
        printf("Error opening file '%s' for writing.\n", FILENAME);
    }
}

void updatePlayerRecord(struct PlayerRecord records[], int numPlayers) {
    int playerId, i, found = 0;

    printf("Enter player ID to update: ");
    scanf("%d", &playerId);

    for (i = 0; i < numPlayers; i++) {
        if (records[i].playerId == playerId) {
            found = 1;
            printf("Current Highest Kills: %d\n", records[i].highestKills);
            printf("Enter new Highest Kills: ");
            scanf("%d", &records[i].highestKills);
            printf("Current Highest Deaths: %d\n", records[i].highestDeaths);
            printf("Enter new Highest Deaths: ");
            scanf("%d", &records[i].highestDeaths);
            printf("Player record updated successfully.\n");

            // Save the updated player records to the file
            FILE* fp = fopen(FILENAME, "wb");
            if (fp != NULL) {
                fwrite(records, sizeof(struct PlayerRecord), numPlayers, fp);
                fclose(fp);
            } else {
                printf("Error opening file '%s' for writing.\n", FILENAME);
            }

            break;
        }
    }

    if (!found) {
        printf("Player with ID %d not found.\n", playerId);
    }
}

void readPlayerRecords(struct PlayerRecord records[], int *numPlayers) {
    FILE* fp = fopen(FILENAME, "rb");
    if (fp != NULL) {
        *numPlayers = fread(records, sizeof(struct PlayerRecord), MAX_PLAYERS, fp);
        fclose(fp);
    } else {
        printf("Error opening file '%s' for reading.\n", FILENAME);
        *numPlayers = 0;
        return;
    }

    int i, maxKills = 0, maxKillsIndex = -1;
    float maxKillsPerDeath = 0.0;

    for (i = 0; i < *numPlayers; i++) {
        if (records[i].highestKills > maxKills) {
            maxKills = records[i].highestKills;
            maxKillsIndex = i;
        }
    }

    if (maxKillsIndex != -1) {
        printf("Player with the highest kills: %s (%d kills)\n",
               records[maxKillsIndex].name, records[maxKillsIndex].highestKills);
    } else {
        printf("No player records found.\n");
    }

    for (i = 0; i < *numPlayers; i++) {
        if (records[i].highestDeaths > 0) {
            float killsPerDeath = (float)records[i].highestKills / records[i].highestDeaths;
            if (killsPerDeath > maxKillsPerDeath) {
                maxKillsPerDeath = killsPerDeath;
            }
        }
    }

    printf("Highest kills per death ratio: %.2f\n", maxKillsPerDeath);
}

int main() {
    struct PlayerRecord records[MAX_PLAYERS];
    int numPlayers = 0, choice, maxPlayers = MAX_PLAYERS;

    // Load existing player records from the file
   // readPlayerRecords(records, &numPlayers);

    while (1) {
        printf("1. Add New Player\n2. Update Player Record\n3. Read Player Records\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewPlayer(records, &numPlayers, maxPlayers);
                break;
            case 2:
                updatePlayerRecord(records, numPlayers);
                break;
            case 3:
                readPlayerRecords(records, &numPlayers);
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