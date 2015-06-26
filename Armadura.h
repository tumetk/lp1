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
        
        int defensa;
    public:
        Armadura(char *,int);
        
        void usar(class Avatar*&);
        void setDefensa(int);
        int getDefensa();
        ~Armadura();
        Armadura();
        
};

#endif	/* ARMADURA_H */

