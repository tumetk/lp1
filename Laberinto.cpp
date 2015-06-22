
#include "interfaz.h"
#include "Laberinto.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;



Laberinto::Laberinto(int M,int N) {
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
    setN(N);
    setM(M);
    this->celda = new Celda*[N];
    
    celda = new Celda*[N+1];
    for(int i=0; i<N;i++){
        
        celda[i] = new Celda[M+1];
    }
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

Laberinto* Laberinto::getLab()  {
    return this;
}


Laberinto::~Laberinto() {
    //delete[] lab; por mientras.
}

void Laberinto::cargarCelda(int fila, int col, char car){
    
    Celda *new_celda_row = this->celda[fila];
    Celda *new_celda ;
    switch(car){
        case ' ':
            new_celda=new Celda(1) ;
            new_celda_row[col].setTipo(1); //1 es ADENTRO
            break;
        case '-':
            
            new_celda_row[col].setTipo(2); //2 es ANTERIOR
            break;
        case '#':
            
            new_celda_row[col].setTipo(3);//3 es PARED
            break;
        case '+':
            
            new_celda_row[col].setTipo(4);//4 es SIGUIENTE
            break;
    }
}

char Laberinto::mostrarCelda(int fila, int col){    
    
    Celda celda = this->getCelda(fila,col);
    int tipo  = celda.getTipo();
    char returned ;
    if (tipo ==1){
        returned = ' ';
    }else if (tipo == 2){
        returned = '-';
    }else if (tipo == 3){
        returned = '#';
    }else if (tipo == 4){
        returned = '+';
    }
    return returned;   
}

Celda Laberinto::getCelda(int fil, int col) {
    Celda *row = this->celda[fil];
    return row[col];
            
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

Laberinto::Laberinto(){
    
}
