#ifndef ATTIVITA_H
#define ATTIVITA_H
#include <QDateTime>
#include <string>

// forwarding
class VisitorAttivita;

class Attivita {

private:
    std::string nome;
    std::string descrizione;

    int soddisfazione;

    QDateTime dataInizio;
    int tempoDedicato;

public:
    Attivita(std::string nome, std::string descrizione, int soddisfazione, QDateTime dataInizio,
        int tempoDedicato);
    virtual ~Attivita();

    virtual std::string dettagliSpecifici() const = 0;
    virtual void accetta(VisitorAttivita &va) = 0;
    virtual std::string riepilogo() const;
    std::string conversioneOrario() const;
    int oreDaTempoDedicato() const;
    int minutiDaTempoDedicato() const;

    std::string getNome() const;
    std::string getDescrizione() const;
    int getSoddisfazione() const;
    QDateTime getDataInizio() const;
    int getTempoDedicato() const;

    void setNome(std::string nome);
    void setDescrizione(std::string descrizione);
    void setSoddisfazione(int soddisfazione);
    void setTempoDedicato(int tempoDedicato);
};

#endif