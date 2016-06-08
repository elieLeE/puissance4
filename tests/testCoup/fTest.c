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

void debutConnu(valCaseGrille **grille){
    grille[0][3] = VAL_TEST;
    grille[0][4] = VAL_TEST;
    grille[0][5] = VAL_TEST;
    grille[0][6] = VAL_TEST;
    grille[0][2] = VAL_TEST;
    grille[1][2] = VAL_TEST;
    grille[1][3] = PLAYER_2;
    grille[1][4] = PLAYER_2;
    grille[1][5] = PLAYER_2;
}

/* GAIN */
void almostGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player){
    int i;

    grille[debLig][col] = player;
    grille[debLig+1][col] = player;
    grille[debLig+2][col] = player;

    for(i=debLig-1; i>=0; i--){
	grille[i][col] = (player==VAL_TEST)?VAL_TEST:VAL_TEST;	//hauteur 6 => 3 cases deja occupes par player ==> on ne peux avoir un gain par en dessous
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
		grille[lig][debCol-1] = VAL_TEST;
	    }
	    else{
		grille[lig][debCol+3] = VAL_TEST;
	    }
	}
    }
    else{
	printf("else\n");
	b = true;
	for(i=0; i<lig; i++, b=!b){
	    if((debCol == 0 || ((gauche) && (debCol+2 != NBRE_COLONNE-1)))){
		grille[i][debCol] = VAL_TEST;
		grille[i][debCol+1] = VAL_TEST;
		grille[i][debCol+2] = VAL_TEST;
		grille[i][debCol+3] = VAL_TEST;
		/*if(debCol != 0){
		    grille[i][debCol-1] = VAL_TEST;
		}*/
	    }
	    else{
		grille[i][debCol-1] = VAL_TEST;
		grille[i][debCol] = VAL_TEST;
		grille[i][debCol+1] = VAL_TEST;
		grille[i][debCol+2] = VAL_TEST;
		/*if(debCol!=NBRE_COLONNE-1){
		    grille[i][debCol+1] = VAL_TEST;
		}*/
	    }
	}
	/*if((debCol!=0) && (debCol != NBRE_COLONNE-1)){
	    if(!gauche){
		grille[lig][debCol-1] = VAL_TEST;
	    }
	    else{
		grille[lig][debCol+1] = VAL_TEST;
	    }
	}*/

    }

    printf("result : \n");
    affGrille(grille);
    printf("sorti almostGainEnLigne\n");
}

/*
 * b = true <==> avant
 * */
void almostGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player, bool avant){
    unsigned int i;

    grille[lig][debCol] = player;
    grille[lig+1][debCol+1] = player;
    grille[lig+2][debCol+2] = player;

    if(avant){
	for(i=0; i<lig; i++){
	    if(i<lig-1){
		grille[i][debCol-1] = VAL_TEST;
	    }
	    grille[i][debCol] = VAL_TEST;
	    grille[i][debCol+1] = VAL_TEST;
	    grille[i][debCol+2] = VAL_TEST;
	}
	grille[lig][debCol+1] = VAL_TEST;
	grille[lig][debCol+2] = VAL_TEST;
	grille[lig+1][debCol+2] = VAL_TEST;
    }
    else{					 //apres
	for(i=0; i<lig; i++){
	    grille[i][debCol] = VAL_TEST;
	    grille[i][debCol+1] = VAL_TEST;
	    grille[i][debCol+2] = VAL_TEST;
	    grille[i][debCol+3] = VAL_TEST;
	}
	if((lig == 1) && (debCol != 0)){
	    grille[0][debCol-1] = VAL_TEST;
	}
	//affGrille(grille);
	grille[lig][debCol+1] = VAL_TEST;
	grille[lig][debCol+2] = VAL_TEST;
	grille[lig][debCol+3] = VAL_TEST;

	grille[lig+1][debCol+2] = VAL_TEST;
	grille[lig+1][debCol+3] = VAL_TEST;

	grille[lig+2][debCol+3] = VAL_TEST;
	/*affGrille(grille);
	nbreLigneSaute(5);*/
    }
}

void almostGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol, valCaseGrille player, bool gauche){
    unsigned int i;

    grille[lig][debCol] = player;
    grille[lig+1][debCol-1] = player;
    grille[lig+2][debCol-2] = player;

    if(gauche){
	for(i=0; i<lig; i++){
	    grille[i][debCol-3] = VAL_TEST;
	    grille[i][debCol-2] = VAL_TEST;
	    grille[i][debCol-1] = VAL_TEST;
	    grille[i][debCol] = VAL_TEST;
	}
	if((lig==1) && (debCol!=NBRE_COLONNE-1)){
	    grille[0][debCol+1] = VAL_TEST;
	}
	grille[lig][debCol-1] = VAL_TEST;
	grille[lig][debCol-2] = VAL_TEST;
	grille[lig+1][debCol-2] = VAL_TEST;

	grille[lig][debCol-3] = VAL_TEST;
	grille[lig+1][debCol-3] = VAL_TEST;

	grille[lig+2][debCol-3] = VAL_TEST;
    }
    else{			//apres
	for(i=0; i<lig; i++){
	    if(i<lig-1){
		grille[i][debCol+1] = VAL_TEST;
	    }
	    grille[i][debCol] = VAL_TEST;
	    grille[i][debCol-1] = VAL_TEST;
	    grille[i][debCol-2] = VAL_TEST;
	}
	grille[lig][debCol-1] = VAL_TEST;
	grille[lig][debCol-2] = VAL_TEST;

	grille[lig+1][debCol-2] = VAL_TEST;
	//affGrille(grille);
    }
}

/* NO GAIN */
/*void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col){
    almostGainEnCol(grille, debLig, col);
    unsigned int has = rand()%(debLig+3+1- debLig)+debLig;
    grille[has][col] = VAL_TEST;
}

void noGainEnLigne(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnLigne(grille, lig, debCol);
    unsigned int has = rand()%(debCol+3+1- debCol)+debCol;
    grille[lig][has] = VAL_TEST;
}

void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol+has] = VAL_TEST;
}

void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int lig, unsigned int debCol){
    almostGainEnDiagonaleDroite(grille, lig, debCol);
    unsigned int has = rand()%(4- 0)+0;
    grille[lig+has][debCol-has] = VAL_TEST;
}*/
