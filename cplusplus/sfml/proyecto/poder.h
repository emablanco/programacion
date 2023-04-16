#ifndef PODER_H
#define PODER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <vector>

class Poder: public sf::Drawable{

    private:
        std::map<std::string,std::vector<sf::Texture>> poderes;
        sf::Sprite ima_spr;
       
        float scale_x;
        float scale_y;
 
        void draw(sf::RenderTarget &target, sf::RenderStates states) const{
            target.draw(ima_spr,states);
        }

    protected:

        bool setPoderes(std::string,sf::Texture);
        bool setValoresEscala(float,float);

    public:
        Poder(float x = 100, float y = 100);
        
        bool setSpriteIndex(std::string m, int);
        int cantidadImagenes(std::string);
        bool setPuntoOrigen(float, float, std::string, int);
        sf::Vector2f getPosicion();
        bool setPosicion(float,float);
        
        virtual ~Poder(){};
};
#endif /* ifndef DEBUG */
