#ifndef PAGINAHOME_H
#define PAGINAHOME_H
#include "GestoreAttivita.h"
#include "VisitorFiltraAttivita.h"
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
    QPushButton *caricaFile;
    QPushButton *salvaFile;

signals:
    void richiestaDettaglio(Attivita *attivita);
    void richiestaCreazioneAttivita();
    void richiestaSalvaFile();
    void richiestaCaricaFile();

private slots:
    // per adesso niente

public:
    void aggiornaPagina();
    PaginaHome(GestoreAttivita *gestore, QWidget *parent = nullptr);
};

#endif