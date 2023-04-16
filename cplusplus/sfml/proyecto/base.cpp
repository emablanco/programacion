#include "base.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

Base::Base(sf::Vector2i r, std::string n): resolucion(r), ventana1(nullptr), wallapapers_tex(nullptr), wallapapers_spr(nullptr){

    //VENTANA
    ventana1 = new sf::RenderWindow(sf::VideoMode(r.x,r.y),n);

    //WALLPAPERS
    wallapapers_tex = new sf::Texture;
    wallapapers_spr = new sf::Sprite;
    wallapapers_tex->loadFromFile("./image/wallpapers.jpg");
    wallapapers_spr->setTexture(*wallapapers_tex);

    //LUCHADORES
    luchadores.push_back(new Goku);

    luchadores[0]->setSpriteIndex("correr", 4);


}

bool Base::gameLoop(){

    while (ventana1->isOpen()) {

        dibujar();
    }
    return false;
}

bool Base::dibujar(){

    ventana1 -> clear(sf::Color::Red);
    ventana1 -> draw(*wallapapers_spr);
    ventana1 -> draw(*luchadores[0]);
    ventana1 -> display();

    return true;
}
