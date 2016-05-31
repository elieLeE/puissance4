#include "menus.h"

menuStart choixMenuStart(){
    int choix = -1;
    printf("%d : Player Vs Player\n", PLAYER_VS_PLAYER);
    printf("%d : Player Vs Computer\n", PLAYER_VS_COMPUTER);
    printf("%d : Options\n", OPTIONS);
    printf("%d : Quitter\n", QUITTER_START);

    int err =  lectureSecuriseInt(&choix);
    while((err != 0) || ((choix < 0) || (choix >= nbreEnumMenu()))){
	printf("Veuillez recommencer\n");
	printf("choix : %d\n", choix);
	err =  lectureSecuriseInt(&choix);
    }
    printf("\n");
    return (menuStart)choix;
}

menuOptions choixMenuOptions(){
    int choix = -1;

    printf("Menu Options : \n");
    printf("%d : Changer le niveau de l'IA\n", SET_LEVEL);
    printf("%d : Quitter\n", QUITTER_OPTS);

    int err =  lectureSecuriseInt(&choix);
    while((err != 0) || ((choix < 0) || (choix >= nbreEnumOptions()))){
	printf("Veuillez recommencer\n");
	err =  lectureSecuriseInt(&choix);
    }
    printf("\n");
    return (menuOptions)choix;
}

