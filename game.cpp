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
    
    
    
    GestorDeLaberinto gestor(1);
    this->listaLaberintos = gestor.crear();
    
    this->listaartefactos = new Artefacto[3];
    this->listamonstruos  = new Monstruo[3];
    this->number          = 1;
    cout << "tume se la come";
    
}
void Game::start(){
    /*system("cls");
    printf("hola");
    int x = 0 ;
    
     
    
    do{
        
    }while (x == 0);*/
    system("cls");    
    gotoxy(10,1);
    cout << "Presiona ESC para regresar";    
    gotoxy(10,5);        
    cout << "Laberinto";
    this->listaLaberintos[0].printLaberinto(10,8); //por mientras.
    gotoxy(10,70);
    cout << "Acciones";    
    gotoxy(60,5);
    cout << "Avatar";
    gotoxy(60,10);
    cout << "Zona de luchas";
    gotoxy(60,25);
    cout << "Opciones";
    gotoxy(60,28);
    cout << "Atacar";
    gotoxy(60,29);
    cout << "Curar";
    gotoxy(60,30);
    cout << "Rendir";
    
    for(int i=10; i<80; i++){
        gotoxy(i,4);
        cout << "=";
        gotoxy(i,6);
        cout << "=";
        if(i>58){
            gotoxy(i,9);
            cout << "=";
            gotoxy(i,11);
            cout << "=";
        }
        gotoxy(i,69);
        cout << "=";
        gotoxy(i,71);
        cout << "=";
    }
    for(int i=4; i<70; i++){
        gotoxy(58,i);
        cout << "=";
    }            
    
    gotoxy(10,28);    
    char tecla = getche();    
    if(tecla == 'A'){        
        char key ;
        do{
            key = getch();
        }while(key != '\r');
        gotoxy(10,30);
        cout << "Atacaste";        
    }
    else if(tecla == 'B'){              
        char key ;
        do{
            key = getch();
        }while(key != '\r');
        gotoxy(10,30);
        cout << "Te curaste";
    }
    else if(tecla == 'C'){        
        char key ;
        do{
            key = getch();
        }while(key != '\r');
        gotoxy(10,30);
        cout << "Te rendiste";
    }
    char key ;
    do{
        key = getch();
    }while(key != 27);
}

Game::~Game(){
    delete this;
}