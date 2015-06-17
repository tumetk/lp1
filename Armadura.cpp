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

void Armadura::setNombre(char* nombre){
  this->nombre = new char[strlen(nombre)+1];
  strcpy(this->nombre,nombre);
}
void Armadura::usar(class Avatar& avatar){
    avatar.equiparArmadura();
}
void Armadura::setDefensa(int defensa){
    this->defensa = defensa;
}
int Armadura::getDefensa(){
    return this->defensa;
}
char *Armadura::getNombre(){
    return this->nombre;
}
