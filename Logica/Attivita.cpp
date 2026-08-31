#include "Attivita.h"
#include <stdexcept>

Attivita::Attivita(std::string nome, std::string descr, int sodd, QDateTime dataIn, int tempDed) :
    nome(nome), descrizione(descr), soddisfazione(sodd), dataInizio(dataIn),
    tempoDedicato(tempDed) {
}

Attivita::~Attivita() {
}

std::string Attivita::riepilogo() const {
    return dataInizio.toString("dd/MM/yyyy").toStdString() + " - " + nome + " (" + descrizione +
        ") [" + conversioneOrario() + ", soddisfazione: " + std::to_string(soddisfazione) +
        "/10]: " + dettagliSpecifici();
}

std::string Attivita::conversioneOrario() const {
    if (tempoDedicato <= 59) {
        return std::to_string(tempoDedicato) + "min";
    }
    return std::to_string(oreDaTempoDedicato()) + "h " + std::to_string(minutiDaTempoDedicato()) +
        "min";
}

int Attivita::oreDaTempoDedicato() const {
    return tempoDedicato / 60;
}

int Attivita::minutiDaTempoDedicato() const {
    return tempoDedicato % 60;
}

std::string Attivita::getNome() const {
    return this->nome;
}
std::string Attivita::getDescrizione() const {
    return this->descrizione;
}
int Attivita::getSoddisfazione() const {
    return this->soddisfazione;
}
QDateTime Attivita::getDataInizio() const {
    return this->dataInizio;
}
int Attivita::getTempoDedicato() const {
    return this->tempoDedicato;
}

void Attivita::setSoddisfazione(int sodd) {
    if (sodd < 0 || sodd > 10) {
        throw std::invalid_argument("Soddisfazione deve essere tra 0 e 10");
    }
    soddisfazione = sodd;
}
void Attivita::setTempoDedicato(int tempDed) {
    if (tempDed == 0 || tempDed < 0)
        throw std::invalid_argument("Non si può creare un'attività di 0 minuti");
    else
        tempoDedicato = tempDed;
}
