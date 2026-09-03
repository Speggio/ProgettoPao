#include "GestoreAttivita.h"
#include "GestoreJson.h"
#include "Lego.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <iostream>

GestoreAttivita::GestoreAttivita(QObject *parent) : QObject(parent) {
}

Attivita *GestoreAttivita::creaAttivitaSport(std::string tit, std::string desc, int sodd,
    QDateTime dt, int tempoTotale, std::string tipoSport, int calorie, int freCard) {

    Attivita *nuova = nullptr;

    nuova = new Sport(tit, desc, sodd, dt, tempoTotale, tipoSport, calorie, freCard);
    return nuova;
}
Attivita *GestoreAttivita::creaAttivitaLego(std::string tit, std::string desc, int sodd,
    QDateTime dt, int tempoTotale, std::string nomeSet, std::string tipologiaSet, int pezziTot,
    bool completato) {

    Attivita *nuova = nullptr;

    nuova = new Lego(tit, desc, sodd, dt, tempoTotale, nomeSet, tipologiaSet, pezziTot, completato);
    return nuova;
}
Attivita *GestoreAttivita::creaAttivitaMusica(std::string tit, std::string desc, int sodd,
    QDateTime dt, int tempoTotale, std::string branoPrefe, std::string artistaPrefe,
    std::string generePrinc, int nBrani, bool scopertaMusi) {

    Attivita *nuova = nullptr;

    nuova = new Musica(tit, desc, sodd, dt, tempoTotale, branoPrefe, artistaPrefe, generePrinc,
        nBrani, scopertaMusi);
    return nuova;
}
Attivita *GestoreAttivita::creaAttivitaVideogioco(std::string tit, std::string desc, int sodd,
    QDateTime dt, int tempoTotale, std::string nomeGioco, std::string piattaforma,
    std::string genere, bool completato) {

    Attivita *nuova = nullptr;

    nuova = new Videogiochi(tit, desc, sodd, dt, tempoTotale, nomeGioco, piattaforma, genere,
        completato);
    return nuova;
}

void GestoreAttivita::aggiungiAttivita(Attivita *a) {

    attivita.push_back(std::unique_ptr<Attivita>(a));

    emit attivitaCambiate();
}

void GestoreAttivita::eliminaAttivita(Attivita *a) {
    auto it = std::find_if(attivita.begin(), attivita.end(),
        [a](const std::unique_ptr<Attivita> &up) { return up.get() == a; });
    if (it != attivita.end()) {
        attivita.erase(it);
    }

    emit attivitaCambiate();
}

const std::vector<std::unique_ptr<Attivita>> &GestoreAttivita::elencoAttivita() const {
    return attivita;
}

void GestoreAttivita::salvaJson(const QString &nomeFile) const {

    std::vector<Attivita *> temp;
    for (const auto &up : attivita) {
        temp.push_back(up.get());
    }
    GestoreJson::salvaInFile(nomeFile, temp);
}

void GestoreAttivita::caricaJson(const QString &nomeFile) {
    std::vector<Attivita *> temp;
    GestoreJson::caricaDaFile(nomeFile, temp);

    attivita.clear();
    for (Attivita *raw : temp) {
        attivita.push_back(std::unique_ptr<Attivita>(raw));
    }

    emit attivitaCambiate();
}