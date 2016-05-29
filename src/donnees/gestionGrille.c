#include "gestionGrille.h"

void initGrille(valCaseGrille** grille){
    unsigned int i, j;

    for(i=0; i<NBRE_RANGE; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    grille[i][j] = NO_PLAY;
	}
    }
}

