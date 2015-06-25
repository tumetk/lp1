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



Artefacto* Avatar::interaccion(Monstruo *enemigo,char accion){

    int attack = rand() %100 +1;
    if (accion == 'A'){
        enemigo->setVidaActual(enemigo->getVidaActual()-this->baseAttack);
        if (enemigo->getVidaActual()== 0){
            int exp_gain = enemigo->getExpGain();
            
            this->setExpActual(exp_gain);
            Saco *mi_saco = enemigo->getMisArtefactos();
            
            int tamano = mi_saco->getTamano();
            int elegido = rand()%tamano+1;
            Artefacto* premio = mi_saco->getElemento(elegido);
            this->agregarArtefacto(premio);
            return premio;
        }else{
            return NULL;
        }
    }else if (accion == 'D'){
        if (attack<= enemigo->getProbAttack()){
            this->RecibeDano(enemigo->getBaseAttack());
            return NULL;
        }
    }
	
}
Avatar::Avatar(char *nombre ,int maxVida,int tipo){
        this->setPosX(0) ;
	this->setPoxY(0) ;
	this->setNivel(1) ;
	this->setNombre(nombre);
	this->setMaxVida(maxVida) ;
	this->newBag(tipo);
	this->expActual=0;
	this->expNextLevel=100;
	this->estado=1;
	this->totalExpNextLevel=100;
	this->baseAttack= 10;
}
Avatar::~Avatar(){
	int expActual_destr= this->expActual;
	int expNextLevel_destr= this->expNextLevel;
	int estado_destr= this->estado_destr;
	int totalExpNextLevel_destr=this->totalExpNextLevel;
	int baseAttack_destr=this->baseAttack;
    Arma* armaequipada_destr= this->armaequipada;
    Armadura* armaduraequipada_destr=this->armaduraequipada;
    delete expActual_destr;
    delete expNextLevel_destr;
    delete estado_destr;
    delete totalExpNextLevel_destr;
    delete baseAttack_destr;
    delete armaduraequipada_destr;
    delete armaequipada_destr;
}
void Avatar::equiparArma(class Arma* new_weapon){
    Saco *saco_actual = this->getMisArtefactos();
    Arma *old_weapon = this->armaequipada;
    this->armaequipada = new_weapon;
    saco_actual->push(old_weapon);
}
void Avatar::equiparArmadura(class Armadura* new_armor){
    Saco *saco_actual = this->getMisArtefactos();
    Armadura *old_armor = this->armaduraequipada;
    this->armaduraequipada = new_armor;
    saco_actual->push(old_armor);
}
void Avatar::setArmadura( class Armadura * armor){
    this->armaduraequipada = armor;
}
void Avatar::setArma(class Arma * weapon){
    this->armaequipada = weapon;
}
Arma* Avatar::getArma(){
    return this->armaequipada;
}
Armadura* Avatar::getArmadura(){
    return this->armaduraequipada;
}