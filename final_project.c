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
    printf("遊戲開始\n");
    char mineMap[ROW][COL];
    char playerMap[ROW][COL];
    initialMap(mineMap,playerMap);
    while (1) {
        printMap(playerMap);
        printf("請輸入要查表的座標及動作 (row,col):");
        int row ,col;
        scanf("%d %d",&row,&col);
        if (row<0||row>=ROW||col<0||col>=COL) {
            printf("已越界，請重新輸入\n");
            continue;
        }
        if (playerMap[row][col]!='O') {
            printf("重複輸入，請重新輸入");
            continue;
        }
        if (mineMap[row][col] == '1') {
            printf("您踩雷了！游戲結束！！\n");
            printMap(mineMap);
            break;
        }
        void remakeMap(char playerMap[ROW][COL], char mineMap[ROW][COL], int row, int col);
        int opened=0;
        if (opened==ROW*COL-MINES_NUMBER) {
            printf("YOU WIN");
        }
    }
    return;
}
void initialMap(char mineMap[ROW][COL],char playerMap[ROW][COL]){
    int i, j;
    for (i = 0; i < ROW; i++){
        for (j = 0; j < COL; j++){
        mineMap[i][j] = '0';
        playerMap[i][j]='O';
        }
    }
    int mineCounter=0;
    while (mineCounter<MINES_NUMBER) {
        int a=rand()%ROW;
        int b=rand()%COL;
        if (mineMap[a][b]=='1') {
            continue;
        }
        mineMap[a][b]='1';
        ++mineCounter;
    }
    return;
}

void printMap(char theMap[ROW][COL])
    {
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
    for (int r = row - 1; r <= row + 1; r++) {
        for (int c = col - 1; c <= col + 1; c++) {
            if (r < 0 || r >= ROW || c < 0 || c >= COL) { //超出地圖范圍，直接跳出進入下次回圈
                continue;
            }
            if (r == row && c == col) { //中間位置不參與計算 直接進入下次回圈
                continue;
            }
            if (mineMap[r][c] == '1') {
                count++;
            }
        }
    }
    playerMap[row][col] = '0' + count;
    return;
}
    
   
