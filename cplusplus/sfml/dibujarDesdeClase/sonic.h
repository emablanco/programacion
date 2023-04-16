#ifndef SONIC_H
#define SONIC_H

#include "personaje.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
class Sonic : public Personaje{

    private:
    
        std::string ruta;
    public:

        Sonic(std::string r = "./imagenes/sonic-sprite.png");
       
        void modificarSprite() override;
    
        ~Sonic()override;

};

#endif /* ifndef SONIC_H
#define SONIC_H

#include "personaje.h"
class Sonic : public Personaje{

}; */
