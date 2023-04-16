#include "nudillos.h"

Nudillos::Nudillos(std::string r):ruta(r), Personaje(r){

}

void Nudillos::modificarSprite(){

    sf::Sprite ema = this->obtenerSprite();
   // ema.setTextureRect({0,157,212,208});
}

Nudillos::~Nudillos(){}
