#include "test.h"

void testEvaluationColonne(){
    unsigned int i, j;
    int eval;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    // Test alignement correcte //
    printf("testEvaluationColonne : \n");
    printf("\ttestEvauationCorrecte : ");
    for(i=0; i<3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    gainEnCol(grille, i, j);
	    assert(evalGrille(grille) == PLAYER_1_WIN);
	    initGrille(grille);
	}
    }
    printf("\tOK\n");

    printf("\ttestEvauationIncorrecte : ");
    for(i=0; i<3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    noGainEnCol(grille, i, j);
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
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testEvaluationLigne : \n");
    printf("\ttestEvauationCorrecte : ");
    for(i=0; i<NBRE_RANGE; i++){
	for(j=0; j<4; j++){
	    gainEnLigne(grille, i, j);
	    assert(evalGrille(grille) == PLAYER_1_WIN);
	    initGrille(grille);
	}
    }
    printf("\tOK\n");

    printf("\ttestEvauationIncorrecte : ");
    for(i=0; i<3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    noGainEnLigne(grille, i, j);
	    eval = evalGrille(grille);
	    assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\tOK\n");
    printf("\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testEvaluationDiagonale(){
    int eval;
    unsigned int i, j;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testEvaluationDiagonale : \n");
    printf("\ttestEvauationCorrecte : \n");
    printf("\t\tdiagonaleDroite : ");
    for(i=0; i<3; i++){
	for(j=0; j<4; j++){
	    gainEnDiagonaleDroite(grille, i, j);
	    assert(evalGrille(grille) == PLAYER_1_WIN);
	    initGrille(grille);
	}
    }
    printf("\tOK\n");

    printf("\t\tdiagonaleGauche : ");
    for(i=0; i<3; i++){
	for(j=3; j<NBRE_COLONNE; j++){
	    gainEnDiagonaleGauche(grille, i, j);
	    assert(evalGrille(grille) == PLAYER_1_WIN);
	    initGrille(grille);
	}
    }
    printf("\tOK\n");

    printf("\ttestEvauationIncorrecte : \n");
    printf("\t\tdiagonaleDroite : ");
    for(i=0; i<3; i++){
	for(j=0; j<4; j++){
	    noGainEnDiagonaleDroite(grille, i, j);
	    eval = evalGrille(grille);
	    assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\tOK\n");

    printf("\t\tdiagonaleGauche : ");
    for(i=0; i<3; i++){
	for(j=3; j<NBRE_COLONNE; j++){
	    noGainEnDiagonaleGauche(grille, i, j);
	    assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\tOK\n");
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
