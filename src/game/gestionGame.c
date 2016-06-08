#include "gestionGame.h"

void game(const menuStart modeGame){
    bool J1ToPlay, b;
    int eval = 0;
    int coup;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    /*
     * si Human Vs Computer 
     *	    => J1 = Human
     *	    => J2 = Computer
     * */
    J1ToPlay = ((rand()%(PLAYER_2+1-PLAYER_1)+PLAYER_1) == PLAYER_1);	//true <==> a J1 de jouer
    
    while(!gameOver(eval = evalGrille(grille))){
	printf("eval : %d\n", eval);
	b = (modeGame == PLAYER_VS_PLAYER) || J1ToPlay;
	if(b){
	    affJoueurToPlay(J1ToPlay);
	}
	//A etudier (conversion => si mets pas ==> warnng)
	//affGrille((const valCaseGrille**const)grille);
	affGrille(grille);
	J1ToPlay = !J1ToPlay;
	coup = nextCoup(grille, b);
	if(J1ToPlay){
	    printf("J1ToPlay true\n");
	}
	else{
	    printf("J1ToPlay false\n");
	}
	addCoup(grille, coup, J1ToPlay?PLAYER_1:PLAYER_2);
    }
    printf("eval : %d\n", eval);
    affResultatGame(eval);
    //affGrille((const valCaseGrille**const)grille);
    affGrille(grille);
    printf("\n\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
    
}

bool gameOver(const int eval){
    return ((eval == PLAYER_1_WIN) || (eval == PLAYER_2_WIN) || (eval == DRAW_GAME));
}

