//
// Created by tchic on 17/01/2022.
//

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "HvC_GamePlay.h"
#include <stdbool.h>
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
void HumanTurn(_Human Aymane,uint8_t g[9]){
    bool validMove=false;
    int choice;
    while(validMove==false){
        printf("Enter your Move: ");
        scanf("%d",&choice);
        if(choice>=0 && choice<=9){
            validMove= checkAvailability(g,choice);
            if(validMove==false){
                printf("\nInvalid Input, Try to Choose another one\n");
                print_grille_2d(g);
            }
        }
    }
    g[choice-1]=Aymane.s;
    print_grille_2d(g);
}
void ComputerTurn(_Computer Beta, uint8_t g[9]){
    bool validMove=false;
    uint8_t moveLocation;
    uint8_t choice;
    while(validMove==false) {
        choice=(rand()%(9-1+1))+1;
        validMove = checkAvailability(g, choice);
    }
    g[choice-1]=Beta.s;
    print_grille_2d(g);
}
bool Winning(uint8_t grille[9]){
    if( ( grille[0] ==1 ) && (1 == grille[3] ) && (1 == grille[6] ) )
    {
        return true;
    }else if( ( grille[1] ==1 ) && (1 == grille[4] ) && (1 == grille[7] ) )
    {
        return true;
    }else if( ( grille[2] == 1 ) && (1 == grille[5] ) && (1== grille[8] ) )
    {
        return true;
    }else if( ( grille[0] ==1 ) && (grille[1] == 1 ) && (grille[2] == 1 ) )
    {
        return true;
    }else if( ( grille[3] ==1 ) && (1 == grille[4] ) && (1 == grille[5] ) )
    {
        return true;
    }else if( ( grille[6] ==1 ) && (1 == grille[7] ) && (1 == grille[8] ) )
    {
        return true;
    }else if( ( grille[1] ==1 ) && (1 == grille[4] ) && (1 == grille[8] ) )
    {
        return true;
    }else if( ( grille[2] ==1 ) && (1 == grille[4] ) && (1 == grille[6] ) )
    {
        return true;
    }else if( ( grille[0] ==2 ) && (2 == grille[3] ) && (2 == grille[6] ) )
    {
        return true;
    }else if( ( grille[1] ==2 ) && (2 == grille[4] ) && (2 == grille[7] ) )
    {
        return true;
    }else if( ( grille[2] == 2 ) && (2 == grille[5] ) && (2== grille[8] ) )
    {
        return true;
    }else if( ( grille[0] ==2 ) && (grille[1] == 2 ) && (grille[2] == 2 ) )
    {
        return true;
    }else if( ( grille[3] ==2 ) && (2 == grille[4] ) && (2 == grille[5] ) )
    {
        return true;
    }else if( ( grille[6] ==2 ) && (2 == grille[7] ) && (2 == grille[8] ) )
    {
        return true;
    }else if( ( grille[1] ==2 ) && (2 == grille[4] ) && (2 == grille[8] ) )
    {
        return true;
    }else if( ( grille[2] ==2 ) && (2 == grille[4] ) && (2 == grille[6] ) )
    {
        return true;
    }else{
        return false;
    }
}
char print_value(uint8_t value)
{
    switch(value)
    {
        case (0):
            return ' ';
        case (1):
            return 'x';
        case (2):
            return 'o';
        default:
            assert(0);
    }
}
void print_grille_2d(uint8_t grille[9])
{
    printf( "\n|%c|%c|%c|\n", print_value(grille[0]), print_value(grille[1]), print_value(grille[2]));
    printf( "|%c|%c|%c|\n", print_value(grille[3]), print_value(grille[4]), print_value(grille[5]));
    printf( "|%c|%c|%c|\n", print_value(grille[6]), print_value(grille[7]), print_value(grille[8]));
}
bool checkAvailability(uint8_t grille[9],uint8_t choice){
    bool locationAvailable;
    if(grille[choice-1]==0){
        locationAvailable=true;
    }else{
        locationAvailable=false;
    }
    return locationAvailable;
}
uint8_t arrayvalues(uint8_t g[9]){
    uint8_t e;
    for(int i=0;i<9;i++){
        e+=g[i];
    }
    return e;
}
void Gameplay_HvC(_Human Aymane, _Computer Beta){
    int s;
    char *dejaVu;

    uint8_t g[9] = {0,0,0,0,0,0,0,0,0};
    uint8_t de= arrayvalues(g);
    printf("%d",de);
    print_grille_2d(g);
    bool endOfGame=false;
    printf("Would you like to play as X or O (1=x,2=o)\n");
    scanf("%d",&s);
    if(s==2){
        Aymane.s=2;
        Beta.s=1;
    }else{
        Beta.s=2;
        Aymane.s=1;
    }
    int count=0;
    while(!endOfGame){

        HumanTurn(Aymane,g);
        count++;
     //   strncat(dejaVu,de,9);
        if(WinningEOG(g)==true){
            printf("Congratulation You Win this Game\n");
            endOfGame=true;
            break;
        }
        if(count==9){
            printf("Its A Draw\n");
            endOfGame=true;
            break;
        }
        ComputerTurn(Beta,g);
        count++;
  //      strncat(dejaVu,de,9);
        if(WinningEOG(g)==true){
            printf("You Lose this Game, Better Luck Next Time\n");
            endOfGame=true;
            break;
        }
    }
    printf("%s\n",dejaVu);
    printf("End of the Game\n");
}
