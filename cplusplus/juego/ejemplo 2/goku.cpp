#include "goku.h"
#include "personaje.h"

Goku::Goku() : Personaje("Goku", 1,5,1,1,true){}

int Goku::atacar(){

    if(this -> verMana() > 2){

        if(this -> verFuerza() >= 5 and this -> verAgilidad() < 5){

            this -> modificarMana(-3);
           
            int punto = -8;
           
            return punto;
        }

        if(this -> verFuerza() >= 5 and this -> verAgilidad() >= 5){

            this -> modificarMana(-3);
            
            int punto = -11; 
            return punto;
        }

        else{

            int punto = -3;

            return punto;
        }

    }

    bool ema = puntosPorTurno();

    return -1;

}

bool  Goku::defender(int i){

    if(this -> verMana() >= 3){

        this -> modificarMana(-3);

        i += 3;

        this -> modificarVida(i);

        if (this -> verVida() < 1) this -> modificarEstado(false); 

        return true;

    }

    this -> modificarVida(i);

    if (this -> verVida() < 1) this -> modificarEstado(false); 

    return false;
}

bool const Goku::puntosPorTurno(){

    this -> modificarMana(3);

    this -> modificarAgilidad(3);
    
    this -> modificarFuerza(4);

    return true;
}

Goku::~Goku(){}
