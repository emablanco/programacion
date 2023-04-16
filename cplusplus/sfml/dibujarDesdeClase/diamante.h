#ifndef DIAMANTE_H
#define DIAMANTE_H

#include "personaje.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>
class Diamante : public Personaje{

    private:
    
        std::string ruta;
    public:

        Diamante(std::string r = "./imagenes/diamante.png");
    
        void modificarSprite() override;
        
        ~Diamante()override;

};

#endif /* ifndef DIAMANTE_H
#define DIAMANTE_H

#include "personaje.h"
class Diamante : public Personaje{

}; */
