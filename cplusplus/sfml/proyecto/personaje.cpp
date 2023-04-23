#include "personaje.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
Personaje::Personaje(std::string r, float x,float y):escalar({x,y}), posicion(0,0), velocidad(3,3), ima_posicion(true), punto_de_origen({0,0}), estado(true){

    ima_tex.loadFromFile(r);
    ima_spr.setTexture(ima_tex);
}

//--------------------------- PROTECTED ----------------------------------

//agrega imagenes al vector
bool Personaje::agregarImagenesParaMovimientos(std::string nombre, sf::Texture imagen){
    movimientos[nombre].push_back(imagen);
    return true;
}

//agrego el nombre del movimiento y el numero de la textura
bool Personaje::agregarMovimientosIndex(std::string n,int i){
    num_movimientos[n] = i;
    return true;
}


//cambiar los valores de escala de los sprite
bool Personaje::valoresParaEscalarImagen(float x, float y){
    escalar.x = x;
    escalar.y =y;
    if(escalar.x == x and escalar.y == y ) return true;
    return false;
}

//cambiar el valor de la velocidad para los sprite
bool Personaje::configurarVelocidad(float x, float y){
    velocidad.x = x;
    velocidad.y = y;
    return true;
}

//obtener un vector2f con la velocidad de la imagen
sf::Vector2f Personaje::obtenerVelocidad(){
    return velocidad;
}

//obtener un vector2f con los valores de escala
sf::Vector2f Personaje::obtenerEscalar(){
    return escalar;
}


//en que posicion estara la imagen. "true" no se voltea, "false" se voltea
bool Personaje::obtenerParaDondeMiraLaImagen()const{
    return ima_posicion;
}

bool Personaje::moveSprite(float x,float y){
        ima_spr.setPosition((ima_spr.getPosition().x + x), (ima_spr.getPosition().y + y));

        posicion.x = ima_spr.getPosition().x;
        posicion.y = ima_spr.getPosition().y;

    return true;
}

//-----------------------------------------------------------------------

//el numero que hace referencia a la textura que se esta dibujando
int Personaje::getIndexImagenDelMovimiento(std::string n){
    return num_movimientos[n];
}
//devolver el rectangulo del sprite para usar con coliciones
sf::FloatRect Personaje::buscarGlobal()const{
    return ima_spr.getGlobalBounds();
}

//carga en la variable ima_spr el sprite que se dibujara con draw
bool Personaje::setSpriteIndex(std::string m, int index){

    if(index >= 0 and index < movimientos[m].size()){

        //std::cout<<"escalos: "<<escalar.x<<" "<<escalar.y<<"\n";
        ima_spr.setTexture(movimientos[m][index]);
        
        //si el valor es true no se voltea la imagen
        if(ima_posicion){
        
            //ima_spr.setScale(escalar.x / ima_spr.getTexture()->getSize().x, escalar.y / ima_spr.getTexture()->getSize().y);
            ima_spr.setScale(100.f / ima_spr.getTexture()->getSize().x, escalar.y / ima_spr.getTexture()->getSize().y);
            ima_spr.setPosition(posicion.x, posicion.y);
            
            return true;
        }
        
        else{

            //si el valor es false, la imagen se voltea
            //ima_spr.setScale((-1 * escalar.x) / ima_spr.getTexture()->getSize().x, escalar.y / ima_spr.getTexture()->getSize().y);
            ima_spr.setScale((-1 * 100.f) / ima_spr.getTexture()->getSize().x, escalar.y / ima_spr.getTexture()->getSize().y);
            ima_spr.setPosition(posicion.x, posicion.y);
            
            return true;
        }

        ima_spr.setOrigin(ima_spr.getTexture()->getSize().x / punto_de_origen.x, ima_spr.getTexture()->getSize().y / punto_de_origen.y);
    }

    return false;
}

//devuelve la cantidad de imagenes disponibles para hacer el movimiento
int Personaje::getCantidadImagenes(std::string n){
    return movimientos[n].size();
}

//cambiar el punto de origen del sprite
bool Personaje::setPuntoDeOrigenSprite(float x,float y){

    sf::Vector2f dimencion_sprite; 
    dimencion_sprite.x = ima_spr.getTexture()->getSize().x;
    dimencion_sprite.y = ima_spr.getTexture()->getSize().y;
    ima_spr.setOrigin(dimencion_sprite.x / x , dimencion_sprite.y / y);

    return true;
}

//revuelve la posicion de la imagen en la ventana
sf::Vector2f Personaje::getPosicionSprite(){

    return ima_spr.getPosition();
}

//la posion por defector del sprite
bool Personaje::setPosicionSprite(float x,float y){
    posicion.x = x;
    posicion.y = y;
    return true;
}

//funcion para cambiar el valor de desplazamiento.
bool Personaje::setVelocidad(float x, float y){
    velocidad.x = x;
    velocidad.y = y;
    return true;
}

//depende el valor la imagen volteara
bool Personaje::setPosicionDeLaImagen(bool i){
    ima_posicion = i;
    return true;
}

//cambiar el punto de origen
bool Personaje::setPuntoDeOrigenPorDefecto(float x,float y){

    punto_de_origen.x = x;
    punto_de_origen.y = y;

    return true;
}

bool Personaje::getEstado()const{
    return estado;
}

bool Personaje::setEstado(bool e){
    estado = e;
    return true;
}
