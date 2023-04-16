#include "base.h"

Base::Base(int n): cantidad(n),vivos(n),peleadores(n), ataqueEspecial(false), kill(false){

    for (int i = 0; i < n; i++) {

        switch (i / 3) {

            case 0:
                peleadores[i].modificarRaza("Guerrero "+std::to_string(i));
                peleadores[i].modificarVida(5);
                peleadores[i].modificarMana(3);
                break;
            
            case 1:
                peleadores[i].modificarRaza("Arquero "+std::to_string(i));
                peleadores[i].modificarVida(5);
                peleadores[i].modificarMana(3);
                break;
            
            case 2:
                peleadores[i].modificarRaza("Mago "+std::to_string(i));
                peleadores[i].modificarVida(5);
                peleadores[i].modificarMana(3);
                break;
            
            default:
                peleadores[i].modificarRaza(std::to_string(i));
                break;
        }
    }
}

bool Base::game(){

    kill = false;

    if(vivos > 1){
    
        do{
        
            turno[0] = rand() % cantidad;
        
        }while(peleadores[turno[0]].verVida() < 1);

        do{

            turno[1] = rand() % cantidad;

        }while(turno[1] == turno[0] or peleadores[turno[1]].verVida() < 1);

        ataqueEspecial = atacar(peleadores[turno[0]], peleadores[turno[1]]);

        return true;
    }

    return false;
}

bool Base::atacar(Personaje &a, Personaje &b){

    if(a.verMana() > 3){

        b.modificarVida(-3);
    
        a.modificarMana(-3);
        
        if(b.verVida() < 1){
        
            --vivos;
            
            kill = true;
        }

        return true; //con ataque especial
    }

    b.modificarVida(-1);
    
    a.modificarMana(1);
    
    if(b.verVida() < 1) {

        --vivos;
        
        kill = true;
    }

    return false; //Sin ataque especial
}

int Base::verGanador()const{
    if(vivos == 1)
        for(int i = 0; i < cantidad; ++i)
            if(peleadores[i].verVida() > 0)
                return i;
    return -1;
}

std::tuple<int,int> Base::verTurno()const{
    return std::make_tuple(turno[0],turno[1]);
}


Personaje Base::verPersonaje(int a)const{return peleadores[a];}
int Base::verCantidad()const{return cantidad;}
int Base::verVivos()const{return vivos;}
bool Base::verAtaque()const{return ataqueEspecial;}
bool Base::verKill()const{return kill;}
