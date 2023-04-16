#ifndef ANILLO_H
#define ANILLO_H

#include "personaje.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
class Anillo : public Personaje{

    private:

    public:
        Anillo(std::string r = "anillo.png");

        virtual ~Anillo()override;
};

#endif /* ifndef ANILLO_H
#define ANILLO_H

class Anillo{

    private:
    public:
}; */
