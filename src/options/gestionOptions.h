#ifndef _OPTIONS_GESTION_OPTIONS_H_
#define _OPTIONS_GESTION_OPTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <libcmine.h>
#include "../spec/enum.h"
#include "../aff/menus.h"

typedef struct structOptions structOptions;
struct structOptions{
    unsigned int niveauIA;
};

void gestionOptions(void);
structOptions* getOptions(void);
void initOptions(void);
void setNiveauIA(int level);

#endif
