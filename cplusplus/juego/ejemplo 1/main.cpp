#include <iostream>
#include "base.h"
#include <iomanip>
#include <tuple>
void verPeleadores(const Base&);
void quienAtaco(const Base &);

int main(int argc, char *argv[])
{

    srand(time(0));

    Base ema(9);

    std::cout <<std::setw(10)<<"PELEADORES\n";

    while(ema.game()){

        quienAtaco(ema);
        
        std::cout <<"\n";
        
        verPeleadores(ema);
   
    }
    
    Personaje aux = ema.verPersonaje(ema.verGanador());

    std::cout << std::setw(10)<<aux.verRaza()<<std::setw(10)<<aux.verVida()<<std::setw(10)<<aux.verMana()<<"\n"; 
    
    return 0;
}

void verPeleadores(const Base &j){
    for (int i = 0; i < j.verCantidad(); ++i) {

        Personaje aux = j.verPersonaje(i);
    
        std::cout << std::setw(10)<<aux.verRaza()<<std::setw(10)<<aux.verVida()<<std::setw(10)<<aux.verMana()<<"\n"; 
    
    }
}

void quienAtaco(const Base &j){
    
    std::cout <<"\n";
    
    int a,b;
    
    std::tie(a,b) = j.verTurno();

    Personaje aux1 = j.verPersonaje(a);
    Personaje aux2 = j.verPersonaje(b);
    
    if(j.verAtaque()) std::cout<<"\n"<<std::setw(10)<<"ATAQUE ESPECIAL";

    if(j.verKill()) std::cout<<" -> LO MATA <- ";
    std::cout<<"\n";
    std::cout <<"\n"<<std::setw(10)<<aux1.verRaza()<<std::setw(10)<<" a "<<std::setw(10)<<aux2.verRaza()<<std::setw(10);
    
    std::cout <<"\n";
}
