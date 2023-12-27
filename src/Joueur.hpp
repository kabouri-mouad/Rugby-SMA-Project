#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Ballon.hpp"

class Joueur {
    private:
        std::string nom;
        std::string role;
        sf::Vector2f position;
        int numero;
        int vitesse;
        int force;
    public:
        Joueur();
        Joueur(std::string nom, std::string role, int numero, int vitesse, int force, float posX, float posY);
        void circuler(float positionX, float positionY);
        void seDeplacer(Ballon & ballon, float nouvellePositionX, float nouvellePositionY);
        sf::Vector2f getPosition() const;
};

#endif // JOUEUR_HPP