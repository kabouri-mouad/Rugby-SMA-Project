#include "Joueur.hpp"

Joueur::Joueur(){}

Joueur::Joueur(std::string nom, std::string role, int numero, int vitesse, int force, float posX, float posY) : nom(nom), role(role), numero(numero), vitesse(vitesse), force(force), position(posX, posY){}

void Joueur::circuler(float positionX, float positionY) {
    position.x += positionX;
    position.y += positionY;

    // Assurez-vous que le ballon reste dans les limites du terrain
    if (position.x < 0) {
        position.x += 1000;
    } else if (position.x > 1000) {
        position.x -= 1000;
    }

    if (position.y < 0) {
        position.y += 500;
    } else if (position.y > 500) {
        position.y -= 500;
    }
}

void Joueur::seDeplacer(Ballon & ballon, float nouvellePositionX, float nouvellePositionY) {
    if(ballon.getPosition().x > position.x) {
        position.x += nouvellePositionX;
    }else {
        position.x -= nouvellePositionX;
    }
    if(ballon.getPosition().y > position.y) {
        position.y += nouvellePositionX;
    }else {
        position.y -= nouvellePositionX;
    }
    // std::cout << nom << " se déplace vers la position [" << position.x << ", " << position.y << "]" << "\n";
}

sf::Vector2f Joueur::getPosition() const {
  return position;
};