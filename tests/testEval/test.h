#ifndef _TEST_EVAL_TEST_H_
#define _TEST_EVAL_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <libcmine.h>
#include "../../src/spec/enum.h"
#include "../../src/spec/define.h"
#include "assert.h"
#include "../../src/donnees/gestionGrille.h"
#include "../../src/donnees/evaluationGrille.h"
#include "fTest.h"
#include "../../src/aff/affJeu.h"

void testEvaluationColonne();
void testEvaluationLigne();
void testEvaluationDiagonale();
void testDraw();

#endif
