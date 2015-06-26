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
    this->setTipo(1);
    this->setNombre(nombre);
}
Arma::Arma(){
    
}
void Arma::setDanhoMin(int danho){
    this->danhoMin = danho;
}
void Arma::setDanhoMax(int danho){
    this->danhoMax = danho;
}

int Arma::getDanhoMin(){
    return this->danhoMin;
}
int Arma::getDanhoMax(){
    return this->danhoMax;
}

void Arma::usar(class Avatar*& avatar){
    avatar->equiparArma(this);
    cout<<"Equipaste "<<this->getNombre()<<endl;
}
Arma::~Arma(){
	int min_destr = this->danhoMin;
	int max_destr = this->danhoMax;

}