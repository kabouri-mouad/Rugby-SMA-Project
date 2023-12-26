#include "Ballon.hpp"

Ballon::Ballon(){}

Ballon::Ballon(float posX, float posY): position(posX, posY) {}

void Ballon::seDeplacer(float nouvellePositionX, float nouvellePositionY) {
     // float deplacementX = uniform(-1.0f, 1.0f) * nouvellePositionX; // Utilisation de la fonction uniform pour générer un déplacement aléatoire
    // float deplacementY = uniform(-1.0f, 1.0f) * nouvellePositionY;

    position.x += nouvellePositionX;
    position.y += nouvellePositionY;

    // Assurez-vous que le ballon reste dans les limites du terrain
    if (position.x < 0) {
        position.x = 0;
    } else if (position.x > 200) {
        position.x = 200;
    }

    if (position.y < 0) {
        position.y = 0;
    } else if (position.y > 40) {
        position.y = 40;
    }

    std::cout << "Le ballon se déplace vers la position [" << position.x << ", " << position.y << "]" << std::endl;
}

sf::Vector2f Ballon::getPosition() const {
    return position;
}

void Ballon::setPosition(float posX, float posY) {
    position = sf::Vector2f(posX, posY);
}