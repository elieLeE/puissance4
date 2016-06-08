#ifndef _SPEC_DEFINE_H_
#define _SPEC_DEFINE_H_

#include <stdio.h>
#include <stdlib.h>
#include "enum.h"

#define DEBUG 0

#define NBRE_COLONNE 7
#define NBRE_RANGE 6
#define ALIGNEMENT_GAIN 4

#define PLAYER_1_WIN -10000
#define PLAYER_2_WIN 10000
#define DRAW_GAME 100000

int enumToDefine(valCaseGrille val);

#endif
