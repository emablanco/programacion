#include "base.h"
#include <cstdlib>
#include <tuple>
Base::Base(int p): l1(0), l2(0), defenza_especial(false), ataque_especial(false),vivos(p),cantidad(p){

    for(size_t i = 0; i < p; i++) {
       
       switch (rand() % 5) {
            case 0:
                luchadores.push_back(new Goku);
                break;
             case 1:
                luchadores.push_back(new Cell);
                break;
             case 2:
                luchadores.push_back(new Vegeta);
                break; 
            case 3:
                luchadores.push_back(new Freezer);
                break; 
            case 4:
                luchadores.push_back(new Picolo);
                break; 
        }
    }
}

bool Base::game(){

    defenza_especial = false;
    ataque_especial = false;

    if(vivos > 1){

        do{

            l1 = rand() % cantidad;
            
        }while(luchadores[l1]->verEstado() == false);

        do{

            l2 = rand() % cantidad;

        }while(l1 == l2 or luchadores[l2]->verEstado() == false);

        int puntos_ataque = luchadores[l1]->atacar();
    
        defenza_especial = luchadores[l2] -> defender(puntos_ataque);

        if((puntos_ataque * -1) > 1) ataque_especial = true;

        if(luchadores[l2] -> verEstado() == false) --vivos;

        return true;
    }

    return false;
}


const Personaje *Base::verGanador()const{
    if(vivos == 1) return luchadores[l1];
    return nullptr;
}


const Personaje *Base::verPersonaje(int i)const{

    return luchadores[i];
}

const int Base::verCantidad()const{return cantidad;}

const std::tuple<int,int>Base::verTurno()const{

    return std::make_tuple(l1,l2);

}

const bool Base::verDefenza()const{
    return defenza_especial;
}

const bool Base::verAtaque()const{
    return ataque_especial;
}

Base::~Base(){
    
    for (size_t i = 0; i < cantidad; i++) {

        delete luchadores[i];
    }
}
