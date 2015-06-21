/* 
 * File:   Celda.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:55 PM
 */

#ifndef CELDA_H
#define	CELDA_H

class Celda{
    private:
        int tipo;
        
    public:
        Celda(int);
        void setTipo(int);
        int getTipo();
        virtual ~Celda();
};

#endif	/* CELDA_H */

