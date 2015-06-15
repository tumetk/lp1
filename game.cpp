#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
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
#include "interfaz.h"

using namespace std;
Game::Game(){
    this->dibujador       = new Dibujador(5,5);
    this->jugador         = NULL;
    this->laberintoActual = NULL;
    
    this->listaLaberintos = new Laberinto[1];
    
    GestorLaberinto gestor = new GestorLaberinto;
    this->listaLaberintos[0] = gestor->crear();
    
    this->listaartefactos = new Artefacto[3];
    this->listamonstruos  = new Monstruo[3];
    this->number          = 1;
    printf("tume se la come");
    
}
void Game::start(){
    system("cls");
    printf("hola");
    int x = 0 ;
    
    
    
    do{
        
    }while (x == 0);
}

Game::~Game(){
    delete this;
}