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
Monstruo::Monstruo(char*nombre,int vida,int attack,int probattack,int expgain){
    this->baseAttack = attack;
    this->expPrize = expgain;
    this->probAttack = probattack;
    this->setNombre(nombre);
    this->setMaxVida(vida);
    this->setVidaActual(vida);
    this->newBag(5);
    
}
void Monstruo::setExpGain(int exp){
	this->expPrize = exp;
}
int Monstruo::getExpGain(){
	return this->expPrize;
}
int Monstruo::getProbAttack(){
	return this->probAttack;
}
void Monstruo::setProbAttack(int prob){
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