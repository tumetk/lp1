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

Celda::Celda(){
    this->tipo = -1;
}
Celda::Celda(int tipo){
    this->tipo = tipo;
}
void Celda::setTipo(int tipo){
    this->tipo = tipo;
}
int Celda::getTipo(){
    return this->tipo;
}
Celda::~Celda(){
    delete this->tipo;
}
