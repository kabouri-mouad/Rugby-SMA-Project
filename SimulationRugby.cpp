#include "SimulationRugby.hpp"

sf::Vector2f SimulationRugby::windowSize(1000.0f, 500.0f);

void SimulationRugby::demarrer() {

    initialiserJoueurs();
    initialiserBallon();

    sf::RenderWindow window(sf::VideoMode(1000, 500), "Simulation Rugby");

    sf::Texture texture;
    if (!texture.loadFromFile("images/rugby-playground.jpg")) {
        std::cerr << "Error: Impossible de telecharger l\'image !" << "\n";
        exit(1);
    }

    sf::Sprite sprite(texture);

    // Redimensionnez le sprite pour qu'il ait les mêmes dimensions que la fenêtre
    sprite.setScale(
        SimulationRugby::getWindowSize().x / sprite.getLocalBounds().width,
        SimulationRugby::getWindowSize().y / sprite.getLocalBounds().height
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Move players and ball randomly
        bougerJoueurs();
        bougerBallon();

        window.clear();
        window.draw(sprite);

        // Dessinez les joueurs et le ballon
        dessinerJoueurs(window);
        dessinerBallon(window);

        window.display();
    }
}

Ballon SimulationRugby::getBallon() {
    return Ballon;
}

std::vector<Joueur> SimulationRugby::getJoueurs() {
  return joueurs;
}

sf::Vector2f SimulationRugby::getWindowSize() {
    return windowSize;
}

void SimulationRugby::initialiserJoueurs() {
    joueurs.push_back(Joueur("Joueur1", "centre", 0.01f, 8, 400, uniform(0, 500)));
    joueurs.push_back(Joueur("Joueur2", "centre", 0.01f, 8, 400, uniform(0, 500)));
    joueurs.push_back(Joueur("Joueur3", "centre", 0.01f, 8, 400, uniform(0, 500)));
}

void SimulationRugby::initialiserBallon() {
    // Calculez la position au milieu de la fenêtre
    float posX = static_cast<float>(getWindowSize().x) / 2;
    float posY = static_cast<float>(getWindowSize().y) / 2;
    ballon.setPosition(posX, posY);
}

void SimulationRugby::dessinerJoueurs(sf::RenderWindow &window) {
    std::vector<Joueur>& joueursRef = getJoueurs();  // Obtenez une référence aux joueurs

    sf::CircleShape joueurShape(10.0f);
    joueurShape.setFillColor(sf::Color::Blue);

    for (const Joueur & joueur : joueursRef) {
        joueurShape.setPosition(joueur.getPosition());
        window.draw(joueurShape);
    }
}

void SimulationRugby::dessinerBallon(sf::RenderWindow &window) {
    sf::CircleShape ballonShape(5.0f);
    ballonShape.setFillColor(sf::Color::Red);

    ballonShape.setPosition(getBallon().getPosition());
    window.draw(ballonShape);
}

void SimulationRugby::bougerJoueurs() {
    std::vector<Joueur>& joueursRef = getJoueurs();  // Obtenez une référence aux joueurs

    for (Joueur & joueur : joueursRef) {
        joueur.seDeplacer(getBallon(), uniform(0, 1), uniform(0, 1));
    }
}

void SimulationRugby::bougerBallon() {
    getBallon().seDeplacer(uniform(-1.0f, 1.0f), uniform(-1.0f, 1.0f));
}