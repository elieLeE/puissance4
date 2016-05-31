#include "test.h"

void testSpec(){
    int eval;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);
    valCaseGrille player;

    printf("testSpec : ");

    player = hasPlayer();
    structSpec(grille, player);
    eval = evalGrille(grille);
    assert(gameOver(eval));

    printf("\t\t\t\tOK\n");
    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testEvaluationColonne(){
    unsigned int i, j;
    int eval;
    valCaseGrille player;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    // Test alignement correcte //
    printf("testEvaluationColonne : \n");
    printf("\ttestGameOver : ");
    for(i=0; i<3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    player = hasPlayer();
	    gainEnCol(grille, i, j, player);
	    assert(evalGrille(grille) == enumToDefine(player));
	    initGrille(grille);
	}
    }
    printf("\t\t\tOK\n");

    printf("\ttestEvauationIncorrecte : ");
    for(i=0; i<3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    player = hasPlayer();
	    noGainEnCol(grille, i, j, player);
	    eval = evalGrille(grille);
	    assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\tOK\n");

    printf("\n");
    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testEvaluationLigne(){
    unsigned int i, j;
    int eval;
    valCaseGrille player;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testEvaluationLigne : \n");
    printf("\ttestGameOver : ");
    for(i=0; i<NBRE_RANGE; i++){
	for(j=0; j<4; j++){
	    player = hasPlayer();
	    gainEnLigne(grille, i, j, player);
	    eval = evalGrille(grille);
	    assert(evalGrille(grille) == enumToDefine(player));
	    initGrille(grille);
	}
    }
    printf("\t\t\tOK\n");

    printf("\ttestGameNotOver : ");
    for(i=0; i<3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    player = hasPlayer();
	    noGainEnLigne(grille, i, j, player);
	    eval = evalGrille(grille);
	    assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\t\tOK\n");
    printf("\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testEvaluationDiagonaleDroite(){
    int eval;
    unsigned int i, j;
    valCaseGrille player;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testEvaluationDiagonaleDroite : \n");
    printf("\ttestGameOver : ");
    for(i=0; i<3; i++){
	for(j=0; j<4; j++){
	    player = hasPlayer();
	    gainEnDiagonaleDroite(grille, i, j, player);
	    assert(evalGrille(grille) == enumToDefine(player));
	    initGrille(grille);
	}
    }
    printf("\t\t\tOK\n");

    printf("\ttestGameNotOver : ");
    for(i=0; i<3; i++){
	for(j=0; j<4; j++){
	    player = hasPlayer();
	    noGainEnDiagonaleDroite(grille, i, j, player);
	    eval = evalGrille(grille);
	    assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\t\tOK\n");
    printf("\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testEvaluationDiagonaleGauche(){
    int eval;
    unsigned int i, j;
    valCaseGrille player;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testEvaluationDiagonaleGauche : \n");
    printf("\ttestGameOver : ");
    for(i=0; i<3; i++){
	for(j=3; j<NBRE_COLONNE; j++){
	    player = hasPlayer();
	    gainEnDiagonaleGauche(grille, i, j, player);
	    assert(evalGrille(grille) == enumToDefine(player));
	    initGrille(grille);
	}
    }
    printf("\t\t\tOK\n");

    printf("\ttestGameNotOver : ");
    for(i=0; i<3; i++){
	for(j=3; j<NBRE_COLONNE; j++){
	    player = hasPlayer();
	    noGainEnDiagonaleGauche(grille, i, j, player);
	    eval = evalGrille(grille);
	    assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\t\tOK\n");
    printf("\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
}


void testDraw(){
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);
    remplissageToDrawGame(grille);

    printf("testEvaluationDraw : ");
    assert(evalGrille(grille)==DRAW_GAME);
    printf("\t\t\tOK\n");
}
