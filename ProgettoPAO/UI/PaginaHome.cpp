#include "PaginaHome.h"
#include "Lego.h"
#include "MainWindow.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <iostream>

PaginaHome::PaginaHome(QWidget *parent) : QWidget(parent) {

    barraRicerca = new QLineEdit(this);
    selettoreAttivita = new QComboBox(this);
    aggiuntaAttivita = new QPushButton("Aggiungi attivita", this);
    listaAttivita = new QListWidget(this);

    selettoreAttivita->addItems({"Sport", "Musica", "Videogiochi", "Lego"});

    QVBoxLayout *layout2 = new QVBoxLayout(this);
    QHBoxLayout *layout1 = new QHBoxLayout;
    layout2->addLayout(layout1, 0);

    layout1->addWidget(barraRicerca);
    layout1->addWidget(selettoreAttivita);
    layout1->addWidget(aggiuntaAttivita);
    layout2->addWidget(listaAttivita);

    QDateTime data(QDate(2025, 10, 10), QTime(0, 0));

    attivita.push_back(std::make_unique<Sport>("Sessione di calcio", "Allenamento di calcio", 10,
        data, 180, "Calcio", 350, 145));
    attivita.push_back(std::make_unique<Musica>("Ascolto", "Sessione di ascolto", 8, data, 150,
        "Fame", "Nayt", "Indie", 15, true));
    attivita.push_back(std::make_unique<Lego>("Costruzione", "Sessione Lego", 9, data, 120,
        "Porsche", "Technic", 1580, false));
    attivita.push_back(std::make_unique<Videogiochi>("Gioco", "Sessione videogiochi", 6, data, 25,
        "Fortnite", "Epic", "Battle Royale", false));

    for (const auto &a : attivita) {
        std::cout << a->riepilogo() << std::endl;
    }

    connect(aggiuntaAttivita, &QPushButton::clicked, this, &PaginaHome::richiestaCreazioneAttivita);
    // per sapere a quale elemento della lista sto cliccando
    connect(listaAttivita, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        int riga = listaAttivita->row(item);
        emit richiestaDettaglio(attivita[riga].get());
    });

    aggiornaPagina();
    // Per adesso non la uso
    // connect(bottoneAggiungi, &QPushButton::clicked, this, &ListaForme::aggiungiForma);
}

void PaginaHome::aggiornaPagina() {

    listaAttivita->clear();
    for (const auto &a : attivita) {
        QString testo = QString::fromStdString(a->riepilogo());
        listaAttivita->addItem(testo);
    }
}