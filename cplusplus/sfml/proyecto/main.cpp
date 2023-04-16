#include <SFML/System/Vector2.hpp>
#include <iostream>
#include "base.h"
int main(int argc, char *argv[])
{

    sf::Vector2i ventana(600,400);
    Base ema(ventana, "Ema");

    while(ema.gameLoop()){

    }


    return EXIT_SUCCESS;
}
