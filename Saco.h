/* 
 * File:   Saco.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:50 PM
 */

#ifndef SACO_H
#define	SACO_H
#include "Artefacto.h"

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
        
        void setTamano(int);
        int getCapacidad();
        void setCapacidad(int);
        int push(Artefacto *);
        virtual ~Saco();
};


#endif	/* SACO_H */

