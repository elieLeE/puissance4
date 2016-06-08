#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct evalStruct evalStruct;
struct evalStruct{
    int eval;
    unsigned int prof;
};

bool bestEval(evalStruct const * const s1, evalStruct const * const s2);
bool sameEval(evalStruct const * const s1, evalStruct const * const s2);

#endif
