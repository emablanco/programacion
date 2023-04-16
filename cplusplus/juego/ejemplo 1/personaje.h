#ifndef PERSONAJE_H
#define PERSONAJE

#include <string>
class Personaje{
    private:
        
        int vida,mana;
        std::string raza;
    
    public:
        
        Personaje();
        
        bool modificarRaza(std::string);
        bool modificarVida(int );
        bool modificarMana(int);
        
        int verVida()const;
        int verMana()const;
        std::string verRaza()const;
};

#endif /* ifndef PERSONAJE_H
#define PERSONAJE

#include <string>
class Personaje{
    private:
        int vida,mana;
        std::string raza;
    public:
        Personaje();
        int verVida()const;
        int verMana()const;
        std::string verRaza()const;
        bool cargarRaza(std::string);
}; */
