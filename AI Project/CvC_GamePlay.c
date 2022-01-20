//
// Created by tchic on 17/01/2022.
//

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include "CvC_GamePlay.h"
#include <stdbool.h>
#include "conio.h"
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
void AITurn(_Computer Beta, uint8_t g[9]){
    bool validMove=false;
    uint8_t moveLocation;
    uint8_t choice;
    while(validMove==false) {
        choice=(rand()%(9-1+1))+1;
        validMove = checkAvailability(g, choice);
    }
    g[choice-1]=Beta.s;
}
bool checkAvailable(uint8_t grille[9],uint8_t moveLocation){
    bool locationAvailable;
    if(moveLocation==0){
        locationAvailable=true;
    }else{
        locationAvailable=false;
    }
    return locationAvailable;
}
bool WinningEOG(uint8_t grille[9]){
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
bool DrawEOG(uint8_t g[9]){
    uint8_t count=0;
    for(uint8_t i=0;i<9;i++){
        if(g[i]==0){
            count++;
        }
    }
    if(count>0){
        return false;
    }else{
        return true;
    }
}
void Gameplay_CvC(_Computer Tchich,_Computer Chaussard, uint32_t rounds){
    Tchich.win=0;
    Chaussard.win=0;
    Tchich.draw=0;
    Chaussard.draw=0;
    Chaussard.lose=0;
    Tchich.lose=0;
    Tchich.s=1;
    Chaussard.s=2;
    uint32_t i=0;
    while(i<rounds){
        uint8_t g[9] = {0,0,0,0,0,0,0,0,0};
        bool endOfGame=false;
        int count=0;
        while(!endOfGame){

            AITurn(Tchich,g);
            count++;
            if(WinningEOG(g)==true){
                Tchich.win++;
                Chaussard.lose++;
                endOfGame=true;
                break;
            }
            if(count==9){
                Tchich.draw++;
                Chaussard.draw++;
                endOfGame=true;
                break;
            }
            AITurn(Chaussard,g);
            count++;
            if(WinningEOG(g)==true){
                Tchich.lose++;
                Chaussard.win++;
                endOfGame=true;
                break;
            }
        }
        i++;

    }
    printf("Chaussard Win %lu and lose %lu Rounds\n",Chaussard.win,Chaussard.lose);
    printf("Tchich win %lu, and lose %lu rounds\n",Tchich.win,Tchich.lose);
    printf("Chaussard and Tchich Draws %lu rounds\n",Tchich.draw);
}

