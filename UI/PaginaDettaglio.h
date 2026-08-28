#ifndef PAGINADETTAGLIO_H
#define PAGINADETTAGLIO_H
#include "Attivita.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class PaginaDettaglio : public QWidget {
    Q_OBJECT

private:
    QLabel *labelTitolo;
    QLabel *labelData;
    QLabel *labelTempo;
    QLabel *labelSoddisfazione;
    QLabel *labelDettagliSpecifici;

    QPushButton *indietro;
    QPushButton *modifica;

signals:
    void tornaIndietro();

public:
    PaginaDettaglio(QWidget *parent = nullptr);
    void leggiAttivita(Attivita *a);
};

#endif