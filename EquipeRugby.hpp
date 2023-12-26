#include<string>
#include <vector>

class EquipeRugby {
    private:
        std::string nomEquipe;
        std::vector<Joueur> joueurs;
        int notesEquipe;
    public:
        EquipeRugby(const std::string& nomEquipe) : nomEquipe(nomEquipe), notesEquipe(0);
        void ajouterJoueur(const Joueur& joueur);
        const std::string& getNomEquipe() const;
        const std::vector<Joueur>& getJoueurs() const;
        int getNotesEquipe() const;
        void attribuerNotesEquipe(int nouvellesNotes);
};