/* 
 * File:   Monstruo.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:53 PM
 */

#ifndef MONSTRUO_H
#define	MONSTRUO_H
#include "Entidad.h"
class Monstruo :public Entidad{
	private:
            int tipo;//Tipo de cada mounstruo
            int expPrize;
            int probAttack;
            int baseAttack;
           
            
    public:
        Monstruo(char*,int,int,int,int);
         ~Monstruo();
        void setExpGain(int);
        int getExpGain();
        int getProbAttack();
        void setProbAttack(int);
        void setBaseAttack(int);
    	int  getBaseAttack();
};

#endif	/* MONSTRUO_H */

