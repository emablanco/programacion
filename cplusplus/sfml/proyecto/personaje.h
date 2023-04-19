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
class Personaje: public sf::Drawable{

    private:

        //textura por defecto del personaje.
        sf::Texture ima_tex;

        //variable sprite queusare para todas las texturas
        sf::Sprite ima_spr;

        //mapa donde por cada movimiento "string" se guardan texturas
        std::map<std::string,std::vector<sf::Texture>> movimientos;

        //vector2f donde se guardan los valores de escala para la image
        sf::Vector2f escalar;

        //para configurar el punto de origen del sprite
        sf::Vector2f puntoOrigen;

        //vector2f para la velocidad del movimiento
        sf::Vector2f velocidad;

        //para voltear la imagen - adonde mira
        bool ima_posicion;
       
        //posicion de la imagen enla ventana
        sf::Vector2f posicion;

        //la posicion de la textura que esta usando el sprite
        int imagen_del_movimiento;

        bool vivo;

        //metodo para dibujar el personaje
        void draw(sf::RenderTarget &target, sf::RenderStates states)const{
            target.draw(ima_spr,states);
        }
    protected:
                //cargar imagenes dentro del mapa
        bool setMovimientos(std::string,sf::Texture);

        //cambiar los valore para la escala de las imagenes
        bool setValoresEscala(float,float);
        
        //cambiar los valores de la velocidad del movimiento
        bool setVelocidad(float,float);

        //cambiar numero que hace referencia a la posicion de la textura
        bool setImagenDelMovimiento(int);

        //obtener el numero de la imagen del movimiento
        int getImagenDelMovimiento();

        //obtener un vector2f con la velocidad
        sf::Vector2f getVelocidad();

        //obtener los valores de escala de las imagenes
        sf::Vector2f getEscalar();

        //obtener la direcion de memoria del sprite
        sf::Sprite *obtenerSprite();

        //devuelve el valor de la posicion de la imagen
        //true no se voltea
        //false se voltea
        bool getImaPosicion()const;

        //mover la posicion del sptrite en la pantalla
        bool moveSprite(float,float);

    public:

        Personaje(std::string r, float, float);
        Personaje(const Personaje&)=delete;

        //si el personaje esta vivo
        bool estaVivo()const;

        //cargar el sprite que se imprimira con draw
        bool setSpriteIndex(std::string m,int index);

        //cantidad de imagenes disponibles para el movimiento
        int cantidadImagenes(std::string);
       
        //cambiar el pinto de origen del sprite
        bool setPuntoOrigen(float, float, std::string, int);
        
        //sera la posicion por defecto del sprite
        bool cambiarPosicion(float,float);
       
        //frames de movimiento para usar con "move" o "setPosition"
        bool cambiarVelocidad(float, float);
       
        //la imagen mirara a la derecha o izquierda
        bool setImaPosicion(bool);
        
        //cambiar punto de origen
        bool setPuntoDeOrigen(float,float);

        //devolver la posicion del sprite en la ventana
        sf::Vector2f getPosicionSprite();

        //movimientos del personaje
        virtual void correr(sf::Vector2f,std::string)=0;

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
