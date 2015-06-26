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
const int CANTIDAD_LABERINTOS =3;
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
    this->dibujador->crear(this->laberintoActual,this);    
    this->dibujador->imprime(10,8); 
}
void Game::batalla(int posx, int posy){
    int fin = 0 ;
    Monstruo* encontrado = this->laberintoActual->getMonstruoByPos(this,posx,posy);
    char accion ; 
    int objetos = 0 ;
    do{
        // verificar si sigo vivo
        if (this->jugador->getVidaActual()<= 0 ){
            fin = 1;
        }else {
            this->imprimirLucha(encontrado);
            objetos = this->imprimirListaObjetos(1);// agregar vida actual avatar desde el inicio ctm
            accion = this->getAccion(encontrado->getNombre());
            if (accion == 'A'){
                this->jugador->interaccion(encontrado,accion);
            }else if(accion =='E'){
                if (objetos == 0 ){
                     gotoxy(45,13);
                     cout<<"No tienes objetos en tu saco "<<endl; 
                }else {
                    this->usarObjetos(encontrado);
                }
            }
            if (encontrado->getVidaActual() <= 0){
                fin = 1 ;
            }else{
                this->jugador->interaccion(encontrado,'D');
            }
        }

    }while (fin == 0);

}
void Game::usarObjetos(Monstruo* encontrado){
    this->imprimirLucha(encontrado);
    int opcion = 0 ;

    do{
        cin>>opcion ;
        if (opcion-1 >this->jugador->getMisArtefactos()->getTamano() || opcion<=0){
            opcion = 0 ;
            cout<<"Opcion no valida";
        }
        
    }while(opcion == 0);
    Artefacto* elegido =this->jugador->getMisArtefactos()->getElemento(opcion);
    elegido->usar(this->jugador);
}

void Game::imprimirLucha(Monstruo* encontrado){
    gotoxy(45,15);
    cout<<(this->jugador->getNombre())<<'\t'<<(encontrado->getNombre())<<endl;
    gotoxy(45,17);
    cout<<(this->jugador->getVidaActual())<<'\t'<<(encontrado->getVidaActual())<<endl;
}
char Game::getAccion(char *nombre){
     
     
    this->imprimirUI(); // crear un metodo limpiarconsola
    this->imprimirLaberinto();  
    gotoxy(10,33);
    cout<<"Encontraste a "<<nombre<<endl<<"empiezan las luchas"<<endl<<"en casa de juanjo!!!!!!!!"<<endl;
    cout<<"Ingresa  comandos:"<<endl;
    //gotoxy(10,38);// no se neceista 
    int accion = 0 ;
    char comando ;
    do{
        cin>>comando;
        if (comando == 'A'){
            accion = 1 ;
        }else if(comando =='E'){
            accion = 1 ;
        }else{
            cout<<"Opcion Invalida"<<endl;
              cin.sync();

        }
    }while(accion == 0);
    
    return comando;
    
}
void Game::recoger(int posx,int posy){
    Artefacto * elegido  = this->laberintoActual->getArtefactoByPos(this,posx,posy);
    
    if (elegido->getTipo() ==1){
        Arma *new_artefacto = new Arma;
        new_artefacto = (Arma*)elegido;
        this->jugador->agregarArtefacto(new_artefacto);
    }else if (elegido->getTipo() ==2){
        Armadura *new_artefacto = new Armadura;
        new_artefacto = (Armadura*)elegido;
        this->jugador->agregarArtefacto(new_artefacto);
    }else if(elegido->getTipo()==3){
        PocionCuracion *new_artefacto = new PocionCuracion;
        new_artefacto = (PocionCuracion*)elegido;
        this->jugador->agregarArtefacto(new_artefacto);
    }
    
    
    gotoxy(10,33);
    cout<<"Recogiste "<<elegido->getNombre()<<endl;
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
    if (this->laberintoActual->verificarMovimiento(new_posx,new_posy)){
        if(!this->laberintoActual->verificarPared(new_posx,new_posy)){
  
           this->jugador->move(new_posx,new_posy);
            this->verificarCelda();
           this->laberintoActual->cargarCelda(posy,posx,' ');
           this->laberintoActual->cargarCelda(new_posy,new_posx,'X');
        }                            
    }else{
        cout<<"Movimiento no valido"<<endl;
    } 

}
void Game::verificarCelda(){
    int posx = this->jugador->getPosX();
    int posy = this->jugador->getPosY();
    if(this->laberintoActual->verificarMonstruo(posx,posy)){
        this->batalla(posx,posy);
    }
    if(this->laberintoActual->verificarArtefacto(posx,posy)){
       this->recoger(posx,posy);
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
    this->laberintoActual->cargarCelda(this->laberintoActual->getInicioY(),this->laberintoActual->getInicioX(),'X');
    this->imprimirUI();
    do{              
        
        this->imprimirLaberinto();     
        this->accciones();
        gano = this->verificarFin(nivelLaberinto);        
    }while (gano == 0);
}

Game::~Game(){
    int number_destr = this->number;
//    delete number_destr;
    
    Laberinto* laberintoActual_destr = this->laberintoActual;
    delete laberintoActual_destr;
    
    Laberinto ** listaLaberintos_destr = this->listaLaberintos;
    for(int indice = 0 ; indice <3 ; indice++){
        delete listaLaberintos_destr[indice];
    }

    Dibujador *dibujador_destr = this->dibujador;
    delete dibujador_destr;

    Avatar *jugador_destr  = this->jugador;
    delete jugador_destr;

    Monstruo **listamonstruos_destr = this->listamonstruos;
    for(int indice = 0 ; indice <10 ; indice++){
        delete listamonstruos_destr[indice];
    }

    Artefacto **listaartefactos_destr = this->listaartefactos;
    for(int indice = 0 ; indice <9; indice++){
        delete listaartefactos_destr[indice];
    }
}

int Game::imprimirListaObjetos(int opcion){
    Saco * listaObjetos = this->jugador->getMisArtefactos();
    int cantidad  = listaObjetos->getTamano();
    int indice ;
    for (indice = 0 ; indice <cantidad;indice ++){
        gotoxy(10,50+indice);
        Artefacto* elegido = listaObjetos->getElemento(indice);
        cout<< elegido->getNombre()<<endl;
        
    }
    int opcionElegida = 0 ;
    if (cantidad == 0){
        gotoxy(45,13);
        cout<<"No tienes objetos en tu saco "<<endl; 
        return 0;
    }
    return 1;
}

Monstruo* Game::getMonstruobypos(int indice){
    return this->listamonstruos[indice];
}
Artefacto* Game::getArtefactobypos(int indice){
    return this->listaartefactos[indice];
}
Avatar * Game::getJugador(){
    return this->jugador;
}