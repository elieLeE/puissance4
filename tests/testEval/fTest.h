#ifndef _TEST_EVAL_FTEST_H_
#define _TEST_EVAL_FTEST_H_

#include <stdio.h>
#include <stdlib.h>
#include "../../src/spec/enum.h"
#include "../../src/spec/define.h"
#include "assert.h"

valCaseGrille hasPlayer();

void structSpec(valCaseGrille** grille, valCaseGrille player);

void gainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);
void gainEnLigne(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);
void gainEnDiagonaleDroite(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);
void gainEnDiagonaleGauche(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);

void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);
void noGainEnLigne(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);
void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);
void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int debLig, unsigned int col, valCaseGrille player);

void remplissageToDrawGame(valCaseGrille** grille);

#endif
