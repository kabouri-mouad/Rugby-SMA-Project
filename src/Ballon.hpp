#ifndef BALLON_HPP
#define BALLON_HPP

#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Equipe.hpp"

class Ballon {
    private:
        sf::Vector2f position;
        Equipe equipePossedante =  EQUIPE_2;
    public:
        Ballon();
        Ballon(float posX, float posY);
        void seDeplacer(float nouvellePositionX, float nouvellePositionY);
        sf::Vector2f getPosition();
        void setPosition(float posX, float posY);
        Equipe getEquipePossedante() const;
        void setEquipePossedante(Equipe nouvelleEquipe);
};

#endif // BALLON_HPP