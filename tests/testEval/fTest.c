#include "fTest.h"

valCaseGrille hasPlayer(){
    return ((rand()%(2)) == 0?PLAYER_1:PLAYER_2);
}

void structSpec(valCaseGrille** grille, valCaseGrille player){
    grille[0][2] = player;
    grille[0][3] = player;
    grille[0][4] = player;
    grille[0][5] = player;

    grille[1][3] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
    grille[2][3] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
    grille[3][3] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
}

/* GAIN */
void gainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player){
    grille[debLig][col] = player;
    grille[debLig+1][col] = player;
    grille[debLig+2][col] = player;
    grille[debLig+3][col] = player;
}

void gainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player){
    grille[lig][debCol] = player;
    grille[lig][debCol+1] = player;
    grille[lig][debCol+2] = player;
    grille[lig][debCol+3] = player;
}

void gainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player){
    grille[lig][debCol] = player;
    grille[lig+1][debCol+1] = player;
    grille[lig+2][debCol+2] = player;
    grille[lig+3][debCol+3] = player;
}

void gainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player){
    grille[lig][debCol] = player;
    grille[lig+1][debCol-1] = player;
    grille[lig+2][debCol-2] = player;
    grille[lig+3][debCol-3] = player;
}

/* NO GAIN */
void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player){
    gainEnCol(grille, debLig, col, player);
    unsigned int has = rand()%(debLig+3+1- debLig)+debLig;
    grille[has][col] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
}

void noGainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player){
    gainEnLigne(grille, lig, debCol, player);
    unsigned int has = rand()%(debCol+3+1- debCol)+debCol;
    grille[lig][has] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
}

void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player){
    gainEnDiagonaleDroite(grille, lig, debCol, player);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol+has] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
}

void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player){
    gainEnDiagonaleGauche(grille, lig, debCol, player);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol-has] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
}
/* DRAW */
void remplissageToDrawGame(valCaseGrille** grille){
    // colonne 1
    grille[0][0] = PLAYER_1;
    grille[1][0] = PLAYER_1;
    grille[2][0] = PLAYER_1;
    grille[3][0] = PLAYER_2;
    grille[4][0] = PLAYER_2;
    grille[5][0] = PLAYER_2;

    // colonne 2
    grille[0][1] = PLAYER_1;
    grille[1][1] = PLAYER_2;
    grille[2][1] = PLAYER_2;
    grille[3][1] = PLAYER_2;
    grille[4][1] = PLAYER_1;
    grille[5][1] = PLAYER_1;

    // colonne 3
    grille[0][2] = PLAYER_2;
    grille[1][2] = PLAYER_2;
    grille[2][2] = PLAYER_1;
    grille[3][2] = PLAYER_1;
    grille[4][2] = PLAYER_1;
    grille[5][2] = PLAYER_2;

    // colonne 4
    grille[0][3] = PLAYER_1;
    grille[1][3] = PLAYER_1;
    grille[2][3] = PLAYER_1;
    grille[3][3] = PLAYER_2;
    grille[4][3] = PLAYER_2;
    grille[5][3] = PLAYER_2;
    
    // colonne 5
    grille[0][4] = PLAYER_2;
    grille[1][4] = PLAYER_2;
    grille[2][4] = PLAYER_1;
    grille[3][4] = PLAYER_1;
    grille[4][4] = PLAYER_1;
    grille[5][4] = PLAYER_2;
    
    // colonne 6
    grille[0][5] = PLAYER_1;
    grille[1][5] = PLAYER_2;
    grille[2][5] = PLAYER_2;
    grille[3][5] = PLAYER_2;
    grille[4][5] = PLAYER_1;
    grille[5][5] = PLAYER_1;
    
    // colonne 7
    grille[0][6] = PLAYER_1;
    grille[1][6] = PLAYER_1;
    grille[2][6] = PLAYER_1;
    grille[3][6] = PLAYER_2;
    grille[4][6] = PLAYER_2;
    grille[5][6] = PLAYER_2;
}
