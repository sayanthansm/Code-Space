#include<stdio.h>
#include<stdlib.h>
int checkWin(char table[3][3],char player);
int main(){
    printf("Welcome to tic tac toe game\n");
    char table[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            table[i][j]=' ';
        }
        
    }
    for(int move=0;move<9;move++){
        int row,col;
                printf("Enter the position (row, col) to place 'X' (1-3): ");
        scanf("%d %d", &row, &col);
        row-=1;
        col-=1;
        if (row>=0 && row<3 && col>=0 && col<3 &&table[row][col]==' ')
        {
            table[row][col]='X';
        }
        else{
            printf("Invalid position or already occupied.");
            move--;
            continue;
        }
          printf("\nCurrent Board:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %c ", table[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf("---|---|---\n");
        }
        printf("\n");
    }
     printf("Game Over. Thank you for playing!\n");
    return 0;
    
}
int checkWin(char table[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == player && table[i][1] == player && table[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (table[0][j] == player && table[1][j] == player && table[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (table[0][0] == player && table[1][1] == player && table[2][2] == player) {
        return 1;
    }
    if (table[0][2] == player && table[1][1] == player && table[2][0] == player) {
        return 1;
    }
}