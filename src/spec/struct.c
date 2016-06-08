#include "struct.h"

bool bestEval(evalStruct const * const s1, evalStruct const * const s2){
    return (s1->eval > s2->eval) || ((s1->eval == s2->eval) && (s1->prof < s2->prof));
}

bool sameEval(evalStruct const * const s1, evalStruct const * const s2){
    return ((s2->eval == s1->eval) && (s1->prof == s2->prof));
}
