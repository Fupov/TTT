//
// Created by tchic on 17/01/2022.
//

#ifndef STRUCTURES_DE_DONNEES_HVC_H
#define STRUCTURES_DE_DONNEES_HVC_H
#include <stdlib.h>
#include <stdbool.h>
#include "Player.h"
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif
void Gameplay_HvC(_Human Aymane,_Computer Beta);
char print_value(uint8_t value);
void print_grille_2d(uint8_t grille[9]);
bool checkAvailability(uint8_t grille[9],uint8_t moveLocation);
void HumanTurn(_Human Aymane,uint8_t g[9]);
void ComputerTurn(_Computer Beta, uint8_t g[9]);

bool WinningEOG(uint8_t g[9]);
#endif //STRUCTURES_DE_DONNEES_HVC_H
