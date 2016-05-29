#include "testAff.h"

void test1(){
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    initGrille(grille);
    affGrille(grille);
    liberationTab2D((void**)grille, NBRE_RANGE);
}
    
void test2(){
    printf("\n");
    valCaseGrille **grille = (valCaseGrille**)allocTab2D(NBRE_RANGE, NBRE_COLONNE, sizeof(**grille));
    remplissageAleatoire(grille);
    affGrille(grille);
    liberationTab2D((void**)grille, NBRE_RANGE);
}
    
