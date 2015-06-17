#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include "interfaz.h"
#include "game.h"
#include "Arma.h"
#include "Armadura.h"
#include "Artefacto.h"
#include "Avatar.h"
#include "Celda.h"
#include "Dibujador.h"
#include "Entidad.h"
#include "GestorLaberinto.h"
#include "Laberinto.h"
#include "Monstruo.h"
#include "PocionCuracion.h"
#include "Saco.h"
#include "ejemplo.h"
using namespace std;

void Monstruo::setExpGain(int exp){
	this->expPrize = exp;
}
int getExpGain(){
	return this->expPrize;
}
int getProbAttack(){
	return this->probAttack;
}
void setProbAttack(int prob){
	this->probAttack = prob;
}
Monstruo::Monstruo(int baseAttack,int expPrize,int prob){
	this->baseAttack= baseAttack;
	this->expPrize= expPrize;
	this->probAttack = prob;
}
Monstruo::~Monstruo(){
	delete this;
}
void Monstruo::setBaseAttack(int attack){
	this->baseAttack = attack;
}
int  Monstruo::getBaseAttack(){
	return this->baseAttack;
}