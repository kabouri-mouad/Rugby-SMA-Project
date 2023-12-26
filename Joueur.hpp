#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include<string>
#include <SFML/Graphics.hpp>
#include "Ballon.hpp"

class Joueur {
    private:
        std::string nom;
        std::string type;
        sf::Vector2f position;
        int vitesse;
        int force;
    public:
        Joueur();
        Joueur(std::string nom, std::string type, int vitesse, int force, float posX, float posY) : nom(nom), type(type), vitesse(vitesse), force(force), position(posX, posY);
        void seDeplacer(Ballon & ballon, float nouvellePositionX, float nouvellePositionY);
        sf::Vector2f getPosition() const;
};

#endif // JOUEUR_HPP