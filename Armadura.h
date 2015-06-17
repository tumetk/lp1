/* 
 * File:   Armadura.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:51 PM
 */
#include "Artefacto.h"
#ifndef ARMADURA_H
#define	ARMADURA_H

class Armadura: public Artefacto{
    private:
        char * nombre;
        int defensa;
    public:
        void setNombre(char*);
        void usar(class Avatar&);
        void setDefensa(int);
        int getDefensa();
        char *getNombre();
};

#endif	/* ARMADURA_H */

