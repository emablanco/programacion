#ifndef BASE_H
#define BASE_H

#include "personaje.h"
#include "goku.h"
#include "vegeta.h"
#include "cell.h"
#include "picolo.h"
#include "freezer.h"
#include <vector>
#include <tuple>
#include <iostream>
class Base{

    private:
    
        std::vector<Personaje *> luchadores;
        
        int cantidad, vivos, l1,l2;
        bool defenza_especial;
        bool ataque_especial;

    public:
    
        explicit Base(int);
        Base() = delete;
        Base(const Base &) = delete;
        const int verCantidad()const;
        bool game();
        const Personaje *verGanador()const;
        const Personaje *verPersonaje(int)const;
        const std::tuple<int,int>verTurno()const;
        const bool verDefenza()const;
        const bool verAtaque()const;
        
        ~Base();
};

#endif /* ifndef BASE_H
#define BASE_H

#include <>
#include <vector>
class Base : Personaje{

    private:
        std::vector<Persona *> luchadores;
    public:
} */
