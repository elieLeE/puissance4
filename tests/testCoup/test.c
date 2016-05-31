#include "test.h"
#include "../../src/aff/affJeu.h"

void testValiditeCoup(){
    unsigned int i, j;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testValiditeCoup : \n");

    /* COUPS VALIDES */
    printf("\tcoupsValides : ");
    for(i=0; i<NBRE_COLONNE; i++){
	for(j=0; j<NBRE_RANGE; j++){
	    assert(validiteCoup(grille[NBRE_RANGE-1], i+1));
	    addCoup(grille, i, PLAYER_1);
	}
    }
    initGrille(grille);
    for(j=0; j<NBRE_RANGE; j++){
	for(i=0; i<NBRE_COLONNE; i++){
	    assert(validiteCoup(grille[NBRE_RANGE-1], i+1));
	    addCoup(grille, i, PLAYER_2);
	}
    }
    printf("\t\tOK\n");

    /* COUPS INVALIDES */
    printf("\tcoupsInvalides : ");
    for(i=0; i<NBRE_COLONNE; i++){
	assert(!validiteCoup(grille[NBRE_RANGE-1], i+1));
    }
    assert(!validiteCoup(grille[NBRE_RANGE-1], 0));
    assert(!validiteCoup(grille[NBRE_RANGE-1], NBRE_COLONNE+1));

    printf("\tOK\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
    printf("\n");
}

void testCoupComputerLigne(){
    unsigned int i, j;
    unsigned int expectedMove;
    bool gauche;
    /*char s[100];
    unsigned int coupComputer;*/
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testCoupComputerLigne\n");
    printf("\tcoupDeSurvie : ");
    for(i=0; i<NBRE_RANGE; i++){
	for(j=0; j<NBRE_COLONNE-2; j++){
	    gauche = (rand()%(2-0) == 0);	    // true => avant
	    almostGainEnLigne(grille, i, j, PLAYER_1, gauche);
	    expectedMove = ((j==0) || (j+2 == NBRE_COLONNE-1))?3:(!gauche)?j-1:j+3;
	    affDebug(grille, PLAYER_2, expectedMove);
	    /*sprintf(s, "fichier %s, ligne %d => coupComputer : %d, expectedMove : %d", __FILE__, __LINE__, coupComputer, expectedMove);
	    my_assert(expectedMove==coupComputer, s);*/
	    //assert(nextCoupComputer(grille) == expectedMove);
	    initGrille(grille);
	}
    }
    printf("\t\tOK\n");

    printf("\tcoupDeGain : ");
    for(i=0; i<NBRE_RANGE; i++){
	for(j=0; j<NBRE_COLONNE-2; j++){
	    gauche = (rand()%(2-0) == 0);	    // true => avant
	    almostGainEnLigne(grille, i, j, PLAYER_2, gauche);
	    expectedMove = ((j==0) || (j+2 == NBRE_COLONNE-1))?3:(!gauche)?j-1:j+3;
	    affDebug(grille, PLAYER_2, expectedMove);
	    //assert(nextCoupComputer(grille) == expectedMove);
	    initGrille(grille);
	}
    }
    printf("\t\tOK\n");
    printf("\n");
    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testCoupComputerCol(){
    unsigned int i, j;
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testCoupComputerCol\n");
    printf("\tcoupDeSurvie : ");
    for(i=0; i<NBRE_RANGE-3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    almostGainEnCol(grille, i, j, PLAYER_1);
	    affDebug(grille, PLAYER_2, j);
	    //assert(nextCoupComputer(grille) == j);
	    initGrille(grille);
	}
    }
    printf("\t\tOK\n");

    printf("\tcoupDeGain : ");
    for(i=1; i<NBRE_RANGE-3; i++){
	for(j=0; j<NBRE_COLONNE; j++){
	    almostGainEnCol(grille, i, j, PLAYER_2);
	    affDebug(grille, PLAYER_2, j);
	    //assert(nextCoupComputer(grille) == j);
	    initGrille(grille);
	}
    }
    printf("\t\tOK\n");
    printf("\n");
    liberationTab2D((void**)grille, NBRE_RANGE);
}

void testCoupComputerDiagDroite(){
    int eval;
    bool gauche;
    unsigned int i, j;
    unsigned int expectedMove;

    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testEvaluationDiagonaleDroite : \n");
    printf("\ttestGameOver : ");
    for(i=0; i<4; i++){
	for(j=0; j<5; j++){
	    if(((i==0) && (j==NBRE_COLONNE-3)) || ((i==NBRE_RANGE-3) && (j==0))){
		continue;
	    }
	    gauche = (rand()%(2-0) == 0);	    // true => avant
	    gauche = ((j==NBRE_COLONNE-3) || (i==NBRE_RANGE-3) || (gauche && (i!=0) && (j!=0)));
	    expectedMove = gauche?j-1:j+3;
	    //expectedMove = ((j==NBRE_COLONNE-3) || (i==NBRE_RANGE-3) || (gauche && (j!=0)))?j-1:j+3;
	    almostGainEnDiagonaleDroite(grille, i, j, PLAYER_1, gauche);
	    //affGrille(grille);
	    /*affGrille(grille);
	    printf("expectedMove : %d\n", expectedMove+1);
	    nbreLigneSaute(5);*/
	    //affDebug(grille, PLAYER_2, j);
	    //assert(evalGrille(grille) == PLAYER_1_WIN);
	    initGrille(grille);
	}
    }
    printf("\t\tTODO\n");

    printf("\ttestGameNotOver : ");
    for(i=0; i<4; i++){
	for(j=0; j<5; j++){
	    if(((i==0) && (j==NBRE_COLONNE-3)) || ((i==NBRE_RANGE-3) && (j==0))){
		continue;
	    }
	    gauche = (rand()%(2-0) == 0);	    // true => avant
	    gauche = ((j==NBRE_COLONNE-3) || (i==NBRE_RANGE-3) || (gauche && (i!=0) && (j!=0)));
	    expectedMove = gauche?j-1:j+3;
	    almostGainEnDiagonaleDroite(grille, i, j, PLAYER_2, gauche);
	    eval = evalGrille(grille);
	    //affGrille(grille);
	    //affDebug(grille, PLAYER_2, j);
	    //assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\tTODO\n");
    printf("\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
}


void testCoupComputerDiagGauche(){
    int eval;
    bool gauche;
    unsigned int i, j;
    unsigned int expectedMove;

    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);

    printf("testCoupComputerDiagGauche\n");
    printf("\ttestGameOver : ");

    for(i=0; i<NBRE_RANGE-2; i++){
	for(j=2; j<NBRE_COLONNE; j++){
	    if(((i==0) && (j==2)) || ((i==NBRE_RANGE-3) && (j == NBRE_COLONNE-1))){
		continue;
	    }
	    gauche = (rand()%(2-0) == 0);	    // true => avant
	    gauche = ((i==0) || (j == NBRE_COLONNE-1) || (gauche && (j!=2) && (i!=NBRE_RANGE-3)));
	    expectedMove = gauche?j-1:j+3;
	    almostGainEnDiagonaleGauche(grille, i, j, PLAYER_1, gauche);
	    //affGrille(grille);
	    //affDebug(grille, PLAYER_2, j);
	    //assert(evalGrille(grille) == PLAYER_1_WIN);
	    initGrille(grille);
	}
    }
    printf("\t\tTODO\n");

    printf("\ttestGameNotOver : ");
    for(i=0; i<NBRE_RANGE-2; i++){
	for(j=2; j<NBRE_COLONNE; j++){
	    if(((i==0) && (j==2)) || ((i==NBRE_RANGE-3) && (j == NBRE_COLONNE-1))){
		continue;
	    }
	    gauche = (rand()%(2-0) == 0);	    // true => avant
	    gauche = ((i==0) || (j == NBRE_COLONNE-1) || (gauche && (j!=2) && (i!=NBRE_RANGE-3)));
	    expectedMove = gauche?j-1:j+3;
	    almostGainEnDiagonaleGauche(grille, i, j, PLAYER_2, gauche);
	    eval = evalGrille(grille);
	    //affDebug(grille, PLAYER_2, j);
	    //assert((eval > (PLAYER_2_WIN)) && (eval < PLAYER_1_WIN));
	    initGrille(grille);
	}
    }
    printf("\tTODO\n");
    printf("\n");

    liberationTab2D((void**)grille, NBRE_RANGE);
}
