#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
class Personaje{

    private:
        sf::Texture imagen_tex;
        sf::Sprite imagen_spr;
        std::string ruta;
    public:

        Personaje(std::string);
        sf::Sprite *obtenerSprite();
        sf::Texture *obtenerTextura();

        virtual ~Personaje(){};
};

#endif
