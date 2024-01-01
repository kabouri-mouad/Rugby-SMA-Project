#ifndef SIMULATION_RUGBY_HPP
#define SIMULATION_RUGBY_HPP

#include "EquipeRugby.hpp"

class SimulationRugby {
  public:
    void demarrer();
    Ballon& getBallon();
    EquipeRugby& getEquipe1();
    EquipeRugby& getEquipe2();
    static sf::Vector2f getWindowSize();

  private:
    EquipeRugby equipe1{};
    EquipeRugby equipe2{};
    Ballon ballon;
    static sf::Vector2f windowSize;
    void init(sf::RenderWindow& window, sf::Sprite& sprite);
    void initialiserEquipes();
    void initialiserBallon();
    void dessinerEquipes(sf::RenderWindow& window);
    void dessinerBallon(sf::RenderWindow& window);
    void circulerJoueurs();
    void circulerBallon();
    void bougerEquipes();
    void bougerBallon();
    bool marquerUnIci();
    void transformation(sf::RenderWindow& window, sf::Sprite& sprite);
    void bougerBallonTransformation();
};

#endif // SIMULATION_RUGBY_HPP