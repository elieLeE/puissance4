#include "test.h"
#include <time.h>
#include <string.h>

int main(){
    srand(time(NULL));

    testValiditeCoup();
    testCoupComputerLigne();

    return 0;
}
