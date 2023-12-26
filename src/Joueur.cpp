#include "Joueur.hpp"

Joueur::Joueur(){}

Joueur::Joueur(std::string nom, std::string role, int numero, int vitesse, int force, float posX, float posY) : nom(nom), role(role), numero(numero), vitesse(vitesse), force(force), position(posX, posY){}

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
    std::cout << nom << " se déplace vers la position [" << position.x << ", " << position.y << "]" << "\n";
}

sf::Vector2f Joueur::getPosition() const {
  return position;
};