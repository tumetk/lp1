/* 
 * File:   Laberinto.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:46 PM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H

#include "Celda.h"
#include "Artefacto.h"
#include "Monstruo.h"
#include "game.h"
class Laberinto {
private:
    int M;
    int N;
    char** lab;
    Celda** celda; 
    double pctMonstruo;
    double pctArtefacto;
    int* nivelesMonstruo;
    int* nivelesArtefacto;
    int inicioX;
    int inicioY;
    int finX;
    int finY;
    int visitado;
public:
    Laberinto();
    Laberinto(int,int);
    
    virtual ~Laberinto();
    void cargarCelda(int,int,char);
    char mostrarCelda(int,int);
    void printLaberinto(int,int);
    void setN(int N);
    int getN() const;
    void setM(int M);
    int getM() const;
    Laberinto* getLab() ;
    Celda getCelda(int,int) ;
    void operator=(const Laberinto&);
    int getInicioX();
    int getInicioY();
    int getFinX();
    int getFinY();
    void setVisitado(int);
    int getVisitado();
    int verificarMovimiento(int,int);
    int verificarMonstruo(int,int);
    int verificarPared(int,int);
    int verificarArtefacto(int,int);
    class Monstruo* getMonstruoByPos( class Game*,int,int);
    class Artefacto * getArtefactoByPos(class Game*,int,int);
};

#endif	/* LABERINTO_H */

