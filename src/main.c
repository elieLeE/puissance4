#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <libcmine.h>
#include "spec/enum.h"
#include "aff/menus.h"
#include "game/gestionGame.h"
#include "options/gestionOptions.h"

int main(){

    srand(time(NULL));	//tirage au sort joueur qui commence
    bool b;
    int reStart = -1, err;
    initOptions();
    printf("options.niveauIA : %d\n", getOptions()->niveauIA);

    do{
	b = true;
	switch(choixMenuStart()){
	    case PLAYER_VS_PLAYER:
		game(PLAYER_VS_PLAYER);
		break;

	    case PLAYER_VS_COMPUTER:
		game(PLAYER_VS_COMPUTER);
		break;

	    case OPTIONS:
		gestionOptions();
		break;

	    case QUITTER_START:
		b = false;
		break;
	}
	if(b){
	    printf("Souhaitez-vous recommencer ?\nentrez 0 pour non et 1 pour oui\n");
	    reStart = -1;
	    while((err != 0) || ((reStart!=0) && (reStart != 1))){
		err = lectureSecuriseInt(&reStart);
	    }
	}
    }while(b && (reStart!=0));

    return 0;
}

