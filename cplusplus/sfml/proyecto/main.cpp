#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "base.h"
#include "personaje.h"
#include "goku.h"
#include "coliciones.h"
#include <SFML/Graphics.hpp>
#include <vector>
bool controlarTiempo2(sf::Clock *reloj1, sf::Time *tiempo2, float n){
    *tiempo2 = reloj1 -> getElapsedTime();
    sf::Time tiempo20= sf::seconds(n);
    if(tiempo2 -> asSeconds() > tiempo20.asSeconds()){
        reloj1 -> restart();
        return true;
    }
    return false;
}

sf::Vector2f valoresAleatorios(){

    sf::Vector2f valor;
    valor.x = rand() % 600;
    valor.y = rand() % 400;
    return valor;
}


int main(int argc, char *argv[]){
    srand(time(0));
    sf::Clock *reloj1;
    sf::Clock *reloj2;
    sf::Time *tiempo1;

    reloj1 = new sf::Clock();
    reloj2 = new sf::Clock();
    tiempo1 = new sf::Time();

    std::vector<Personaje*> luchadores1;
    std::vector<Personaje*> luchadores2;
    sf::Vector2f ventana(600,400);
    sf::Vector2f p1;
    sf::Vector2f p2;
    sf::Vector2f p3;
    sf::Vector2f p4;
    Base ema(ventana, "Ema");

    for (size_t i = 0; i < 2; i++) {
        luchadores1.push_back(new Goku);
    }
     for (size_t i = 0; i < 2; i++) {
        luchadores2.push_back(new Goku);
    }
    
    while(ema.ventanaAbierta()){
        if(controlarTiempo2(reloj1, tiempo1, 5.0)){
            p1 = valoresAleatorios();
            p2 = valoresAleatorios();
            p3 = valoresAleatorios();
            p4 = valoresAleatorios();
            luchadores1[0]->buscarEnemigo(p1);
            luchadores1[1]->buscarEnemigo(p2);
            luchadores2[0]->buscarEnemigo(p3);
            luchadores2[1]->buscarEnemigo(p4);
        }
        if(controlarTiempo2(reloj2, tiempo1, 0.5)){
            luchadores1[0]->atacarEnemigo();
            luchadores1[1]->atacarEnemigo();
            luchadores2[0]->atacarEnemigo();
            luchadores2[1]->atacarEnemigo();
        }
/**        if(ale -> comprobarSiColiciona(*ragnar)){
           // std::cout<<"Colpe\n";
        }

        if(atacar){
            atacar = ale -> recibirGolpes(reloj3, tiempo1, 0.5, 1);
        }else
            ale -> dibujarMuerto();
**/

        ema.dibujar(luchadores1,luchadores2);
    }
    delete reloj1;
    delete reloj2;
    delete tiempo1;

    return EXIT_SUCCESS;
}


