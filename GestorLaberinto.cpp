
#include "GestorDeLaberinto.h"
#include "Laberinto.h"
#include <iostream>
#include <fstream>

using namespace std;

GestorDeLaberinto::GestorDeLaberinto(int n) {
    numLab = n;
}

GestorDeLaberinto::GestorDeLaberinto(const GestorDeLaberinto& orig) {
}

GestorDeLaberinto::~GestorDeLaberinto() {
}

Laberinto* GestorDeLaberinto::crear(){
    ifstream inputFile("laberintos.txt",ios::in);
    int M,N;
    char car;
    char linea[100];
    Laberinto* laberintos = new Laberinto[numLab];
    int numL = 0;
    int numCar = 0;
    inputFile >> M;
    inputFile >> N;
    inputFile.get();
    while(!inputFile.eof()){
        Laberinto laberinto(M,N);
//        for(int i=0; i<N ; i++)
//            for(int j=0;j<N;j++){
//                car = inputFile.get();
//                if(car != '\n')
//                    laberinto.cargarCelda(i,j,car);
//            }
        for(int i=0; i<M ;i++){
            inputFile.getline(linea,100);
            for(int j=0;j<N;j++)
                laberinto.cargarCelda(i,j,linea[j]);
        }
        laberinto.printLaberinto();
        cout << endl<<endl;
//        laberintos[numL++] = laberinto;
        inputFile >> M;
        inputFile >> N;
        inputFile.get();
    }    
    return laberintos;
}

void GestorDeLaberinto::setNumLab(int numLab) {
    this->numLab = numLab;
}

int GestorDeLaberinto::getNumLab() const {
    return numLab;
}
