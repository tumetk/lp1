
#include "interfaz.h"
#include "Laberinto.h"
#include <iostream>

using namespace std;

Laberinto::Laberinto(){
    lab = NULL;
}

Laberinto::Laberinto(int M,int N) {
    setN(N);
    setM(M);
    lab = new char*[N];
    for(int i=0; i<N;i++){
        lab[i] = new char[M]; 
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

Laberinto::Laberinto(const Laberinto& orig) {
    setN(orig.N);
    setM(orig.M);
}

Laberinto::~Laberinto() {
    //delete[] lab; por mientras.
}

void Laberinto::cargarCelda(int fila, int col, char car){
    lab[fila][col] = car;   
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