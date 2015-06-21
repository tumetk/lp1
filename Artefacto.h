/* 
 * File:   Artefacto.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:45 PM
 */

#ifndef ARTEFACTO_H
#define	ARTEFACTO_H

class Artefacto{
private:
    int tipo;
    public:
       virtual void usar( class Entidad) = 0 ;
};

#endif	/* ARTEFACTO_H */

