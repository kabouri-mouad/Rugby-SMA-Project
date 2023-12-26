#ifndef SIMULATION_RUGBY_HPP
#define SIMULATION_RUGBY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "mt19937ar.c"

class SimulationRugby {
  public:
      void demarrer();
      Ballon getBallon();
      std::vector<Joueur> getJoueurs();
      static sf::Vector2f getWindowSize();
  private:
      std::vector<Joueur> joueurs;
      Ballon ballon;
      static sf::Vector2f windowSize;
      void initialiserJoueurs();
      void initialiserBallon();
      void dessinerJoueurs(sf::RenderWindow &window);
      void dessinerBallon(sf::RenderWindow &window);
      void bougerJoueurs();
      void bougerBallon();
};

#endif // SIMULATION_RUGBY_HPP
