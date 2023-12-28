#include "Joueur.hpp"

Joueur::Joueur(){}

Joueur::Joueur(std::string nom, std::string role, int numero, float vitesse, float force, float posX, float posY) : nom(nom), role(role), numero(numero), vitesse(vitesse), force(force), position(posX, posY){}

std::string& Joueur::getRole() {
    return role;
}

void Joueur::circuler(float positionX, float positionY) {
    position.x += positionX;
    position.y += positionY;
}

void Joueur::seDeplacer(const sf::Vector2f& positionBallon, float nouvellePositionX, float nouvellePositionY) {
    
    if(positionBallon.x > position.x ) {
        position.x += nouvellePositionX * vitesse;
    }else {
        position.x -= nouvellePositionX * vitesse;
    }

    
    if(positionBallon.y > position.y) {
        position.y += nouvellePositionY;
    }else{
        position.y -= nouvellePositionY;
    }
    // std::cout << nom << " se déplace vers la position [" << position.x << ", " << position.y << "]" << "\n";
}

sf::Vector2f Joueur::getPosition() const {
  return position;
};