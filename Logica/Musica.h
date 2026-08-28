#ifndef MUSICA_H
#define MUSICA_H
#include "Attivita.h"

class Musica : public Attivita {
private:
    std::string branoPreferito;
    std::string artistaPreferito;
    std::string generePrincipale;
    int numeroBrani;
    bool scopertaMusicale;

public:
    Musica(std::string nome, std::string descrizione, int soddisfazione, QDateTime dataInizio,
        int tempoDedicato, std::string branoPreferito, std::string artistaPreferito,
        std::string generePrincipale, int numeroBrani, bool scopertaMusicale);

    std::string dettagliSpecifici() const override;

    std::string getBranoPreferito() const;
    std::string getArtistaPreferito() const;
    std::string getGenerePrincipale() const;
    int getNumeroBrani() const;
    bool getScopertaMusicale() const;

    void setBranoPreferito(std::string branoPreferito);
    void setArtistaPreferito(std::string artistaPreferito);
    void setGenerePrincipale(std::string generePrincipale);
    void setNumeroBrani(int numeroBrani);
    void setScopertaMusicale(bool scopertaMusicale);
};

#endif