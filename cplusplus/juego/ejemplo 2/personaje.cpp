#include "personaje.h"

Personaje::Personaje(std::string r, int m, int v, int f, int a, bool e):raza(r), mana(m), vida(v), fuerza(f), agilidad(a),estado(e){}

int Personaje::verAgilidad()const{return agilidad;}
int Personaje::verVida()const{return vida;}
int Personaje::verMana()const{return mana;}
int Personaje::verFuerza()const{return fuerza;}
bool Personaje::verEstado()const{return estado;}

bool Personaje::modificarVida(int i) {
    
    vida += i;

    return true;
}

bool Personaje::modificarMana(int i) {
    
    mana += i;
    
    return true;
}

bool Personaje::modificarFuerza(int i) {
    
    fuerza += i;
    
    return true;
}

bool Personaje::modificarAgilidad(int i) {
 
    agilidad += i;

    return true;
}

bool Personaje::modificarEstado(bool i) {

    estado = i;

    return true;
}

std::string Personaje::verRaza()const{return raza;}
