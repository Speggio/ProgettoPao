#include "PaginaDettaglio.h"
#include "MainWindow.h"
#include <QVBoxLayout>

PaginaDettaglio::PaginaDettaglio(QWidget *parent) : QWidget(parent) {

    testo = new QLabel("Pagina dettaglio", this);
    indietro = new QPushButton("Torna indietro", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(testo);
    layout->addWidget(indietro);

    connect(indietro, &QPushButton::clicked, this, &PaginaDettaglio::tornaIndietro);
}