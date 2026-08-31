#ifndef PAGINAHOME_H
#define PAGINAHOME_H
#include "GestoreAttivita.h"
#include <QComboBox>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>

class PaginaHome : public QWidget {
    Q_OBJECT

private:
    QLineEdit *barraRicerca;
    QComboBox *selettoreAttivita;
    QPushButton *aggiuntaAttivita;
    QListWidget *listaAttivita;
    GestoreAttivita *gestoreAtt;

signals:
    void richiestaDettaglio(Attivita *attivita);
    void richiestaCreazioneAttivita();

private slots:
    // per adesso niente

public:
    void aggiornaPagina();
    PaginaHome(GestoreAttivita *gestore, QWidget *parent = nullptr);
};

#endif