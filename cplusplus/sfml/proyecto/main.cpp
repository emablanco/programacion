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

sf::Vector2f valoresAleatorios(){

    sf::Vector2f valor;
    valor.x = rand() % 600;
    valor.y = rand() % 400;
    return valor;
}
int main(int argc, char *argv[])
{
    srand(time(0));
    sf::Clock *reloj1;
    sf::Clock *reloj2;
    sf::Clock *reloj3;
    sf::Time *tiempo1;
    reloj1 = new sf::Clock();
    reloj2 = new sf::Clock();
    reloj3 = new sf::Clock();
    tiempo1 = new sf::Time();


    Personaje *ale = new Goku;
    Personaje *ragnar = new Goku;

    sf::Vector2f ventana(600,400);
    sf::Vector2f p;
    
    p = valoresAleatorios();
    ale -> setSpriteIndex("correr", 0);
    ale->setPosicionSprite(p.x,p.y);
    Base ema(ventana, "Ema");
    
    while(ema.ventanaAbierta()){

        if(controlarTiempo2(reloj1, tiempo1, 3.0)){
        std::cout<<"VAlor Ema: "<<p.x<<" "<<p.y<<"\n";
            p = valoresAleatorios();
        }
        if(controlarTiempo2(reloj2, tiempo1, 0.3)){
            ale->buscarEnemigo(p);
            if(ragnar->buscarEnemigo(p))
                ragnar->atacarEnemigo();
                
        }
        ema.dibujar(ale, ragnar);
    }
    delete reloj1;
    delete reloj2;
    delete reloj3;
    delete tiempo1;
    delete ale;
    delete ragnar;

    return EXIT_SUCCESS;
}


