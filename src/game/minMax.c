#include "minMax.h"

unsigned int minMax(valCaseGrille **grille, const unsigned int p, const bool modeMax){
    int eval = evalGrille(grille);
    bool tabCoupsPosssibles[NBRE_COLONNE] = {false};
    unsigned int i;
    unsigned int bestCoup;
    int minOrMaxEval;
    
    if(gameOver(eval) || p == 0){
	return eval;
    }

    coupsPossibles(grille[NBRE_RANGE-1], tabCoupsPosssibles);
    for(i=0; i<NBRE_COLONNE; i++){
	if(tabCoupsPosssibles[i]){
	    addCoup(grille, i, modeMax?PLAYER_2:PLAYER_1);
	    eval = minMax(grille, p-1, !modeMax);
	    if(betterCoup(minOrMaxEval, eval, modeMax)){
		bestCoup = i;
		minOrMaxEval = eval;
	    }
	    removeCoup(grille, i);
	}
    }
    return bestCoup;
}

/*
 * modeMax = true ==> evaluation coup computer
 * */
bool betterCoup(const int minOrMaxEval, const int eval, const bool modeMax){
    if(modeMax){
	return minOrMaxEval < eval;
    }
    return minOrMaxEval > eval;
}
