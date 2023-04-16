#ifndef NUDILLOS_H
#define NUDILLOS_H

#include "personaje.h"
#include <string>
class Nudillos : public Personaje{

    private:
    
        std::string ruta;
    public:

        Nudillos(std::string r = "./imagenes/nudillos.png");
    
        void modificarSprite() override;
        
        virtual ~Nudillos()override;

};

#endif /* ifndef NUDILLOS_H
#define NUDILLOS_H

#include "personaje.h"
class Nudillos : public Personaje{

}; */
