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

bool posicionInicial(sf::Clock *r1, sf::Time *t1,const float &s, Personaje *p1, sf::Vector2f &v1);

//atacar a enemigo
bool realizarAtaque(sf::Clock *, sf::Time *, const float, Personaje *, Personaje *, sf::Vector2f);

//mostrar ki el ganador
bool mostrarKi(sf::Clock *r1, sf::Time *t1, const float s, Personaje *p1, sf::Vector2f v1);

bool mostrarKi(sf::Clock *r1, sf::Time *t1, const float s, Personaje *p1, Personaje *p2);

bool iniciarTurno(sf::Clock *reloj1, sf::Clock *reloj2, sf::Time *tiempo, const float &s, Personaje *p1, sf::Vector2f &v1);

bool iniciarTurno(sf::Clock *, sf::Clock *, sf::Time *, const float &, Personaje *, Personaje *, sf::Vector2f &, sf::Vector2f &);

bool dueloMuerte(sf::Clock * , sf::Time *, const float &, bool &, Personaje *, Personaje *);

int main(int argc, char *argv[]){
    
    srand(time(0));
   
    std::vector<sf::Clock*> reloj;

    for (size_t i = 0; i < 7 ; i++) reloj.push_back(new sf::Clock);
    
    sf::Time *tiempo1; tiempo1 = new sf::Time();
    
    sf::Vector2f ventana(600,400);
    sf::Vector2f v1(50,400);
    sf::Vector2f v2(550,400);
    //luchador 1
    Personaje *l1 = new Goku;
    //luchador 2
    Personaje *l2 = new Goku;


    Base ema(ventana, "Ema");
    
    float s = 0.2;
    bool jugar = true;
    bool turno = (rand() % 10) < 5 ? true : false;
    bool e = true;

    while(ema.ventanaAbierta()){
        if(jugar){
            if(controlarTiempo2(reloj[0], tiempo1, 2)){
                e = !e;
                turno = (rand() % 10) < 5 ? true : false;
            }
        
            if(e){
                iniciarTurno(reloj[1], reloj[2], tiempo1, s, l1, l2 , v1, v2);
            }
            else jugar = dueloMuerte(reloj[3],tiempo1,s, turno, l1,l2);
        }

        else iniciarTurno(reloj[4], reloj[5], tiempo1, s, l1, l2, v1, v2);
        
        ema.dibujar(l2,l1);
    }

    for(auto x : reloj) delete x;


    return EXIT_SUCCESS;
}

bool posicionInicial(sf::Clock *r1, sf::Time *t1,const float &s, Personaje *p1, sf::Vector2f &v1){
    //tiempo que se esperara para dibujar 
    if(controlarTiempo2(r1, t1, s)){
        // no es lo mismo que poner los dos por separado
        if(p1->buscarEnemigo(v1,false)){std::cout<<"personaje:1\n";}
        //asi funciona mejor. poniendo por separado
        return true;
    }
    return false;
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
        if(p1->getEstado())
            p1->ki();
        else
            p1->dibujarMuerto();
        if(p2->getEstado())
            p2->ki();
        else
            p2->dibujarMuerto();

        return true;
    }
    return false;
}

bool dueloMuerte(sf::Clock* reloj1, sf::Time *tiempo, const float &s,bool &turno, Personaje *p1, Personaje *p2){

    if(p1 -> getEstado() and p2 -> getEstado()){
//------------------------- CAMBIAR ATAQUE ------------------------------------
        int n = rand() % 10;
        switch (n){
            case 2: turno = !turno; break;
            default: break;
        }
//-----------------------------------------------------------------------------
        if(turno) return realizarAtaque(reloj1, tiempo, s, p1, p2, p2->getPosicionSprite());
        else return realizarAtaque(reloj1, tiempo, s, p2, p1, p1->getPosicionSprite());
    }
    return false;
}

bool iniciarTurno(sf::Clock *reloj1, sf::Clock *reloj2, sf::Time *tiempo, const float &s, Personaje *p1, sf::Vector2f &v1){
   if(posicionInicial(reloj1, tiempo, s, p1, v1))
       if(mostrarKi(reloj2, tiempo, s, p1, v1))
           return true;
   return false;
}

bool iniciarTurno(sf::Clock *reloj1, sf::Clock *reloj2, sf::Time *tiempo, const float &s, Personaje *p1, Personaje *p2, sf::Vector2f &v1, sf::Vector2f &v2){
   if(posicionInicial(reloj1, tiempo, s, p1, p2, v1, v2))
       if(mostrarKi(reloj2, tiempo, s, p1, p2))
           return true;
   return false;
}
