#ifndef VIDEOGIOCHI_H
#define VIDEOGIOCHI_H
#include "Attivita.h"

class Videogiochi : public Attivita {
private:
    std::string nomeGioco;
    std::string piattaforma;
    std::string genere;
    bool completato;

public:
    Videogiochi(std::string nome, std::string descrizione, int soddisfazione, QDateTime dataInizio,
        int tempoDedicato, std::string nomeGioco, std::string piattaforma, std::string genere,
        bool completato);

    std::string dettagliSpecifici() const override;

    std::string getNomeGioco() const;
    std::string getPiattaforma() const;
    std::string getGenere() const;
    bool getCompletato() const;

    void setNomeGioco(std::string nomeGioco);
    void setPiattaforma(std::string piattaforma);
    void setGenere(std::string genere);
    void setCompletato(bool completato);
};

#endif