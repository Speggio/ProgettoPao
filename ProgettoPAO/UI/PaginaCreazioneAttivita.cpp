#include "MainWindow.h"
#include "PaginaDettaglio.h"
#include <QVBoxLayout>

PaginaCreazioneAttivita::PaginaCreazioneAttivita(QWidget *parent) : QWidget(parent) {

    testo = new QLabel("Pagina creazione attivita", this);
    indietro = new QPushButton("Torna indietro", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(testo);
    layout->addWidget(indietro);

    connect(indietro, &QPushButton::clicked, this, &PaginaCreazioneAttivita::tornaIndietro);
}