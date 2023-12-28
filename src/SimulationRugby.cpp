#include "SimulationRugby.hpp"
#include "mt19937ar.c"

sf::Vector2f SimulationRugby::windowSize(1000.0f, 500.0f);

void SimulationRugby::demarrer() {

    //Initialisation du générateur MT
    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
    init_by_array(init, length);

    float rand = 0.0f;

    Ballon& ballon = getBallon();

    initialiserEquipes();
    initialiserBallon();

    sf::RenderWindow window(sf::VideoMode(1000, 500), "Simulation Rugby");

    sf::Texture texture;
    if (!texture.loadFromFile("../images/rugby-playground.jpg")) {
        std::cerr << "Error: Impossible de telecharger l\'image !" << "\n";
        exit(1);
    }

    sf::Sprite sprite(texture);

    // Redimensionnez le sprite pour qu'il ait les mêmes dimensions que la fenêtre
    sprite.setScale(
        SimulationRugby::getWindowSize().x / sprite.getLocalBounds().width,
        SimulationRugby::getWindowSize().y / sprite.getLocalBounds().height
    );

    this->init(window, sprite);

    sf::Clock clock;  
    sf::Time elapsed = clock.getElapsedTime();

    while (window.isOpen() && clock.getElapsedTime().asSeconds() < 300) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(marquerUnIci()) {
            initialiserEquipes();
            initialiserBallon();
            this->init(window, sprite);
        }

        window.clear();
        window.draw(sprite);

        bougerBallon();
        bougerEquipes();

        rand = uniform(0, 1);

        if(rand < 0.0001) {
            Equipe equipe = ballon.getEquipePossedante();
            if(equipe == EQUIPE_1) {
                ballon.setEquipePossedante(EQUIPE_2);
            }else {
                ballon.setEquipePossedante(EQUIPE_1);
            }
        }

        dessinerEquipes(window);
        dessinerBallon(window);
        window.display();
    }
}

Ballon& SimulationRugby::getBallon() {
    return ballon;
}

EquipeRugby& SimulationRugby::getEquipe1() {
    return equipe1;
}

EquipeRugby& SimulationRugby::getEquipe2() {
    return equipe2;
}

sf::Vector2f SimulationRugby::getWindowSize() {
    return windowSize;
}

void SimulationRugby::init(sf::RenderWindow &window, sf::Sprite & sprite) {

    sf::Clock clock;  
    sf::Time elapsed = clock.getElapsedTime();
    while(window.isOpen() && clock.getElapsedTime().asSeconds() < 5) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        circulerJoueurs();
        // circulerBallon();

        window.clear();
        window.draw(sprite);

        // Dessinez les joueurs et le ballon
        dessinerEquipes(window);
        dessinerBallon(window);
        window.display();
    }
}

void SimulationRugby::initialiserEquipes() {

    EquipeRugby& equipe1 = getEquipe1();
    EquipeRugby& equipe2 = getEquipe2();

    equipe1.getJoueurs().clear();
    equipe2.getJoueurs().clear();

    // Équipe 1
    equipe1.ajouterJoueur(Joueur("J1E1", "pilier", 1, 0.1f, 10, 530, 400));
    equipe1.ajouterJoueur(Joueur("J2E1", "talonneur", 2, 0.1f, 10, 520, 250));
    equipe1.ajouterJoueur(Joueur("J3E1", "pilier", 3, 0.1f, 10, 530, 100));

    equipe1.ajouterJoueur(Joueur("J4E1", "verrouillage", 4, 0.1f, 10, 580, 350));
    equipe1.ajouterJoueur(Joueur("J5E1", "verrouillage", 5, 0.1f, 10, 580, 150));

    equipe1.ajouterJoueur(Joueur("J6E1", "ailier", 6, 0.1f, 10, 620, 400));
    equipe1.ajouterJoueur(Joueur("J8E1", "centre", 8, 0.1f, 10, 620, 250));
    equipe1.ajouterJoueur(Joueur("J7E1", "ailier", 7, 0.1f, 10, 620, 100));

    equipe1.ajouterJoueur(Joueur("J9E1", "demiMelee", 9, 0.1f, 6, 670, 350));
    equipe1.ajouterJoueur(Joueur("J10E1", "demiOuverture", 10, 0.1f, 6, 670, 150));

    equipe1.ajouterJoueur(Joueur("J11E1", "ailier", 11, 0.1f, 5, 750, 450));
    equipe1.ajouterJoueur(Joueur("J12E1", "centre", 12, 0.1f, 5, 750, 350));
    equipe1.ajouterJoueur(Joueur("J13E1", "centre", 13, 0.1f, 5, 750, 150));
    equipe1.ajouterJoueur(Joueur("J14E1", "ailier", 14, 0.1f, 5, 750, 50));

    equipe1.ajouterJoueur(Joueur("J15E1", "arriere", 15, 0.01f, 6, 900, 250));

    // Équipe 2
    equipe2.ajouterJoueur(Joueur("J1E2", "pilier", 1, 0.1f, 10, 460, 100));
    equipe2.ajouterJoueur(Joueur("J2E2", "talonneur", 2, 0.1f, 10, 470, 250));
    equipe2.ajouterJoueur(Joueur("J3E2", "pilier", 3, 0.1f, 10, 460, 400));

    equipe2.ajouterJoueur(Joueur("J4E2", "verrouillage", 4, 0.1f, 10, 400, 150));
    equipe2.ajouterJoueur(Joueur("J5E2", "verrouillage", 5, 0.1f, 10, 400, 350));

    equipe2.ajouterJoueur(Joueur("J6E2", "ailier", 6, 0.1f, 10, 350, 100));
    equipe2.ajouterJoueur(Joueur("J8E2", "centre", 8, 0.1f, 10, 350, 250));
    equipe2.ajouterJoueur(Joueur("J7E2", "ailier", 7, 0.1f, 10, 350, 400));
    
    equipe2.ajouterJoueur(Joueur("J9E2", "demiMelee", 9, 0.1f, 10, 300, 150));
    equipe2.ajouterJoueur(Joueur("J10E2", "demiOuverture", 10, 0.1f, 10, 300, 350));

    equipe2.ajouterJoueur(Joueur("J11E2", "ailier", 11, 0.1f, 10, 220, 50));
    equipe2.ajouterJoueur(Joueur("J12E2", "centre", 12, 0.1f, 10, 220, 150));
    equipe2.ajouterJoueur(Joueur("J13E2", "centre", 13, 0.1f, 10, 220, 350));
    equipe2.ajouterJoueur(Joueur("J14E2", "ailier", 14, 0.1f, 10, 220, 450));

    equipe2.ajouterJoueur(Joueur("J15E2", "arriere", 15, 0.01f, 10, 100, 250));

}

void SimulationRugby::initialiserBallon() {
    Ballon& ballon = getBallon();
    // Calculez la position au milieu de la fenêtre
    float posX = static_cast<float>(getWindowSize().x) / 2;
    float posY = static_cast<float>(getWindowSize().y) / 2;
    ballon.setPosition(posX, posY);
}

void SimulationRugby::dessinerEquipes(sf::RenderWindow &window) {
    std::vector<Joueur>& joueursEquipe1 = getEquipe1().getJoueurs();  // Obtenez une référence aux joueurs
    std::vector<Joueur>& joueursEquipe2 = getEquipe2().getJoueurs();  // Obtenez une référence aux joueurs

    sf::CircleShape joueurShape(10.0f);

    joueurShape.setFillColor(sf::Color::Blue);
    for (Joueur & joueur : joueursEquipe1) {
        joueurShape.setPosition(joueur.getPosition());
        window.draw(joueurShape);
    }

    joueurShape.setFillColor(sf::Color::Red);
    for (Joueur & joueur : joueursEquipe2) {
        joueurShape.setPosition(joueur.getPosition());
        window.draw(joueurShape);
    }

}

void SimulationRugby::dessinerBallon(sf::RenderWindow &window) {
    sf::CircleShape ballonShape(7.0f);
    ballonShape.setFillColor(sf::Color::White);

    ballonShape.setPosition(getBallon().getPosition());
    window.draw(ballonShape);
}

void SimulationRugby::circulerJoueurs() {
    std::vector<Joueur>& joueursEquipe1 = getEquipe1().getJoueurs();  // Obtenez une référence aux joueurs
    std::vector<Joueur>& joueursEquipe2 = getEquipe2().getJoueurs();  // Obtenez une référence aux joueurs

    for (Joueur & joueur : joueursEquipe1) {
        joueur.circuler(uniform(-.1f, .1f), uniform(-.1f, .1f));
    }

    for (Joueur & joueur : joueursEquipe2) {
        joueur.circuler(uniform(-.1f, .1f), uniform(-.1f, .1f));
    }
}

void SimulationRugby::circulerBallon() {
    getBallon().seDeplacer(uniform(-.1f, .1f), uniform(-.1f, .1f));
}

void SimulationRugby::bougerEquipes() {

    std::vector<Joueur>& joueursEquipe1 = getEquipe1().getJoueurs();  // Obtenez une référence aux joueurs
    std::vector<Joueur>& joueursEquipe2 = getEquipe2().getJoueurs();  // Obtenez une référence aux joueurs

    Ballon& ballon = getBallon();
    const sf::Vector2f& positionBallon = ballon.getPosition();

    for (Joueur & joueur : joueursEquipe1) {
        const std::string& role = joueur.getRole();
        if (role == "pilier" || role == "talonneur") {
            joueur.seDeplacer(positionBallon, uniform(0, 2), uniform(0, .1));
        } else if (role == "verrouillage" || role == "ailier" || role == "centre") {
            joueur.seDeplacer(positionBallon, uniform(0, 1.5), uniform(0, .1));
        } else if (role == "demiMelee" || role == "demiOuverture") {
            joueur.seDeplacer(positionBallon, uniform(0, .5), uniform(0, .1));
        } else if (role == "arriere") {
            joueur.seDeplacer(positionBallon, uniform(0, .2), uniform(0, .1));
        } else {
            // Gestion pour d'autres rôles non couverts
            std::cout << "Role non pris en charge pour l'équipe 1 : " << role << "\n";
        }
    }

    for (Joueur & joueur : joueursEquipe2) {
        const std::string& role = joueur.getRole();
        if (role == "pilier" || role == "talonneur") {
            joueur.seDeplacer(positionBallon, uniform(0, 2), uniform(0, .1));
        } else if (role == "verrouillage" || role == "ailier" || role == "centre") {
            joueur.seDeplacer(positionBallon, uniform(0, 1.5), uniform(0, .1));
        } else if (role == "demiMelee" || role == "demiOuverture") {
            joueur.seDeplacer(positionBallon, uniform(0, .5), uniform(0, .1));
        } else if (role == "arriere") {
            joueur.seDeplacer(positionBallon, uniform(0, .2), uniform(0, .1));
        } else {
            // Gestion pour d'autres rôles non couverts
            std::cout << "Role non pris en charge pour l'équipe 1 : " << role << "\n";
        }
    }
}

void SimulationRugby::bougerBallon() {
    getBallon().seDeplacer(uniform(0.0f, 0.1f), uniform(-2, 2));
}

bool SimulationRugby::marquerUnIci() {
    Ballon& ballon = getBallon();
    const sf::Vector2f& position = ballon.getPosition();
    EquipeRugby& equipe1 = getEquipe1();
    EquipeRugby& equipe2 = getEquipe2();

    if(position.x < 60 && position.y > 20 && position.y < 460 && ballon.getEquipePossedante() == EQUIPE_1 && (position.y < 240 || position.y > 250)) {
        equipe1.attribuerNotesEquipe(5);
        ballon.setEquipePossedante(EQUIPE_2);
        std::cout << "Equipe1 | " << equipe1.getNotesEquipe() << " : " << equipe2.getNotesEquipe() << " | Equipe2" << "\n";
        return true;
    }

    if(position.x > 940 && position.y > 40 && position.y < 460 && ballon.getEquipePossedante() == EQUIPE_2  && (position.y < 240 || position.y > 250)) {
        equipe2.attribuerNotesEquipe(5);
        ballon.setEquipePossedante(EQUIPE_1);
        std::cout << "Equipe1 | " << equipe1.getNotesEquipe() << " : " << equipe2.getNotesEquipe() << " | Equipe2" << "\n";
        return true;
    }
    return false;
}