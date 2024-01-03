#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Ballon.hpp"

class Joueur {
    private:
        int numero;
        std::string nom;
        std::string role;
        float vitesse;
        float force;
        sf::Vector2f position;
    public:
        Joueur();
        Joueur(int numero, std::string nom, std::string role, float vitesse, float force, float posX, float posY);
        std::string& getRole();
        int getNumero();
        sf::Vector2f getPosition() const;
        void setPosition(float nouvellePositionX, float nouvellePositionY);
        void circuler(float positionX, float positionY);
        void seDeplacer(const sf::Vector2f& positionBallon, float nouvellePositionX, float nouvellePositionY);
};

#endif // JOUEUR_HPP