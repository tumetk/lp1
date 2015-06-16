/* 
 * File:   GestorLaberinto.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:54 PM
 */

#ifndef GESTORLABERINTO_H
#define	GESTORLABERINTO_H

#include "Laberinto.h"
class GestorDeLaberinto {
private:
    int numLab;
public:
    GestorDeLaberinto(int);
    GestorDeLaberinto(const GestorDeLaberinto& orig);
    virtual ~GestorDeLaberinto();
    Laberinto* crear();
    void setNumLab(int numLab);
    int getNumLab() const;
};

#endif	/* GESTORLABERINTO_H */

