/* 
 * File:   Dibujador.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:55 PM
 */

#ifndef DIBUJADOR_H
#define	DIBUJADOR_H
#include "Laberinto.h"

class Dibujador {
private:
    int A;
    int B;
    char **dib;
public:
    Dibujador();
    Dibujador(int,int);
    Dibujador(const Dibujador& orig);
    virtual ~Dibujador();
    void SetB(int);
    int GetB() const;
    void SetA(int);
    int GetA() const;
    void buscarJugador(Laberinto*,int &,int &);
    void crear(Laberinto*);   
    void imprime(int,int);
};


#endif	/* DIBUJADOR_H */

