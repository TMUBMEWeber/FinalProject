//
//  final_project.c
//  final_project
//
//  Created by 陳椲博 on 2022/6/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int menu(void);
void initialMap(char Map[][11]);
void printMap(void);
void printMap(void);
void game(void);

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
    int Maps[11][11];
    initialMap(Maps);
    printMap();
    printf("Game over!!!!!\n");
}

void initialMap(char Map[][11]){/* 這邊我把地圖給初始化*/
    int i, j;
    for (i = 0; i < 11; i++)
    for (j = 0; j < 11; j++)
        Map[i][j] = 0;
}
void printMap(void){
    int i,j;
    printf("\n");
    for (i=0; i<=9; i++) {
        if (i==0) {
            printf("  ");
        }
        else{
            printf("%d ",i);
        }
    }
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            if (i==0&&j==0){
                printf("  ");
            }
            else if(j==0&&i!=0){
                printf("%d ",i);
            }
            else if(j!=0&&i!=0){
                printf("■ ");
            }
        }
        printf("\n");
    }
}
