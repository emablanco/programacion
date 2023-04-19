#include "personaje.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
Personaje::Personaje(std::string r, float x,float y):escalar({x,y}), posicion(0,0), velocidad(3,3), ima_posicion(true), imagen_del_movimiento(0), puntoOrigen({0,0}),vivo(true){

    ima_tex.loadFromFile(r);
    ima_spr.setTexture(ima_tex);
}

//--------------------------- PROTECTED ----------------------------------

//agrega imagenes al vector
bool Personaje::setMovimientos(std::string nombre, sf::Texture imagen){
    movimientos[nombre].push_back(imagen);
    return true;
}

//cambiar los valores de escala de los sprite
bool Personaje::setValoresEscala(float x, float y){
    escalar.x = x;
    escalar.y =y;
    return true;
}

//cambiar el valor de la velocidad para los sprite
bool Personaje::setVelocidad(float x, float y){
    velocidad.x = x;
    velocidad.y = y;
    return true;
}

//cambiar el numero referente a la posicion de la textura
bool Personaje::setImagenDelMovimiento(int n){
    imagen_del_movimiento = n;
    return true;
}

//obtener el numero referente al movimiento
int Personaje::getImagenDelMovimiento(){
    return imagen_del_movimiento;
}
//obtener un vector2f con la velocidad de la imagen
sf::Vector2f Personaje::getVelocidad(){
    return velocidad;
}

//obtener un vector2f con los valores de escala
sf::Vector2f Personaje::getEscalar(){
    return escalar;
}

//obtener la direccion de memoria del sprite
sf::Sprite *Personaje::obtenerSprite(){
    return &ima_spr;
}

//en que posicion estara la imagen. "true" no se voltea, "false" se voltea
bool Personaje::getImaPosicion()const{
    return ima_posicion;
}

bool Personaje::moveSprite(float x,float y){
        ima_spr.setPosition((ima_spr.getPosition().x + x), (ima_spr.getPosition().y + y));

        posicion.x = ima_spr.getPosition().x;
        posicion.y = ima_spr.getPosition().y;

    return true;
}

//-----------------------------------------------------------------------


//carga en la variable ima_spr el sprite que se dibujara con draw
bool Personaje::setSpriteIndex(std::string m, int index){

    if(index >= 0 and index < movimientos[m].size()){
        ima_spr.setTexture(movimientos[m][index]);
        //si el valor es true no se voltea la imagen
        if(ima_posicion){
            ima_spr.setScale(escalar.x / movimientos[m][index].getSize().x, escalar.y / movimientos[m][index].getSize().y);
            ima_spr.setPosition(posicion.x, posicion.y);
            return true;
        }
        
        else{
            //si el valor es false, la imagen se voltea
            ima_spr.setScale((-1 *escalar.x) / movimientos[m][index].getSize().x, escalar.y / movimientos[m][index].getSize().y);
            ima_spr.setPosition(posicion.x, posicion.y);
            return true;
        }

        sf::Vector2f spriteSize(ima_spr.getGlobalBounds().width, ima_spr.getGlobalBounds().height);

        ima_spr.setOrigin(ima_spr.getTexture()->getSize().x / 2.f, ima_spr.getTexture()->getSize().y / 2.f);
        //ima_spr.setOrigin(spriteSize.x / puntoOrigen.x, spriteSize.y / puntoOrigen.y);

    }
    return false;
}

//devuelve la cantidad de imagenes disponibles para hacer el movimiento
int Personaje::cantidadImagenes(std::string n){
    return movimientos[n].size();
}

//cambiar el punto de origen del sprite
bool Personaje::setPuntoOrigen(float x,float y,std::string n, int i){

    ima_spr.setOrigin(movimientos[n][i].getSize().x /x,movimientos[n][i].getSize().y / y);

    return true;
}

//revuelve la posicion de la imagen en la ventana
sf::Vector2f Personaje::getPosicionSprite(){

    return ima_spr.getPosition();
}

//la posion por defector del sprite
bool Personaje::cambiarPosicion(float x,float y){
    posicion.x = x;
    posicion.y = y;
    return true;
}

//funcion para cambiar el valor de desplazamiento.
bool Personaje::cambiarVelocidad(float x, float y){
    velocidad.x = x;
    velocidad.y = y;
    return true;
}

//depende el valor la imagen volteara
bool Personaje::setImaPosicion(bool i){
    ima_posicion = i;
    return true;
}

//cambiar el punto de origen
bool Personaje::setPuntoDeOrigen(float x,float y){

    puntoOrigen.x = x;
    puntoOrigen.y = y;

    return true;
}
bool Personaje::estaVivo()const{
    return vivo;
}
