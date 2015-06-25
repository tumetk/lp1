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
    char* nombre;
    public:
       virtual void usar( class Avatar&) = 0 ;
       void setNombre(char *);
       char * getNombre();
       virtual ~Artefacto();
};

#endif	/* ARTEFACTO_H */

