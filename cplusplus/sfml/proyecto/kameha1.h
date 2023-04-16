#ifndef KAMEHA_H
#define KAMEHA_H

#include <string>
#include "personaje.h"
#include <fstream>
#include <string>
#include <cctype>
#include <SFML/Graphics/Texture.hpp>
#include "poder.h"
class Kameha1: public Poder{

    private:

    public:
        Kameha1();
        Kameha1(const Kameha1&)= delete;
        ~Kameha1()override;
};
#endif /* ifndef DEBUG */
