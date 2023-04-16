#ifndef ANILLO_H
#define ANILLO_H

#include "personaje.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
class Anillo : public Personaje{

    private:
    
        std::string ruta;
    public:

        Anillo(std::string r = "./imagenes/anillo.png");
    
        void modificarSprite() override;
        
        virtual ~Anillo()override;

};

#endif /* ifndef ANILLO_H
#define ANILLO_H

#include "personaje.h"
class Anillo : public Personaje{

}; */
