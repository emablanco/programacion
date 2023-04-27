#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
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

//a la velocidad que se dibujaran las imagenes
bool controlarTiempo2(sf::Clock *, sf::Time *, float);

//genero un vector con posiciones aleatorias
sf::Vector2f valoresAleatorios();

//me preparo en las posiciones
bool posicionInicial(sf::Clock *, sf::Time *,const float &, Personaje *, Personaje *, sf::Vector2f &, sf::Vector2f &);

//atacar a enemigo
bool realizarAtaque(sf::Clock *, sf::Time *, const float, Personaje *, Personaje *, sf::Vector2f);

//mostrar ki el ganador
bool mostrarKi(sf::Clock *r1, sf::Time *t1, const float s, Personaje *p1, sf::Vector2f v1);

bool mostrarKi(sf::Clock *r1, sf::Time *t1, const float s, Personaje *p1, Personaje *p2);

int main(int argc, char *argv[]){
    
    srand(time(0));
    
    sf::Clock *reloj1; sf::Clock *reloj2; sf::Clock *reloj3; sf::Clock *reloj4; sf::Clock *reloj5; sf::Clock *reloj6;sf::Clock *reloj7;
    sf::Time *tiempo1;
    tiempo1 = new sf::Time();
    reloj1 = new sf::Clock(); reloj2 = new sf::Clock(); reloj3 = new sf::Clock();
    reloj4 = new sf::Clock(); reloj5 = new sf::Clock(); reloj6 = new sf::Clock(); reloj7 = new sf::Clock();
    sf::Vector2f ventana(600,400);
    sf::Vector2f v1;
    sf::Vector2f v2;
    v1 = {50,400};
    v2 = {550,400};
    //luchador 1
    Personaje *luchadores1 = new Goku;
    //luchador 2
    Personaje *luchadores2 = new Goku;
    Base ema(ventana, "Ema");
    float s = 0.2;
    bool turno =true;
    bool vivo1 = true,vivo2 =true;
    bool jugar = true;
    bool inicio = true;
    
    while(ema.ventanaAbierta()){
        
        if(jugar){
            if(controlarTiempo2(reloj5, tiempo1, 2)){
                if(vivo1 and vivo2){
                    turno = (rand() % 10) < 5 ? true : false; 
                    inicio = !inicio;
                }else{
                    inicio = false;
                    jugar = false;
               }
            }else{
                if(inicio){
                    if(posicionInicial(reloj1, tiempo1, 0.2,luchadores1, luchadores2,v1, v2))
                        if(mostrarKi(reloj2, tiempo1,s,luchadores1,luchadores2)){}
                }
                else{
                    if(vivo1 and vivo2){
                        if(turno)
                            vivo1 = realizarAtaque(reloj3, tiempo1, s, luchadores1, luchadores2, luchadores2->getPosicionSprite());
                        else
                            vivo2 = realizarAtaque(reloj4, tiempo1, s, luchadores2, luchadores1, luchadores1->getPosicionSprite());
                    }
                }
            }
        }
        if(vivo1==false or vivo2 == false){
            if(luchadores1->getEstado()){
                if(mostrarKi(reloj5, tiempo1,s,luchadores1,v1)){}
                    luchadores2->dibujarMuerto();
            }else{
                if(mostrarKi(reloj5, tiempo1,s,luchadores2,v2)){}
                    luchadores1->dibujarMuerto();
            }
        }

        ema.dibujar(luchadores2,luchadores1);
    }

    delete reloj1;
    delete reloj2;
    delete reloj3;
    delete reloj4;
    delete reloj5;
    delete reloj6;
    delete reloj7;
    delete tiempo1;
    return EXIT_SUCCESS;
}

bool posicionInicial(sf::Clock *r1, sf::Time *t1,const float &s, Personaje *p1, Personaje *p2, sf::Vector2f &v1, sf::Vector2f &v2){
    //tiempo que se esperara para dibujar 
    if(controlarTiempo2(r1, t1, s)){
        // no es lo mismo que poner los dos por separado
        if(p1->buscarEnemigo(v1,false)){std::cout<<"personaje:1\n";}
        if(p2->buscarEnemigo(v2,false)){std::cout<<"Personaje:2\n";}
        //asi funciona mejor. poniendo por separado
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

bool controlarTiempo2(sf::Clock *reloj1, sf::Time *tiempo1, float n){
    //obtener cuanto tiempo paso desde qeu inicio el reloj
    *tiempo1 = reloj1 -> getElapsedTime();
    //paso el nuemro flotante en segundos
    sf::Time tiempo2 = sf::seconds(n);
    //comparo el tiempo
    if(tiempo1 -> asSeconds() > tiempo2.asSeconds()){
        //si el tiempo es mayor a los segundos reinicio el reloj
        reloj1 -> restart();
        //devuelve verdadero
        return true;
    }
    //devuelve falso
    return false;
}


bool realizarAtaque(sf::Clock *r1, sf::Time *t1, const float s, Personaje *p1, Personaje *p2, sf::Vector2f v){
    if(controlarTiempo2(r1, t1, 0.1))
        if(p1->atacarEnemigo(v))
            if(p2->comprobarSiColiciona(*p1))
                if(!p2->recibirGolpes(10))
                    return false;
    return true;
}

bool mostrarKi(sf::Clock *r1, sf::Time *t1, const float s, Personaje *p1, sf::Vector2f v1){
    if(controlarTiempo2(r1, t1, s))
        if(p1->buscarEnemigo(v1,true))
            return p1->ki();
    return false;
}

bool mostrarKi(sf::Clock *r1, sf::Time *t1, const float s, Personaje *p1, Personaje *p2){
    if(controlarTiempo2(r1, t1, s)){
        p1->ki();
        return p2->ki();
    }
    return false;
}

