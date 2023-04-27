#include "goku.h"
#include "personaje.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <iostream>

Goku::Goku(std::string r,float x, float y):Personaje(r,x,y),life(10){

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
                        if(cadena[1] == 'l')
                            life = valor;
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
                    this -> agregarMovimientosIndex(movimiento, 0);
                    std::cout<<"Movimiento: "<<movimiento<<" valor: 0\n";
                    std::cout<<"Movimiento: "<<movimiento<<" ruta: "<<cadena<<"\n";
                } 
            }
        }
    }
    archivo.close();
    std::cout<<"Movimiento: 'ki' valor: 0\n";
    std::cout<<"Valor Escala: "<<escalar_x<<" "<<escalar_y<<"\n";
    std::cout<<"Valor Posicion: "<<posicion_x<<" "<<posicion_y<<"\n";
    std::cout<<"Valor Escala: "<<velocidad_x<<" "<<velocidad_y<<"\n";
    std::cout<<"Valor origen: "<<origen_x<<" "<<origen_y<<"\n";
    std::cout<<"Life: "<<life<<"\n";
    
    this -> valoresParaEscalarImagen(escalar_x, escalar_y);
    this -> setPosicionSprite(posicion_x, posicion_y);
    this -> configurarVelocidad(velocidad_x, velocidad_y);
    this -> setPosicionDeLaImagen(ima_posicion);
    this -> setPuntoDeOrigenPorDefecto(origen_x, origen_y);
    this -> agregarMovimientosIndex("ki", 0);
    std::cout<<"Datos cargados correctos\n";
}

bool Goku::atacarEnemigo(sf::Vector2f e){

    e.x += this -> getPosicionSprite().x < e.x ? -20 : 20;

    if(buscarEnemigo(e))
        return ataquePatada();
    else
        return false;
}

bool Goku::buscarEnemigo(sf::Vector2f v, bool m){

    sf::Vector2f p;
    p = this ->getPosicionSprite();

    //para donde va a mirar el sprite
    //this -> setPosicionDeLaImagen(v.x < p.x ? false : true);

    int imagen = this -> getIndexImagenDelMovimiento("correr");
    
    //cuando llegue al enemigo no cambia mas de sprite
    if(imagen == 0 and p.x == v.x and p.y == v.y){
        return true;
    
    //preparar sprite para dibujar
    this -> setSpriteIndex("correr", imagen);

    //aumento
    ++imagen;
   
    //esta es la textura de transportacion
    if(imagen == 3){
        this -> setPosicionDeLaImagen(v.x < p.x ? !m : m);
        this -> setPosicionSprite(v.x, v.y);
    } 
    //si el index de las imagenes es igual al tamaño
    this -> agregarMovimientosIndex("correr", imagen == this->getCantidadImagenes("correr") ? 0 : imagen);
    
    return false;
}
/**
bool Goku::buscarEnemigo(sf::Vector2f v){

    //velocidad
    sf::Vector2f vel_movimiento = this -> obtenerVelocidad();
    //posicion del sprite en la ventana
    sf::Vector2f ima_spr = this -> getPosicionSprite();
    //si se encuentra en la posicion devuelve true.

    int imagen = this -> getIndexImagenDelMovimiento("correr");

//------ no siempre queda en x del enemigo-------------------------------------
    sf::Vector2f posicion_imagen(0,0);
    posicion_imagen.x = 0;
   
    if(imagen == 0){
        if(v.x > ima_spr.x)
            posicion_imagen.x = v.x - ima_spr.x;
        else
            posicion_imagen.x = ima_spr.x - v.x;
    }
//-----------------------------------------------------------------------------


    if(posicion_imagen.x <= vel_movimiento.x and ima_spr.y == v.y){
    
        return true;
    }
    else{
        //textura que se esta dibijando
        this -> setSpriteIndex("correr", imagen);
    
        //si la imagen no corresponde a la imagen de transportacion
        if(imagen != 2){
            if(v.x == ima_spr.x){
                vel_movimiento.x = 0;
           //enemigo esta a la derecha
            }else{ 
                if(v.x > ima_spr.x){
                    this->setPosicionDeLaImagen(true); //la imagen mira a la derecha
                    vel_movimiento.x = this -> obtenerVelocidad().x < 0 ? this -> obtenerVelocidad().x * -1 : this -> obtenerVelocidad().x;
                    if(v.x - ima_spr.x <= vel_movimiento.x) // si la distancia del enemigo es menor a la velucidad
                        vel_movimiento.x = 0;
                }else{
            //enemigo esta a la izquierda
                    if(v.x < ima_spr.x){
                        this->setPosicionDeLaImagen(false); // mira a la izquierda
                        vel_movimiento.x = this -> obtenerVelocidad().x > 0 ? this -> obtenerVelocidad().x * -1 : this -> obtenerVelocidad().x;
                        if(ima_spr.x - v.x <= vel_movimiento.x)
                            vel_movimiento.x = 0;
                    }
                }
            }
            if(v.y == ima_spr.y){
                vel_movimiento.y = 0;
            }else{
                if(v.y > ima_spr.y){ // si el enemigo esta arriba
                    vel_movimiento.y = this -> obtenerVelocidad().y < 0 ? this -> obtenerVelocidad().y * -1 : this -> obtenerVelocidad().y;
                    if(v.y - ima_spr.y <= vel_movimiento.y)
                        vel_movimiento.y = 0;
                }else{
                    if(v.y < ima_spr.y){ //si el enemigo esta anbajo
                        vel_movimiento.y = this -> obtenerVelocidad().y > 0 ? this -> obtenerVelocidad().x * -1 : this -> obtenerVelocidad().y;
                        if(ima_spr.y - v.y <= vel_movimiento.y)
                            vel_movimiento.y = 0;
                    }
                }
           }
            //le suma a la posicion del sprite estos valores definidos en la velocidad
            this -> moveSprite(vel_movimiento.x,vel_movimiento.y);
        }
        else {//si la imaen es 2 aparecera junto al enemigo
            this -> setVelocidad(0,0);
            this -> setPosicionSprite(v.x , v.y);
        }

        ++imagen; // paso a la proxima imagen

        if(imagen == this -> getCantidadImagenes("correr")) // si el nuemero es mayor a las imagenes disponibles
            this -> agregarMovimientosIndex("correr",0);
        else // si el numero no es mayor
            this -> agregarMovimientosIndex("correr",imagen);
        
        return false;
    }
    return false;
}


**/
bool Goku::ataquePatada(){
//los golpes los dara del lado que se tenga configurado la posicion de la imagen 
//usar junto a buscar enemigo
    
    int imagen_patadas = this -> getIndexImagenDelMovimiento("golpes");
    //golpe_patada
    int cantidad_imagenes = this -> getCantidadImagenes("golpes");
    //preparar sprite para dibujar
    this -> setSpriteIndex("golpes", imagen_patadas);
    ++imagen_patadas;
    if(imagen_patadas == this -> getCantidadImagenes("golpes"))
        this -> agregarMovimientosIndex("golpes",0);
    else // si el numero no es mayor
        this -> agregarMovimientosIndex("golpes",imagen_patadas);
    
    return true;
}

bool Goku::recibirGolpes(int damage){

    if(this -> getEstado()){
    
        life -= damage;
        
        std::cout<<life<<"\n";
        
        //imagen del movimiento
        int imagen_golpeado = this ->  getIndexImagenDelMovimiento("golpeado");
        
        this -> setSpriteIndex("golpeado", imagen_golpeado);//dibujar

        ++imagen_golpeado; //aumento el index 
            
        if(imagen_golpeado < 3)
            this -> agregarMovimientosIndex("golpeado",imagen_golpeado);//aumento
        else
            this -> agregarMovimientosIndex("golpeado",0);//aumento
            
       if(life <= 0)
            this -> setEstado(false);
        }
    return this ->getEstado();
}

bool Goku::dibujarMuerto(){
    if(!this->getEstado()){
        this ->valoresParaEscalarImagen(80,35);
        this -> setSpriteIndex("golpeado", 4);//dibujar
        return true;//si lo dibuja devulve true
    }
    return false; //si el personaje esta vivo revuelve falso
}

bool Goku::finalizarTurno(sf::Vector2f ventana, sf::Vector2f posicion_ene){
   
    //textura que se esta dibijando
    int imagen = this -> getIndexImagenDelMovimiento("descanso");

    std::cout <<"Descanso: "<<imagen<<"\n";
    std::cout <<"cantidad de imagenes: "<<this->getCantidadImagenes("descanso")<<"\n";
    std::cout <<"Imagen del movimiento: "<<this->getIndexImagenDelMovimiento("descanso")<<"\n";

    if(imagen < 2){
        std::cout<<"entro\n";
        if(posicion_ene.x < this -> getPosicionSprite().x)
            this -> setPosicionDeLaImagen(false);
        else
            this -> setPosicionDeLaImagen(true);
    
        this -> setSpriteIndex("descanso", imagen);//dibujar
        ++imagen;
        this -> agregarMovimientosIndex("descanso",imagen);//aumento
        return true; // no se dibijaron todas las imagenes
    }

    if(posicion_ene.x < (ventana.x / 2.f)){
        this->setPosicionSprite((ventana.x -50.f), ventana.y);
        this -> setPosicionDeLaImagen(false);
    }
    else {
        this->setPosicionSprite(50.f, ventana.y);
        this -> setPosicionDeLaImagen(true);
    }

    this -> setSpriteIndex("descanso",imagen);//dibujar
    
    ++imagen;
    
    if(imagen == this -> getCantidadImagenes("descanso")){
        this -> agregarMovimientosIndex("descanso", 0);
        return true; //se dibijaron todas las imagenes
    }
    else
        this -> agregarMovimientosIndex("descanso",imagen);//aumento
    return false; //no se dibijaron todas las imagenes
}

bool Goku::ki(){
    
    int imagen_ki = this -> getIndexImagenDelMovimiento("descanso"); 
    
    if(imagen_ki == 0)
        imagen_ki += 6;
    else
        ++imagen_ki;

    this -> setSpriteIndex("descanso", imagen_ki);//dibujar
    
    if(imagen_ki < 7)
        this-> agregarMovimientosIndex("descanso", imagen_ki);
    else{
        this-> agregarMovimientosIndex("descanso", 0);
        return true;
    }
    return false;
}

bool Goku::esperarAtaque(){
    return true;
}

Goku::~Goku(){}
