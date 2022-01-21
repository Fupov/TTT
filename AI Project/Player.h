//
// Created by tchic on 17/01/2022.
//
#include <stdint.h>
#ifndef STRUCTURES_DE_DONNEES_PLAYER_H
#define STRUCTURES_DE_DONNEES_PLAYER_H
typedef struct Human{
    uint32_t win;
    uint32_t lose;
    uint32_t draw;
    uint8_t s;
}_Human;

typedef struct Computer{
    uint32_t win;
    uint32_t lose;
    uint32_t draw;
    uint8_t s;
}_Computer;
#endif //STRUCTURES_DE_DONNEES_PLAYER_H
