#ifndef _TEST_EVAL_FTEST_H_
#define _TEST_EVAL_FTEST_H_

#include <stdio.h>
#include <stdlib.h>
#include "../../src/spec/enum.h"
#include "../../src/spec/define.h"
#include "assert.h"

void gainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void gainEnLigne(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void gainEnDiagonaleDroite(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void gainEnDiagonaleGauche(valCaseGrille **grille, unsigned int debLig, unsigned int col);

void noGainEnCol(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void noGainEnLigne(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void noGainEnDiagonaleDroite(valCaseGrille **grille, unsigned int debLig, unsigned int col);
void noGainEnDiagonaleGauche(valCaseGrille **grille, unsigned int debLig, unsigned int col);

void remplissageToDrawGame(valCaseGrille** grille);

#endif
