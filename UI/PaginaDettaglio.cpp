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

    indietro = new QPushButton("Torna alla Home", this);
    modifica = new QPushButton("Modifica attivita", this);
    elimina = new QPushButton("Elimina attivita", this);

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
    layoutBottoni->addWidget(elimina);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(layoutGenerale);
    layout->addWidget(labelDettagliSpecifici);
    layout->addLayout(layoutBottoni);

    connect(indietro, &QPushButton::clicked, this, &PaginaDettaglio::tornaIndietro);

    // eliminazione attività
    connect(elimina, &QPushButton::clicked, this,
        [this]() { emit eliminazioneAttivita(attivitaCorrente); });

    /*
    per adesso tolgo perchè in teoria quando chiamo eliminazione attività dopo fatto lo switch
della pagina
// Torno indietro dopo aver eliminato l'attività
connect(elimina, &QPushButton::clicked, this, &PaginaDettaglio::tornaIndietro);
*/
}

void PaginaDettaglio::leggiAttivita(Attivita *att) {
    attivitaCorrente = att;
    labelTitolo->setText(QString::fromStdString(att->getNome()));
    labelData->setText(att->getDataInizio().toString("dd/MM/yyyy"));
    labelTempo->setText(QString::fromStdString(att->conversioneOrario()));
    labelSoddisfazione->setText(QString::number(att->getSoddisfazione()));
    labelDettagliSpecifici->setText(QString::fromStdString(att->dettagliSpecifici()));
}