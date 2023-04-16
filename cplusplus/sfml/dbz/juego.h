#ifndef JUEGO_H
#define JUEGO_H


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Juego{

    private:

        int fps;
       
        bool correr = true;
        bool correr_P1 = true;
        sf::RenderWindow ventana;
        sf::Texture wallpapers_tex;
        sf::Sprite wallpapers_spr;
        sf::Texture personaje1_tex;
        sf::Texture personaje2_tex;
        sf::Texture personaje3_tex;
        sf::Sprite personaje1_spr;
        sf::Sprite personaje2_spr;
        sf::Sprite personaje3_spr;
        sf::Event evento1;
        sf::Vector2f personaje1_dimencion;
        sf::Vector2f personaje2_dimencion;
        sf::Vector2f personaje3_dimencion;

        sf::Clock reloj;
        sf::Time tiempo;

    public:
        Juego(int, int , std::string);
        bool gameLoop();
        bool dibujar();
        void procesarEvento(); 
        void correrP2();
        void correrP1();
};




#endif
