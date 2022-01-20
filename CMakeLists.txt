cmake_minimum_required(VERSION 3.21)
project(Structures_de_Donnees C)

set(CMAKE_C_STANDARD 11)

add_executable(Structures_de_Donnees
        "AI Project/aide_projet.c"
        "AI Project/Main_Class.c" "AI Project/CvC_GamePlay.c" "AI Project/HvC_GamePlay.c" "AI Project/HvC_GamePlay.h" "AI Project/CvC_GamePlay.h" "AI Project/Player.h" "AI Project/Gameplay.h")
