#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>


class Jugador : public sf::Drawable {
public:
    Jugador() : currentSpriteIndex(0) {}
    ~Jugador() {}

    void loadTextures() {
        // Carga las texturas en el vector sprites
        // En este ejemplo, cargaremos 10 texturas
        for (int i = 0; i < 5; i++) {
            sf::Texture texture;
            texture.loadFromFile(std::to_string(i) + ".png");
            textura.push_back(texture);
        }
    }

    void setSpriteIndex(int index) {
        if (index >= 0 && index < textura.size()) {
            currentSpriteIndex = index;
            sprites.setTexture(textura[index]);
        }
    }

private:
    std::vector<sf::Texture> textura;
    sf::Sprite sprites;
    int currentSpriteIndex;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // Dibuja el sprite actual en la posición (0, 0) de la pantalla
        
        target.draw(sprites, states);
    }
};

