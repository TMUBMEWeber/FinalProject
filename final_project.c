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
void mines_generation(void);

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
        else{            printf("Please enter correct number!");
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
    int i = 0, j = 0;
    int M,N;
    int minefield[i][j];
    int blank_minefield[i][j];
    int final_minefield[i][j];
    srand(time(0));                                  //Starts the random no. generator

    while(j<N)                                          //Nested loop for making the blank minefield and final minefield
    {
        while(i<M)
        {
            minefield[i][j] = '-';
            blank_minefield[i][j] = minefield[i][j];
            final_minefield[i][j] = minefield[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    int mines = 0;
    int total_mines;
    while(mines<total_mines)                            //Randomly generates the mines into the minefield
    {
        i = rand()%(M);
        j = rand()%(N);
        if( minefield[i][j] != '*')                         //If statement that checks if there is a mine already there and doesn't place a mine if there is
        {
            minefield[i][j] = '*';
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < N )                                          //While loop that generates the numbers for any adjacent mines
    {
        while( i < M)
        {
            if( minefield[i][j] != '*') minefield[i][j] = 0;
            if((minefield[i-1][j-1] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            if((minefield[i-1][j] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            if((minefield[i][j-1] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            if((minefield[i-1][j+1] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            if((minefield[i+1][j-1] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            if((minefield[i+1][j] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            if((minefield[i][j+1] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            if((minefield[i+1][j+1] == '*') && (minefield[i][j] != '*')) minefield[i][j]++;
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    print_minefield()
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

void print_minefield(void)                                  // This function prints the minefield
{
    int i = 0, j = 0, z = 0;
    int M,N;
    while( z < M )                                          // This while loop prints out the line of co-ordinates along the x axis of the minefield
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )                                          // Loop that prints out each character in the minefield
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            if( blank_minefield[i][j] == '-')
            {
                printf("|%c|\t", blank_minefield[i][j]);

            }
            else if( minefield[i][j] == 0 )                 // This changes any spaces with values of zero to the character 'B'
            {
                blank_minefield[i][j] = 'B';
                printf("|%c|\t", blank_minefield[i][j]);
            }
            else
            {
                printf("|%d|\t", blank_minefield[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

