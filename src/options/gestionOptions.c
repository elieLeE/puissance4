#include "gestionOptions.h"

structOptions* getOptions(){
    static structOptions opt; 
    return &opt;
}

void gestionOptions(){
    switch(choixMenuOptions()){
	case SET_LEVEL:
	    setNiveauIA();
	    break;
    }
}

void initOptions(){
    structOptions *opt = getOptions();
    opt->niveauIA = 3;
}

/*
 * niveauMax => 10 (sinon trop lent)
 * */
void setNiveauIA(){
    int err = -1, level=-1;

    printf("entrez le nouveau niveau de l'IA (entre 0 et 10)\n");
    err = lectureSecuriseInt(&level);
    while((err!=0) || (level < 0) || (level > 10)){
	printf("Veuillez recommencer\n");
	err = lectureSecuriseInt(&level);
    }

    structOptions *opt = getOptions();
    opt->niveauIA = level;
}
