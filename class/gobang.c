// File: gobang.c
#include<stdio.h>
#include<stdlib.h>
#define ROW 15
#define COL 15
#define BLACK 1
#define WHITE -1
#define BLANK 0
int main(){
    int chess[ROW][COL] = {BLANK};
    int loc_i = -1;
    int loc_j = -1;
    int player = WHITE;
    int winner = BLANK;
    do{
        system("cls");
        //system("clear");
        //step 1. display or update the whole chess board
        printf("   ");
        for(int i = 0; i<COL; i++){
            printf("%3d", i);
        }
        printf("\n");
        for(int i = 0; i < ROW; i++){
            printf("%2d ", i);
            //printf("\033[47;31m");
            for(int j = 0; j < COL; j++){
                if(chess[i][j] == 0)
                    printf("%s", "|__");
                else if (chess[i][j] == BLACK){
                    printf("| *");
                }      
                else{
                    printf("| O");
                }
            }
            printf("\n");
            //printf("|\033[0m\n");
        }
        //step 2: judge whether this player wins or not? 
        for(int i = 0; i<ROW; i++){
            for(int j = 0; j<COL; j++){
                if(chess[i][j] == BLANK)
                    continue;
                if(
                (j < COL-4 && chess[i][j] == chess[i][j+1] && chess[i][j] == chess[i][j+2] && chess[i][j] == chess[i][j+3] && chess[i][j] == chess[i][j+4])||//横
                (i < ROW-4 && chess[i][j] == chess[i+1][j] && chess[i][j] == chess[i+2][j] && chess[i][j] == chess[i+3][j] && chess[i][j] == chess[i+4][j])||//纵
                (i < ROW-4 && j > 3 && chess[i][j] == chess[i+1][j-1] && chess[i][j] == chess[i+2][j-2] && chess[i][j] == chess[i+3][j-3] && chess[i][j] == chess[i+4][j-4])||//左斜
                (i < ROW-4 && j < COL-4 && chess[i][j] == chess[i+1][j+1] && chess[i][j] == chess[i+2][j+2] && chess[i][j] == chess[i+3][j+3] && chess[i][j] == chess[i+4][j+4])){//右斜
                    winner = -player;//player;
                    goto L;
                }
            }
        }
        //step 3. let the player play and switch
        printf("Player %d! Please enter the location when you want to play chess: \n", player);
        scanf("%d %d", &loc_i, &loc_j);
        while (loc_i > ROW || loc_j > COL || chess[loc_i][loc_j]!= BLANK)
        {
            printf("The location is invalid. Please enter again: ");
            scanf("%d %d", &loc_i, &loc_j);
        }
        chess[loc_i][loc_j] = (player == WHITE? WHITE: BLACK);
        player = (player == WHITE? BLACK: WHITE);
    }while(loc_i != -1 && loc_j != -1);
    L: printf("Player %s wins! Cong!\n", winner==WHITE? "WHITE (O)": "BLACK (*)");
    return 0;
}