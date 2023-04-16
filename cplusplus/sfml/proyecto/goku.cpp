#include "goku.h"
#include <string>

Goku::Goku(std::string r): Personaje(r){

    std::ifstream archivo("./configuraciones/config_goku.txt"); // Abre el archivo
    
    if(archivo.is_open()){
    
        std::string cadena;
        std::string movimiento;

        while (std::getline(archivo,cadena)) {

            //https://cplusplus.com/reference/string/string/empty/
            if(!cadena.empty() and std::isalpha(cadena[0])){
                movimiento = cadena;
            }

            if (!cadena.empty() and cadena[0] == '.') {
                sf::Texture imagen;
                imagen.loadFromFile(cadena);
                this -> setMovimientos(movimiento, imagen);
            } 
            
        }

        archivo.close();
    }
}

Goku::~Goku(){}
