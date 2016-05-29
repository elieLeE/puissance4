#ifndef _DONNEES_GESTION_COUP_H_
#define _DONNEES_GESTION_COUP_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libcmine.h>
#include "../spec/enum.h"
#include "../spec/define.h"
#include "../options/gestionOptions.h"
#include "minMax.h"

unsigned int nextCoup(valCaseGrille **grille, bool b);
unsigned int nextCoupHuman(valCaseGrille* grille);
unsigned int nextCoupComputer(valCaseGrille **grille);

bool validiteCoup(const valCaseGrille * const grille, const int coup);
void addCoup(valCaseGrille ** const grille, const unsigned int coup, const unsigned int);
void removeCoup(valCaseGrille ** const grille, const unsigned int col);
void coupsPossibles(const valCaseGrille* const grille, bool *const tab); 


#endif
