/* 
 * File:   Entidad.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:43 PM
 */

#ifndef ENTIDAD_H
#define	ENTIDAD_H

class Entidad{
    private : 
        int posX;
        int posY;
        int maxVida;
        char *nombre;
    public:
    
        void move(int,int );
    
};

#endif	/* ENTIDAD_H */
