#ifndef BASE_H
#define BASE_H

#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>
#include "personaje.h"
#include "sonic.h"
#include "nudillos.h"
#include "anillo.h"
#include "diamante.h"
#include <iostream>
class Base{

    private:

        sf::SoundBuffer sonido1;
        sf::SoundBuffer sonido2;
        sf::Sound sonar;
        std::vector<sf::SoundBuffer> tilin;
        sf::Clock reloj;
        sf::Time tiempo;


        sf::Text textPlay;
    
        sf::Text textSelect;

        sf::Clock reloj2;
        sf::Time tiempo2;

        int vidas;

        bool estadoDiamante;
        sf::Text text2;
        sf::Font font;
        sf::Text text;
        sf::Vector2i resolucion;
        sf::RenderWindow ventana1;
        std::string nombre;
        std::vector<Personaje *> jugadores;
        sf::Vector2f tamanio;
        sf::Vector2i v1;
        sf::Vector2f move;
        sf::Vector2f enemigo;
        int puntos;
        int cant_p;
    public:
        Base(int,int,std::string, int);

        bool gameLooop();
        bool dibujar();
        int verPunstos()const;
        bool controlarTiempo(float);

        bool moverEnemigo(float);

        ~Base();
};

#endif /* ifndef BASE_H
#define BASE_H


#include <SFML/
class Base{

    private:



    public:
}; */
