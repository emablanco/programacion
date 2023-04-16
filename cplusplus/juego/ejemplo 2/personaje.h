#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <fstream>
#include <string>

class Personaje{

    private:
        
        int mana,vida,fuerza,agilidad;
        
        std::string raza;
        
        bool estado;

        //std::ifstream configuracion;

    public:
        
        explicit Personaje(std::string, int,int,int,int,bool);
    
        Personaje() = delete;
        
        Personaje(const Personaje & ) = delete;
        
        int verVida()const;
        
        int verMana()const;
        
        int verFuerza()const;
        
        int verAgilidad()const;
        
        std::string verRaza()const;
        
        bool verEstado()const;
        
        bool modificarVida(int);
        
        bool modificarMana(int);
        
        bool modificarFuerza(int);
        
        bool modificarAgilidad(int);
        
        bool modificarEstado(bool);

        virtual int atacar()=0;
        
        virtual bool defender(int)=0;
        
        virtual const bool puntosPorTurno()=0;
        
        virtual ~Personaje(){};
};

#endif /* ifndef PERSONAJE_H
#define PERSONAJE_H

class Personaje{

    private:
        int mana,vida,fuerza,agilidad;
    public:
}; */
