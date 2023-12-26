#include "EquipeRugby.hpp"

EquipeRugby::EquipeRugby(const std::string& nomEquipe) : nomEquipe(nomEquipe), notesEquipe(0) {}

void EquipeRugby::ajouterJoueur(const Joueur& joueur) {
    joueurs.push_back(joueur);
}

const std::string& EquipeRugby::getNomEquipe() const {
    return nomEquipe;
}

const std::vector<Joueur>& EquipeRugby::getJoueurs() const {
    return joueurs;
}

int EquipeRugby::getNotesEquipe() const {
    return notesEquipe;
}

void EquipeRugby::attribuerNotesEquipe(int nouvellesNotes) {
    notesEquipe = nouvellesNotes;
}