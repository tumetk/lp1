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


using namespace std;
Game::Game(){
    this->dibujador       = new Dibujador(5,5);
    this->jugador         = NULL;
    this->laberintoActual = NULL;
    
    
    
    GestorLaberinto gestor = new GestorLaberinto;
    this->listaLaberintos = gestor->crear();
    
    this->listaartefactos = new Artefacto[3];
    this->listamonstruos  = new Monstruo[3];
    this->number          = 1;
    printf("tume se la come");
    
}
void Game::start(){
    /*system("cls");
    printf("hola");
    int x = 0 ;
    
     
    
    do{
        
    }while (x == 0);*/
    system("cls");    
    gotoxy(10,1);
    printf("Presiona ESC para regresar");    
    gotoxy(10,5);        
    printf("Laberinto");
    gotoxy(10,25);
    printf("Acciones");    
    gotoxy(60,5);
    printf("Avatar");
    gotoxy(60,10);
    printf("Zona de luchas");
    gotoxy(60,25);
    printf("Opciones");
    gotoxy(60,28);
    printf("Atacar");
    gotoxy(60,29);
    printf("Curar");
    gotoxy(60,30);
    printf("Rendir");
    
    for(int i=10; i<80; i++){
        gotoxy(i,4);
        printf("=");
        gotoxy(i,6);
        printf("=");
        if(i>58){
            gotoxy(i,9);
            printf("=");
            gotoxy(i,11);
            printf("=");
        }
        gotoxy(i,24);
        printf("=");
        gotoxy(i,26);
        printf("=");
    }
    for(int i=4; i<40; i++){
        gotoxy(58,i);
        printf("=");
    }            
    
    gotoxy(10,28);    
    char tecla = getche();    
    if(tecla == 'A'){        
        char key ;
        do{
            key = getch();
        }while(key != '\r');
        gotoxy(10,30);
        printf("Atacaste");        
    }
    else if(tecla == 'B'){              
        char key ;
        do{
            key = getch();
        }while(key != '\r');
        gotoxy(10,30);
        printf("Te curaste");
    }
    else if(tecla == 'C'){        
        char key ;
        do{
            key = getch();
        }while(key != '\r');
        gotoxy(10,30);
        printf("Te rendiste");
    }
    char key ;
    do{
        key = getch();
    }while(key != 27);
}

Game::~Game(){
    delete this;
}