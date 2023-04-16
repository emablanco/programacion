#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
#include <SFML/Graphics/Drawable.hpp>
#include <map>
#include <vector>

class Personaje: public sf::Drawable{

    private:

        sf::Texture ima_tex;
        sf::Sprite ima_spr;
        std::map<std::string,std::vector<sf::Texture>> movimientos;

    protected:

        bool setMovimientos(std::string,sf::Texture);

    public:

        Personaje(std::string r);
        
        bool setSpriteIndex(std::string m, int);



        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

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
