#include "minMax.h"

unsigned int minMax(valCaseGrille **grille, const unsigned int p){
    int eval = evalGrille(grille);
    unsigned int i;
    unsigned int bestCoup = 0;
    int minOrMaxEval = INT_MAX;

    /*printf("first, minMax\n");
    affGrille(grille);*/
    if(p == 0){
	return (rand()%(NBRE_COLONNE-0)+0);
    }
    
    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[NBRE_RANGE-1][i] == NO_PLAY){
	    addCoup(grille, i, PLAYER_2);
	    eval = evalMin(grille, p-1);
	    /*printf("eval : %d, minOrMaxEval : %d\n", eval, minOrMaxEval);
	    nbreLigneSaute(2);*/
	    if(minOrMaxEval > eval){
		bestCoup = i;
		minOrMaxEval = eval;
	    }
	    removeCoup(grille, i);
	}
    }
    //printf("choix : %d\n", bestCoup+1);
    return bestCoup;
}

/*
 * point de vue IA => on retourne l'evaluation correspondant au coup considere comme etant le meilleur,
 * c'est a dire ayant la meilleur evaluation
 * s'interrompt (dans le for) si on trouve un coup donnant le gain pour IA
 * */
unsigned int evalMax(valCaseGrille **grille, const unsigned int p){
    int eval = evalGrille(grille);
    unsigned int i;
    int maxEval = INT_MAX;
    
    //affGrille(grille);
    if(gameOver(eval) || p == 0){
	return eval;
    }

    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[NBRE_RANGE-1][i] == NO_PLAY){
	    addCoup(grille, i, PLAYER_2);
	    eval = evalMin(grille, p-1);
	    /*printf("eval : %d, max : %d\n", eval, maxEval);
	    nbreLigneSaute(2);*/
	    if(maxEval < eval){
		maxEval = eval;
	    }
	    removeCoup(grille, i);
	}
    }
    return maxEval;
}

/*
 * point de vue human player => on retourne la meilleur evaluation pour le joeur humain, c'est a dire la pire pour l'IA
 * on s'arrete (dans le for) si on trouve un coup donnant le gain pour l'human player
 * */
unsigned int evalMin(valCaseGrille **grille, const unsigned int p){
    int eval = evalGrille(grille);
    unsigned int i;
    int minEval = INT_MIN;

    //affGrille(grille);
    if(gameOver(eval) || p == 0){
	return eval;
    }

    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[NBRE_RANGE-1][i] == NO_PLAY){
	    addCoup(grille, i, PLAYER_1);
	    eval = evalMin(grille, p-1);
	    /*printf("eval : %d, min : %d\n", eval, minEval);
	    nbreLigneSaute(2);*/
	    if(minEval < eval){
		minEval = eval;
	    }
	    removeCoup(grille, i);
	}
    }
    return minEval;
}

