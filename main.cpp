/* 
 * File:   main.cpp
 * Author: Franco
 *
 * Created on 7 de junio de 2015, 08:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include "interfaz.h"
using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    
    int finished=0;
    maininterface();
    int option = 10;
    do{
        option = play(option);
        
    }while(option != 0);    
    gotoxy(0,20);
    return 0;
}

