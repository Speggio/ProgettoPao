#include "PaginaDettaglio.h"
#include "Attivita.h"
#include "MainWindow.h"
#include <QFormLayout>
#include <QVBoxLayout>

PaginaDettaglio::PaginaDettaglio(QWidget *parent) : QWidget(parent) {

    labelTitolo = new QLabel(this);
    labelData = new QLabel(this);
    labelTempo = new QLabel(this);
    labelSoddisfazione = new QLabel(this);

    indietro = new QPushButton("Torna indietro", this);
    modifica = new QPushButton("Modifica attivita", this);

    QFormLayout *layoutGenerale = new QFormLayout;
    layoutGenerale->addRow("Titolo:", labelTitolo);
    layoutGenerale->addRow("Data:", labelData);
    layoutGenerale->addRow("Tempo dedicato:", labelTempo);
    layoutGenerale->addRow("Soddisfazione:", labelSoddisfazione);

    labelDettagliSpecifici = new QLabel(this);
    labelDettagliSpecifici->setWordWrap(true);
    labelDettagliSpecifici->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout *layoutBottoni = new QHBoxLayout;

    layoutBottoni->addWidget(indietro);
    layoutBottoni->addWidget(modifica);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(layoutGenerale);
    layout->addWidget(labelDettagliSpecifici);
    layout->addLayout(layoutBottoni);

    connect(indietro, &QPushButton::clicked, this, &PaginaDettaglio::tornaIndietro);
}

void PaginaDettaglio::leggiAttivita(Attivita *att) {
    labelTitolo->setText(QString::fromStdString(att->getNome()));
    labelData->setText(att->getDataInizio().toString("dd/MM/yyyy"));
    labelTempo->setText(QString::number(att->getTempoDedicato()) + " min");
    labelSoddisfazione->setText(QString::number(att->getSoddisfazione()));
    labelDettagliSpecifici->setText(QString::fromStdString(att->dettagliSpecifici()));
}