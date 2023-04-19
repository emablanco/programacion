#include "base.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
Base::Base(sf::Vector2f r, std::string n): resolucion(r), ventana1(nullptr){

    ventana1 = new sf::RenderWindow(sf::VideoMode(r.x,r.y),n);

}

bool Base::dibujar(Personaje *ema){
    ventana1->clear(sf::Color::Red);
//    ventana1->draw(*wallpapers_spr);
    ventana1 -> draw(*ema);
    ventana1->display();
    return true;
}


bool Base::ventanaAbierta(){
    while (ventana1 -> pollEvent(evento1))
        if(evento1.type == sf::Event::Closed){
            ventana1 -> close();
            return false;
        }
    return ventana1 -> isOpen();
}

Base::~Base(){

//    delete wallpapers_tex;
//    delete wallpapers_spr;
    delete ventana1;
}
