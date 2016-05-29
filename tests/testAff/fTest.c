#include "fTest.h"

void remplissageAleatoire(valCaseGrille** grille){
    unsigned int i, j;
    valCaseGrille val;

    for(i=0; i<NBRE_RANGE; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    val = (valCaseGrille)(rand()%(3-0)+0);
	    grille[i][j] = val;
	}
    }
}

