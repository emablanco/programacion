#ifndef BASE_H
#define BASE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <string.h>
#include "personaje.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "sonic.h"
#include "nudillos.h"
#include "anillo.h"
class Base{

    private:

        std::vector<Personaje*> jugadores;
        int x,y;
        std::string nombre;
        sf::RenderWindow ventana1;
        sf::Event evento1;
        sf::Vector2f velocidad;
        sf::Vector2f velocidad2;
        int fps;

    public:
        
        Base(int , int ,std::string);
        
        bool gameLoop();
        
        bool dibujar();

        void verEvento();

        void moverSolo();

        void cambiarPosicion();
};
#endif
