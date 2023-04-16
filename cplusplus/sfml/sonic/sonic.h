#ifndef SONIC_H
#define SONIC_H

#include "personaje.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
class Sonic : public Personaje{

    private:

    public:
        Sonic(std::string r = "sonic.png");

        virtual ~Sonic()override;
};

#endif /* ifndef SONIC_H
#define SONIC_H

class Sonic{

    private:
    public:
}; */
