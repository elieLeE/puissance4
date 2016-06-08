#include "minMax.h"

unsigned int minMax(valCaseGrille **grille, const unsigned int p){
    unsigned int i;
    unsigned int bestCoup = 0;

    evalStruct evalMax, eval;
    evalMax.eval = INT_MIN;
    evalMax.prof = 0;

    /*int evalMax = INT_MIN;
    int eval;
    */

    nbreLigneSaute(100);
    affGrille(grille);
    if(p == 0){
	return (rand()%(NBRE_COLONNE-0)+0);
    }
    
    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[NBRE_RANGE-1][i] == NO_PLAY){
	    printf("coup : %d", i);
	    addCoup(grille, i, PLAYER_2);
	    eval = evalMin(grille, p-1);
	    if(bestEval(&eval, &evalMax)){
	    //if(evalMax < eval){
		bestCoup = i;
		//max = eval;
		eval = evalMax;
	    }
	    //else if((max == eval) && (rand()%2 == 0)){
	    /*else if(sameEval(&evalMax, &eval) && (rand()%2 == 0)){
		bestCoup = i;
		//max = eval;
		eval = evalMax;
	    }*/
	    removeCoup(grille, i);
	    nbreLigneSaute(40);
	}
    }
    return bestCoup;
}

/*
 * point de vue IA => on retourne l'evaluation correspondant au coup considere comme etant le meilleur,
 * c'est a dire ayant la meilleur evaluation
 * s'interrompt (dans le for) si on trouve un coup donnant le gain pour IA
 * */
evalStruct evalMax(valCaseGrille **grille, const unsigned int p){
//unsigned int evalMax(valCaseGrille **grille, const unsigned int p);
    unsigned int i;
    unsigned int bestCoup = -1;

    evalStruct evalMax, eval;
    evalMax.eval = INT_MIN;
    evalMax.prof = 0;
    eval.eval = evalGrille(grille);
    if(gameOver(eval.eval) || p == 0){
	printf(" => eval : %d\n", eval.eval);
	eval.prof = p;
	return eval;
    }

    /*int maxEval = INT_MIN;
    int eval = evalGrille(grille);
    if(gameOver(eval) || p == 0){
	printf(" => eval : %d\n", eval);
	//affGrille(grille);
	return eval;
    }*/

    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[NBRE_RANGE-1][i] == NO_PLAY){
	    printf(" => coup : %d", i);
	    addCoup(grille, i, PLAYER_2);
	    eval = evalMin(grille, p-1);
	    nbreDecal(4-p+1);
	    if(p!=1){
		printf("\n");
	    }
	    if(bestEval(&eval, &evalMax)){
	    //if(maxEval < eval){
		evalMax = eval;
		bestCoup = i;
	    }
	    //else if((evalMax == eval) && (rand()%2 == 0)){
	    /*else if(sameEval(&eval, &evalMax) && (rand()%2 == 0)){
		bestCoup = i;
		//maxEval = eval;
		evalMax = eval;
	    }*/
	    removeCoup(grille, i);
	}
    }
    /*printf("\n");
    nbreDecal(4-p+1);
    printf("==> eval : %d, coup : %d\n", evalMax.eval, bestCoup);*/
    return evalMax;
}

/*
 * point de vue human player => on retourne la meilleur evaluation pour le joeur humain, c'est a dire la pire pour l'IA
 * on s'arrete (dans le for) si on trouve un coup donnant le gain pour l'human player
 * */
evalStruct evalMin(valCaseGrille **grille, const unsigned int p){
//unsigned int evalMax(valCaseGrille **grille, const unsigned int p);
    unsigned int i;
    unsigned int bestCoup = -1;

    evalStruct evalMin, eval;
    evalMin.eval = INT_MAX;
    evalMin.prof = 0;
    eval.eval = evalGrille(grille);
    if(gameOver(eval.eval) || p == 0){
	printf(" => eval : %d\n", eval.eval);
	return eval;
    }

    /*int evalMin = INT_MAX;
    int eval = evalGrille(grille);
    if(gameOver(evalMin) || p == 0){
	printf(" => eval : %d\n", eval);
	return eval;
    }
    */

    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[NBRE_RANGE-1][i] == NO_PLAY){
	    printf(" => coup : %d", i);
	    addCoup(grille, i, PLAYER_1);
	    eval = evalMax(grille, p-1);
	    nbreDecal(4-p+1);
	    /*if(p!=1){
		printf("\n");
	    }*/
	    if(bestEval(&evalMin, &eval)){
	    //if(minEval > eval){
		//minEval = eval;
		evalMin = eval;
		bestCoup = i;
	    }
	    //else if((minEval == eval) && (rand()%2 == 0)){
	    /*else if(sameEval(&eval, &evalMin) && (rand()%2 == 0)){
		bestCoup = i;
		evalMin = eval;
	    }*/
	    removeCoup(grille, i);
	}
    }
    /*printf("\n");
    nbreDecal(4-p+1);
    printf("==> eval : %d, coup : %d\n", minEval, bestCoup);*/
    return evalMin;
}

