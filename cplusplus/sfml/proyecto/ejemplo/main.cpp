#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "jugador.h"
int main(int argc, char *argv[])
{

    sf::RenderWindow video1(sf::VideoMode(600,400),"emanuel");

    Jugador ema;
    ema.loadTextures();
    ema.setSpriteIndex(4);

    while(video1.isOpen()){

        video1.clear(sf::Color::Red);
        video1.draw(ema);
        video1.display();
    }
    
    
    return EXIT_SUCCESS;
}
