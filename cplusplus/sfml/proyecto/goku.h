#ifndef GOKU_H
#define GOKU_H

#include <string>
#include "personaje.h"
#include <fstream>
#include <string>
#include <cctype>
#include <SFML/Graphics/Texture.hpp>
class Goku: public Personaje{

    private:

    public:
    
        Goku( std::string ruta = "./image/LUCHADORES/GOKU4.png", float x = 100, float y = 100);
        Goku(const Goku&)= delete;
        ~Goku()override;
};
#endif /* ifndef DEBUG */
