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
        cout << "Atacar cuando encuentres ";
        gotoxy(41,34);
        cout<<"un monstruo presiona A para atacar ";
        gotoxy(41,35);
        cout << "Para usar objetos presiona E ";
        gotoxy(41,36);
        cout<<"para poder seleccionar un item para usar";
        gotoxy(41,37);
        cout << "Rendir presiona 2";
    
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
        gotoxy(45,8);
        cout<<this->jugador->getNombre();
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
int Game::batalla(int posx, int posy){
    int fin = 0 ;
    Monstruo* encontrado = this->laberintoActual->getMonstruoByPos(this,posx,posy);
    char accion ; 
    int objetos = 0 ;
    do{
        // verificar si sigo vivo
        if (this->jugador->getVidaActual()<= 0 ){
            fin = 2;
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
            if (accion == 'R'){
                fin =1;
            }else{
                if (encontrado->getVidaActual() <= 0){
                    fin = 1 ;
                }else{
                    this->jugador->interaccion(encontrado,'D');
                }
            }
            
        }

    }while (fin == 0);
    return fin;
}
void Game::usarObjetos(Monstruo* encontrado){
    gotoxy(10,47);
    cout<<"Escoger artefacto";
    gotoxy(10,48);
    int opcion = 0 ;
    cout<<'\t'<<'\t'<<'\t';
    gotoxy(10,48);
    do{
        cin>>opcion ;
        if (opcion-1 >this->jugador->getMisArtefactos()->getTamano() || opcion<=0){
            opcion = 0 ;
            cout<<"Opcion no valida";
        }
        
    }while(opcion == 0);
    Artefacto* elegido =this->jugador->getMisArtefactos()->getElemento(opcion-1);
    elegido->usar(this->jugador);
}

void Game::imprimirLucha(Monstruo* encontrado){
    gotoxy(45,15);
    cout<<'\t'<<'\t'<<'\t'<<'\t';
    gotoxy(45,15);
    cout<<(this->jugador->getNombre())<<'\t'<<'\t'<<(encontrado->getNombre());
    gotoxy(45,17);
    cout<<'\t'<<'\t'<<'\t'<<'\t';
    gotoxy(45,17);
    cout<<(this->jugador->getVidaActual())<<'\t'<<'\t'<<(encontrado->getVidaActual());
}
char Game::getAccion(char *nombre){
     
     
//    this->imprimirUI(); // crear un metodo limpiarconsola
//    this->imprimirLaberinto();  
    gotoxy(10,33);
    cout<<"Encontraste a "<<nombre;
    gotoxy(10,34);
    cout<<"empiezan las luchas";
    gotoxy(10,35);
    cout<<"en casa de juanjo!!!!!!!!";
    gotoxy(10,36);
    cout<<"Ingresa  comandos:";
    gotoxy(10,37);
    cout<<'\t'<<'\t'<<'\t';
    gotoxy(10,37);
    //gotoxy(10,38);// no se neceista 
    int accion = 0 ;
    char comando ;
    do{
        cin>>comando;
        if (comando == 'A'){
            accion = 1 ;
            cout<<'\b';
        }else if(comando =='E'){
            accion = 1 ;
            cout<<'\b';
        }else if(comando=='R'){
            accion = 1;
            cout<<'\b';
        }else{
            
            cout<<"Opcion Invalida"<<endl;
            

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
    
    
    gotoxy(10,45);
    cout<<"Recogiste "<<elegido->getNombre()<<endl;
}
int Game::accciones(){
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
        gotoxy(10,25);
        
        cout<<"Rendirse?(y/n)"<<endl;
        if(getch()=='y'){
            gotoxy(10,25);
            cout<<'\t'<<'\t'<<'\t';
            return 2;
            
        }
        gotoxy(10,25);
        cout<<'\t'<<'\t'<<'\t';
    }else {
        cout<<"Comando Invalido"<<endl;
    }
    if (this->laberintoActual->verificarMovimiento(new_posx,new_posy)){
        if(!this->laberintoActual->verificarPared(new_posx,new_posy)){
            int proxlab = this->laberintoActual->verificarSalidas(new_posx,new_posy);
            if (proxlab != 0){
                return proxlab;
            }
           this->jugador->move(new_posx,new_posy);
            if(this->verificarCelda()==2){
                return 2;
            };
           this->laberintoActual->cargarCelda(posy,posx,' ');
           this->laberintoActual->cargarCelda(new_posy,new_posx,'X');
        }                            
    }else{
        cout<<"Movimiento no valido"<<endl;
    } 
    return 0;

}
int Game::verificarCelda(){
    int posx = this->jugador->getPosX();
    int posy = this->jugador->getPosY();
    if(this->laberintoActual->verificarMonstruo(posx,posy)){
       return  this->batalla(posx,posy);
    }
    if(this->laberintoActual->verificarArtefacto(posx,posy)){
       this->recoger(posx,posy);
    }
}
int Game::verificarFin(int &nivelLaberinto,int mismolab){
    
        if(this->verificar()){
            return 1;
        }
    
}
int Game::start(){    
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
    int mismolab = 0 ;
    
    do{              
        nivelLaberinto =nivelLaberinto+mismolab;
        if (nivelLaberinto <0 ){
            nivelLaberinto = 2;
        }else if (nivelLaberinto>2 ){
            nivelLaberinto = 0;
        }
        this->laberintoActual = this->listaLaberintos[nivelLaberinto]->getLab();
        this->jugador->move(this->laberintoActual->getInicioX(),this->laberintoActual->getInicioY());
        this->laberintoActual->cargarCelda(this->laberintoActual->getInicioY(),this->laberintoActual->getInicioX(),'X');
        do{
            this->imprimirLaberinto();     
            mismolab = this->accciones();
            gano = this->verificarFin(nivelLaberinto,mismolab);        
        }while(mismolab == 0 && gano==0 && mismolab!=2);
        this->laberintoActual->setVisitado(1);    
    }while (gano == 0 && mismolab!=2);
    if (mismolab ==2){
        return 2;
    }else {
        return 1;
    }
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
        cout<<indice+1<<". "<<elegido->getNombre()<<endl;
        
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