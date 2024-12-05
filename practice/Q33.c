#include <stdio.h>
#include <string.h>

#define MAX_CHARACTERS 100

// Define the GameCharacter structure
typedef struct {
    char name[81]; // Name of the character (max 80 characters + 1 for null terminator)
    int HP;        // Health Points
    int AP;        // Attack Points
    int DP;        // Defense Points
} GameCharacter;

// Function prototypes
void createCharacters(GameCharacter characters[], int *count);
void displayCharacters(GameCharacter characters[], int count);
void battleSimulation(GameCharacter characters[], int count);

int main() {
    GameCharacter characters[MAX_CHARACTERS];
    int count = 0; // Number of characters created
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create Characters\n");
        printf("2. Display Characters\n");
        printf("3. Battle Simulation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createCharacters(characters, &count);
                break;
            case 2:
                displayCharacters(characters, count);
                break;
            case 3:
                battleSimulation(characters, count);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to create characters
void createCharacters(GameCharacter characters[], int *count) {
    while (*count < MAX_CHARACTERS) {
        GameCharacter newCharacter;

        printf("\nEnter character name (max 80 chars): ");
        getchar(); // Consume leftover newline
        fgets(newCharacter.name, 81, stdin);
        newCharacter.name[strcspn(newCharacter.name, "\n")] = '\0'; // Remove newline

        printf("Enter Health Points (1-5): ");
        scanf("%d", &newCharacter.HP);
        printf("Enter Attack Points (1-5): ");
        scanf("%d", &newCharacter.AP);
        printf("Enter Defense Points (1-5): ");
        scanf("%d", &newCharacter.DP);

        // Validate inputs
        if (newCharacter.HP + newCharacter.AP + newCharacter.DP != 10) {
            printf("Error: HP + AP + DP must equal 10. Try again.\n");
            continue;
        }
        if (newCharacter.HP <= 0 || newCharacter.AP <= 0 || newCharacter.DP <= 0 || 
            newCharacter.HP > 5 || newCharacter.AP > 5 || newCharacter.DP > 5) {
            printf("Error: All points must be between 1 and 5. Try again.\n");
            continue;
        }
        if (newCharacter.HP == newCharacter.AP || newCharacter.AP == newCharacter.DP || 
            newCharacter.HP == newCharacter.DP) {
            printf("Error: All points must be distinct. Try again.\n");
            continue;
        }

        // Add the character to the array
        characters[*count] = newCharacter;
        (*count)++;

        printf("Character created successfully! Press ESC to stop or any other key to add another.\n");
        getchar(); // Wait for user input
        if (getchar() == 27) { // ESC key
            break;
        }
    }
}

// Function to display all characters
void displayCharacters(GameCharacter characters[], int count) {
    if (count == 0) {
        printf("No characters available to display.\n");
        return;
    }

    printf("\nList of Characters:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, HP: %d, AP: %d, DP: %d\n",
               characters[i].name, characters[i].HP, characters[i].AP, characters[i].DP);
    }
}

// Function to simulate a battle
void battleSimulation(GameCharacter characters[], int count) {
    if (count < 2) {
        printf("At least two characters are needed for a battle.\n");
        return;
    }

    int char1, char2;

    // Choose two characters for the battle
    printf("\nChoose two characters for the battle:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, characters[i].name);
    }

    printf("Enter the number for the first character: ");
    scanf("%d", &char1);
    printf("Enter the number for the second character: ");
    scanf("%d", &char2);

    if (char1 < 1 || char1 > count || char2 < 1 || char2 > count || char1 == char2) {
        printf("Invalid choices. Try again.\n");
        return;
    }

    GameCharacter *c1 = &characters[char1 - 1];
    GameCharacter *c2 = &characters[char2 - 1];

    // Simulate the battle
    int c1_remainingHP = c1->HP - c2->AP + c1->DP;
    int c2_remainingHP = c2->HP - c1->AP + c2->DP;

    printf("\nBattle Results:\n");
    if (c1_remainingHP > c2_remainingHP) {
        printf("%s wins!\n", c1->name);
    } else if (c2_remainingHP > c1_remainingHP) {
        printf("%s wins!\n", c2->name);
    } else {
        printf("It's a draw!\n");
    }
}
