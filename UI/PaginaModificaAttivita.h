#ifndef PAGINAMODIFICAATTIVITA_H
#define PAGINAMODIFICAATTIVITA_H
#include "Attivita.h"
#include "VisitorAttivita.h"
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QStackedWidget>
#include <QWidget>
#include <memory>

class Sport;
class Musica;
class Lego;
class Videogiochi;

class PaginaModificaAttivita : public QWidget {
    Q_OBJECT

private:
    TipoAttivita tipoCorrente;
    Attivita *attivitaCorrente;

    // widget generali
    QStackedWidget *stackCampiSpecifici;
    QLineEdit *titolo;
    QLineEdit *descrizione;
    QSpinBox *livelloSoddisfazione;
    QDateEdit *data;
    QSpinBox *ore;
    QSpinBox *minuti;
    QPushButton *salva;
    QPushButton *annulla;

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
    QLineEdit *artistaPrefe;
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
    void modificheSalvate();
    void modificaAttivita(Attivita *a);

public:
    PaginaModificaAttivita(QWidget *parent = nullptr);
    bool campiValidi();

    void impostaAttivita(Attivita *a);

    void impostaCampiSport(Sport &s);
    void applicaCampiSport(Sport &s) const;

    void impostaCampiMusica(Musica &m);
    void applicaCampiMusica(Musica &m) const;

    void impostaCampiLego(Lego &l);
    void applicaCampiLego(Lego &l) const;

    void impostaCampiVideogiochi(Videogiochi &v);
    void applicaCampiVideogiochi(Videogiochi &v) const;

    void cliccaSalva();
};

#endif