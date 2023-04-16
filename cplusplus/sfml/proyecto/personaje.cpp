#include "personaje.h"
#include <SFML/Graphics/Texture.hpp>

Personaje::Personaje(std::string r){
    ima_tex.loadFromFile(r);
    ima_spr.setTexture(ima_tex);
}

//--------------------------- PROTECTED ----------------------------------

bool Personaje::setMovimientos(std::string nombre, sf::Texture imagen){

    movimientos[nombre].push_back(imagen);
     
    return true;
}

//-----------------------------------------------------------------------


bool Personaje::setSpriteIndex(std::string m, int index){
    if(index >= 0 and index < movimientos[m].size()){
        ima_spr.setTexture(movimientos[m][index]);
        return true;
    }
    return false;
}



void Personaje::draw(sf::RenderTarget &target, sf::RenderStates states)const{
    target.draw(ima_spr,states);
}

