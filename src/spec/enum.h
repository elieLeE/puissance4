#ifndef _SPEC_ENUM_H_
#define _SPEC_ENUM_H_

typedef enum valCaseGrille valCaseGrille;
typedef enum menuStart menuStart;
typedef enum menuOptions menuOptions;
typedef enum valGrille valGrille;

//enum valGrille{PLAYER_1_WIN, PLAYER_2_WIN, DRAW_GAME, GAME_NOT_TERMINATED};
enum menuStart{PLAYER_VS_PLAYER, PLAYER_VS_COMPUTER, OPTIONS, QUITTER};
enum menuOptions{SET_LEVEL};

enum valCaseGrille{NO_PLAY, PLAYER_1, PLAYER_2};

int nbreEnumMenu();
int nbreEnumOptions();

#endif
