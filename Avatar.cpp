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

void Avatar::setExpNextLevel(int exp){
	this->expNextLevel = exp;
}
int Avatar::getExpNextLevel(){
	return this->expNextLevel;
}
void Avatar::setExpActual(int exp_gain){
	if (this->expNextLevel - exp_gain <= 0){
		int resta = (this->expNextLevel - exp_gain)*-1;
		this->expActual = resta;
		this->totalExpNextLevel = this->totalExpNextLevel + this->totalExpNextLevel/2;
		this->expNextLevel = this->totalExpNextLevel - resta;
		this->nivel = this->nivel +1;
		this->baseAttack = this->baseAttack + 10*this->nivel;

	}else{
		this->expNextLevel = this->expNextLevel - exp_gain;
	}
}
int Avatar::getExpActual(){
	return this->expActual;
}
void Avatar::RecibeDano(int dano){
	if (this->vidaActual - dano <= 0){
		this->vidaActual = 0 ;
		this->estado = 0 
	}else{
		this->vidaActual = this->vidaActual - dano;
	}
}
void Avatar::setTotalExpNextLevel(int exp){
	this->totalExpNextLevel = exp;
}
int Avatar::getTotalExpNextLevel(){
	return this->totalExpNextLevel;
}
void Avatar::setBaseAttack(int attack){
	this->baseAttack = attack;
}
int  Avatar::getBaseAttack(){
	return this->baseAttack;
}

void Avatar::interaccion(Monstruo enemigo){
	int attack = rand() %100 +1;
	if (attack<= enemigo.getProbAttack()){
		this->RecibeDano(enemigo.getBaseAttacK());	
	}
}