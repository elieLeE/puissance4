#include "fTest.h"

void affDebug(valCaseGrille **grille, valCaseGrille player, unsigned int expectedMove){
    int coup;

    coup = nextCoupComputer(grille);
    assert((coup>=0) && (coup < NBRE_COLONNE));
    if((unsigned int)coup!=expectedMove){
	printf("first : \n");
	affGrille(grille);
	addCoup(grille, coup, player);
	printf("last : \n");
	affGrille(grille);
	printf("expectedMove : %d, nextCoupComputer : %d\n", expectedMove+1, coup+1);
	removeCoup(grille, coup);
	abort();
    }
}

/* GAIN */
void almostGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player){
    int i;

    grille[debLig][col] = player;
    grille[debLig+1][col] = player;
    grille[debLig+2][col] = player;

    for(i=debLig-1; i>=0; i--){
	grille[i][col] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;	//hauteur 6 => 3 cases deja occupes par player ==> on ne peux avoir un gain par en dessous
    }
}

void almostGainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player, bool gauche){
    unsigned int i;
    bool b;

    grille[lig][debCol] = player;
    grille[lig][debCol+1] = player;
    grille[lig][debCol+2] = player;

    if(lig==0){
	if((debCol!=0) && (debCol+2!=NBRE_COLONNE-1)){
	    if(gauche){
		grille[lig][debCol-1] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
	    }
	    else{
		grille[lig][debCol+3] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
	    }
	}
    }
    else{
	b = true;
	for(i=0; i<lig; i++, b=!b){
	    if((debCol == 0 || ((gauche) && (debCol+2 != NBRE_COLONNE-1)))){
		grille[i][debCol] = b?PLAYER_1:PLAYER_2;
		grille[i][debCol+1] = b?PLAYER_1:PLAYER_2;
		grille[i][debCol+2] = b?PLAYER_2:PLAYER_1;
		grille[i][debCol+3] = b?PLAYER_2:PLAYER_1;
	    }
	    else{
		grille[i][debCol-1] = b?PLAYER_1:PLAYER_2;
		grille[i][debCol] = b?PLAYER_1:PLAYER_2;
		grille[i][debCol+1] = b?PLAYER_2:PLAYER_1;
		grille[i][debCol+2] = b?PLAYER_2:PLAYER_1;
	    }
	}
    }
}

/*
 * b = true <==> avant
 * */
void almostGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player, bool avant){
    unsigned int i;
    bool b;

    grille[lig][debCol] = player;
    grille[lig+1][debCol+1] = player;
    grille[lig+2][debCol+2] = player;

    b = true;
    if(avant){
	for(i=0; i<lig; i++, b=!b){
	    if(i<lig-1){
		grille[i][debCol-1] = b?PLAYER_1:PLAYER_2;
	    }
	    grille[i][debCol] = b?PLAYER_1:PLAYER_2;
	    grille[i][debCol+1] = b?PLAYER_2:PLAYER_1;
	    grille[i][debCol+2] = b?PLAYER_2:PLAYER_1;
	}
	grille[lig][debCol+1] = PLAYER_1;
	grille[lig][debCol+2] = PLAYER_2;
	grille[lig+1][debCol+2] = PLAYER_2;
    }
    else{							    //apres
	for(i=0; i<lig; i++, b=!b){
	    grille[i][debCol] = b?PLAYER_1:PLAYER_2;
	    grille[i][debCol+1] = b?PLAYER_1:PLAYER_2;
	    grille[i][debCol+2] = b?PLAYER_2:PLAYER_1;
	    grille[i][debCol+3] = b?PLAYER_2:PLAYER_1;
	}
	if((lig == 1) && (debCol != 0)){
	    grille[0][debCol-1] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
	}
	//affGrille(grille);
	grille[lig][debCol+1] = PLAYER_1;
	grille[lig][debCol+2] = PLAYER_2;
	grille[lig][debCol+3] = PLAYER_2;

	grille[lig+1][debCol+2] = PLAYER_2;
	grille[lig+1][debCol+3] = PLAYER_1;

	grille[lig+2][debCol+3] = PLAYER_1;
	/*affGrille(grille);
	nbreLigneSaute(5);*/
    }
}

void almostGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player, bool gauche){
    unsigned int i;
    bool b;

    grille[lig][debCol] = PLAYER_1;
    grille[lig+1][debCol-1] = PLAYER_1;
    grille[lig+2][debCol-2] = PLAYER_1;

    b = true;
    if(gauche){
	for(i=0; i<lig; i++, b=!b){
	    grille[i][debCol-3] = b?PLAYER_1:PLAYER_2;
	    grille[i][debCol-2] = b?PLAYER_1:PLAYER_2;
	    grille[i][debCol-1] = b?PLAYER_2:PLAYER_1;
	    grille[i][debCol] = b?PLAYER_2:PLAYER_1;
	}
	if((lig==1) && (debCol!=NBRE_COLONNE-1)){
	    grille[0][debCol+1] = (player==PLAYER_1)?PLAYER_2:PLAYER_1;
	}
	grille[lig][debCol-1] = PLAYER_1;
	grille[lig][debCol-2] = PLAYER_2;
	grille[lig+1][debCol-2] = PLAYER_2;

	grille[lig][debCol-3] = PLAYER_2;
	grille[lig+1][debCol-3] = PLAYER_1;

	grille[lig+2][debCol-3] = PLAYER_1;
    }
    else{							    //apres
	for(i=0; i<lig; i++, b=!b){
	    if(i<lig-1){
		grille[i][debCol+1] = b?PLAYER_1:PLAYER_2;
	    }
	    grille[i][debCol] = b?PLAYER_1:PLAYER_2;
	    grille[i][debCol-1] = b?PLAYER_2:PLAYER_1;
	    grille[i][debCol-2] = b?PLAYER_2:PLAYER_1;
	}
	grille[lig][debCol-1] = PLAYER_1;
	grille[lig][debCol-2] = PLAYER_2;

	grille[lig+1][debCol-2] = PLAYER_2;
	//affGrille(grille);
    }
}

/* NO GAIN */
/*void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col){
    almostGainEnCol(grille, debLig, col);
    unsigned int has = rand()%(debLig+3+1- debLig)+debLig;
    grille[has][col] = PLAYER_2;
}

void noGainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnLigne(grille, lig, debCol);
    unsigned int has = rand()%(debCol+3+1- debCol)+debCol;
    grille[lig][has] = PLAYER_2;
}

void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol+has] = PLAYER_2;
}

void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol-has] = PLAYER_2;
}*/
