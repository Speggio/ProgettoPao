#ifndef SPORT_H
#define SPORT_H
#include "Attivita.h"

class Sport : public Attivita {
private:
    std::string tipoSport;
    int calorie;
    int freqCardiacaMedia;

public:
    Sport(std::string nome, std::string descrizione, int soddisfazione, QDateTime dataInizio,
        int tempoDedicato, std::string tipoSport, int calorie, int freqCardiacaMedia);

    std::string dettagliSpecifici() const override;

    std::string getTipoSport() const;
    int getCalorie() const;
    int getfreqCardiacaMedia() const;

    void setTipoSport(std::string sport);
    void setCalorie(int calorie);
    void setfreqCardiacaMedia(int freqCardiacaMedia);
};

#endif