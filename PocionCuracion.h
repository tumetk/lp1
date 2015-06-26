/* 
 * File:   PocionCuracion.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:53 PM
 */

#ifndef POCIONCURACION_H
#define	POCIONCURACION_H
#include "Avatar.h"
class PocionCuracion:public Artefacto{
    private:
        int puntosVida;
    public:
        PocionCuracion(char *,int);
        void setPuntosVida(int );
        int getPuntosVida();
        void usar( Avatar*&);
        ~PocionCuracion();
        PocionCuracion();
};

#endif	/* POCIONCURACION_H */

