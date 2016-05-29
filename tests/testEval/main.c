#include "test.h"
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL));

    testEvaluationColonne();
    testEvaluationLigne();
    testEvaluationDiagonale();
    testDraw();

    return 0;
}
