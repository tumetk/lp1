/* 
 * File:   Laberinto.cpp
 * Author: Christian
 * 
 * Created on 15 de junio de 2015, 13:41
 */

#include "Laberinto.h"

Laberinto::Laberinto() {
}

Laberinto::Laberinto(const Laberinto& orig) {
	SetN(orig.N);
	SetM(orig.M);
	SetNivelesArtefacto(orig.nivelesArtefacto);
	SetPctArtefacto(orig.pctArtefacto);
	SetNivelesMonstruo(orig.nivelesMonstruo);
	SetPctMonstruo(orig.pctMonstruo);
}

Laberinto::~Laberinto() {
    delete[] nivelesMonstruo;
    delete[] nivelesArtefacto;
}

void Laberinto::SetNivelesArtefacto(int* nivelesArtefacto) {
    this->nivelesArtefacto = nivelesArtefacto;
}

int* Laberinto::GetNivelesArtefacto() const {
    return nivelesArtefacto;
}

void Laberinto::SetPctArtefacto(double pctArtefacto) {
    this->pctArtefacto = pctArtefacto;
}

double Laberinto::GetPctArtefacto() const {
    return pctArtefacto;
}

void Laberinto::SetNivelesMonstruo(int* nivelesMonstruo) {
    this->nivelesMonstruo = nivelesMonstruo;
}

int* Laberinto::GetNivelesMonstruo() const {
    return nivelesMonstruo;
}

void Laberinto::SetPctMonstruo(double pctMonstruo) {
    this->pctMonstruo = pctMonstruo;
}

double Laberinto::GetPctMonstruo() const {
    return pctMonstruo;
}

void Laberinto::SetN(int N) {
    this->N = N;
}

int Laberinto::GetN() const {
    return N;
}

void Laberinto::SetM(int M) {
    this->M = M;
}

int Laberinto::GetM() const {
    return M;
}

