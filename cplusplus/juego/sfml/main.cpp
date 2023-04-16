#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana de 800x600 píxeles
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ejemplo");

    // Cargar el fondo de pantalla
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("campo.jpg"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite background(backgroundTexture);

    // Cargar la imagen del personaje 1
    sf::Texture characterTexture1;
    if (!characterTexture1.loadFromFile("personaje1.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite character1(characterTexture1);
    character1.setScale(0.5f, 0.5f); // Redimensionar el sprite a la mitad del tamaño original
    character1.setPosition(50.f, 300.f); // Posicionar el sprite a la izquierda

    // Cargar la imagen del personaje 2
    sf::Texture characterTexture2;
    if (!characterTexture2.loadFromFile("personaje2.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite character2(characterTexture2);
    character2.setScale(-0.5f, 0.5f); // Redimensionar y voltear el sprite a la mitad del tamaño original
    character2.setPosition(750.f, 300.f); // Posicionar el sprite a la derecha

    // Bucle principal del juego
    while (window.isOpen())
    {
        // Manejar eventos de la ventana
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Si se recibe el evento de cerrar la ventana, cerrarla
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Dibujar el fondo de pantalla y los sprites en la ventana
        window.clear();
        window.draw(background);
        window.draw(character1);
        window.draw(character2);
        window.display();
    }

    return EXIT_SUCCESS;
}

