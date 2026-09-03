#ifndef GESTOREATTIVITA_H
#define GESTOREATTIVITA_H
#include "Attivita.h"
#include <QWidget>
#include <memory>

class GestoreAttivita : public QObject {
    Q_OBJECT

private:
    std::vector<std::unique_ptr<Attivita>> attivita;

public:
    GestoreAttivita(QObject *parent = nullptr);
    void aggiungiAttivita(Attivita *a);
    void eliminaAttivita(Attivita *a);
    const std::vector<std::unique_ptr<Attivita>> &elencoAttivita() const;

    Attivita *creaAttivitaSport(std::string tit, std::string desc, int sodd, QDateTime dt,
        int tempoTotale, std::string tipoSport, int calorie, int freCard);

    Attivita *creaAttivitaLego(std::string tit, std::string desc, int sodd, QDateTime dt,
        int tempoTotale, std::string nomeSet, std::string tipologiaSet, int pezziTot,
        bool completato);

    Attivita *creaAttivitaMusica(std::string tit, std::string desc, int sodd, QDateTime dt,
        int tempoTotale, std::string branoPrefe, std::string artistaPrefe, std::string generePrinc,
        int nBrani, bool scopertaMusi);

    Attivita *creaAttivitaVideogioco(std::string tit, std::string desc, int sodd, QDateTime dt,
        int tempoTotale, std::string nomeGioco, std::string piattaforma, std::string genere,
        bool completato);

    void salvaJson(const QString &nomeFile) const;
    void caricaJson(const QString &nomeFile);

signals:
    void attivitaCambiate();
};

#endif