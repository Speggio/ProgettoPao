#include "PaginaDettaglio.h"
#include "Attivita.h"
#include "MainWindow.h"
#include <QFormLayout>
#include <QVBoxLayout>

PaginaDettaglio::PaginaDettaglio(QWidget *parent) : QWidget(parent) {

    labelTitolo = new QLabel(this);
    labelDescrizione = new QLabel(this);
    labelData = new QLabel(this);
    labelTempo = new QLabel(this);
    labelSoddisfazione = new QLabel(this);

    indietro = new QPushButton("Torna alla Home", this);
    modifica = new QPushButton("Modifica attivita", this);
    elimina = new QPushButton("Elimina attivita", this);

    QFormLayout *layoutGenerale = new QFormLayout;
    layoutGenerale->addRow("Titolo:", labelTitolo);
    layoutGenerale->addRow("Data:", labelData);
    layoutGenerale->addRow("Tempo dedicato:", labelTempo);
    layoutGenerale->addRow("Soddisfazione:", labelSoddisfazione);

    labelDescrizione->setWordWrap(true);
    labelDescrizione->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    labelDettagliSpecifici = new QLabel(this);
    labelDettagliSpecifici->setWordWrap(true);
    labelDettagliSpecifici->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QHBoxLayout *layoutBottoni = new QHBoxLayout;

    layoutBottoni->addWidget(indietro);
    layoutBottoni->addWidget(modifica);
    layoutBottoni->addWidget(elimina);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(layoutGenerale);
    layout->addWidget(labelDescrizione);
    layout->addWidget(labelDettagliSpecifici);
    layout->addLayout(layoutBottoni);

    connect(indietro, &QPushButton::clicked, this, &PaginaDettaglio::tornaIndietro);

    // eliminazione attività
    connect(elimina, &QPushButton::clicked, this,
        [this]() { emit eliminazioneAttivita(attivitaCorrente); });

    // modifica attivtà
    connect(modifica, &QPushButton::clicked, this,
        [this]() { emit modificaAttivita(attivitaCorrente); });
}

void PaginaDettaglio::leggiAttivita(Attivita *att) {
    attivitaCorrente = att;
    labelTitolo->setText(QString::fromStdString(att->getNome()));
    labelData->setText(att->getDataInizio().toString("dd/MM/yyyy"));
    labelTempo->setText(QString::fromStdString(att->conversioneOrario()));
    labelSoddisfazione->setText(QString::number(att->getSoddisfazione()));
    labelDescrizione->setText(QString::fromStdString(att->getDescrizione()));
    labelDettagliSpecifici->setText(QString::fromStdString(att->dettagliSpecifici()));
}