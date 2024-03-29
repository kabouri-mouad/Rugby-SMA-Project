#include "EquipeRugby.hpp"

EquipeRugby::EquipeRugby() {}

EquipeRugby::EquipeRugby(const std::string& nomEquipe) : nomEquipe(nomEquipe), notesEquipe(0) {}

std::string& EquipeRugby::getNomEquipe() {
    return nomEquipe;
}

std::vector<Joueur>& EquipeRugby::getJoueurs() {
    return joueurs;
}

int EquipeRugby::getNotesEquipe() const {
    return notesEquipe;
}

void EquipeRugby::attribuerNotesEquipe(int notesAAjouter) {
    notesEquipe += notesAAjouter;
}

void EquipeRugby::ajouterJoueur(const Joueur& joueur) {
    joueurs.push_back(joueur);
}