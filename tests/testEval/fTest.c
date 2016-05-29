#include "fTest.h"

/* GAIN */
void gainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col){
    grille[debLig][col] = PLAYER_1;
    grille[debLig+1][col] = PLAYER_1;
    grille[debLig+2][col] = PLAYER_1;
    grille[debLig+3][col] = PLAYER_1;
}

void gainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    grille[lig][debCol] = PLAYER_1;
    grille[lig][debCol+1] = PLAYER_1;
    grille[lig][debCol+2] = PLAYER_1;
    grille[lig][debCol+3] = PLAYER_1;
}

void gainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    grille[lig][debCol] = PLAYER_1;
    grille[lig+1][debCol+1] = PLAYER_1;
    grille[lig+2][debCol+2] = PLAYER_1;
    grille[lig+3][debCol+3] = PLAYER_1;
}

void gainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    grille[lig][debCol] = PLAYER_1;
    grille[lig+1][debCol-1] = PLAYER_1;
    grille[lig+2][debCol-2] = PLAYER_1;
    grille[lig+3][debCol-3] = PLAYER_1;
}

/* NO GAIN */
void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col){
    gainEnCol(grille, debLig, col);
    unsigned int has = rand()%(debLig+3+1- debLig)+debLig;
    grille[has][col] = PLAYER_2;
}

void noGainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    gainEnLigne(grille, lig, debCol);
    unsigned int has = rand()%(debCol+3+1- debCol)+debCol;
    grille[lig][has] = PLAYER_2;
}

void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    gainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol+has] = PLAYER_2;
}

void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    gainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol-has] = PLAYER_2;
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
