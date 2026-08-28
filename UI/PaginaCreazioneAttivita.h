#ifndef PAGINACREAZIONEATTIVITA_H
#define PAGINACREAZIONEATTIVITA_H
#include "Attivita.h"
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QStackedWidget>
#include <QWidget>
#include <memory>

class PaginaCreazioneAttivita : public QWidget {
    Q_OBJECT

private:
    // widget generali
    QComboBox *selettoreAttivita;
    QStackedWidget *stackCampiSpecifici;
    QLineEdit *titolo;
    QLineEdit *descrizione;
    QSpinBox *livelloSoddisfazione;
    QDateEdit *data;
    QSpinBox *ore;
    QSpinBox *minuti;
    QPushButton *creazione;
    QPushButton *indietro;

    // widget solo specifici
    QWidget *paginaCampiSport;
    QWidget *paginaCampiMusica;
    QWidget *paginaCampiLego;
    QWidget *paginaCampiVideogiochi;

    // Sport
    QLineEdit *tipoSport;
    QSpinBox *nCalorie;
    QSpinBox *freCardiaca;

    // musica
    QLineEdit *branoPrefe;
    QLineEdit *atristaPrefe;
    QLineEdit *generePrinc;
    QSpinBox *nBrani;
    QCheckBox *scopertaMusica;

    // lego
    QLineEdit *nomeSet;
    QLineEdit *tipoSet;
    QSpinBox *nPezziTot;
    QCheckBox *completatoLego;

    // videogiochi
    QLineEdit *nomeGioco;
    QLineEdit *piattaforma;
    QLineEdit *genereGioco;
    QCheckBox *completatoGioco;

signals:
    void tornaIndietro();
    void aggiungiAttivita(Attivita *nuovaAttivita);

public:
    PaginaCreazioneAttivita(QWidget *parent = nullptr);
};

#endif