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
                    std::cout<<"Movimiento: "<<movimiento<<" ruta: "<<cadena<<"\n";
                } 
            }
        }
    }
    archivo.close();
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

    std::cout<<"Datos cargados correctos\n";
}

bool Goku::atacarEnemigo(){

    return ataquePatada();
}

bool Goku::buscarEnemigo(sf::Vector2f v){

    //textura que se esta dibijando
    int imagen = this -> getIndexImagenDelMovimiento("correr");

    this -> setSpriteIndex("correr", imagen);
 
    //velocidad
    sf::Vector2f vel_movimiento = this -> obtenerVelocidad();
   
    //posicion del sprite en la ventana
    sf::Vector2f ima_spr = this -> getPosicionSprite();
    
    //si se encuentra en la posicion devuelve true.
    if(v.x == ima_spr.x and v.y == ima_spr.y){
        this -> setSpriteIndex("correr", 4);
        this -> agregarMovimientosIndex("correr",0);
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
    else //si la imaen es 2 aparecera junto al enemigo
        this -> setPosicionSprite(v.x , v.y);
     
    ++imagen; // paso a la proxima imagen

    if(imagen == this -> getCantidadImagenes("correr")) // si el nuemero es mayor a las imagenes disponibles
        this -> agregarMovimientosIndex("correr",0);
    else // si el numero no es mayor
        this -> agregarMovimientosIndex("correr",imagen);

    return false;
}

bool Goku::ataquePatada(){
//los golpes los dara del lado que se tenga configurado la posicion de la imagen 
//usar junto a buscar enemigo
    
    int imagen_patadas = this -> getIndexImagenDelMovimiento("golpe_patada");
    //golpe_patada
    int cantidad_imagenes = this -> getCantidadImagenes("golpe_patada");
    //preparar sprite para dibujar
    this -> setSpriteIndex("golpe_patada", imagen_patadas);
    ++imagen_patadas;
    if(imagen_patadas == this -> getCantidadImagenes("golpe_patada"))
        this -> agregarMovimientosIndex("golpe_patada",0);
    else // si el numero no es mayor
        this -> agregarMovimientosIndex("golpe_patada",imagen_patadas);
    
    return true;
}

bool Goku::recibirGolpes(sf::Clock *reloj, sf::Time *tiempo1,float segundos, int damage){

    if(this -> getEstado()){
        *tiempo1 = reloj -> getElapsedTime(); //tiempo actual
        sf::Time tiempo2= sf::seconds(segundos); //timepos maximo a esperar
        life -= damage;
        std::cout<<life<<"\n";
        //imagen del movimiento
        int imagen_golpeado = this ->  getIndexImagenDelMovimiento("golpeado");
        
        if(tiempo1 -> asSeconds() > tiempo2.asSeconds()){
            reloj -> restart();//pongo en 0 el reloj
            this -> setSpriteIndex("golpeado", imagen_golpeado);//dibujar
            ++imagen_golpeado; //aumento el index 
            if(imagen_golpeado < 3)
                this -> agregarMovimientosIndex("golpeado",imagen_golpeado);//aumento
            else
                this -> agregarMovimientosIndex("golpeado",0);//aumento
            if(life <= 0)
                this -> setEstado(false);
        }
    }
    return this ->getEstado();
}

bool Goku::dibujarMuerto(){
    if(!this->getEstado()){
        this -> setSpriteIndex("golpeado", 4);//dibujar
        return true;//si lo dibuja devulve true
    }
    return false; //si el personaje esta vivo revuelve falso
}

Goku::~Goku(){}
