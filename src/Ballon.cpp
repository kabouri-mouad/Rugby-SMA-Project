#include "Ballon.hpp"

Ballon::Ballon(){}

Ballon::Ballon(float posX, float posY): position(posX, posY) {}

void Ballon::seDeplacer(float nouvellePositionX, float nouvellePositionY) {
    
    position.x += nouvellePositionX;
    position.y += nouvellePositionY;

    // Assurez-vous que le ballon reste dans les limites du terrain
    if (position.x < 0) {
        position.x = 500;
    } else if (position.x > 1000) {
        position.x = 500;
    }

    if (position.y < 0) {
        position.y = 250;
    } else if (position.y > 500) {
        position.y = 250;
    }

    // std::cout << "Le ballon se déplace vers la position [" << position.x << ", " << position.y << "]" << std::endl;
}

sf::Vector2f Ballon::getPosition() const {
    return position;
}

void Ballon::setPosition(float posX, float posY) {
    position = sf::Vector2f(posX, posY);
}