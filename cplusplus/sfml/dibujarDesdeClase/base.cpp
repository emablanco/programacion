#include "base.h"
#include "anillo.h"
#include "diamante.h"
#include "nudillos.h"
#include "sonic.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <string>

Base::Base(int x, int y, std::string n, int c):cant_p(c),resolucion({x,y}), ventana1(sf::VideoMode(resolucion.x, resolucion.y),nombre){

    sf:: Text textPlay1("Jugar", font, 50);
    sf::Text textSelect1("Seleccionar personaje", font, 50);

    textPlay = textPlay1; 

    textSelect = textSelect1;

    textPlay.setPosition(200, 200);
    textSelect.setPosition(200, 300);

 
    vidas = 3;
    v1={x,y};

    reloj.restart();
    reloj2.restart();

    ventana1.setFramerateLimit(60);

    estadoDiamante = false;

    sf::SoundBuffer til;

    til.loadFromFile("./sound/eso tilin.wav");
    tilin.push_back(til);

    til.loadFromFile("./sound/wau tilin.wav");
    tilin.push_back(til);

    til.loadFromFile("./sound/eso tilin2.wav");
    tilin.push_back(til);

    til.loadFromFile("./sound/vaya tilin.wav");
    tilin.push_back(til);

    til.loadFromFile("./sound/risa tilin.wav");
    tilin.push_back(til);
    font.loadFromFile("./font/Boba Cups.ttf");
    text.setFont(font);

    text2.setFont(font);
    text2.setPosition(0,text.getGlobalBounds().height+50);
    
    sonido1.loadFromFile("./sound/anillo.wav");
    sonido2.loadFromFile("./sound/diamante.wav");

    tamanio = {40,60};
    puntos = 0;
    move={3,3};

    for (size_t i = 0; i < cant_p; i++) {

        switch (i) {
            
            case 0: jugadores.push_back(new Sonic); break;

            case 1: jugadores.push_back(new Nudillos); break;
            
            case 2: jugadores.push_back(new Anillo); break;
            
            case 3: jugadores.push_back(new Diamante); break;
            
            default: break;
        }
   
        if(i != 0){
            jugadores[i]->renderizarSprite(tamanio.x,tamanio.y);
            jugadores[i]->posicionRandom(v1);
    
        }
    }

    enemigo = {(float)ventana1.getSize().x / 2, (float)ventana1.getSize().y / 2};

    jugadores[0]->modificarSprite();
    
}

bool Base::gameLooop(){

    while(ventana1.isOpen()){
    
        sf::Event event;
       
        while (ventana1.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                ventana1.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (textPlay.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
       
                        dibujar();
        
                        jugadores[0]->gestionarEvento(move,v1);
//      jugadores[1]->gestionarEvento(move,v1);
        
                        if(jugadores[2]->comprobarSiColiciona(*jugadores[0])){
                            jugadores[2]->posicionRandom(v1);
            
                            ++puntos;
            
                            sonar.setBuffer(sonido1);
            //sonar.setPitch(0.5 + std::rand() % 10 / 10.f);
            
                            sonar.play();
        
                        }
                        if(jugadores[3]->comprobarSiColiciona(*jugadores[0])){
            
                            jugadores[3]->posicionRandom(v1);
           
                            reloj.restart();

                            sonar.setBuffer(tilin[rand() % tilin.size()]);
            
                            sonar.play();
            
                            estadoDiamante = !estadoDiamante;
        
                        }

        
                        text.setString("Puntos: " + std::to_string(puntos));
        
                        text2.setString("Vidas: " + std::to_string(vidas));

                        if(controlarTiempo(15)) estadoDiamante = true;

                        moverEnemigo(1); 

                        jugadores[1]->moverSolo(enemigo);

                        // Opción "Jugar" seleccionada
                        // Agrega aquí el código para iniciar el juego
                    
                    }
                    
                    if (textSelect.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        // Opción "Seleccionar personaje" seleccionada
                        // Agrega aquí el código para mostrar la pantalla de selección de personajes
                    }
                }
            }
        }

 
           }

    return true;
}

bool Base::dibujar(){

    ventana1.clear(sf::Color::Red);

    ventana1.draw(*jugadores[0]);

    ventana1.draw(*jugadores[1]);
    
    ventana1.draw(*jugadores[2]);

    if(estadoDiamante) {
     
        ventana1.draw(*jugadores[3]);
    }

    ventana1.draw(textPlay);
    ventana1.draw(textSelect);
  
    ventana1.draw(text);
   
    ventana1.draw(text2);
    
    ventana1.display();

    return true;
}


int Base::verPunstos()const{return puntos;}


bool Base::controlarTiempo(float n){

    sf::Time tiempoMaximo = sf::seconds(n);
    
    tiempo = reloj.getElapsedTime();

    if(tiempo.asSeconds() > tiempoMaximo.asSeconds()){

        reloj.restart();
        return true;
    }

    return false;
}


Base::~Base(){
    for (size_t i = 0; i < cant_p; i++) {

        delete jugadores[i];
    }
}

bool Base::moverEnemigo(float n){

    sf::Time tiempoMaximo = sf::seconds(n);
    
    tiempo2 = reloj2.getElapsedTime();

    if(tiempo2.asSeconds() > tiempoMaximo.asSeconds()){

        enemigo = jugadores[0]->posicionActual();

        reloj2.restart();

        return true;
    }

    return false;

}
