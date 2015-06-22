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
const int   CANTIDAD  = 3 ;
const int CANTIDAD_MONSTRUO = 10;
const int CANTIDAD_LABERINTOS =1;
using namespace std;
Artefacto **Game::levantarArtefactos(){
    ifstream lectura("artefactos.txt");
    
    Artefacto **new_lista = new Artefacto*[CANTIDAD];
    char tipo ;
    char nombre[100];
    int cantidad;
    int max_attack;
    int min_attack;
    for (int indice = 0 ;indice <CANTIDAD;indice++){
        lectura>>tipo;
            if( tipo =='P'){
                lectura>>nombre>>cantidad;
                
                PocionCuracion *new_pocion = new PocionCuracion(nombre,cantidad);
                new_lista[indice] = new_pocion;
                
            }else if (tipo == 'A'){
                lectura>>nombre>>cantidad;
                
                Armadura *new_armadura = new Armadura(nombre,cantidad);
                new_lista[indice] = new_armadura;
                
            }else if (tipo == 'W'){
                lectura>>nombre>>min_attack>>max_attack;
                
                Arma *new_arma = new Arma(min_attack,max_attack,nombre);
                new_lista[indice] = new_arma;
                
            }
    }
    
    return new_lista;
    
}
Monstruo **Game::levantarMonstruos(){
    ifstream lectura("monstruo.txt");
    Monstruo **new_lista = new Monstruo*[10];
    
    char nombre[100];
    int vida;
    int attack;
    int probattack;
    int expgain;
    for (int  indice= 0 ; indice <CANTIDAD_MONSTRUO;indice++){
        lectura>>nombre>>vida>>attack>>probattack>>expgain;
        Monstruo *new_monstruo = new Monstruo(nombre,vida,attack,probattack,expgain);
        new_lista[indice] = new_monstruo;
    }
    return new_lista;
    
}
Avatar* Game::crearJugador(){
    char nombre[100];
    cout<<"INGRESA EL NOMBRE DE TU PERSONAJE(MAXIMO 100 CARACTERES)"<<endl;
    cin>>nombre;
    return new Avatar(nombre,100,1);
}
Game::Game(){
    this->dibujador       = new Dibujador(5,5);
    
    
    GestorDeLaberinto gestor(CANTIDAD_LABERINTOS); //por mientras.
    this->listaartefactos = this->levantarArtefactos();
    this->listamonstruos = this->levantarMonstruos();
    this->listaLaberintos = gestor.crear();
    
    
    this->number          = 1;
    cout << "tume se la come";
    
}
void Game::historia(){
    printf("La historia comienza con penes luego llega un pene un dia y le dice a otro pene lo siguiente: pene.");
    char key ;
    do{
        key = getch();
    }while(key != '\r');
}
void Game::imprimirUI(){
    system("cls");    
    gotoxy(10,1);
    cout << "Presiona ESC para regresar";   
       gotoxy(10,30);
        cout << "Acciones";    
        gotoxy(41,5);
        cout << "Avatar";
        gotoxy(41,10);
        cout << "Zona de luchas";
        gotoxy(41,30);
        cout << "Opciones";
        gotoxy(41,33);
        cout << "Atacar";
        gotoxy(41,34);
        cout << "Curar";
        gotoxy(41,35);
        cout << "Rendir";
    
        for(int i=10; i<80; i++){
            gotoxy(i,4);
            cout << "=";
            gotoxy(i,6);
            cout << "=";
            if(i>39){
                gotoxy(i,9);
                cout << "=";
                gotoxy(i,11);
                cout << "=";
            }
            gotoxy(i,29);
            cout << "=";
            gotoxy(i,31);
            cout << "=";
        }
        for(int i=4; i<50; i++){
            gotoxy(39,i);
            cout << "=";
        }            
    
}
int Game::verificar(){
    Laberinto **lista = this->listaLaberintos;
    
    for (int indice = 0; indice < CANTIDAD_LABERINTOS;indice++){
        Laberinto *examinado = lista[indice];
        if (examinado->getVisitado()==0){
            return 0 ;
        }
    }
    return 1;
}
void Game::imprimirLaberinto(){
    gotoxy(10,5);        
    cout << "Laberinto";                
    this->dibujador->crear(this->laberintoActual);    
    this->dibujador->imprime(10,8); 
}
void Game::batalla(){
    
}
void Game::accciones(){
    char tecla = getch();
    gotoxy(10,33);    
    int posx,posy;
    posx = this->jugador->getPosX();
    posy = this->jugador->getPosY();
    int new_posx =posx;
    int new_posy=posy;
    if (tecla == 'a'){
        new_posx--;
    }else if (tecla =='s'){
        new_posy ++;
    }else if (tecla =='d'){
        new_posx++;
    }else if (tecla =='w'){
        new_posy--;
    }else if(tecla =='1'){
        cout<<"Ir a Artefactos?(y/n)"<<endl;
    }else if (tecla =='2'){
        cout<<"Rendirse?(y/n)"<<endl;
    }else {
        cout<<"Comando Invalido"<<endl;
    }
    if (this->laberintoActual->verificarMovimiento(posx,posy)){
           this->laberintoActual->cargarCelda(posx,posy,' ');
           if(this->laberintoActual->verificarMonstruo(new_posx,new_posy)){
               this->batalla();
           }
           this->jugador->move(new_posx,new_posy);
           this->laberintoActual->cargarCelda(new_posx,new_posy,'j');
           
       }else{
           cout<<"Movimiento no valido"<<endl;
    } 

}
int Game::verificarFin(int &nivelLaberinto){
    Avatar *jugador_actual = this->jugador;
    int posx = jugador_actual->getPosX();
    int posy = jugador_actual->getPosY();
    Celda celda_actual = this->laberintoActual->getCelda(posx,posy);
    if (celda_actual.getTipo()==4){
        this->laberintoActual->setVisitado(1);
        if(this->verificar()){
            return 1;
        }else {
            nivelLaberinto++;
            this->laberintoActual = this->listaLaberintos[nivelLaberinto]->getLab();
            this->jugador->move(this->laberintoActual->getInicioX(),this->laberintoActual->getInicioY());
            return 0;
        }
    }else{
        return 0;
    }
}
void Game::start(){    
    system("cls");
    this->jugador = crearJugador();
    system("cls");
    
    int nivelLaberinto = 0;
    int gano = 0;
    int posX = this->jugador->getPosX(), posY = this->jugador->getPosY();
    this->laberintoActual = this->listaLaberintos[nivelLaberinto]->getLab();
    this->jugador->move(this->laberintoActual->getInicioX(),this->laberintoActual->getInicioY());
    
    do{              
        this->imprimirUI();
        this->imprimirLaberinto();     
        this->accciones();
        gano = this->verificarFin(nivelLaberinto);        
    }while (gano == 0);
}

Game::~Game(){
    delete this;
}