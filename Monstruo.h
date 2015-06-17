/* 
 * File:   Monstruo.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:53 PM
 */

#ifndef MONSTRUO_H
#define	MONSTRUO_H

class Monstruo :public Entidad{
	public:
		int expPrize;
		int probAttack;
		int baseAttack;
    private:
        Monstruo();
        virtual ~Monstruo();
        void setExpGain(int);
        int getExpGain();
        int getProbAttack();
        void setProbAttack(int);
        void setBaseAttack(int);
    	int  getBaseAttack();
};

#endif	/* MONSTRUO_H */

