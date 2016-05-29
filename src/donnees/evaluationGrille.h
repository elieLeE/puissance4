#ifndef _DONNEES_EVALUATION_GRILLE_H_
#define _DONNEES_EVALUATION_GRILLE_H_

#include <stdbool.h>
#include <math.h>
#include "../spec/define.h"
#include "../spec/enum.h"

int evalGrille(valCaseGrille **grille);
int evalGrillePlayer(valCaseGrille **grille, valCaseGrille player);
int evalGrillePlayerCol(valCaseGrille** grille, valCaseGrille player);
int evalPlayerCol(valCaseGrille** grille, valCaseGrille player, unsigned int col);
int evalGrillePlayerLig(valCaseGrille** grille, valCaseGrille player);
int evalPlayerLigne(valCaseGrille* grille, valCaseGrille player);
int evalGrilleDiagDroite(valCaseGrille** grille, valCaseGrille player);
int evalGrilleDiagGauche(valCaseGrille** grille, valCaseGrille player);

bool drawGame(valCaseGrille* grille);


//int evalGrille(const valCaseGrille ** const grille){
//int evalGrillePlayer(const valCaseGrille **const grille, const valCaseGrille player){
//int evalGrillePlayerCol(const valCaseGrille** const grille, const valCaseGrille player){
//int evalPlayerCol(const valCaseGrille** const grille, const valCaseGrille player, const unsigned int col){
//int evalGrillePlayerLig(const valCaseGrille** const grille, const valCaseGrille player){
//int evalPlayerLigne(const valCaseGrille* const grille, const valCaseGrille player){
//int evalGrilleDiagDroite(const valCaseGrille** const grille, const valCaseGrille player){
//int evalGrilleDiagGauche(const valCaseGrille** const grille, const valCaseGrille player){
//bool drawGame(const valCaseGrille* const grille){

#endif
