#include "vegeta.h"
#include "personaje.h"

Vegeta::Vegeta() : Personaje("Vegeta",1,5,1,1,true){}

int Vegeta::atacar(){

    if(this -> verMana() >= 3){

        if(this -> verFuerza() > 5 and this -> verAgilidad() < 5){

            this -> modificarMana(-3);
            
            return -(3+5);
        }

        if(this -> verFuerza() > 5 and this -> verAgilidad() >= 5){

            this -> modificarMana(-3);
            
            return -(3+5+3);
        }

        else{

            return -3;
        }

    }

    puntosPorTurno();
   
    return -1;

}

bool  Vegeta::defender(int i){

    if(this -> verMana() >= 3){

        this -> modificarMana(-3);

        i -= 3;

        this -> modificarVida(i);

        if (this -> verVida() < 1) this -> modificarEstado(false); 

        return true;

    }

    this -> modificarVida(i);

    if (this -> verVida() < 1) this -> modificarEstado(false); 

    return false;
}

const bool Vegeta::puntosPorTurno(){

    this -> modificarAgilidad(3);
    this -> modificarFuerza(4);
    this -> modificarMana(3);
    return true;
}

Vegeta::~Vegeta(){}
