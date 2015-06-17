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
		this->setNivel(this->getNivel()+1) ;
		this->baseAttack = this->baseAttack + 10*this->getNivel();

	}else{
		this->expNextLevel = this->expNextLevel - exp_gain;
	}
}
int Avatar::getExpActual(){
	return this->expActual;
}
void Avatar::RecibeDano(int dano){
	if (this->getVidaActual() - dano <= 0){
		this->setVidaActual(0)  ;
		this->estado = 0 ;
	}else{
		this->setVidaActual(this->getVidaActual()- dano);
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



Artefacto* Avatar::interaccion(Monstruo enemigo,char accion){

    int attack = rand() %100 +1;
    if (accion == 'A'){
        enemigo.setVidaActual(enemigo.getVidaActual()-this->baseAttack);
        if (enemigo.getVidaActual()== 0){
            int exp_gain = enemigo.getExpGain();
            
            this->setExpActual(exp_gain);
            Saco *mi_saco = enemigo.getMisArtefactos();
            
            int tamano = mi_saco->getTamano();
            int elegido = rand()%tamano+1;
            Artefacto* premio = mi_saco->getElemento(elegido);
            this->agregarArtefacto(premio);
            return premio;
        }else{
            return NULL;
        }
    }else if (accion == 'D'){
        if (attack<= enemigo.getProbAttack()){
            this->RecibeDano(enemigo.getBaseAttack());
            return NULL;
        }
    }
	
}
Avatar::Avatar(){
	this->expActual=0;
	this->expNextLevel=100;
	this->estado=1;
	this->totalExpNextLevel=100;
	this->baseAttack= 10;
}
Avatar::~Avatar(){
	delete this;
}