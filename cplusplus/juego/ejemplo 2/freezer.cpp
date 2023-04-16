#include "freezer.h"
#include "personaje.h"

Freezer::Freezer() : Personaje("Freezer", 1,5,1,1,true){}

int Freezer::atacar(){

    if(this -> verMana() >= 3){

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

    puntosPorTurno();
   
    return -1;

}

bool  Freezer::defender(int i){

    if(i > 3 and this -> verMana() >= 3){

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
const bool Freezer::puntosPorTurno(){

    this -> modificarMana(3);

    this -> modificarAgilidad(3);
    
    this -> modificarFuerza(4);

    return true; 

}
Freezer::~Freezer(){}
