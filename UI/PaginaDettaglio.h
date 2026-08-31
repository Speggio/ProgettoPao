#ifndef PAGINADETTAGLIO_H
#define PAGINADETTAGLIO_H
#include "Attivita.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class PaginaDettaglio : public QWidget {
    Q_OBJECT

private:
    Attivita *attivitaCorrente = nullptr;

    QLabel *labelTitolo;
    QLabel *labelData;
    QLabel *labelTempo;
    QLabel *labelSoddisfazione;
    QLabel *labelDettagliSpecifici;

    QPushButton *indietro;
    QPushButton *modifica;
    QPushButton *elimina;

signals:
    void tornaIndietro();
    void eliminazioneAttivita(Attivita *a);

public:
    PaginaDettaglio(QWidget *parent = nullptr);
    void leggiAttivita(Attivita *a);
};

#endif