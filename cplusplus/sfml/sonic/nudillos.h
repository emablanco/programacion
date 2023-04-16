#ifndef NUDILLOS_H
#define NUDILLOS_H

#include "personaje.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
class Nudillos : public Personaje{

    private:

    public:
        Nudillos(std::string r = "nudillos.png");

        virtual ~Nudillos() override;
};

#endif /* ifndef NUDILLOS_H
#define NUDILLOS_H

class Nudillos{

    private:
    public:
}; */
