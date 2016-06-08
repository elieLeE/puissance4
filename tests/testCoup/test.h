#ifndef _TEST_EVAL_TEST_H_
#define _TEST_EVAL_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <libcmine.h>
#include "fTest.h"
#include "../../src/spec/enum.h"
#include "../../src/spec/define.h"
#include "../../src/donnees/gestionGrille.h"
#include "../../src/game/gestionCoup.h"
#include "../../src/donnees/evaluationGrille.h"
#include "../../src/game/gestionGame.h"
#include <assert.h>

void testValiditeCoup();
void testCoupComputerLigne();
void testCoupComputerCol();
void testCoupComputerDiagDroite();
void testCoupComputerDiagGauche();

void testSpec();

#endif
