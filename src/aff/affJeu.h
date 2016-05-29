#ifndef _AFF_AFFJEU_H_
#define _AFF_AFFJEU_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libcmine.h>
#include "../spec/enum.h"
#include "../spec/define.h"

void affJoueurToPlay(const bool b);
void affResultatGame(const int evalFinal);
//void affGrille(const valCaseGrille **const tab);
void affGrille(valCaseGrille **tab);
char* affCase(const valCaseGrille c);

#endif
