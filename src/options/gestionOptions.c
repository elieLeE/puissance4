#include "gestionOptions.h"

structOptions* getOptions(void){
    static structOptions opt; 
    return &opt;
}

void gestionOptions(void){
    switch(choixMenuOptions()){
	case SET_LEVEL:
	    setNiveauIA(-1);
	    break;

	case QUITTER_OPTS:
	    break;
    }
}

void initOptions(void){
    structOptions *opt = getOptions();
    opt->niveauIA = 2;
}

/*
 * niveauMax => 10 (sinon trop lent)
 * */
void setNiveauIA(int level){
    structOptions *opt = getOptions();
    int err = -1;

    if(level<0){
	printf("entrez le nouveau niveau de l'IA (entre 0 et 10)\n");
	err = lectureSecuriseInt(&level);
	while((err!=0) || (level < 0) || (level > 10)){
	    printf("Veuillez recommencer\n");
	    err = lectureSecuriseInt(&level);
	}
	opt->niveauIA = level;
    }
    opt->niveauIA = level;
}
