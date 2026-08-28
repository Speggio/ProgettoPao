#include "Sport.h"
#include <stdexcept>

Sport::Sport(std::string nome, std::string descr, int sodd, QDateTime dataIn, int tempDed,
    std::string sport, int cal, int fCard) :
    Attivita(nome, descr, sodd, dataIn, tempDed), tipoSport(sport), calorie(cal),
    freqCardiacaMedia(fCard) {
}

std::string Sport::dettagliSpecifici() const {
    return "Nella sessione di: " + tipoSport + " sono state consumate: " + std::to_string(calorie) +
        " avendo una frequenza cardiaca media di: " + std::to_string(freqCardiacaMedia);
}

std::string Sport::getTipoSport() const {
    return this->tipoSport;
}
int Sport::getCalorie() const {
    return this->calorie;
}
int Sport::getfreqCardiacaMedia() const {
    return this->freqCardiacaMedia;
}

void Sport::setTipoSport(std::string sport) {
    tipoSport = sport;
}
void Sport::setCalorie(int cal) {
    calorie = cal;
}
void Sport::setfreqCardiacaMedia(int fCard) {
    freqCardiacaMedia = fCard;
}