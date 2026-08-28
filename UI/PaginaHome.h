#ifndef PAGINAHOME_H
#define PAGINAHOME_H
#include "Attivita.h"
#include <QComboBox>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QWidget>
#include <memory>

class PaginaHome : public QWidget {
    Q_OBJECT

private:
    std::vector<std::unique_ptr<Attivita>> attivita;
    QLineEdit *barraRicerca;
    QComboBox *selettoreAttivita;
    QPushButton *aggiuntaAttivita;
    QListWidget *listaAttivita;

    void aggiornaPagina();

signals:
    void richiestaDettaglio(Attivita *attivita);
    void richiestaCreazioneAttivita();

private slots:
    // per adesso niente

public:
    PaginaHome(QWidget *parent = nullptr);
    void aggiungiAttivita(Attivita *a);
};

#endif