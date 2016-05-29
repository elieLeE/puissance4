#ifndef _GAME_MIN_MAX_H_
#define _GAME_MIN_MAX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../spec/enum.h"
#include "../donnees/evaluationGrille.h"
#include "../game/gestionGame.h"
#include "../game/gestionCoup.h"

unsigned int minMax(valCaseGrille **grille, const unsigned int p, const bool modeMax);
bool betterCoup(const int minOrMaxEval, const int eval, const bool modeMax);

#endif
