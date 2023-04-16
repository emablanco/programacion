#include "base.h"
#include "anillo.h"
#include "nudillos.h"
#include "sonic.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

Base::Base(int _x, int _y, std::string n) : x(_x), y(_y), nombre(n), ventana1(sf::VideoMode(x,y),n){

    jugadores.push_back(new Sonic);
    jugadores.push_back(new Nudillos);
    jugadores.push_back(new Anillo);

    fps = 60;
    velocidad = {3.0,3.0};
    velocidad2 = {3.0,3.0};


    sf::Vector2f v1(jugadores[0]->obtenerTextura()->getSize());
    sf::Vector2f v2(jugadores[1]->obtenerTextura()->getSize());
    jugadores[0]->obtenerSprite()->setScale(40.f / v1.x, 60.f / v1.y);
    jugadores[1]->obtenerSprite()->setScale(40.f / v2.x, 60.f / v2.y);
    ventana1.setFramerateLimit(fps);

    sf::Vector2f t1(jugadores[0]->obtenerTextura()->getSize());
    jugadores[0]->obtenerSprite()->setOrigin(t1.x / 2.f, t1.y / 2.f);
    sf::Vector2f t2(jugadores[1]->obtenerTextura()->getSize());
    
    jugadores[1]->obtenerSprite()->setOrigin(t1.x / 2.f, t1.y / 2.f);
    jugadores[1]->obtenerSprite()->setPosition(ventana1.getSize().x / 2.f, ventana1.getSize().y / 2.f);

    jugadores[2]->obtenerSprite()->setOrigin(t1.x / 2.f, t1.y / 2.f);
    jugadores[2]->obtenerSprite()->setPosition(ventana1.getSize().x / 2.f, ventana1.getSize().y / 2.f);


    sf::Vector2f v3(jugadores[2]->obtenerTextura()->getSize());
    jugadores[2]->obtenerSprite()->setScale(25.f / v3.x, 25.f / v3.y);

}

bool Base::gameLoop(){

    dibujar();
    verEvento();
    moverSolo();
    cambiarPosicion();

    return true;
}


bool Base::dibujar(){

    ventana1.clear(sf::Color::Red);
    ventana1.draw(*jugadores[2]->obtenerSprite());
    ventana1.draw(*jugadores[0]->obtenerSprite());
    ventana1.draw(*jugadores[1]->obtenerSprite());
    ventana1.display();

    return true;
}

void Base::verEvento(){

    while(ventana1.pollEvent(evento1)){

        if(evento1.type == sf::Event::Closed){
            
            ventana1.close();

        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

        jugadores[0]->obtenerSprite()->move(0, (velocidad.y*-1));
        
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

        jugadores[0]->obtenerSprite()->move(0, velocidad.y);
        
    }
 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        jugadores[0]->obtenerSprite()->move((velocidad.x*-1), 0);

        sf::Vector2f v1(jugadores[0]->obtenerTextura()->getSize());
        jugadores[0]->obtenerSprite()->setScale(40.f / v1.x, 60.f / v1.y);

    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        jugadores[0]->obtenerSprite()->move(velocidad.x,0);
        
        sf::Vector2f v1(jugadores[0]->obtenerTextura()->getSize());
        jugadores[0]->obtenerSprite()->setScale(-40.f / v1.x, 60.f / v1.y);

    }

    sf::Vector2f p1(jugadores[0]->obtenerSprite()->getPosition());
    if(p1.x < 0){
        jugadores[0]->obtenerSprite()->setPosition(0,p1.y);
    }

    if(p1.x > ventana1.getSize().x){
        jugadores[0]->obtenerSprite()->setPosition(ventana1.getSize().x,p1.y);

    }

    if(p1.y < 0){
        jugadores[0]->obtenerSprite()->setPosition(p1.x,0);
    }
    
    if(p1.y > ventana1.getSize().y){
        jugadores[0]->obtenerSprite()->setPosition(p1.x, ventana1.getSize().y);
    }
}

void Base::moverSolo(){

    jugadores[1]->obtenerSprite()->move(velocidad2);
    
    if(jugadores[1]->obtenerSprite()->getPosition().x < 0){
        velocidad2.x = -velocidad2.x;

        sf::Vector2f v1(jugadores[1]->obtenerTextura()->getSize());
    
        jugadores[1]->obtenerSprite()->setScale(40.f / v1.x, 60.f / v1.y);

    }

    if(jugadores[1]->obtenerSprite()->getPosition().x >= ventana1.getSize().x){

        velocidad2.x = -velocidad2.x;

        sf::Vector2f v1(jugadores[1]->obtenerTextura()->getSize());
    
        jugadores[1]->obtenerSprite()->setScale(-40.f / v1.x, 60.f / v1.y);

    }

    if(jugadores[1]->obtenerSprite()->getPosition().y < 0){
    
        velocidad2.y = -velocidad2.y;
    }
    
    if(jugadores[1]->obtenerSprite()->getPosition().y >= ventana1.getSize().y){

        velocidad2.y = -velocidad2.y;
    }

}

void Base::cambiarPosicion(){


    jugadores[2]->obtenerSprite()->setPosition(rand() % 500, rand() % 300);

}
