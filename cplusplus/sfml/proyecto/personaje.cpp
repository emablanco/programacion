#include "personaje.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

Personaje::Personaje(std::string r, float x,float y): scale_x(x), scale_y(y){

    ima_tex.loadFromFile(r);
    ima_spr.setTexture(ima_tex);
}

//--------------------------- PROTECTED ----------------------------------

bool Personaje::setMovimientos(std::string nombre, sf::Texture imagen){

    movimientos[nombre].push_back(imagen);
     
    return true;
}

bool Personaje::setValoresEscala(float x, float y){

    scale_x = x;
    scale_y = y;
    return true;
}

//-----------------------------------------------------------------------


bool Personaje::setSpriteIndex(std::string m, int index){
    if(index >= 0 and index < movimientos[m].size()){
        ima_spr.setTexture(movimientos[m][index]);
        ima_spr.setScale(scale_x / movimientos[m][index].getSize().x, scale_y / movimientos[m][index].getSize().y);
        return true;
    }
    return false;
}

int Personaje::cantidadImagenes(std::string n){
    return movimientos[n].size();
}

bool Personaje::setPosicion(float x, float y){
    ima_spr.setPosition(x, y);
    return true;
}

bool Personaje::setPuntoOrigen(float x,float y,std::string n, int i){

    ima_spr.setOrigin(movimientos[n][i].getSize().x /x,movimientos[n][i].getSize().y / y);

    return true;
}

sf::Vector2f Personaje::getPosicion(){

    return ima_spr.getPosition();
}

