#ifndef LEGO_H
#define LEGO_H
#include "Attivita.h"

class Lego : public Attivita {
private:
    std::string nomeSet;
    std::string tipologiaSet;
    int pezziTot;
    bool completato;

public:
    Lego(std::string nome, std::string descrizione, int soddisfazione, QDateTime dataInizio,
        int tempoDedicato, std::string nomeSet, std::string tipologiaSet, int pezziTot,
        bool completato);

    std::string dettagliSpecifici() const override;

    std::string getNomeSet() const;
    std::string getTipologiaSet() const;
    int getPezziTot() const;
    bool getCompletato() const;

    void setNomeSet(std::string nomeSet);
    void setTipologiaSet(std::string tipologiaSet);
    void setPezziTot(int pezziTot);
    void setCompletato(bool completato);
};

#endif