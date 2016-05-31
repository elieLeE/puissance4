#include "test.h"
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL));

    testEvaluationColonne();
    testEvaluationLigne();
    testEvaluationDiagonaleDroite();
    testEvaluationDiagonaleGauche();
    testDraw();

    testSpec();

    return 0;
}
