#ifndef GOKU_H
#define GOKU_H

#include <string>
#include "personaje.h"
#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <string>
#include <cctype>
#include <SFML/Graphics/Texture.hpp>

class Goku: public Personaje{

    private:

        int imagen_patadas;
        int imagen_correr;

    public:
    
        Goku( std::string ruta = "./image/LUCHADORES/GOKU4.png", float x = 100, float y = 100);
        Goku(const Goku&)= delete;

        bool ataquePatada();

        
//-------------------VIRTUALES ------------------------------------

//        void correr(sf::Vector2f, std::string)override;

        bool buscarEnemigo(sf::Vector2f) override;

        bool atacarEnemigo() override;

        ~Goku()override;
};
#endif /* ifndef DEBUG */
