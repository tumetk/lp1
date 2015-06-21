
#include "interfaz.h"
#include "Laberinto.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;

Laberinto::Laberinto(){
    srand(time(NULL));
    pctMonstruo = (rand()%10)/10;
    pctArtefacto = (rand()%10)/10;
    nivelesMonstruo = new int[10];
    nivelesArtefacto = new int[10];
    for(int i=0; i<10;i++){
        nivelesMonstruo[i] = rand()%11;
        nivelesArtefacto[i] = rand()%11;
    }
    lab = NULL;
}

Laberinto::Laberinto(int M,int N) {
    setN(N);
    setM(M);
//    lab = new char*[N+1];
//    celda = new int*[N+1];
//    for(int i=0; i<N;i++){
//        lab[i] = new char[M+1]; 
//        celda[i] = new int[M+1];
//    }
}

void Laberinto::setN(int N) {
    this->N = N;
}

int Laberinto::getN() const {
    return N;
}

void Laberinto::setM(int M) {
    this->M = M;
}

int Laberinto::getM() const {
    return M;
}

Laberinto Laberinto::getLab() const {
    return *this;
}

Laberinto::Laberinto(const Laberinto& orig) {
    *this = orig;
}

Laberinto::~Laberinto() {
    //delete[] lab; por mientras.
}

void Laberinto::cargarCelda(int fila, int col, char car){
    lab[fila][col] = car;   
    Celda *new_celda;
    switch(car){
        case ' ':
            new_celda=new Celda(1) ;
            celda[fila][col] =  new_celda; //1 es ADENTRO
            break;
        case '-':
            new_celda=new Celda(2) ;
            celda[fila][col] = new_celda; //2 es ANTERIOR
            break;
        case '#':
            new_celda=new Celda(3) ;
            celda[fila][col] = new_celda;//3 es PARED
            break;
        case '+':
            new_celda=new Celda(4) ;
            celda[fila][col] = new_celda; //4 es SIGUIENTE
            break;
    }
}

char Laberinto::mostrarCelda(int fila, int col){    
    char **aux = new char *[fila+1];
    aux[fila] = new char [col+1];
    aux[fila][col] = lab[fila][col];
    return aux[fila][col];   
}

Celda* Laberinto::getCelda(int fil, int col) {
    return celda[fil][col];
}

void Laberinto::printLaberinto(int x, int y){
    for(int i =0 ; i<N; i++){
        for(int j=0; j<M;j++){
            gotoxy(x+j,y+i);
            cout << lab[i][j];
        }
        cout << endl;
    }
}