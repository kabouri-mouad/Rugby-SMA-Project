#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Ballon.hpp"

class Joueur {
    private:
        std::string nom;
        std::string role;
        sf::Vector2f position;
        int numero;
        float vitesse;
        float force;
    public:
        Joueur();
        Joueur(std::string nom, std::string role, int numero, float vitesse, float force, float posX, float posY);
        std::string& getRole();
        void circuler(float positionX, float positionY);
        void seDeplacer(const sf::Vector2f& positionBallon, float nouvellePositionX, float nouvellePositionY);
        sf::Vector2f getPosition() const;
};

#endif // JOUEUR_HPP