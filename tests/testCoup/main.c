#include "test.h"
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL));
    initOptions();

    testValiditeCoup();

    setNiveauIA(2);
    printf("profondeur : %d\n", getOptions()->niveauIA);
    testCoupComputerLigne();
    testCoupComputerCol();
    testCoupComputerDiagDroite();
    testCoupComputerDiagGauche();
    return 0;

    return 0;

    setNiveauIA(3);
    printf("profondeur : %d\n", getOptions()->niveauIA);
    testCoupComputerLigne();
    testCoupComputerCol();
    testCoupComputerDiagDroite();
    testCoupComputerDiagGauche();

    return 0;
}
