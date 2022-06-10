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

int main(){
    int play;
    srand(time(0));
    while (1) {
        play=menu();
        if (play==1) {
            game();
        }
        else if(play==2){
            break;
        }
        else{
            printf("Please enter correct number!");
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
    printMap(playerMap);
    while (1) {
        printf("請輸入要查表的座標及動作 (row,col):");
        int row ,col;
        scanf("%d %d",&row,&col);
        if (row<0||row>=ROW||col<0||col>=COL) {
            printf("已越界，請重新輸入");
            continue;
        }
        if (playerMap[row][col]!='O') {
            printf("重複輸入，請重新輸入");
            continue;
        }
        if (mineMap[row][col] == '0') {
            printf("您踩雷了！游戲結束！！\n");
            break;
    }
    }
}
void initialMap(char mineMap[ROW][COL],char playerMap[ROW][COL])
{/* 這邊我把地圖給初始化*/
    int i, j;
    for (i = 0; i < 11; i++){
        for (j = 0; j < 11; j++){
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
}

void printMap(char theMap[ROW][COL])
    {
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
        printf("%c  ",theMap[i][j]);
        }
        printf("\n");
    }
}

    
    
   
