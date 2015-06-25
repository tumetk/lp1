/* 
 * File:   Avatar.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:48 PM
 */
#include "Entidad.h"
#include "Monstruo.h"
#ifndef AVATAR_H
#define	AVATAR_H

class Avatar:public Entidad{
	private:
		int expActual;
		int expNextLevel;
		int estado;
		int totalExpNextLevel;
		int baseAttack;
        class Arma* armaequipada;
        class Armadura* armaduraequipada;
    public:
        Avatar(char *,int,int);
         ~Avatar();
    	void setBaseAttack(int);
    	int  getBaseAttack();
    	void setTotalExpNextLevel(int);
    	int  getTotalExpNextLevel();
    	void setExpNextLevel(int);
    	int  getExpNextLevel();
    	void setExpActual(int);
    	int  getExpActual();
    	void RecibeDano(int);
    	Artefacto* interaccion(Monstruo*,char);
        void equiparArma(class Arma*);
        void equiparArmadura(class Armadura*);
        void setArmadura( class Armadura *);
        void setArma(class Arma *);
        Arma* getArma();
        Armadura* getArmadura();

};

#endif	/* AVATAR_H */

