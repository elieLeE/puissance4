#include "fTest.h"

/* GAIN */
void almostGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col){
    grille[debLig][col] = PLAYER_1;
    grille[debLig+1][col] = PLAYER_1;
    grille[debLig+2][col] = PLAYER_1;
}

void almostGainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    grille[lig][debCol] = PLAYER_1;
    grille[lig][debCol+1] = PLAYER_1;
    grille[lig][debCol+2] = PLAYER_1;
}

void almostGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    grille[lig][debCol] = PLAYER_1;
    grille[lig+1][debCol+1] = PLAYER_1;
    grille[lig+2][debCol+2] = PLAYER_1;
}

void almostGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    grille[lig][debCol] = PLAYER_1;
    grille[lig+1][debCol-1] = PLAYER_1;
    grille[lig+2][debCol-2] = PLAYER_1;
}

/* NO GAIN */
void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col){
    almostGainEnCol(grille, debLig, col);
    unsigned int has = rand()%(debLig+3+1- debLig)+debLig;
    grille[has][col] = PLAYER_2;
}

void noGainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnLigne(grille, lig, debCol);
    unsigned int has = rand()%(debCol+3+1- debCol)+debCol;
    grille[lig][has] = PLAYER_2;
}

void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol+has] = PLAYER_2;
}

void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol-has] = PLAYER_2;
}
