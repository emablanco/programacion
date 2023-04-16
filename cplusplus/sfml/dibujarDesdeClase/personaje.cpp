#include "personaje.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Personaje::Personaje(std::string r ): ruta(r){

    ima_tex.loadFromFile(ruta);
   
    sonic1 = 53;

    sonic2 = 0;
    
    ima_spr.setTexture(ima_tex);
    //ima_spr.setTextureRect({0,157,212,208});
}

bool Personaje::cambiarPuntoDeOrigen(){

    ima_spr.setOrigin(ima_tex.getSize().x / 2.f, ima_tex.getSize().y / 2.f);

    return true;
}

void Personaje::gestionarEvento(sf::Vector2f mover, sf::Vector2i ventana){

    sonic1 += 53;

    sonic2 += 53;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        ima_spr.move(0,-mover.y);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        ima_spr.move(0, mover.y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        ima_spr.move(-mover.x,0);
   
        ima_spr.setTextureRect(sf::IntRect(sonic2,157,53,51));

        if(sonic2 >= 157){
            sonic2 = 0;

        }
  //      ima_spr.setScale(renderImagen.x, renderImagen.y);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        ima_spr.move(mover.x,0);

        ima_spr.setTextureRect(sf::IntRect(sonic2,157,53,51));
        
        if(sonic2 >= 157){
            sonic2 = 0;

        }

       
//        ima_spr.setScale(-renderImagen.x, renderImagen.y);
    }

    if(ima_spr.getPosition().x < 0) 
        ima_spr.setPosition(0,ima_spr.getPosition().y);
   
    if(ima_spr.getPosition().x > ventana.x) 
        ima_spr.setPosition(ventana.x,ima_spr.getPosition().y);
    
    if(ima_spr.getPosition().y < 0) 
        ima_spr.setPosition(ima_spr.getPosition().x, 0);
    
    if(ima_spr.getPosition().y > ventana.y) 
        ima_spr.setPosition(ima_spr.getPosition().x,ventana.y);


    ima_spr.setTextureRect(sf::IntRect(0,322,38,51));
    ima_spr.setTextureRect(sf::IntRect(38,322,40,51));
    ima_spr.setTextureRect(sf::IntRect(78,322,38,51));
    ima_spr.setTextureRect(sf::IntRect(116,322,50,51));
    ima_spr.setTextureRect(sf::IntRect(166,322,45,51));
    ima_spr.setTextureRect(sf::IntRect(211,322,50,51));
    ima_spr.setTextureRect(sf::IntRect(261,322,51,51));
    ima_spr.setTextureRect(sf::IntRect(312,322,40,51));
    ima_spr.setTextureRect(sf::IntRect(352,322,43,51));
    ima_spr.setTextureRect(sf::IntRect(395,322,60,51));
    ima_spr.setTextureRect(sf::IntRect(455,322,60,51));
    ima_spr.setTextureRect(sf::IntRect(515,322,60,51));

}



bool Personaje::renderizarSprite(float x, float y){
   
    renderImagen = {x / ima_tex.getSize().x ,y / ima_tex.getSize().y};

    ima_spr.setScale(renderImagen.x, renderImagen.y);
    
    return true;
}


bool Personaje::cambiarPosicion(float x , float y){

    ima_spr.setPosition(x,y);

    return true;

}

void Personaje::draw(sf::RenderTarget &target, sf::RenderStates states)const{

    target.draw(ima_spr, states);
}

bool Personaje::posicionRandom(sf::Vector2i v){

    ima_spr.setPosition(rand() % v.x , rand() % v.y);

    return true;
}

sf::FloatRect Personaje::buscarGlobal()const{

    return ima_spr.getGlobalBounds();
}

bool Personaje::moverSolo(sf::Vector2f v){

    sf::Vector2f m(3,3);

    if(v.x > ima_spr.getPosition().x){
        m.x = 3;
        if(v.x - ima_spr.getPosition().x <= 3)
            m.x = 0;
    }

    else{
        if(ima_spr.getPosition().x > v.x){
            m.x = -3;
            if(ima_spr.getPosition().x - v.x <= 3){
                m.x = 0;
            }
        }
    }

    if(v.y == ima_spr.getPosition().y)
        m.y =0;

    if(v.y > ima_spr.getPosition().y){
        m.y = 3;
        if(v.y - ima_spr.getPosition().y <= 3)
            m.y = 0;
    }

    else{
        if(ima_spr.getPosition().y > v.y){
            m.y = -3;
            if(ima_spr.getPosition().y - v.y <= 3){
                m.y = 0;
            }
        }
    }

    if(v.y == ima_spr.getPosition().y)
        m.y =0;

    ima_spr.move(m.x,m.y);

    return true;
}


sf::Vector2f Personaje::posicionActual()const{
    return ima_spr.getPosition();
}

sf::Sprite &Personaje::obtenerSprite(){
    return ima_spr;
}
