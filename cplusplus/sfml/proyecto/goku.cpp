#include "goku.h"
#include "personaje.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>

Goku::Goku(std::string r,float x, float y):Personaje(r,x,y){

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
                    this -> setMovimientos(movimiento, imagen);
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

    this -> setValoresEscala(escalar_x, escalar_y);
    this -> cambiarPosicion(posicion_x, posicion_y);
    this -> setVelocidad(velocidad_x, velocidad_y);
    this -> setImaPosicion(ima_posicion);
    this ->setPuntoDeOrigen(origen_x, origen_y);

    std::cout<<"Datos cargados correctos\n";
}

void Goku::correr(sf::Vector2f ventana, std::string poder){
    
    //obtengo el nuemero de la imagen que se esta usando para correr
    int imagen = this -> getImagenDelMovimiento();
    
    //puntero al sprite
    sf::Sprite *sprite = this -> obtenerSprite();
    
    //preparo el sprite que se imprimira 
    this -> setSpriteIndex(poder, imagen);

    //creo un vector con la velocidad
    sf::Vector2f vel = this -> getVelocidad();
    
    //creo un vector con a posicion del sprite
    sf::Vector2f pos = sprite -> getPosition();

    //aumento en 1 la imagen
    ++imagen;
    
    //cambia el valor del vector de posicion que usara "setSpriteIndex"
    this -> cambiarPosicion(pos.x + vel.x, pos.y);

    if(sprite->getPosition().x < 570)
        if(sprite -> getPosition().x > 530)
            if( this -> getVelocidad().x < 0)
                if(imagen == 3)
                    this -> cambiarPosicion(10, sprite -> getPosition().y);
 
    if(sprite->getPosition().x > 30)
        if(sprite -> getPosition().x < 80)
            if( this -> getVelocidad().x > 0)
                if(imagen == 3)
                    this -> cambiarPosicion(580, sprite -> getPosition().y);
   

//no permito que se pase del lado izquiero de la ventana
   if(sprite->getPosition().x < 20){
       this -> setImaPosicion(true);
       if(vel.x < 0) vel.x *= -1;
       this -> setVelocidad(vel.x, this -> getVelocidad().y);
       sprite->setPosition(20 ,sprite->getPosition().y);
    }

   //no permito que se pase mas del tamaño de el ancho de la ventana
   if(sprite->getPosition().x > (ventana.x-20)){
       this ->setImaPosicion(false);
       if(vel.x > 0) vel.x *= -1;
       this -> setVelocidad(vel.x, this -> getVelocidad().y);
       sprite->setPosition((ventana.x-20),sprite->getPosition().y);
    }

   //actualizo la posicion de la textura
   if(imagen < this -> cantidadImagenes(poder))
       this -> setImagenDelMovimiento(imagen);

   //reseteo cuando para que comience por la primera textura
   if(imagen == this -> cantidadImagenes(poder))
       this -> setImagenDelMovimiento(0);
    
   sprite = nullptr;
}

bool Goku::atacarEnemigo(){

    return ataquePatada();
}

bool Goku::buscarEnemigo(sf::Vector2f v){

    //velocidad
    sf::Vector2f vel_movimiento = this -> getVelocidad();
    //posicion del sprite en la ventana
    sf::Vector2f ima_spr = this -> getPosicionSprite();
    //textura que se esta dibijando
    int imagen = this -> getImagenDelMovimiento();

    //si se encuentra en la posicion devuelve true.
    if(v.x == ima_spr.x and v.y == ima_spr.y){
        if(!this -> getImaPosicion()){
            this -> moveSprite(10, 0);
        }
        this -> setSpriteIndex("correr", imagen);
        return true;
    }
    //si la imagen no corresponde a la imagen de transportacion
    if(imagen != 4){

        if(v.x > ima_spr.x){
            this->setImaPosicion(true); //la imagenmira a la derecha
            vel_movimiento.x = this -> getVelocidad().x < 0 ? this -> getVelocidad().x * -1 : this -> getVelocidad().x;
            if(v.x - ima_spr.x <= vel_movimiento.x) vel_movimiento.x = 0;
        }
        else{
            if(v.x < ima_spr.x){
                this->setImaPosicion(false); // mira a la izquierda
                vel_movimiento.x = this -> getVelocidad().x > 0 ? this -> getVelocidad().x * -1 : this -> getVelocidad().x;
                if(ima_spr.x - v.x <= vel_movimiento.x) vel_movimiento.x = 0;
            }
        }

        if(v.y > ima_spr.y){
            vel_movimiento.y = this -> getVelocidad().y < 0 ? this -> getVelocidad().y * -1 : this -> getVelocidad().y;
            if(v.y - ima_spr.y <= vel_movimiento.y) vel_movimiento.y = 0;
        }
        else{
            if(v.y < ima_spr.y){
                vel_movimiento.y = this -> getVelocidad().y > 0 ? this -> getVelocidad().x * -1 : this -> getVelocidad().y;
                if(ima_spr.y - v.y <= vel_movimiento.y) vel_movimiento.y = 0;
            }
        }
       //le suma a la posicion del sprite estos valores
        this -> moveSprite(vel_movimiento.x,vel_movimiento.y);
    }
    else{
        this -> cambiarPosicion(v.x , v.y);
    }

    this -> setSpriteIndex("correr", imagen);
    
    ++imagen;
    
    return false;
}

Goku::~Goku(){}
