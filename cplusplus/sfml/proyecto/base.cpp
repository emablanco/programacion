#include "base.h"
#include "kameha1.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>

Base::Base(sf::Vector2i r, std::string n): resolucion(r), ventana1(nullptr), wallapapers_tex(nullptr), wallapapers_spr(nullptr){

    imagenes = 0;
    //VENTANA
    ventana1 = new sf::RenderWindow(sf::VideoMode(r.x,r.y),n);

    //WALLPAPERS
    wallapapers_tex = new sf::Texture;
    wallapapers_spr = new sf::Sprite;
    wallapapers_tex->loadFromFile("./image/wallpapers.jpg");
    wallapapers_spr->setTexture(*wallapapers_tex);

    wallapapers_spr->setScale((float)resolucion.x / wallapapers_tex->getSize().x, (float)resolucion.y / wallapapers_tex->getSize().y);

    //LUCHADORES
    luchadores.push_back(new Goku);
    poderes.push_back(new Kameha1);

    //RELOG 1 
    reloj1.restart();

    //DIBUJAR EJEMPLO
    poderes[0]->setSpriteIndex("kameha_dorado", 0);

}

bool Base::gameLoop(){

    while (ventana1->isOpen()) {

        if(controlarTiempo(0.15)){
    
            luchadores[0]->setSpriteIndex("super_kameha", imagenes);
            luchadores[0]->setPosicion(resolucion.x / 2.f,resolucion.y / 2.f);            
            luchadores[0]->setPuntoOrigen(2, 2,"super_kameha", imagenes);
            ++imagenes;
            
            int cantidad=luchadores[0]->cantidadImagenes("super_kameha");

            if(imagenes >= cantidad){
                imagenes = 0;
            }
        }

        dibujar();
    }
    return false;
}

bool Base::dibujar(){

    ventana1 -> clear(sf::Color::Red);
    ventana1 -> draw(*wallapapers_spr);
    ventana1 -> draw(*luchadores[0]);
    ventana1 -> draw(*poderes[0]);
    ventana1 -> display();

    return true;
}

bool Base::controlarTiempo(float n){

    tiempo1 = reloj1.getElapsedTime();
    sf::Time tiempo2= sf::seconds(n);
    if(tiempo1.asSeconds() > tiempo2.asSeconds()){
        reloj1.restart();
        return true;
    }
    return false;
}
