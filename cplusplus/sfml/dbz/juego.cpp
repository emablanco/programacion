#include "juego.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

Juego::Juego(int a, int b, std::string n): ventana(sf::VideoMode(a,b),n),fps(60){
 

    //reloj.getElapsedTime();


    wallpapers_tex.loadFromFile("campo1.jpg");

    personaje1_tex.loadFromFile("personaje1.png");
    personaje2_tex.loadFromFile("personaje2.png");
    personaje3_tex.loadFromFile("personaje3.png");

    wallpapers_spr.setTexture(wallpapers_tex);

    personaje1_spr.setTexture(personaje1_tex);
    personaje2_spr.setTexture(personaje2_tex);
    personaje3_spr.setTexture(personaje3_tex);

    personaje1_spr.setOrigin(personaje1_tex.getSize().x / 2.f, personaje1_tex.getSize().y /2.f);
    
    personaje1_spr.setPosition(ventana.getSize().x / 3.f, ventana.getSize().y / 2.f);
    
    
    personaje2_spr.setOrigin(personaje2_tex.getSize().x / 2.f, personaje2_tex.getSize().y /2.f);

    personaje2_spr.setPosition(ventana.getSize().x / 2.f, ventana.getSize().y / 2.f);


    wallpapers_spr.setScale(((float)ventana.getSize().x) / ((float)wallpapers_tex.getSize().x), ((float)ventana.getSize().y) / ((float)wallpapers_tex.getSize().y));

    personaje1_dimencion.x = (100.0 / personaje1_tex.getSize().x);
    personaje1_dimencion.y = (100.0 / personaje1_tex.getSize().y);
 personaje2_dimencion.x = (100.0 / personaje2_tex.getSize().x);
    personaje2_dimencion.y = (100.0 / personaje2_tex.getSize().y);

 personaje3_dimencion.x = (100.0 / personaje3_tex.getSize().x);
    personaje3_dimencion.y = (100.0 / personaje3_tex.getSize().y);

    personaje1_spr.setScale(personaje1_dimencion);
    personaje2_spr.setScale(personaje2_dimencion);
    personaje3_spr.setScale(personaje3_dimencion);

    //VELOCIDAD DE REFRESCO DE VENTANA
    ventana.setFramerateLimit(fps);

}

bool Juego::gameLoop(){

    while(ventana.isOpen()){
    
       // std::cout <<tiempo.asSeconds()<<"\n";
       // tiempo = reloj.getElapsedTime();
       // if(tiempo.asSeconds() > 10){
         //personaje2_spr.setRotation(personaje2_spr.getRotation()+10);
        correrP1();
        correrP2();
        procesarEvento();
        dibujar();
        }
    //}
    return true;

}
bool Juego::dibujar(){
    
    ventana.clear(sf::Color::Red);
    ventana.draw(wallpapers_spr);
    ventana.draw(personaje1_spr);
    ventana.draw(personaje2_spr);
    ventana.display();
    
    return true;
}

void Juego::procesarEvento(){

    while(ventana.pollEvent(evento1)){
        
        switch (evento1.type) {
        
            case sf::Event::Closed:
                exit(1);
                break;

            case sf::Event::KeyPressed:
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                   personaje1_spr.setPosition(personaje1_spr.getPosition().x, personaje1_spr.getPosition().y -3);
                    break; 
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                   personaje1_spr.setPosition(personaje1_spr.getPosition().x, personaje1_spr.getPosition().y +3);
                    break; 
                }
                
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                   personaje1_spr.setPosition(personaje1_spr.getPosition().x +3, personaje1_spr.getPosition().y);
                    break; 

                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                   personaje1_spr.setPosition(personaje1_spr.getPosition().x - 3, personaje1_spr.getPosition().y);
                    break; 

                }
        }
    }
}

void Juego::correrP2(){

    if(correr and personaje2_spr.getPosition().x <= ventana.getSize().x){

        personaje2_spr.setPosition(personaje2_spr.getPosition().x+5, personaje2_spr.getPosition().y);

    }

    else{
        
        if(!correr and personaje2_spr.getPosition().x >= 0){

        personaje2_spr.setPosition(personaje2_spr.getPosition().x-5, personaje2_spr.getPosition().y);
        }
        
        else{
            correr = !correr;

            personaje2_dimencion.x *= -1;

            personaje2_spr.setScale(personaje2_dimencion);
        }

    }

}

void Juego::correrP1(){

    if(correr_P1 and personaje1_spr.getPosition().x <= ventana.getSize().x and !personaje1_spr.getGlobalBounds().intersects(personaje2_spr.getGlobalBounds())){

        personaje1_spr.setPosition(personaje1_spr.getPosition().x+5, personaje1_spr.getPosition().y);

    }

    else{
        
        if(!correr_P1 and personaje1_spr.getPosition().x >= 0 and !personaje1_spr.getGlobalBounds().intersects(personaje2_spr.getGlobalBounds())){

        personaje1_spr.setPosition(personaje1_spr.getPosition().x-5, personaje1_spr.getPosition().y);
        }
        
        else{
            correr_P1 = !correr;

            personaje1_dimencion.x *= -1;

            personaje1_spr.setScale(personaje1_dimencion);
        }

    }

}




