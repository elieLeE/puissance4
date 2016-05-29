#include "define.h"

int enumToDefine(valCaseGrille val){
    if(val == PLAYER_1){
	return PLAYER_1_WIN;
    }
    return PLAYER_2_WIN;
}
