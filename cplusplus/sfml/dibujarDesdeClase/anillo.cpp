#include "anillo.h"

Anillo::Anillo(std::string r):ruta(r), Personaje(r){

}

void Anillo::modificarSprite(){

    sf::Sprite ema = this->obtenerSprite();
    ema.setTextureRect({0,157,212,208});
}

Anillo::~Anillo(){}
