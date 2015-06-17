/* 
 * File:   PocionCuracion.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:53 PM
 */

#ifndef POCIONCURACION_H
#define	POCIONCURACION_H

class PocionCuracion:public Artefacto{
    private:
        int puntosVida;
    public:
        void setPuntosVida(int );
        int getPuntosVida();
        void usar(class Avatar&);
};

#endif	/* POCIONCURACION_H */

