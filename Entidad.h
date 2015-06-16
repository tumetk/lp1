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
        int nivel;
        Saco *misArtefactos;
        int vidaActual;
    public:
    	Entidad();
    	virtual ~Entidad();
    	void setNivel(int);
    	int  getNivel();
    	void setVidaActual(int);
    	int getVidaActual();
    	int  getNivel();
    	void setPosX(int);
    	void setPoxY(int);
    	void setMaxVida(int);
    	void setNombre(char *);
    	char *getNombre();
    	int  getPosX();
    	int  getPosY();
    	int  getMaxVida();
        void move(int,int);
        void agregarArtefacto(Artefacto*);
        Saco *getMisArtefactos();
};

#endif	/* ENTIDAD_H */

