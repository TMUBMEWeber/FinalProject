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
void initialMap(char mineMap[ROW][COL],char playerMap[ROW][COL]);
void game(void);
void printMap(char theMap[ROW][COL]);
void remakeMap(char playerMap[ROW][COL], char mineMap[ROW][COL], int row, int col);

int main(){
    srand(time(0));
    while (1) {
        int play=0;
        play=menu();
        if (play==1) {
            game();
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
    printf("-----------------\n");
    printf("1.Start\n2.Leave\n");
    printf("-----------------\n");
    int play=0;
    scanf("%d", &play);
    return play;
}

void game(void){
    time_t start,end;
    start=time(NULL);
    printf("Game start!\n");
    char mineMap[ROW][COL];
    char playerMap[ROW][COL];
    initialMap(mineMap,playerMap);
    int step=0;
    while (1) {
        printMap(playerMap);
        printf("Please enter x , y(row , col):\n");
        int row ,col;
        scanf("%d %d",&row,&col);
        step++;
        if (row<0||row>=ROW||col<0||col>=COL) {
            printf("Please enter a value inside the grid:\n");
            continue;
        }
        if (playerMap[row][col]!='0') {
            printf("Please enter a value that has not already been entered\n");
            continue;
        }
        if (mineMap[row][col] == 'B') {
            printf("Boom! You died!\n");
            printMap(mineMap);
            printf("Steps:%d\n",step);
            end=time(NULL);
            printf("Use time:%ld sec(s)\n",end-start);
            break;
        }
        int opened=0;
        if (opened==ROW*COL-MINES_NUMBER) {
            printf("YOU WIN");
            end=time(NULL);
            printf("Use time:%ld sec(s)\n",end-start);
            printf("Steps:%d\n",step);
        }
        remakeMap(playerMap, mineMap, row, col);
    }
    return;
}
void initialMap(char mineMap[ROW][COL],char playerMap[ROW][COL]){
    int i, j;
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
        mineMap[i][j] = 'O';
        playerMap[i][j]='0';
        }
    }
    int mineCounter=0;
    while (mineCounter<MINES_NUMBER) {
        int a=rand()%ROW;
        int b=rand()%COL;
        if (mineMap[a][b]=='B') {
            continue;
        }
        mineMap[a][b]='B';
        ++mineCounter;
    }
    return;
}

void printMap(char theMap[ROW][COL]){
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
        printf("%c  ",theMap[i][j]);
        }
        printf("\n");
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
         if (row < ROW && row >= 0 && col < COL && col - 1 >= 0&& playerMap[row][col - 1] == '0'){
             remakeMap(playerMap, mineMap, row, col - 1);
         }
         if (row < ROW && row >= 0 && col + 1 < COL && col >= 0&& playerMap[row][col + 1] == '0'){
             remakeMap(playerMap, mineMap, row, col + 1);
         }
         if (row < ROW && row - 1 >= 0 && col < COL && col >= 0&& playerMap[row - 1][col] == '0'){
             remakeMap(playerMap, mineMap, row - 1, col);
         }
         if (row + 1 < ROW && row >= 0 && col < COL && col >= 0&& playerMap[row + 1][col] == '0'){
             remakeMap(playerMap, mineMap, row + 1, col);
         }
    }
}
