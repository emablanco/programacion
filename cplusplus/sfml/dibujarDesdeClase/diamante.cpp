#include "diamante.h"

Diamante::Diamante(std::string r):ruta(r), Personaje(r){

}

void Diamante::modificarSprite(){

    sf::Sprite ema = this->obtenerSprite();
    //ema.setTextureRect({0,157,212,208});
}

Diamante::~Diamante(){}
