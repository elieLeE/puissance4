#include "gestionCoup.h"

/*
 * b = true => humanPlayer
 * b = false => ComputerPlayer
 * */
unsigned int nextCoup(valCaseGrille **grille, bool b){
    if(b){
	return nextCoupHuman(grille[NBRE_RANGE-1]);
    }
    else{
	return nextCoupComputer(grille);
    }
}

unsigned int nextCoupHuman(valCaseGrille* grille){
    int coup = -1;

    int err =  lectureSecuriseInt(&coup);
    while((err != 0) || (!validiteCoup(grille, coup))){
	printf("coup non valide. Veuillez recommencer\n");
	err =  lectureSecuriseInt(&coup);
    }
    printf("\n");
    return (unsigned int)(coup-1);
}

unsigned int nextCoupComputer(valCaseGrille **grille){
    structOptions *opt = getOptions();
    return minMax(grille, opt->niveauIA, true);
}

/*
 * on pense comme l'utilisateur => premiere colonne <==> colonne 1
 * 1 ==> taille (et non 0 to taille -1)
 * le coup sera ensuite decrement de 1 afin de penser comme pour un tableau
 * */
bool validiteCoup(const valCaseGrille* const grille, const int coup){
    return ((coup > 0) && (coup <= NBRE_COLONNE) && (grille[coup-1] == NO_PLAY));
}

void addCoup(valCaseGrille ** const grille, const unsigned int coup, const unsigned int player){
    unsigned int i = 0;

    while(grille[i][coup] != NO_PLAY){
	i++;
    }
    grille[i][coup] = player;
}

void removeCoup(valCaseGrille** const grille, const unsigned int col){
    int i = NBRE_RANGE-1;
    
    while((i>=0) && (grille[i][col] == NO_PLAY)){
	i--;
    }
    grille[i][col] = NO_PLAY;
}

void coupsPossibles(const valCaseGrille* const grille, bool *const tab){
    unsigned int i;

    for(i=0; i<NBRE_COLONNE; i++){
	tab[i] = (grille[i] == NO_PLAY);
    }
}
