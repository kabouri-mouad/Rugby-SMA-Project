#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class Ballon {
    private:
        sf::Vector2f position;
    public:
        Ballon();
        Ballon(float posX, float posY);
        void seDeplacer(float nouvellePositionX, float nouvellePositionY);
        sf::Vector2f getPosition() const;
        void setPosition(float posX, float posY);
};