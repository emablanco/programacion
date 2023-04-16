#ifndef BASE_H
#define BASE_H
#include "personaje.h"
#include <tuple>
#include <vector>

class Base{
    private:
        std::vector<Personaje>peleadores;
        int cantidad;
        int vivos;
        int turno[2];
        bool ataqueEspecial;
        bool kill;
    public:
        
        Base(int);
        Personaje verPersonaje(int)const;
        int verCantidad()const;
        int verVivos()const;
        int verGanador()const;
        bool verKill()const;
        std::tuple<int,int> verTurno()const;
        bool game();
        bool atacar(Personaje &, Personaje &);
        bool verAtaque()const;
        bool seleccionarPj();

};

#endif /* ifndef BASE_H
#define BASE_H
#include "personaje.h"
class Base{
    private:
        std::vector<
    public:
}; */
