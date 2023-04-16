#include "kameha1.h"
#include <string>
#include <iostream>
Kameha1::Kameha1(){

    float valor_x = 100;
    float valor_y = 100;

    std::ifstream archivo("./configuraciones/config_kameha1.txt");
    if(archivo.is_open()){
    
        std::string cadena;
        std::string poder;

        while (std::getline(archivo,cadena)) {
        
            if(!cadena.empty() and cadena[0] == 'y' or cadena[0] == 'x'){
       
                float valor;
                // Buscamos el símbolo "="
                size_t posicion = cadena.find('=');
                
                if (posicion != std::string::npos) {
                    // Extraemos la subcadena que sigue al símbolo "="
                    std::string valor_str = cadena.substr(posicion + 1);
                    // Convertimos la subcadena en un valor float
                    valor = std::stof(valor_str);
            
                    if(cadena[0] == 'x') valor_x = valor; 
            
                    if(cadena[0] == 'y') valor_y = valor;
                }
            }

            else{
            
                //https://cplusplus.com/reference/string/string/empty/
                if(!cadena.empty() and std::isalpha(cadena[0])){
                    poder = cadena;
                }
                
                if (!cadena.empty() and cadena[0] == '.') {
                
                    sf::Texture imagen;
                    imagen.loadFromFile(cadena);
                    this -> setPoderes(poder, imagen);
                } 
            }
        }

        archivo.close();
        
        this -> setValoresEscala(valor_x, valor_y);
    }
}

Kameha1::~Kameha1(){}
