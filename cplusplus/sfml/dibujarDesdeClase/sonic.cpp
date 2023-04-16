#include "sonic.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

Sonic::Sonic(std::string r):ruta(r), Personaje(r){

    modificarSprite();
}

void Sonic::modificarSprite(){

    this->obtenerSprite().setTextureRect(sf::IntRect(0,157,53,51));
}

Sonic::~Sonic(){}
