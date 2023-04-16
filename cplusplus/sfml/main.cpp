#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Menú");

    sf::Font font;
    if (!font.loadFromFile("./Boba Cups.ttf")) {
        return EXIT_FAILURE;
    }

    sf::Text textPlay("Jugar", font, 50);
    sf::Text textSelect("Seleccionar personaje", font, 50);

    textPlay.setPosition(200, 200);
    textSelect.setPosition(200, 300);

    int selectedOption = 0;
    bool isEnterPressed = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    selectedOption--;
                    if (selectedOption < 0) {
                        selectedOption = 1;
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    selectedOption++;
                    if (selectedOption > 1) {
                        selectedOption = 0;
                    }
                }
                if (event.key.code == sf::Keyboard::Enter) {
                    isEnterPressed = true;
                }
            }
        }

        if (isEnterPressed) {
            if (selectedOption == 0) {
                // Opción "Jugar" seleccionada
                // Agrega aquí el código para iniciar el juego
            }
            if (selectedOption == 1) {
                // Opción "Seleccionar personaje" seleccionada
                // Agrega aquí el código para mostrar la pantalla de selección de personajes
            }
            isEnterPressed = false;
        }

        // Cambia el color del texto de la opción seleccionada
        textPlay.setFillColor(sf::Color::Black);
        textSelect.setFillColor(sf::Color::Black);
        if (selectedOption == 0) {
            textPlay.setFillColor(sf::Color::Red);
        }
        if (selectedOption == 1) {
            textSelect.setFillColor(sf::Color::Red);
        }

        window.clear(sf::Color::Green);
        window.draw(textPlay);
        window.draw(textSelect);
        window.display();
    }

    return EXIT_SUCCESS;
}

