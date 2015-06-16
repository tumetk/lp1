
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
    delete[] lab;
}

void Laberinto::cargarCelda(int fila, int col, char car){
    lab[fila][col] = car;   
}

void Laberinto::printLaberinto(){
    for(int i =0 ; i<M; i++){
        for(int j=0; j<N;j++){
            cout << lab[i][j];
        }
        cout << endl;
    }
}