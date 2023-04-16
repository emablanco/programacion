#include "poder.h"

Poder::Poder(float x, float y):scale_x(x), scale_y(y){}

//--------------------------- PROTECTED ----------------------------------

bool Poder::setPoderes(std::string nombre, sf::Texture imagen){

    poderes[nombre].push_back(imagen);
     
    return true;
}

bool Poder::setValoresEscala(float x, float y){

    scale_x = x;
    scale_y = y;

    return true;
}
//-----------------------------------------------------------------------


bool Poder::setSpriteIndex(std::string p, int index){

    if(index >= 0 and index < poderes[p].size()){
        ima_spr.setTexture(poderes[p][index]);
        ima_spr.setScale(scale_x / poderes[p][index].getSize().x, scale_y / poderes[p][index].getSize().y);
        return true;
    }
    return false;
}

int Poder::cantidadImagenes(std::string n){
    return poderes[n].size();
}

bool Poder::setPuntoOrigen(float x,float y,std::string n, int i){

    ima_spr.setOrigin(poderes[n][i].getSize().x /x, poderes[n][i].getSize().y / y);

    return true;
}


sf::Vector2f Poder::getPosicion(){

    return ima_spr.getPosition();
}

bool Poder::setPosicion(float x, float y){
    ima_spr.setPosition(x, y);
    return true;
}
