#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <tuple>


#include "base.h"
#include "personaje.h"
#include "goku.h"
#include "vegeta.h"
#include "cell.h"

void verLuchadores(const Base &);
void fichaLuchador(const Personaje *);
void verTurno(const Base &);

int main(void){

    srand(time(0));

    Base ema(20);

    while(ema.game()){

        verTurno(ema);

        std::cout<<"\n";
        
//        verLuchadores(ema);
        
        std::cout<<"\n";

    }

    std::cout<<"\n"<<std::setw(10)<<"VER GANADOR";

    fichaLuchador(ema.verGanador());

    return 0;
}



void fichaLuchador(const Personaje *aux){

    std::cout<<std::setw(10)<<"Raza: "<<aux -> verRaza()<<std::setw(10)<<"Vida: "<<aux -> verVida()<<std::setw(10);
   
    std::cout<<std::setw(10)<<"Agi: "<<aux -> verAgilidad()<<std::setw(10)<<"Mana: "<<aux -> verMana()<<std::setw(10);
    
    std::cout<<std::setw(10)<<"Fuerza: "<<aux ->verFuerza();
    if(aux -> verEstado()) std::cout<<std::setw(10)<<" Esta Vivo"<<"\n";
    else std::cout<<std::setw(10)<<" Esta Muerto\n";
}

void verLuchadores(const Base &j){

    for (size_t i = 0; i < j.verCantidad(); i++) {

        const Personaje *p = j.verPersonaje(i);

        if(p -> verEstado()) fichaLuchador(p);

       }
}

void verTurno(const Base &j){

    int n1, n2;

    std::tie(n1,n2) = j.verTurno();

    const Personaje * aux1 = j.verPersonaje(n1);

    const Personaje * aux2 = j.verPersonaje(n2);

    std::cout <<"\n"<<std::setw(10)<<aux1 -> verRaza()<<std::setw(10);
    
    if(j.verAtaque()) std::cout<<std::setw(10)<<" ATACA CON UN ATAQUE ESPECIAL A ";
    
    else std::cout <<" ATACA A ";
    
    std::cout <<std::setw(10)<<aux2 -> verRaza();
    
    if(j.verDefenza()) std::cout <<std::setw(10)<<" SE DEFIENDE CON UNA DEFENZA ESPECIAL";
    

    if(aux2 -> verEstado()) std::cout <<std::setw(10)<<" Y SEMUERE\n";

    else std::cout <<"\n";
}
