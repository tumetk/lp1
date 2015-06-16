/* 
 * File:   Laberinto.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 10:46 PM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H

class Laberinto {
private:
    int M;
    int N;
    char** lab;
public:
    Laberinto();
    Laberinto(int,int);
    Laberinto(const Laberinto& orig);
    virtual ~Laberinto();
    void cargarCelda(int,int,char);
    void printLaberinto(int,int);
    void setN(int N);
    int getN() const;
    void setM(int M);
    int getM() const;
};

#endif	/* LABERINTO_H */

