#include <stdio.h>
#include <string.h>
struct player {
    char name[20];
    char team[20];
} ply[5];
struct bowl {
    char type[10];
    char arm[5];
    struct player ply;
} bowlers[3];
struct bat {
    char type[10];
    char handed[8];
    struct bowl ply2;
} batters[2];
void createplayer(struct player ply) {
    FILE *fptr = fopen("players.txt", "a");
    if (fptr == NULL) {
        printf("File does not exist!.\n");
        return;
    }
    printf("Enter player name: ");
    scanf(" %[^\n]", ply.name);
    printf("Enter player team: ");
    scanf(" %[^\n]", ply.team);
    fprintf(fptr, "%s, %s\n", ply.name, ply.team);
    fclose(fptr);
    printf("Player information saved successfully!\n");
}
int readplayer() {
    FILE *fptr = fopen("players.txt", "r");
    if (fptr == NULL) {
        printf("File does not exist!.\n");
        return 0;
    }
    int count =0;
    while (count < 5 && fscanf(fptr, " %19[^,], %19[^\n]", ply[count].name, ply[count].team) == 2) {
        count++;
    }
    fclose(fptr);
    return count;
}
void displayplayer(int count) {
    if (count == 0) {
        printf("No players to display.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Team: %s\n", ply[i].name, ply[i].team);
    }
}
void createbowl(struct bowl bowlers[]) {
    FILE *fptr = fopen("bowlers.txt", "a");
    if (fptr == NULL) {
        printf("File does not exist!.\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
        printf("Enter bowler %d name: ", i + 1);
        scanf(" %[^\n]", bowlers[i].ply.name);
        printf("Enter bowler %d team: ", i + 1);
        scanf(" %[^\n]", bowlers[i].ply.team);
        printf("Enter bowler %d type: ", i + 1);
        scanf(" %[^\n]", bowlers[i].type);
        printf("Enter bowler %d arm : ", i + 1);
        scanf(" %[^\n]", bowlers[i].arm);
        fprintf(fptr, "%s, %s, %s, %s\n", bowlers[i].ply.name, bowlers[i].ply.team, bowlers[i].type, bowlers[i].arm);
    }
    fclose(fptr);
    printf("Bowler information saved successfully!\n");
}
void createbat(struct bat batters[]) {
    FILE *fptr = fopen("batters.txt", "a");
    if (fptr == NULL) {
        printf("File does not exist!.\n");
        return;
    }
    for (int i = 0; i < 2; i++) {
        printf("Enter batter %d name: ", i + 1);
        scanf(" %[^\n]", batters[i].ply2.ply.name);
        printf("Enter batter %d team: ", i + 1);
        scanf(" %[^\n]", batters[i].ply2.ply.team);
        printf("Enter batter %d type (top/middle/lower order): ", i + 1);
        scanf(" %[^\n]", batters[i].type);
        printf("Enter batter %d handed (lefty/righty): ", i + 1);
        scanf(" %[^\n]", batters[i].handed);
        printf("Enter bowler type of batter %d type: ", i + 1);
        scanf(" %[^\n]", batters[i].ply2.type);
        printf("Enter bowling arm (left/right) of batter %d: ", i + 1);
        scanf(" %[^\n]", batters[i].ply2.arm);
        fprintf(fptr, "%s, %s, %s, %s, %s, %s\n", batters[i].ply2.ply.name, batters[i].ply2.ply.team, batters[i].type, batters[i].handed, batters[i].ply2.type, batters[i].ply2.arm);
    }
    fclose(fptr);
    printf("Batter information saved successfully!\n");
}
void updateplayer(int count) {
    if (count == 0) {
        printf("No players available to update.\n");
        return;
    }
    char name[20], newTeam[20];
    int found = 0;
    printf("Enter player name to update: ");
    scanf(" %[^\n]", name);
    for (int i=0; i<count; i++) {
        if (strcmp(ply[i].name, name) == 0) {
            printf("Enter new team for player %s: ", name);
            scanf(" %[^\n]", newTeam);
            strcpy(ply[i].team, newTeam);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Player not found.\n");
        return;
    }
    FILE *fptr = fopen("players.txt", "w");
    if (fptr == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    for (int i = 0; i<count; i++) {
        fprintf(fptr, "%s, %s\n", ply[i].name, ply[i].team);
    }
    fclose(fptr);
    printf("Player information updated successfully!\n");
}
void deleteplayer(int *count) {
    if (*count == 0) {
        printf("No players available to delete.\n");
        return;
    }
    char name[20];
    int found = 0;
    printf("Enter player name to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < *count; i++) {
        if (strcmp(ply[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                ply[j] = ply[j + 1];
            }
            (*count)--;
            break;
        }
    }
    if (!found) {
        printf("Player not found.\n");
        return;
    }
    FILE *fptr = fopen("players.txt", "w");
    if (fptr == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }
    for (int i = 0;i<*count; i++) {
        fprintf(fptr, "%s, %s\n", ply[i].name, ply[i].team);
    }
    fclose(fptr);
    printf("Player deleted successfully.\n");
}
int main() {
    int count = readplayer();
    createplayer(ply[0]); 
    count = readplayer(); 
    createbowl(bowlers); 
    createbat(batters); 
    updateplayer(count);  
    count = readplayer(); 
    deleteplayer(&count); 
    displayplayer(count);  
    return 0;
}
