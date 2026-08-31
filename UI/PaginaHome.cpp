#include "PaginaHome.h"
#include "Lego.h"
#include "MainWindow.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QVBoxLayout>

PaginaHome::PaginaHome(GestoreAttivita *gestore, QWidget *parent) :
    QWidget(parent), gestoreAtt(gestore) {

    //----------------LAYER E VISUALIZZAZIONE DELLA PAGINA----------------//
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
    //----------------FINE LAYER E VISUALIZZAZIONE DELLA PAGINA----------------//

    connect(aggiuntaAttivita, &QPushButton::clicked, this, &PaginaHome::richiestaCreazioneAttivita);
    // per sapere a quale elemento della lista sto cliccando
    connect(listaAttivita, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        int riga = listaAttivita->row(item);
        emit richiestaDettaglio(gestoreAtt->elencoAttivita()[riga].get());
    });

    aggiornaPagina();
}

void PaginaHome::aggiornaPagina() {

    listaAttivita->clear();
    for (const auto &a : gestoreAtt->elencoAttivita()) {
        QString testo = QString::fromStdString(a->riepilogo());
        listaAttivita->addItem(testo);
    }
}
