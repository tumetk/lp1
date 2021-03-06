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

Saco::Saco(int tipo){
    this->lista = new Artefacto*[100];
    this->tamano = 0;
    this->capacidad = 0;
    this->tipo = tipo;
    
}

int Saco::getTamano(){
    return this->tamano;
}

Artefacto *Saco::getElemento(int elemento){
    return this->lista[elemento];
}
int Saco::getTipo(){
    return this->tipo;
}
void Saco::setTipo(int tipo){
    
    this->tipo = tipo;
    
}

Saco::~Saco(){
    Artefacto** lista = this->lista;
    delete[] lista;
    delete this;
    
}
void Saco::setTamano(int tamano){
    this->tamano = tamano;
}
int Saco::getCapacidad(){
    return this->capacidad;
}
void Saco::setCapacidad(int capacidad){
    this->capacidad = capacidad;
}

int Saco::push(Artefacto* artefacto){
    int tamano = this->tamano;
    tamano++;
    if (this->capacidad >= tamano){
        this->lista[tamano] = artefacto;
        this->tamano += 1;
        return 1 ;
    }else {
        Artefacto **old_lista = this->lista;
        this->lista = new Artefacto*[this->capacidad + 10];
        for(int x = 0 ; x< this->capacidad;x++){
            this->lista[x] = old_lista[x];
        }
        this->lista[tamano] = artefacto;
        this->tamano += 1;
        return 1;
    }
}
