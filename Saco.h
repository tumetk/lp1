/* 
 * File:   Saco.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:50 PM
 */
#include "Artefacto.h"
#ifndef SACO_H
#define	SACO_H

class Saco{
    private:
        Artefacto **lista;
        int tipo;
        int tamano;
        int capacidad;
    public:
        Saco(int);
        int getTamano();
        Artefacto *getElemento(int);
        int getTipo();
        void setTipo(int);
        virtual ~Saco();
        void setTamano(int);
        int getCapacidad();
        void setCapacidad(int);
        int push(Artefacto *);
};


#endif	/* SACO_H */

