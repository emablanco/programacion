#include "base.h"
#include "personaje.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

Base::Base(sf::Vector2f r, std::string n): resolucion(r), ventana1(new sf::RenderWindow(sf::VideoMode(r.x,r.y),n)), wallpapers_tex(nullptr), wallpapers_spr(nullptr){

    wallpapers_tex = new sf::Texture;
    wallpapers_spr = new sf::Sprite;

    wallpapers_tex -> loadFromFile("./image/wallpapers1.jpg");
    wallpapers_spr->setTexture(*wallpapers_tex);
    wallpapers_spr->setScale(resolucion.x / wallpapers_spr->getTexture()->getSize().x ,resolucion.y / wallpapers_spr->getTexture()->getSize().y);

    ventana1 -> setFramerateLimit(60);
}

bool Base::dibujar(sf::Sprite *ema){
    ventana1->clear(sf::Color::Red);
    ventana1->draw(*wallpapers_spr);
    ventana1 -> draw(*ema);
    ventana1->display();
    return true;
}

bool Base::dibujar(Personaje *ema){
    ventana1->clear(sf::Color::Red);
    ventana1->draw(*wallpapers_spr);
    ventana1 -> draw(*ema);
    ventana1->display();
    return true;
}

bool Base::dibujar(Personaje *bueno, Personaje *malo){
    ventana1->clear(sf::Color::Red);
    ventana1->draw(*wallpapers_spr);
    ventana1 -> draw(*bueno);
    ventana1 -> draw(*malo);
    ventana1->display();
    return true;
}
/**
bool Base::dibujar(std::vector<Personaje*> &luchadores){

    ventana1->clear(sf::Color::Red);
    ventana1->draw(*wallpapers_spr);
    for (size_t i = 0; i < luchadores.size(); i++)
        ventana1->draw(*luchadores[i]);
    ventana1->display();
    return true;
}

**/

bool Base::dibujar(const std::vector<Personaje*>& bueno,const std::vector<Personaje*>& malo){
    ventana1->clear(sf::Color::Red);
    ventana1->draw(*wallpapers_spr);
    for (const auto& personaje : bueno) 
        ventana1->draw(*personaje);
    for (const auto& personaje : malo) 
        ventana1->draw(*personaje);
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

    delete wallpapers_tex;
    delete wallpapers_spr;
    delete ventana1;

}
