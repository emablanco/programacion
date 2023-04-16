#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{

    std::srand(time(0));

    sf::RenderWindow ventana1(sf::VideoMode(600,400),"Emanuel");

    sf::Texture ima_tex;
    ima_tex.loadFromFile("./imagenes/sonic-sprite.png");
    
    sf::Sprite ima_spr1(ima_tex);
    sf::Sprite ima_spr2(ima_tex);
    sf::Sprite ima_spr3(ima_tex);
    sf::Sprite ima_spr4(ima_tex);
    sf::Event evento;

    sf::IntRect a1(0,157,53,51);
    sf::IntRect a2(53,157,53,51);
    sf::IntRect a3(106,157,53,51);
    sf::IntRect a4(159,157,53,51);

    ima_spr1.setTextureRect(a1);
    ima_spr2.setTextureRect(a2);
    ima_spr3.setTextureRect(a3);
    ima_spr4.setTextureRect(a4);

    ima_spr1.setPosition(rand() % 500, rand() % 300);
    ima_spr2.setPosition(rand() % 500, rand() % 300);
    ima_spr3.setPosition(rand() % 500, rand() % 300);
    ima_spr4.setPosition(rand() % 500, rand() % 300);


    while(ventana1.isOpen()){

        ventana1.clear(sf::Color::Red);
        ventana1.draw(ima_spr1);
        ventana1.draw(ima_spr2);
        ventana1.draw(ima_spr3);
        ventana1.draw(ima_spr4);
        ventana1.display();

    
    }

    return EXIT_SUCCESS;
}
