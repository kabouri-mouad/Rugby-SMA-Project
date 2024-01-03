#include "Joueur.hpp"

Joueur::Joueur(){}

Joueur::Joueur(int numero, std::string nom, std::string role, float vitesse, float force, float posX, float posY) : numero(numero), nom(nom), role(role), vitesse(vitesse), force(force), position(posX, posY){}

std::string& Joueur::getRole() {
    return role;
}

int Joueur::getNumero() {
    return numero;
}

sf::Vector2f Joueur::getPosition() const {
  return position;
};

void Joueur::setPosition(float nouvellePositionX, float nouvellePositionY) {
    position.x = nouvellePositionX;
    position.y = nouvellePositionY;
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