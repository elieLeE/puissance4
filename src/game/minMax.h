#ifndef _GAME_MIN_MAX_H_
#define _GAME_MIN_MAX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../spec/enum.h"
#include "../spec/struct.h"
#include "../donnees/evaluationGrille.h"
#include "../game/gestionGame.h"
#include "../game/gestionCoup.h"

evalStruct evalMax(valCaseGrille **grille, const unsigned int p);
evalStruct evalMin(valCaseGrille **grille, const unsigned int p);
/*unsigned int evalMax(valCaseGrille **grille, const unsigned int p);
unsigned int evalMin(valCaseGrille **grille, const unsigned int p);*/

unsigned int minMax(valCaseGrille **grille, const unsigned int p);
bool betterCoup(const int minOrMaxEval, const int eval, const bool modeMax);

#endif
