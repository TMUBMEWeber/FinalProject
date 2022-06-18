//
//  final_project.c
//  final_project
//
//  Created by 陳椲博 on 2022/6/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROW 10
#define COL 10
#define MINES_NUMBER 15

int menu(void);
void initialMap(char mineMap1[ROW][COL],char mineMap2[ROW][COL],char playerMap[ROW][COL]);
void game(int win ,int lose);
void printMap(char theMap[ROW][COL]);
void remakeMap(char playerMap[ROW][COL], char mineMap[ROW][COL], int row, int col);
int Ask(void);

int main(){
    srand(time(0));
    while (1) {
        int play=0;
        int win=0;int lose=0;
        play=menu();
        if (play==1) {
            game(win,lose);
        }
        else if(play==2){
            break;
        }
        else{
            printf("Please enter correct number!\n");
            continue;
        }
    }
    return 0;
}

int menu(void){
    printf("--------------------------------------------------------\n");
    printf("1.Start\n2.Leave\n");
    printf("Function 1 to open the cell\nFunction 2 to mark or unmark the cell\n");
    printf("Attention!You \"must \"mark on the bomb-cell to win\n");
    printf("Total score is round of win minus lose\n");
    printf("--------------------------------------------------------\n");
    int play=0;
    scanf("%d", &play);
    return play;
}

void game(int win,int lose){
    time_t start,end;
    start=time(NULL);
    printf("Game start!\n");
    char mineMap1[ROW][COL];
    char mineMap2[ROW][COL];
    char playerMap[ROW][COL];
    initialMap(mineMap1,mineMap2,playerMap);
    int step=0;
    int mine=-1;
    while (1) {
        printMap(playerMap);
        printf("Please enter (row , col, function):\n");
        int row ,col,func;
        scanf("%d%d%d",&row,&col,&func);
        if (func!=1&&func!=2) {
            printf("Please enter function 1 or function 2");
        }
        if (func==1&&row < ROW && row >= 0 && col < COL && col >= 0&& playerMap[row][col] == '*') {
            step++;
        }
        if (row<0||row>=ROW||col<0||col>=COL) {
            printf("Please enter a value inside the grid:\n");
            continue;
        }
        for (int i=0; i<ROW; i++) {
            for (int j=0; j<COL; j++) {
                if (mineMap2[i][j]=='B') {
                    mine++;
                }
            }
        }
        if (mineMap1[row][col] == 'B'&&func==1) {
            printf("Boom! You died!\n");
            printMap(mineMap1);
            printf("Steps:%d\n",step);
            end=time(NULL);
            printf("Use time:%ld sec(s)\n",end-start);
            lose++;
            int ask=Ask();
            if (ask==1) {
                game(win,lose);
            }
            if (ask==2) {
                int score=win-lose;
                printf("Total win & lose :%d & %d\nSo the total score is %d\n",win ,lose,score);
                break;
            }
            break;
        }
        if (mine==0) {
            printf("YOU WIN\n");
            end=time(NULL);
            printf("Use time:%ld sec(s)\n",end-start);
            printf("Steps:%d\n",step);
            win++;
            int ask=Ask();
            if (ask==1) {
                game(win,lose);
            }
            if (ask==2) {
                int score=win-lose;
                printf("Total win & lose :%d & %d\nSo the total score is %d\n",win ,lose,score);
                break;
            }
        }
        mine=-1;
        if (playerMap[row][col]!='*'&&playerMap[row][col]!='M') {
            printf("Please enter a value that has not already been entered\n");
            continue;
        }
        if (func==2 && playerMap[row][col]!='M') {
            playerMap[row][col]='M';
            mineMap2[row][col]='M';
            continue;
        }
        if (func==2 && playerMap[row][col]=='M'&&mineMap1[row][col]=='B') {
            playerMap[row][col]='*';
            mineMap2[row][col]='B';
            continue;
        }
        if (func==2 && playerMap[row][col]=='M'&&mineMap1[row][col]=='O') {
            playerMap[row][col]='*';
            mineMap2[row][col]='O';
            continue;
        }
        if (func==1&&row < ROW && row >= 0 && col < COL && col>= 0&& playerMap[row][col] == '*') {
            remakeMap(playerMap, mineMap1, row, col);
        }
    }
    return;
}
void initialMap(char mineMap1[ROW][COL],char mineMap2[ROW][COL],char playerMap[ROW][COL]){
    int i, j;
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
            mineMap1[i][j]='O';
            mineMap2[i][j]='O';
            playerMap[i][j]='*';
        }
    }
    int mineCounter=0;
    while (mineCounter<MINES_NUMBER) {
        int a=rand()%ROW;
        int b=rand()%COL;
        if (mineMap1[a][b]=='B') {
            continue;
        }
        mineMap1[a][b]='B';
        mineMap2[a][b]='B';
        ++mineCounter;
    }
    return ;
}

void printMap(char theMap[ROW][COL]){
    for (int i=0; i<ROW; i++) {
        printf("%d  ",i);
    }
    printf("\n\n");
    
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
        printf("%c  ",theMap[i][j]);
        }
        printf(" ");printf("%d",i);printf("\n");
    }
    return;
}
void remakeMap(char playerMap[ROW][COL], char mineMap[ROW][COL], int row, int col) {
    int count = 0;
        for (int i = row-1; i <=row+1 ; i++){
            for (int j = col-1; j <= col+1; j++){
                if (i >= ROW || i < 0 || j >= COL || j < 0){
                    continue;
                }
                if (mineMap[i][j] == 'B'){
                    count++;
                }
            }
            
        }
     playerMap[row][col] = '0' + count;
     if (playerMap[row][col] == '0'){
         playerMap[row][col]=' ';
         if (row < ROW && row >= 0 && col < COL && col - 1 >= 0&& playerMap[row][col - 1] == '*'){
             remakeMap(playerMap, mineMap, row, col - 1);
         }
         if (row < ROW && row >= 0 && col + 1 < COL && col >= 0&& playerMap[row][col + 1] == '*'){
             remakeMap(playerMap, mineMap, row, col + 1);
         }
         if (row < ROW && row - 1 >= 0 && col < COL && col >= 0&& playerMap[row - 1][col] == '*'){
             remakeMap(playerMap, mineMap, row - 1, col);
         }
         if (row + 1 < ROW && row >= 0 && col < COL && col >= 0&& playerMap[row + 1][col] == '*'){
             remakeMap(playerMap, mineMap, row + 1, col);
         }
    }
    return;
}
int Ask( void ){
    printf("Do you want to play again?(Type 1 to restart , 2 to End)\n");
    int choice;
    scanf("%d", &choice);
    return choice;
}
