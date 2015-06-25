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
        
    public:
        Arma(int,int,char*);
        void setDanhoMin(int);
        void setDanhoMax(int);
        
        int getDanhoMin();
        int getDanhoMax();
        
        void usar(class Avatar&);
        ~Arma();
            
};

#endif	/* ARMA_H */

