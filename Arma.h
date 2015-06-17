/* 
 * File:   Arma.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:52 PM
 */
#include "Artefacto.h"
#ifndef ARMA_H
#define	ARMA_H

class Arma:public Artefacto{
    private:
        int danhoMin;
        int danhoMax;
        char* nombre;
    public:
        Arma(int,int,char*);
        void setDanhoMin(int);
        void setDanhoMax(int);
        void setNombre(char*);
        int getDanhoMin();
        int getDanhoMax();
        char* getNombre();
        void usar(class Avatar&);
            
};

#endif	/* ARMA_H */

