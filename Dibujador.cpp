#include "Dibujador.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include "Laberinto.h"
#include "interfaz.h"
#include <iostream>

using namespace std;

Dibujador::Dibujador() {    
    dib = NULL;
}

Dibujador::Dibujador(int a, int b){
    SetA(a);
    SetB(b);
    dib = new char*[2*A + 1];
    for(int i=0; i<2*A + 1;i++){
        dib[i] = new char [2*B + 1]; 
    }
}

Dibujador::Dibujador(const Dibujador& orig) {
}

Dibujador::~Dibujador() {
}

void Dibujador::SetB(int b) {
    this->B = b;
}

int Dibujador::GetB() const {
    return B;
}

void Dibujador::SetA(int a) {
    this->A = a;
}

int Dibujador::GetA() const {
    return A;
}

void Dibujador::buscarJugador(Laberinto *lab, int &fil, int &col){
    for(int i=fil; i<lab->getN(); i++){
        for(int j=col; j<lab->getM(); j++){
            if(lab->mostrarCelda(i,j) == '°')
            {
                fil=i;
                col=j;
                return;
            };
        }
    }
    return;
}

void Dibujador::crear(Laberinto *lab){
    int i=0, j=0;
    buscarJugador(lab,i,j);
    //i=0; j=6;
    int pasosRestantesX, pasosRestantesY;
    int yW=i,yS=i,xA=j,xD=j;
    int indiceYW=0, indiceYS=0, indiceXA=0, indiceXD=0;
    //para arriba
    int y=i,x=j,pasoA = A, pasoB = B;
    while(y>=0 && pasoA>0){
        y--;
        pasoA--;
    }
    if(y<0){
        indiceYW = 1;
        pasosRestantesY = pasoA;
        yW = i - (A - pasoA) + 1;
    }
    else
        yW = y - pasoA; 
    //para abajo
    y=i,x=j,pasoA = A, pasoB = B;
    while(y<lab->getN() && pasoA>0){
        y++;
        pasoA--;
    }
    if(y>=lab->getN()){
        indiceYS = 1;        
        pasosRestantesY = pasoA;
        yS = i + (A - pasoA) - 1;
    }
    else
        yS = y - pasoA; 
    //para derecha
    y=i,x=j,pasoA = A, pasoB = B;
    while(x<lab->getM() && pasoB>0){
        x++;
        pasoB--;
    }
    if(x>=lab->getM()){
        indiceXD = 1;
        pasosRestantesX = pasoB;
        xD = j + (B - pasoB) + 1;
    }
    else
        xD = x + pasoB; 
    //para izquierda
    y=i,x=j,pasoA = A, pasoB = B;
    while(x>=0 && pasoB>0){
        x--;
        pasoB--;
    }
    if(x<0){
        indiceXA = 1;
        pasosRestantesX = pasoB;
        xA = j - (B - pasoB) + 1;
    }
    else
        xA = x - pasoB; 
    
    if(indiceYW == 1){
        if(indiceXA == 1){
            for(int a=0,i=yW-(pasosRestantesY*indiceYS); i<yS+(pasosRestantesY*indiceYW)+1+1; a++,i++){
                for(int b=0,j=xA-(pasosRestantesX*indiceXD); j<xD+(pasosRestantesX*indiceXA)+1+1; b++,j++){
                    this->dib[a][b] = lab->mostrarCelda(i,j);
                }
            }
        }
        else{
            for(int a=0,i=yW-(pasosRestantesY*indiceYS); i<yS+(pasosRestantesY*indiceYW)+1+1; a++,i++){
                for(int b=0,j=xA-(pasosRestantesX*indiceXD)-1; j<=xD+(pasosRestantesX*indiceXA); b++,j++){
                    this->dib[a][b] = lab->mostrarCelda(i,j);
                }
            }
        }
    }
    else{
        if(indiceXA == 1){
            for(int a=0,i=yW-(pasosRestantesY*indiceYS)-1; i<=yS+(pasosRestantesY*indiceYW); a++,i++){
                for(int b=0,j=xA-(pasosRestantesX*indiceXD); j<xD+(pasosRestantesX*indiceXA)+1+1; b++,j++){
                    this->dib[a][b] = lab->mostrarCelda(i,j);
                }
            }
        }
        else{
            for(int a=0,i=yW-(pasosRestantesY*indiceYS)-1; i<=yS+(pasosRestantesY*indiceYW); a++,i++){
                for(int b=0,j=xA-(pasosRestantesX*indiceXD)-1; j<=xD+(pasosRestantesX*indiceXA); b++,j++){
                    this->dib[a][b] = lab->mostrarCelda(i,j);
                }
            }
        }
    }
}

void Dibujador::imprime(int x, int y){
    for(int i =0 ; i<2*A + 1; i++){
        for(int j=0; j<2*B + 1;j++){
            gotoxy(x+j,y+i);
            cout << dib[i][j];
        }
        cout << endl;
    }
}
