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
    
        Goku(std::string r = "./image/DBZ/GOKU4/0.png", float x = 100, float y = 100);
        ~Goku()override;
};
#endif /* ifndef DEBUG */
