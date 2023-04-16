#ifndef BASE_H
#define BASE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include "personaje.h"
#include "goku.h"
class Base{

    private:

        sf::RenderWindow *ventana1;
        sf::Texture *wallapapers_tex;
        sf::Sprite *wallapapers_spr;

        sf::Vector2i resolucion;
       
        std::vector<Personaje *> luchadores;

        sf::Clock reloj1;
        sf::Time tiempo1;

        int imagenes;

    public:
 
        Base(sf::Vector2i, std::string);
        
        bool gameLoop();
        
        bool dibujar();
        
        bool controlarTiempo(float);
};

#endif /* ifndef BASE_H
#define BASE_H

#include <SFML/
class Base{

    private:

        sf::

    public:

}; */
