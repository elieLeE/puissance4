#include "evaluationGrille.h"

/*
 * on compte les jetons dans la gille en multipliant par 4 au centre, 
 * 3 autour du centre, ...
 * */
//int evalGrille(const valCaseGrille ** const grille){
int evalGrille(valCaseGrille ** grille){
    //printf("evlauation\n");
    int evalPlayer1 = evalGrillePlayer(grille, PLAYER_1);
    int evalPlayer2 = evalGrillePlayer(grille, PLAYER_2);
    int const marge = 1000;

    if(evalPlayer1 >= PLAYER_1_WIN-marge){
	return PLAYER_1_WIN;
    }
    else if(evalPlayer2 <= PLAYER_2_WIN+marge){	//on realise des sommes de nombre principalement >=0 => 1000 >> max valGrille (si la partie n'est pas finie
	return PLAYER_2_WIN;
    }
    else if(drawGame(grille[NBRE_RANGE-1])){
	return DRAW_GAME;
    }
    else{
	return (evalPlayer1 - evalPlayer2);
    }
}

//int evalGrillePlayer(const valCaseGrille **const grille, const valCaseGrille player){
int evalGrillePlayer(valCaseGrille ** grille, valCaseGrille player){
    return evalGrillePlayerCol(grille, player) + evalGrillePlayerLig(grille, player) + evalGrilleDiagDroite(grille, player) + evalGrilleDiagGauche(grille, player);
}

//int evalGrillePlayerCol(const valCaseGrille** const grille, const valCaseGrille player){
int evalGrillePlayerCol(valCaseGrille**  grille,  valCaseGrille player){
    unsigned int j;
    int sum = 0;

    for(j=0; j<NBRE_COLONNE; j++){
	sum += evalPlayerCol(grille, player, j);
    }
    return sum;
}

//int evalPlayerCol(const valCaseGrille** const grille, const valCaseGrille player, const unsigned int col){
/*int evalPlayerCol(valCaseGrille** grille, valCaseGrille player, unsigned int col){
    unsigned int i;
    unsigned int compt = 0, compt2 = 0;
    bool b, first;

    for(i=0; (i<NBRE_RANGE) && (grille[i][col] != NO_PLAY); i++){
	if(grille[i][col] == PLAYER_1){
	    if(b){
		compt++;
	    }
	    else{
		compt = 1;
	    }
	    b = true;
	    compt2++;
	}
	else{
	    if(!b){
		compt++;
	    }
	    else{
		compt = 1;
	    }
	    b = false;
	    compt--;
	}
	if(compt == ALIGNEMENT_GAIN){
	    return enumToDefine(b?PLAYER_1:PLAYER_2);
	}
    }
    int result = compt2*(4-((int)fabs(((int)col)-3)));
    return result;
}*/

int evalPlayerCol(valCaseGrille**  grille, valCaseGrille player, unsigned int col){
    unsigned int i;
    unsigned int compt = 0, compt2 = 0;

    for(i=0; i<NBRE_RANGE; i++){
	if(grille[i][col] == player){
	    compt++;
	    compt2++;
	    if(compt == ALIGNEMENT_GAIN){
		return enumToDefine(player);
	    }
	}
	else{
	    compt = 0;
	}
    }
    int result = compt2*(4-((int)fabs(((int)col)-3)));
    return result;
}

//int evalGrillePlayerLig(const valCaseGrille** const grille, const valCaseGrille player){
int evalGrillePlayerLig(valCaseGrille** grille, valCaseGrille player){
    unsigned int i;
    int sum = 0;

    for(i=0; i<NBRE_RANGE; i++){
	//printf("ligne i : %d\n", evalPlayerLigne(grille[i], player));
	sum += evalPlayerLigne(grille[i], player);
    }
    return sum;
}

//int evalPlayerLigne(const valCaseGrille* const grille, const valCaseGrille player){
/*int evalPlayerLigne(valCaseGrille* grille, valCaseGrille player){
    unsigned int i;
    unsigned int compt = 0;

    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[i] == player){
	    compt++;
	    if(compt == ALIGNEMENT_GAIN){
		return enumToDefine(player);
	    }
	}
	else{
	    compt = 0;
	}
    }
    return 0;
}*/

int evalPlayerLigne(valCaseGrille* grille, valCaseGrille player){
    unsigned int i;
    unsigned int compt = 0;

    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[i] == player){
	    compt++;
	    if(compt == ALIGNEMENT_GAIN){
		return enumToDefine(player);
	    }
	}
	else{
	    compt = 0;
	}
    }
    return 0;
}

//int evalGrilleDiagDroite(const valCaseGrille** const grille, const valCaseGrille player){
int evalGrilleDiagDroite(valCaseGrille** grille, valCaseGrille player){
    unsigned int i, j, k;

    for(i=0; i<3; i++){
	for(j=0; j<4; j++){
	    for(k=0; (k<ALIGNEMENT_GAIN) && (grille[i+k][j+k]==player); k++);
	    if(k==ALIGNEMENT_GAIN){
		return enumToDefine(player);
	    }
	}
    }
    return 0;
}

//int evalGrilleDiagGauche(const valCaseGrille** const grille, const valCaseGrille player){
int evalGrilleDiagGauche(valCaseGrille** grille, valCaseGrille player){
    unsigned int i, j, k;

    for(i=0; i<3; i++){
	for(j=3; j<NBRE_COLONNE; j++){
	    for(k=0; (k<ALIGNEMENT_GAIN) && (grille[i+k][j-k]==player); k++);
	    if(k==ALIGNEMENT_GAIN){
		return enumToDefine(player);
	    }
	}
    }
    return 0;
}

//bool drawGame(const valCaseGrille* const grille){
bool drawGame(valCaseGrille* grille){
    unsigned int i;
    for(i=0; i<NBRE_COLONNE; i++){
	if(grille[i] == NO_PLAY){
	    return false;
	}
    }
    return true;
}
