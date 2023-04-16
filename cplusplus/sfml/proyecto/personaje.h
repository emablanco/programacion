#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>
#include <vector>
class Personaje: public sf::Drawable{

    private:

        sf::Texture ima_tex;
        sf::Sprite ima_spr;
        std::map<std::string,std::vector<sf::Texture>> movimientos;
        float scale_x;
        float scale_y;
        void draw(sf::RenderTarget &target, sf::RenderStates states)const{
    target.draw(ima_spr,states);
}
    protected:

        bool setMovimientos(std::string,sf::Texture);
        bool setValoresEscala(float,float);

    public:

        Personaje(std::string r, float, float);

        bool setSpriteIndex(std::string m, int);
        int cantidadImagenes(std::string);
        bool setPuntoOrigen(float, float, std::string, int);
        sf::Vector2f getPosicion();
        bool setPosicion(float,float);

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
