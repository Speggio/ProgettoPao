#include "Videogiochi.h"

Videogiochi::Videogiochi(std::string nome, std::string descr, int sodd, QDateTime dataIn,
    int tempDed, std::string nomeGioco, std::string piattaforma, std::string genere, bool comp) :
    Attivita(nome, descr, sodd, dataIn, tempDed), nomeGioco(nomeGioco), piattaforma(piattaforma),
    genere(genere), completato(comp) {
}

std::string Videogiochi::dettagliSpecifici() const {
    return "Il videogioco: " + nomeGioco + " si trova nella piattaforma: " + piattaforma +
        " e come genere ha: " + genere + " (" + (completato ? "completato" : "non completato") +
        ")";
}

std::string Videogiochi::getNomeGioco() const {
    return this->nomeGioco;
}
std::string Videogiochi::getPiattaforma() const {
    return this->piattaforma;
}
std::string Videogiochi::getGenere() const {
    return this->genere;
}
bool Videogiochi::getCompletato() const {
    return this->completato;
}

void Videogiochi::setNomeGioco(std::string nomeGioco) {
    this->nomeGioco = nomeGioco;
}
void Videogiochi::setPiattaforma(std::string piattaforma) {
    this->piattaforma = piattaforma;
}
void Videogiochi::setGenere(std::string genere) {
    this->genere = genere;
}
void Videogiochi::setCompletato(bool comp) {
    completato = comp;
}