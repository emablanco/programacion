#include "goku.h"
#include "personaje.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>

Goku::Goku(std::string r,float x, float y):Personaje(r,x,y),imagen_correr(0), imagen_patadas(0){

    float escalar_x = 100;
    float escalar_y = 100;
    float posicion_x = 0;
    float posicion_y = 0;
    float velocidad_x = 3;
    float velocidad_y = 3;
    float origen_x = 0;
    float origen_y = 0;
    bool ima_posicion = true;

    std::ifstream archivo("./configuraciones/config_goku.txt");
    
    if(archivo.is_open()){
        
        std::string cadena;
        std::string movimiento;

        while (std::getline(archivo,cadena)) {
            if(!cadena.empty() and cadena[0] == '_'){
                float valor;
                    // Buscamos el símbolo "="
                    size_t posicion = cadena.find('=');
                    if (posicion != std::string::npos) {
                        // Extraemos la subcadena que sigue al símbolo "="
                        std::string valor_str = cadena.substr(posicion + 1);
                        // Convertimos la subcadena en un valor float
                        valor = std::stof(valor_str);
                        //escalar
                        if(cadena[1] == 'e' and cadena[2] == 'x') 
                            escalar_x = valor; 
                        if(cadena[1] == 'e' and cadena[2] == 'y')
                            escalar_y = valor;
                        //punto de origen
                        if(cadena[1] == 'o' and cadena[2] == 'x')
                            origen_x = valor;
                        if(cadena[1] == 'o' and cadena[2] == 'y')
                            origen_y = valor;
                        //posicion
                        if(cadena[1] == 'p' and cadena[2] == 'x') 
                            posicion_x = valor; 
                        if(cadena[1] == 'p' and cadena[2] == 'y') 
                            posicion_y = valor;
                        //velocidad
                        if(cadena[1] == 'v' and cadena[2] == 'x')
                            velocidad_x = valor; 
                        if(cadena[1] == 'v' and cadena[2] == 'y')
                            velocidad_y = valor;
                        //para donde mira la imagen "Derecha o "izquierda"
                        if(cadena[1] == 'i') 
                            if (valor < 1)
                                ima_posicion = false;
                    }
            }
            else{
                //https://cplusplus.com/reference/string/string/empty/
                if(!cadena.empty() and std::isalpha(cadena[0])) 
                    movimiento = cadena;
                if (!cadena.empty() and cadena[0] == '.') {
                    sf::Texture imagen;
                    imagen.loadFromFile(cadena);
                    this -> agregarImagenesParaMovimientos(movimiento, imagen);
                    std::cout<<"Movimiento: "<<movimiento<<"ruta: "<<cadena<<"\n";
                } 
            }
        }
    }
    archivo.close();
    std::cout<<"Valor Escala: "<<escalar_x<<" "<<escalar_y<<"\n";
    std::cout<<"Valor Posicion: "<<posicion_x<<" "<<posicion_y<<"\n";
    std::cout<<"Valor Escala: "<<velocidad_x<<" "<<velocidad_y<<"\n";
    std::cout<<"Valor origen: "<<origen_x<<" "<<origen_y<<"\n";

    this -> valoresParaEscalarImagen(escalar_x, escalar_y);
    this -> setPosicionSprite(posicion_x, posicion_y);
    this -> configurarVelocidad(velocidad_x, velocidad_y);
    this -> setPosicionDeLaImagen(ima_posicion);
    this ->setPuntoDeOrigen(origen_x, origen_y);

    std::cout <<"Cantidad de imagenes Correr: "<<this -> getCantidadImagenes("correr")<<"\n";
    std::cout<<"Datos cargados correctos\n";
}

bool Goku::atacarEnemigo(){

    return ataquePatada();
}

bool Goku::buscarEnemigo(sf::Vector2f v){

    this -> setSpriteIndex("correr", imagen_correr);
 
    //velocidad
    sf::Vector2f vel_movimiento = this -> obtenerVelocidad();
   
    //posicion del sprite en la ventana
    sf::Vector2f ima_spr = this -> getPosicionSprite();
   
    //textura que se esta dibijando
    int imagen = imagen_correr;
    
    //si se encuentra en la posicion devuelve true.
    if(v.x == ima_spr.x and v.y == ima_spr.y){
        this -> setSpriteIndex("correr", 4);
        imagen_correr = 0;
        return true;
    }
    
    //si la imagen no corresponde a la imagen de transportacion
    if(imagen != 2){
        //enemigo esta a la derecha
        if(v.x > ima_spr.x){
            this->setPosicionDeLaImagen(true); //la imagen mira a la derecha
            vel_movimiento.x = this -> obtenerVelocidad().x < 0 ? this -> obtenerVelocidad().x * -1 : this -> obtenerVelocidad().x;
            if(v.x - ima_spr.x <= vel_movimiento.x) // si la distancia del enemigo es menor a la velucidad
                vel_movimiento.x = 0;
        }
        else{
            //enemigo esta a la izquierda
            if(v.x < ima_spr.x){
                this->setPosicionDeLaImagen(false); // mira a la izquierda
                vel_movimiento.x = this -> obtenerVelocidad().x > 0 ? this -> obtenerVelocidad().x * -1 : this -> obtenerVelocidad().x;
                if(ima_spr.x - v.x <= vel_movimiento.x)
                    vel_movimiento.x = 0;
            }
        }

        if(v.y > ima_spr.y){ // si el enemigo esta arriba
            vel_movimiento.y = this -> obtenerVelocidad().y < 0 ? this -> obtenerVelocidad().y * -1 : this -> obtenerVelocidad().y;
            if(v.y - ima_spr.y <= vel_movimiento.y)
                vel_movimiento.y = 0;
        }
        else{
            if(v.y < ima_spr.y){ //si el enemigo esta anbajo
                vel_movimiento.y = this -> obtenerVelocidad().y > 0 ? this -> obtenerVelocidad().x * -1 : this -> obtenerVelocidad().y;
                if(ima_spr.y - v.y <= vel_movimiento.y)
                    vel_movimiento.y = 0;
            }
        }
       //le suma a la posicion del sprite estos valores definidos en la velocidad
        this -> moveSprite(vel_movimiento.x,vel_movimiento.y);
    }
    else{ //si la imaen es 2 aparecera junto al enemigo
        this -> setPosicionSprite(v.x , v.y);
    } 
    ++imagen; // paso a la proxima imagen

    if(imagen == this -> getCantidadImagenes("correr")) // si el nuemero es mayor a las imagenes disponibles
        imagen_correr = 0;
    else // si el numero no es mayor
        imagen_correr = imagen;

    return false;
}

bool Goku::ataquePatada(){
//los golpes los dara del lado que se tenga configurado la posicion de la imagen 
//usar junto a buscar enemigo
    
    //golpe_patada
    int cantidad_imagenes = this -> getCantidadImagenes("golpe_patada");
    this -> setSpriteIndex("golpe_patada", imagen_patadas);
    ++imagen_patadas;
    if(imagen_patadas == this -> getCantidadImagenes("golpe_patada")){
        imagen_patadas = 0;
        return true;
    }

    return false;
}

Goku::~Goku(){}
