/* 
 * File:   Avatar.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:48 PM
 */

#ifndef AVATAR_H
#define	AVATAR_H

class Avatar:public Entidad{
	private:
		int expActual;
		int expNextLevel;
		int estado;
		int totalExpNextLevel;
		int baseAttack;
    public:
    	void setBaseAttack(int);
    	int  getBaseAttack();
    	void setTotalExpNextLevel(int);
    	int  getTotalExpNextLevel();
    	void setExpNextLevel(int);
    	int  getExpNextLevel();
    	void setExpActual(int);
    	int  getExpActual();
    	void RecibeDano(int);
    	Artefacto* interaccion(Monstruo);

};

#endif	/* AVATAR_H */

