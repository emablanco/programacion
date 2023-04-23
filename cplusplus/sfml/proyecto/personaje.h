#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <vector>
#include "coliciones.h"


class Personaje: public sf::Drawable, public Coliciones{

    private:

        //estado del personaje
        bool estado;

        //textura por defecto del personaje.
        sf::Texture ima_tex;

        //variable sprite queusare para todas las texturas
        sf::Sprite ima_spr;

        //mapa donde por cada movimiento "string" se guardan texturas
        std::map<std::string,std::vector<sf::Texture>> movimientos;

        //controlar que imagen se esta usando para el movimiento
        std::map<std::string,int> num_movimientos;
    
        //vector2f donde se guardan los valores de escala para la image
        sf::Vector2f escalar;

        //para configurar el punto de origen del sprite
        sf::Vector2f punto_de_origen;

        //vector2f para la velocidad del movimiento
        sf::Vector2f velocidad;

        //para voltear la imagen - adonde mira
        bool ima_posicion;
       
        //posicion de la imagen enla ventana
        sf::Vector2f posicion;

        //metodo para dibujar el personaje
        void draw(sf::RenderTarget &target, sf::RenderStates states)const{
            target.draw(ima_spr,states);
        }

    protected:

        //cargar imagenes dentro del mapa
        bool agregarImagenesParaMovimientos(std::string,sf::Texture);

        //modificar imagen del movimiento
        bool modificarImagenDelMovimiento(std::string,int);

        //mapa para guardar el index del movimiento
        bool agregarMovimientosIndex(std::string,int);
        
        //cambiar los valore para la escala de las imagenes
        bool valoresParaEscalarImagen(float,float);
        
        //cambiar los valores de la velocidad del movimiento
        bool configurarVelocidad(float,float);

       //obtener un vector2f con la velocidad
        sf::Vector2f obtenerVelocidad();

        //valores de escala de las imagenes 100 por defecto
        sf::Vector2f obtenerEscalar();

        //false mira a la izquierda 
        //true mira a la derecha
        bool obtenerParaDondeMiraLaImagen()const;

        //le sumo a la posicion actual del sprite 
        //similar a la funcion move
        bool moveSprite(float,float);

    public:

        Personaje(std::string r, float, float);

        Personaje(const Personaje&)=delete;

        //obtener imaen del movimiento
        int getIndexImagenDelMovimiento(std::string);

        //devolver la posicion del sprite en la ventana
        sf::Vector2f getPosicionSprite();

        //obtener el estado del personaje vivo o muerto
        bool getEstado()const;

        //cantidad de imagenes disponibles para el movimiento
        int getCantidadImagenes(std::string);

        //sera la posicion por defecto del sprite
        bool setPosicionSprite(float,float);

        //frames de movimiento para usar con "move" o "setPosition"
        bool setVelocidad(float, float);
       
        //cargar el sprite que se imprimira con draw
        bool setSpriteIndex(std::string m,int index);

        //la imagen mirara a la derecha o izquierda
        bool setPosicionDeLaImagen(bool);
 
        //PUNTO DE ORIGEN POR DEFECTO PARA TODOS LOS SPRITE
        bool setPuntoDeOrigenPorDefecto(float x,float y);

        //cambiar el punto de origen para el sprite actual
        bool setPuntoDeOrigenSprite(float x,float y);

        //cambar el estado del personaje. vivo o muerto
        bool setEstado(bool );


// --------------------- COLICIONES ------------------------------------
        
        sf::FloatRect buscarGlobal()const override;

//---------------------------- VIRTUAL --------------------------------


        virtual bool dibujarMuerto()=0;
        
        virtual bool recibirGolpes(sf::Clock *, sf::Time *,float,int) =0;
        
        //buscar enemigo
        virtual bool buscarEnemigo(sf::Vector2f)=0;

        //atacar al enemigo
        virtual bool atacarEnemigo()=0;

        //destructor virtual
        virtual ~Personaje(){}
};

#endif /* ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

class Personaje: {

    private:

        sf::Texture ima_tex;
        sf::Sprite ima_spr;

    public:

        Personaje(std::string r);
}; */
