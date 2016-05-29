#ifndef _GAME_GESTION_GAME_H_
#define _GAME_GESTION_GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libcmine.h>
#include "../spec/enum.h"
#include "../spec/define.h"
#include "../donnees/gestionGrille.h"
#include "../donnees/evaluationGrille.h"
#include "../aff/affJeu.h"
#include "gestionCoup.h"

bool gameOver(const int eval);
void game(const menuStart modeGame);

#endif
