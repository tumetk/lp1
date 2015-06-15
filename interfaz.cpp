#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "interfaz.h"
#include "game.h"
using namespace std;
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }
void instructions(){
    system("cls");
    gotoxy(15,8);
    printf("lalalalalalalalalala");
    gotoxy(15,9);
    printf("presiana ESC para regresar");
    char key ;
    do{
        key = getch();
    }while(key != 27);
}
void maininterface(){
    gotoxy(10,5);
    printf("SUPER JUEGO DE LP PARA PASARLO EN PRIMA");
    gotoxy(15,10);
    printf("Jugar");
    gotoxy(15,11);
    printf("Instrucciones");
    gotoxy(15,12);
    printf("Salir");
    
    
}
int play(int option){
    char key;
    system("cls");
    maininterface();
    gotoxy(14,option);
    printf("+");
    key = getch();
    if(key == 's'){
        if (option <12){
            return option +1;
        }else{
            return option;
        }
    }else if(key =='w'){
        if (option>10){
            return option -1;
        }else {
            return option;
        }
    }else if(key == '\r'){
        if (option == 10){
            Game *juego = new Game;
            juego->start();
            return 10;
        }else if (option == 11){
            instructions();
            return 10;
        }else if (option == 12){
            return 0;
        }
    }else{
        return option;
    }
}