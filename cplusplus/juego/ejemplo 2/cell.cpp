#include "cell.h"
#include "personaje.h"

Cell::Cell() : Personaje("Cell",1,5,1,1,true){}

int Cell::atacar(){

    if(this -> verMana() >= 3){

        if(this -> verFuerza() > 5 and this -> verAgilidad() < 5){

            this -> modificarMana(-3);

            int punto = -8;
            
            return punto;
        }

        if(this -> verFuerza() > 5 and this -> verAgilidad() >= 5){

            this -> modificarMana(-3);
            
            int punto = -11;

            return punto ;
        }

        else{

            int punto = -3;

            return punto;
        }

    }
    
    puntosPorTurno();

    return -1;

}

bool  Cell::defender(int i){

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

const bool Cell::puntosPorTurno(){

    this -> modificarMana(3);

    this -> modificarAgilidad(3);
    
    this -> modificarFuerza(4);

    return true;
} 

Cell::~Cell(){}
