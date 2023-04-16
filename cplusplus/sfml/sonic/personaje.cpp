#include "personaje.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

Personaje::Personaje(std::string r):ruta(r){

    imagen_tex.loadFromFile(ruta);
   
    imagen_spr.setTexture(imagen_tex);

}

sf::Sprite *Personaje::obtenerSprite(){
    return &imagen_spr;
}
sf::Texture *Personaje::obtenerTextura(){
    return &imagen_tex;
}

