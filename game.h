/* 
 * File:   game.h
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 08:27 PM
 */
#include "Laberinto.h"
#ifndef GAME_H
#define	GAME_H
#include "Dibujador.h"
#include "Avatar.h"
class Game {
    private:
        int number;
        Laberinto* laberintoActual;
        Laberinto **listaLaberintos;
        Dibujador *dibujador;
        Avatar *jugador ;
        Monstruo **listamonstruos;
        Artefacto **listaartefactos;
        Artefacto** levantarArtefactos();
        Monstruo** levantarMonstruos();
        Avatar* crearJugador();
    public :
        Game();
        void start();
        virtual ~Game();
        
};


#endif	/* GAME_H */

