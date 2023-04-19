#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "base.h"
#include "personaje.h"
#include "goku.h"
#include <SFML/Graphics.hpp>
bool controlarTiempo2(sf::Clock *reloj1, sf::Time *tiempo2, float n){
    *tiempo2 = reloj1 -> getElapsedTime();
    sf::Time tiempo20= sf::seconds(n);
    if(tiempo2 -> asSeconds() > tiempo20.asSeconds()){
        reloj1 -> restart();
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    sf::Clock *reloj1;
    sf::Time *tiempo2;
    reloj1 = new sf::Clock();
    tiempo2 = new sf::Time();

    srand(time(0));

    Personaje *ale = new Goku;

    sf::Vector2f ventana(600,400);
    Base ema(ventana, "Ema");

        while(ema.ventanaAbierta()){

            bool esta = controlarTiempo2(reloj1, tiempo2, 0.3); 

    
            if(esta) ale->correr(ventana, "correr");
            
            ema.dibujar(ale);

    }

    delete reloj1;
    delete tiempo2;

    return EXIT_SUCCESS;
}


