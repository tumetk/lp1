/* 
 * File:   game.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 08:27 PM
 */

#ifndef GAME_H
#define	GAME_H
#include "Dibujador.h"
#include "Avatar.h"
#include "Laberinto.h"
class Game {
    private:
        int number;
        class Laberinto* laberintoActual;
        class Laberinto **listaLaberintos;
        class Dibujador *dibujador;
        Avatar *jugador ;
        Monstruo **listamonstruos;
        Artefacto **listaartefactos;
        Artefacto** levantarArtefactos();
        Monstruo** levantarMonstruos();
        Avatar* crearJugador();
        void historia();
        int verificar();
        void imprimirUI();
        void imprimirLaberinto();
        int accciones();
        int verificarFin(int &,int);
        void recoger(int,int);
        void moverPersonaje(int,int);
        int batalla(int,int);
        void imprimirLucha(Monstruo*);
        int imprimirListaObjetos(int);
        char getAccion(char*);
        void usarObjetos(class Monstruo*);
        int verificarCelda();
    public :
        Game();
         int start();
        virtual ~Game();
        Monstruo* getMonstruobypos(int);
        Artefacto* getArtefactobypos(int);
        Avatar * getJugador();
};


#endif	/* GAME_H */

