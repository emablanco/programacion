#ifndef BASE_H
#define BASE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "personaje.h"
class Base{

    private:

        sf::RenderWindow *ventana1;
        sf::Texture * wallpapers_tex;
        sf::Sprite * wallpapers_spr;

        sf::Vector2f resolucion;
        sf::Event evento1;

    public:
 
        Base(sf::Vector2f, std::string);
        bool dibujar(sf::Sprite *);
        bool dibujar(Personaje *);
        bool dibujar(Personaje *, Personaje *);
      //  bool dibujar(std::vector<Personaje *> &);
        bool dibujar(const std::vector<Personaje *> &,const std::vector<Personaje *> &);

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
