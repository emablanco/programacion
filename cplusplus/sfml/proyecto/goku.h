#ifndef GOKU_H
#define GOKU_H

#include <string>
#include "personaje.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <string>
#include <cctype>
#include <SFML/Graphics/Texture.hpp>
class Goku: public Personaje{

    private:

        int life;

    public:
    
        Goku( std::string ruta = "./image/LUCHADORES/GOKU4.png", float x = 100, float y = 100);
        
        Goku(const Goku&)= delete;

        bool ataquePatada();

        bool dibujarMuerto()override;
        
//-------------------VIRTUALES ------------------------------------

        bool recibirGolpes(sf::Clock *, sf::Time *, float, int) override;

        bool buscarEnemigo(sf::Vector2f) override;

        bool atacarEnemigo() override;

        ~Goku()override;
};
#endif /* ifndef DEBUG */
