#include <stdio.h>
#include <string.h>

struct player {
    char name[50];
    int score;
};

int main(){
    char name[50];

    printf("Enter name for player 1: ");
    scanf("%s", name);

    struct player player1;
    strcpy(player1.name, name);

    printf("Enter name for player 2: ");
    scanf("%s", name);
    printf("\n");

    struct player player2;
    strcpy(player2.name, name);

    player2.score = 0;
    player1.score = 0;

    printf("%s\n", player1.name);
    printf("%d\n\n", player1.score);

    printf("%s\n", player2.name);
    printf("%d\n", player2.score);

    return 0;
    

}