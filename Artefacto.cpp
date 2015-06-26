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

void Artefacto::usar(Avatar*&){
    
}

void Artefacto::setNombre(char*nombre){
     char *new_nombre = new char[strlen(nombre)+1];
    strcpy(new_nombre,nombre);
    this->nombre = new_nombre;
}

char *Artefacto::getNombre(){
    return this->nombre;
}
Artefacto::~Artefacto(){
	char *nombre_destr = this->nombre;
	int tipo_destr = this->tipo;
	delete []nombre_destr;
	
}
int Artefacto::getTipo(){
    return this->tipo;
}
void Artefacto::setTipo(int tipo){
    this->tipo = tipo;
}