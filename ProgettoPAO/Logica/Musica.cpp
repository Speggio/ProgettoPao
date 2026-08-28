#include "Musica.h"

Musica::Musica(std::string nome, std::string descr, int sodd, QDateTime dataIn, int tempDed,
    std::string branoPref, std::string artPref, std::string generePrinc, int nBrani,
    bool scopMusic) :
    Attivita(nome, descr, sodd, dataIn, tempDed), branoPreferito(branoPref),
    artistaPreferito(artPref), generePrincipale(generePrinc), numeroBrani(nBrani),
    scopertaMusicale(scopMusic) {
}

std::string Musica::dettagliSpecifici() const {
    return "In questa sessione sono stati ascoltati " + std::to_string(numeroBrani) +
        " brani, il brano preferito e' stato: " + branoPreferito + " di: " + artistaPreferito +
        " mentre il genere ascoltato maggiormente e': " + generePrincipale + ". " +
        (scopertaMusicale ? "Sono stati scoperti nuovi brani"
                          : "Non sono stati scoperti nuovi brani");
}

std::string Musica::getBranoPreferito() const {
    return this->branoPreferito;
}
std::string Musica::getArtistaPreferito() const {
    return this->artistaPreferito;
}
std::string Musica::getGenerePrincipale() const {
    return this->generePrincipale;
}
int Musica::getNumeroBrani() const {
    return this->numeroBrani;
}
bool Musica::getScopertaMusicale() const {
    return this->scopertaMusicale;
}

void Musica::setBranoPreferito(std::string branoPref) {
    branoPreferito = branoPref;
}
void Musica::setArtistaPreferito(std::string artPref) {
    artistaPreferito = artPref;
}
void Musica::setGenerePrincipale(std::string generePrinc) {
    generePrincipale = generePrinc;
}
void Musica::setNumeroBrani(int nBrani) {
    numeroBrani = nBrani;
}
void Musica::setScopertaMusicale(bool scopMusic) {
    scopertaMusicale = scopMusic;
}