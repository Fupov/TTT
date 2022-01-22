#include <stdio.h>
#include <stdint.h>
#include "CvC_GamePlay.h"
#include "HvC_GamePlay.h"
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include "Player.h"
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
int main()
{
    uint32_t choice,round;
    do
    {
        printf("\n----Menu de l'application----\n");
        printf("01. Player vs IA\n");
        printf("02. IA vs IA\n");
        printf("03. Quit\n");
        printf("Choose between 1 to 3 (1-3)\n");
        scanf("%lu",&choice);
        system(CLEAR);
        switch(choice){
            case 1:
                printf("");
                _Computer Beta;
                _Human Aymane;
                Beta.draw=0;Beta.win=0;Beta.draw=0;
                Aymane.lose=0;Aymane.win=0;Aymane.draw=0;
                bool continuePlay=true;
                while(continuePlay){
                    Gameplay_HvC(Aymane, Beta);
                    uint32_t choice2;
                    printf("Would you like to play another Game? (Y=1/N=0)\n");
                    scanf("%lu",&choice2);
                    if(choice2==0){
                        continuePlay=false;
                    }
                    else{
                        continuePlay=true;
                    }
                }
                system(CLEAR);
                break;
            case 2:
                printf("\nHow many times you want me to play?\n");
                scanf("%lu",&round);
                _Computer Tchich;
                _Computer Chaussard;
                Gameplay_CvC(Tchich,Chaussard,round);
                printf("\nPress any button to continue\n");
                getch();
                system(CLEAR);

            case 3:
            break;
        }
    }while(choice!=3);
    system(CLEAR);
    printf("---------------------------------------- \n");
	printf("---Jeu Realiser Par Aymane && Ilyes  --- \n");
    printf("---------------------------------------- \n");

    getch();
    return EXIT_SUCCESS;
}