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

Arma::Arma(int danhomin,int danhomax,char* nombre){
    this->danhoMax = danhomax;
    this->danhoMin = danhomin;
    char *new_nombre = new char[strlen(nombre)+1];
    strcpy(new_nombre,nombre);
    this->nombre = new_nombre;
}
void Arma::setDanhoMin(int danho){
    this->danhoMin = danho;
}
void Arma::setDanhoMax(int danho){
    this->danhoMax = danho;
}
void Arma::setNombre(char* nombre){
    
    char *new_nombre = new char[strlen(nombre)+1];
    strcpy(new_nombre,nombre);
    this->nombre = new_nombre;
    
}
int Arma::getDanhoMin(){
    return this->danhoMin;
}
int Arma::getDanhoMax(){
    return this->danhoMax;
}
char* Arma::getNombre(){
    return this->nombre;
}
void Arma::usar(class Avatar& avatar){
    avatar.equiparArma(this);
}
