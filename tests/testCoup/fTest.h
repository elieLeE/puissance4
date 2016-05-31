#ifndef _TEST_EVAL_FTEST_H_
#define _TEST_EVAL_FTEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../src/spec/enum.h"
#include "../../src/spec/define.h"
#include "../../src/aff/affJeu.h"
#include "../../src/game/gestionCoup.h"
#include "assert.h"

void affDebug(valCaseGrille **grille, valCaseGrille player, unsigned int expectedMove);

void almostGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);
void almostGainEnLigne(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille, bool);
void almostGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille, bool);
void almostGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player, bool avant);

void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void noGainEnLigne(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int debLig, unsigned int col);

#endif
