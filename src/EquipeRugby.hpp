#include "Joueur.hpp"

class EquipeRugby {
    private:
        std::string nomEquipe;
        std::vector<Joueur> joueurs;
        int notesEquipe = 0;
    public:
        EquipeRugby();
        EquipeRugby(const std::string& nomEquipe);
        void ajouterJoueur(const Joueur& joueur);
        std::string& getNomEquipe();
        std::vector<Joueur>& getJoueurs();
        int getNotesEquipe() const;
        void attribuerNotesEquipe(int notesAAjouter);
};