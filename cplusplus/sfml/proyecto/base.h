#ifndef BASE_H
#define BASE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "goku.h"
#include "personaje.h"
class Base{

    private:

        sf::RenderWindow *ventana1;
//        sf::Texture *wallpapers_tex;
//        sf::Texture *wallpapers_spr;

        sf::Vector2f resolucion;
        sf::Event evento1;

    public:
 
        Base(sf::Vector2f, std::string);
        bool dibujar(Personaje *);
        bool ventanaAbierta();
        ~Base();
};

#endif /* ifndef BASE_H
#define BASE_H

#include <SFML/
class Base{

    private:

    public:

}; */
