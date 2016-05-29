#include "menus.h"

menuStart choixMenuStart(){
    int choix = -1;
    printf("0 : Player Vs Player\n");
    printf("1 : Player Vs Computer\n");
    printf("2 : Options\n");
    printf("3 : Quitter\n");

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
    printf("0 : changer le niveau de l'IA\n");
    int err =  lectureSecuriseInt(&choix);
    while((err != 0) || ((choix < 0) || (choix >= nbreEnumOptions()))){
	printf("Veuillez recommencer\n");
	err =  lectureSecuriseInt(&choix);
    }
    printf("\n");
    return (menuOptions)choix;
}

