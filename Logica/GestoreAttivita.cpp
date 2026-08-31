#include "GestoreAttivita.h"
#include "Lego.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <iostream>

GestoreAttivita::GestoreAttivita(QObject *parent) : QObject(parent) {

    // TUTTA ROBA PER LA BASH DA SISTEMA
    QDateTime data(QDate(2025, 10, 10), QTime(0, 0));

    attivita.push_back(std::make_unique<Sport>("Sessione di calcio", "Allenamento di calcio", 10,
        data, 180, "Calcio", 350, 145));
    attivita.push_back(std::make_unique<Musica>("Ascolto", "Sessione di ascolto", 8, data, 150,
        "Fame", "Nayt", "Indie", 15, true));
    attivita.push_back(std::make_unique<Lego>("Costruzione", "Sessione Lego", 9, data, 120,
        "Porsche", "Technic", 1580, false));
    attivita.push_back(std::make_unique<Videogiochi>("Gioco", "Sessione videogiochi", 6, data, 25,
        "Fortnite", "Epic", "Battle Royale", false));

    for (const auto &a : attivita) {
        std::cout << a->riepilogo() << std::endl;
    }
    // FINE ROBA PER BASH DA SISTEMA
}

void GestoreAttivita::aggiungiAttivita(Attivita *a) {

    attivita.push_back(std::unique_ptr<Attivita>(a));

    emit attivitaCambiate();
}

void GestoreAttivita::eliminaAttivita(Attivita *a) {
    auto it = std::find_if(attivita.begin(), attivita.end(),
        [a](const std::unique_ptr<Attivita> &up) { return up.get() == a; });
    if (it != attivita.end()) {
        attivita.erase(it); // qui l'unique_ptr esistente viene distrutto correttamente
    }

    emit attivitaCambiate();
}

const std::vector<std::unique_ptr<Attivita>> &GestoreAttivita::elencoAttivita() const {
    return attivita;
}