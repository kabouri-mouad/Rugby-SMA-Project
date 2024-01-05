#ifndef EQUIPERUGBY_HPP
#define EQUIPERUGBY_HPP

#include "Joueur.hpp"

class EquipeRugby {
    private:
        std::string nomEquipe;
        std::vector<Joueur> joueurs;
        int notesEquipe = 0;
    public:
        EquipeRugby();
        EquipeRugby(const std::string& nomEquipe);
        std::string& getNomEquipe();
        std::vector<Joueur>& getJoueurs();
        int getNotesEquipe() const;
        void attribuerNotesEquipe(int notesAAjouter);
        void ajouterJoueur(const Joueur& joueur);
};

#endif // EQUIPERUGBY_HPP