#include "test.h"
#include "../../src/aff/affJeu.h"

void testValiditeCoup(){
    unsigned int i, j;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testValiditeCoup : \n");

    /* COUPS VALIDES */
    printf("\tcoupsValides : ");
    for(i=0; i<NBRE_COLONNE; i++){
	for(j=0; j<NBRE_RANGE; j++){
	    assert(validiteCoup(grille[NBRE_RANGE-1], i+1));
	    addCoup(grille, i, PLAYER_1);
	}
    }
    initGrille(grille);
    for(j=0; j<NBRE_RANGE; j++){
	for(i=0; i<NBRE_COLONNE; i++){
	    assert(validiteCoup(grille[NBRE_RANGE-1], i+1));
	    addCoup(grille, i, PLAYER_2);
	}
    }
    printf("\t\tOK\n");

    /* COUPS INVALIDES */
    printf("\tcoupsInvalides : ");
    for(i=0; i<NBRE_COLONNE; i++){
	assert(!validiteCoup(grille[NBRE_RANGE-1], i+1));
    }
    assert(!validiteCoup(grille[NBRE_RANGE-1], 0));
    assert(!validiteCoup(grille[NBRE_RANGE-1], NBRE_COLONNE+1));

    printf("\tOK\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testCoupComputerLigne(){
    unsigned int i, j;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testCoupComputerLigne\n");

    for(i=0; i<3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    almostGainEnLigne(grille, i, j);
	    affGrille(grille);
	    printf("coupComputer : %d\n", minMax(grille, 1, true));
	    assert(nextCoupComputer(grille) == j);
	    initGrille(grille);
	}
    }

    printf("\n");
}
