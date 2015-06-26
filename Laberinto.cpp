
#include "interfaz.h"
#include "Laberinto.h"
#include "Arma.h"
#include <time.h>
#include <cstdlib>
#include <iostream>

using namespace std;



Laberinto::Laberinto(int M,int N) {
    srand(time(NULL));
    pctMonstruo = (rand()%30)+1;
    int resta = 100 - pctMonstruo;
    pctArtefacto = (rand()%30 )+1;
    nivelesMonstruo = new int[10];
    nivelesArtefacto = new int[10];
    for(int i=0; i<10;i++){
        nivelesMonstruo[i] = rand()%11;
        nivelesArtefacto[i] = rand()%11;
    }
    lab = NULL;
    setN(N);
    setM(M);
    this->visitado = 0 ;
    
    celda = new Celda*[N+1];
    for(int i=0; i<N;i++){
        
        celda[i] = new Celda[M+1];
    }
}

void Laberinto::setN(int N) {
    this->N = N;
}

int Laberinto::getN() const {
    return N;
}

void Laberinto::setM(int M) {
    this->M = M;
}

int Laberinto::getM() const {
    return M;
}

Laberinto* Laberinto::getLab()  {
    return this;
}


Laberinto::~Laberinto() {
    int M_destr = this->M;
    int N_destr = this->N;
    char** lab_destr = this->lab;
    Celda** celda_destr = this->celda; 
    double pctMonstruo_destr = this->pctMonstruo;
    double pctArtefacto_destr = this->pctArtefacto;
    int* nivelesMonstruo_destr = this->nivelesMonstruo;
    int* nivelesArtefacto_destr = this->nivelesArtefacto;
    int inicioX_destr = this->inicioX;
    int inicioY_destr = this->inicioY;
    int finX_destr = this->finX;
    int finY_destr = this->finY;
    int visitado_destr = this->visitado;

//    delete M_destr;
//    delete N_destr;
    for (int indice = 0 ;  indice< N+1;indice++){
        delete[] celda_destr[indice];
    }
    delete[] celda_destr;
//    delete pctMonstruo_destr;
//    delete  pctArtefacto_destr;
    delete[] nivelesMonstruo_destr ;
    delete[] nivelesArtefacto_destr;
//    delete inicioY_destr;
//    delete inicioX_destr;
//    delete finY_destr;
//    delete finX_destr;
//    delete visitado_destr;
//    

}

void Laberinto::cargarCelda(int fila, int col, char car){
    
    Celda *new_celda_row = this->celda[fila];
    Celda *new_celda ;
    int probalidadMonstruo = this->pctMonstruo;
    int probalidadArtefacto = this->pctArtefacto;
    int porcentaje ;
    switch(car){
        case ' ':
           porcentaje = rand() %100 +1;
            if (porcentaje >=1 && porcentaje <= probalidadMonstruo){
                new_celda_row[col].setTipo(6);
            }else if (porcentaje > probalidadMonstruo && porcentaje <= probalidadMonstruo + probalidadArtefacto ){
                new_celda_row[col].setTipo(7);
            }else {
                new_celda_row[col].setTipo(1);
            }
            break;
        case '-':
            this->inicioX = col ;
            this->inicioY = fila;
            new_celda_row[col].setTipo(2); //2 es ANTERIOR
            break;
        case '#':
            
            new_celda_row[col].setTipo(3);//3 es PARED
            break;
        case '+':
            this->finX = col;
            this->finY = fila;
            new_celda_row[col].setTipo(4);//4 es SIGUIENTE
            break;
        case 'X':
            new_celda_row[col].setTipo(5);//jugador
            break;
        case 'm':
            new_celda_row[col].setTipo(6);//monstruo
            break;
        case 'a' :
            new_celda_row[col].setTipo(7);// artefacto
            break;
    }
}

char Laberinto::mostrarCelda(int fila, int col){    
    
    Celda celda = this->getCelda(fila,col);
    int tipo  = celda.getTipo();
    char returned ;
    if (tipo ==1){
        returned = ' ';
    }else if (tipo == 2){
        returned = '-';
    }else if (tipo == 3){
        returned = '#';
    }else if (tipo == 4){
        returned = '+';
    }else if(tipo ==5){ // jugardor tipo 5
        returned ='X';
    }else if(tipo ==6 || tipo ==7){ // artefacto tipo 7 y monstruo tipo 6
        returned =' ';
    }
    
    return returned;   
}

Celda Laberinto::getCelda(int fil, int col) {
    Celda *row = this->celda[fil];
    return row[col];
            
}

void Laberinto::printLaberinto(int x, int y){
    for(int i =0 ; i<N; i++){
        for(int j=0; j<M;j++){
            gotoxy(x+j,y+i);
            cout << lab[i][j];
        }
        cout << endl;
    }
}

Laberinto::Laberinto(){
    
}
int Laberinto::getInicioX(){
    return this->inicioX;
}
int Laberinto::getInicioY(){
    return this->inicioY;
}
int Laberinto::getFinX(){
    return this->finX   ;
}
int Laberinto::getFinY(){
    return this->finY   ;
}
void Laberinto::setVisitado(int estado){
    this->visitado = estado;
}
int Laberinto::getVisitado(){
    return this->visitado;
}
int Laberinto::verificarMovimiento(int new_posx,int new_posy){
    int max_m = this->M;
    int max_n = this->N;
    
    if (new_posx >max_m  || new_posy < 0){
        return 0 ;
    }
    if (new_posy > max_n || new_posy <0){
        return 0;
    }
    return 1 ;
}
int Laberinto::verificarMonstruo(int new_posx,int new_posy){
    Celda new_celda = this->getCelda(new_posy,new_posx);
    if (new_celda.getTipo()==6){
       return 1;
      
    }else{
        return 0;
    }
}

int Laberinto::verificarPared(int posx,int posy){
    Celda new_celda = this->getCelda(posy,posx);
    if (new_celda.getTipo()==3){
        return 1;
    }else{
        return 0;
    }
}
int Laberinto::verificarArtefacto(int posx,int posy){
   Celda new_celda = this->getCelda(posy,posx);
    if (new_celda.getTipo()==7){
        return 1;
        
    }else{
        return 0;
    }
}

Monstruo* Laberinto::getMonstruoByPos(Game *game,int posx,int posy){
    int a = posx + posy;
    int b = 10 ;
    int ret = a % b;
    if(ret < 0){
        ret+=b;
    }
    int nivel = this->nivelesMonstruo[ret];
    Monstruo *elegido = game->getMonstruobypos(ret);
    return elegido;
}
Artefacto* Laberinto::getArtefactoByPos(Game* game,int posx,int posy){
     int a = posx + posy;
    int b = 3 ;
    int ret = a % b;
    if(ret < 0){
        ret+=b;
    }
    int nivel = this->nivelesArtefacto[ret];
    
    Artefacto *elegido = game->getArtefactobypos(ret);
    return elegido;
}
int Laberinto::verificarSalidas(int posx,int posy){
    Celda new_celda = this->getCelda(posy,posx);
    if(new_celda.getTipo()==2){
        return -1;
    }else if(new_celda.getTipo()==4) {
        return 1;
    }
    return 0;
}