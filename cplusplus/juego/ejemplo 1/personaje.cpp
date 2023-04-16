#include "personaje.h"

Personaje::Personaje(){}

int Personaje::verVida()const{return vida;}
int Personaje::verMana()const{return mana;}
std::string Personaje::verRaza()const{return raza;}

bool Personaje::modificarVida(int i){
    vida += i;
    return vida > 0 ? true : false;
}
bool Personaje::modificarMana(int i){
    mana += i;
    return mana > 0 ? true : false;
}
bool Personaje::modificarRaza(std::string n){
    raza = n;
    return true;
}
