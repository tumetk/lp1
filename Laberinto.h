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
};

#endif	/* LABERINTO_H */

