#include "Lego.h"

Lego::Lego(std::string nome, std::string descr, int sodd, QDateTime dataIn, int tempDed,
    std::string nomeSet, std::string typeSet, int pezTot, bool comp) :
    Attivita(nome, descr, sodd, dataIn, tempDed), nomeSet(nomeSet), tipologiaSet(typeSet),
    pezziTot(pezTot), completato(comp) {
}

std::string Lego::dettagliSpecifici() const {
    return "Il set: " + nomeSet + " fa parte della tipologia: " + tipologiaSet +
        " e ha: " + std::to_string(pezziTot) + " pezzi totali (" +
        (completato ? "completato" : "non completato") + ")";
}

std::string Lego::getNomeSet() const {
    return this->nomeSet;
}
std::string Lego::getTipologiaSet() const {
    return this->tipologiaSet;
}
int Lego::getPezziTot() const {
    return this->pezziTot;
}
bool Lego::getCompletato() const {
    return this->completato;
}

void Lego::setNomeSet(std::string nomeSet) {
    this->nomeSet = nomeSet;
}
void Lego::setTipologiaSet(std::string typeSet) {
    tipologiaSet = typeSet;
}
void Lego::setPezziTot(int pezTot) {
    pezziTot = pezTot;
}
void Lego::setCompletato(bool comp) {
    completato = comp;
}