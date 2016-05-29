#include "gestionGame.h"

void game(const menuStart modeGame){
    bool b;
    int eval = 0;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    /*
     * si Human Vs Computer 
     *	    => J1 = Human
     *	    => J2 = Computer
     * */
    b = ((rand()%(3-1)+1) == PLAYER_1);	//true <==> a J1 de jouer
    
    while(gameOver(evalGrille(grille))){
	affJoueurToPlay(b);
	//A etudier (conversion => si mets pas ==> warnng)
	//affGrille((const valCaseGrille**const)grille);
	affGrille(grille);
	b = !b;
	addCoup(grille, nextCoup(grille, (modeGame == PLAYER_VS_PLAYER) || b), b?PLAYER_1:PLAYER_2);
	eval = evalGrille(grille);
    }
    affResultatGame(eval);
    //affGrille((const valCaseGrille**const)grille);
    affGrille(grille);
    printf("\n\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
    
}

bool gameOver(const int eval){
    return !((eval == PLAYER_1_WIN) || (eval == PLAYER_2_WIN) || (eval == DRAW_GAME));
}

