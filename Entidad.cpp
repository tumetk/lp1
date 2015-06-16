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

void Entidad::setPosX(int posx){
	this->posx = posx;
}

void Entidad::setPoxY(int posy){
	this->posy = posy
}

void Entidad::setMaxVida(int maxVida){
	this->maxVida = maxVida;
}

void Entidad::setNombre(char *nombre){
	char *new_nombre = new char[strlen(nombre)+1];
	strcpy(new_nombre,nombre);
	this->nombre = new_nombre;
}

char *Entidad::getNombre(){
	return this->nombre;
}

int  Entidad::getPosX(){
	return this->posx;
}

int  Entidad::getPosY(){
	return this->posy;
}

int  Entidad::getMaxVida(){
	return this->maxVida;
}

void Entidad::move(int posx,int posy){
	this->posx = this->posx + posx;
	this->posy = this->posy + posy;
}

void Entidad::setNivel(int nivel){
	this->nivel = nivel;
}

int Entidad::getNivel(){
	return this->nivel;
}

Entidad::Entidad(char *nombre, int maxVida){
	this->posx = 0 ;
	this->posY = 0 ;
	this->nivel = 1 ;
	this->nombre = new char[strlen(nombre)+1];
	strcpy(this->nombre,nombre);
	this->maxVida = maxVida ;
	this->misArtefactos = new Saco;
}

Entidad::~Entidad(){
	char *nombre = this->nombre;
	delete[] nombre;
	delete this;
}

void Entidad::agregarArtefacto(Artefacto objeto){
		this->saco->push(objeto);
}

void Entidad::setVidaActual(int vida){
	this->vidaActual = vida;
}

int Entidad::getVidaActual (){
	return this->vidaActual;
}