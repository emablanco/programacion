#ifndef GOKU_H
#define GOKU_H

#include <string>
#include "personaje.h"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <string>
#include <cctype>
#include <SFML/Graphics/Texture.hpp>
class Goku: public Personaje{

    private:

        int life;

    public:
    
        Goku( std::string ruta = "./image/LUCHADORES/GOKU4.png", float x = 100, float y = 100);
        
        Goku(const Goku&)= delete;

        bool ataquePatada();
        
//-------------------VIRTUALES ------------------------------------

        //recibe golpes 
        bool recibirGolpes(int) override;

        bool dibujarMuerto()override;
        
        //buscar enemigo
        bool buscarEnemigo(sf::Vector2f, bool m = true) override;

        //seleccionar que tipo de ataque random
        bool atacarEnemigo(sf::Vector2f) override;

        //esperar ataque del enemigo
        bool esperarAtaque() override;

        //turno finalizado
        bool finalizarTurno(sf::Vector2f, sf::Vector2f) override;

        //iniciar turno
        bool ki()override;

        ~Goku()override;
};
#endif /* ifndef DEBUG */
