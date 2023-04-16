#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include "coliciones.h"
class Personaje : public sf::Drawable , public Coliciones{

    private:
    
        sf::Texture ima_tex;
        sf::Sprite ima_spr;
        sf::Event evento1;
        std::string ruta;
        sf::Vector2f renderImagen;
        int sonic1;
        int sonic2;

    public:

        Personaje(std::string);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

        bool renderizarSprite(float, float);

        bool cambiarPosicion(float, float);

        bool cambiarPuntoDeOrigen();

        void gestionarEvento(sf::Vector2f, sf::Vector2i);

        bool posicionRandom(sf::Vector2i);

        sf::FloatRect buscarGlobal()const override;

        bool moverSolo(sf::Vector2f);

        sf::Vector2f posicionActual()const;
       
        sf::Sprite &obtenerSprite();

        virtual void modificarSprite()=0;

        virtual ~Personaje(){};
};

#endif /* ifndef PERSONAJE_H
#define PERSONAJE_H

class */
