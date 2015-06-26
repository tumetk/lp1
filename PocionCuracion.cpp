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

PocionCuracion::PocionCuracion(char* nombre, int cantidad){
    this->puntosVida = cantidad;
    this->setNombre(nombre);
}
void PocionCuracion::setPuntosVida(int vida){
    this->puntosVida = vida;
}
int PocionCuracion::getPuntosVida(){
    return this->puntosVida;
}
void PocionCuracion::usar(class Avatar& avatar){
    int vidaactual = avatar.getVidaActual();
    int nueva_vida = vidaactual + this->puntosVida;
    if (nueva_vida >= avatar.getMaxVida()){
        avatar.setVidaActual(avatar.getMaxVida());
    }else{
        avatar.setVidaActual(nueva_vida);
    }
}

PocionCuracion::~PocionCuracion(){
//    delete this->puntosVida;
}