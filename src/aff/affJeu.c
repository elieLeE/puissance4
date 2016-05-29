#include "affJeu.h"

void affJoueurToPlay(const bool b){
    printf("a J%d de jouer\n", b?1:2);
    printf("veuillez indiquer votre choix en choisissant un nombre entre 1 et 7 (compris)\n");
}

void affResultatGame(const int evalFinal){
    printf("\n");
    switch(evalFinal){
	case PLAYER_1_WIN:
	    printf("victoire J1\n");
	    break;

	case PLAYER_2_WIN:
	    printf("victoire J2\n");
	    break;

	case DRAW_GAME:
	    printf("match nul\n");
	    break;
    }
}

//void affGrille(const valCaseGrille **const grille){
void affGrille(valCaseGrille** grille){
    int i, j;

    printf("joueur 1 : x || joueur 2 : o\n\n");

    for(i=NBRE_RANGE-1; i>=0; i--){
	for(j=0; j<NBRE_COLONNE; j++){
	    printf("|%s", affCase(grille[i][j]));
	}
	printf("|\n");
    }
    /*
     * on pense comme l'utilisateur
     * premiere colonne <==> colonne 1
     * */
    for(i=0; i<NBRE_COLONNE; i++){
	printf(" %d", i+1);
    }
    printf("\n");
}

char* affCase(const valCaseGrille c){
    switch(c){
	case NO_PLAY:
	    return " ";

	case PLAYER_1:
	    return "x";

	case PLAYER_2:
	    return "o";
    }
    return "";
}

