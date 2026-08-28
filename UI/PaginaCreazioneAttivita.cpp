#include "PaginaCreazioneAttivita.h"
#include "Lego.h"
#include "MainWindow.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

PaginaCreazioneAttivita::PaginaCreazioneAttivita(QWidget *parent) : QWidget(parent) {

    QVBoxLayout *layoutPrincipale = new QVBoxLayout(this);

    // creazione widget principali per il layout
    selettoreAttivita = new QComboBox(this);
    selettoreAttivita->addItems({"Sport", "Musica", "Lego", "Videogiochi"});
    stackCampiSpecifici = new QStackedWidget(this);
    indietro = new QPushButton("Torna indietro", this);
    creazione = new QPushButton("Crea", this);

    // Widget per attributi generali
    QFormLayout *layoutGenerale = new QFormLayout;
    titolo = new QLineEdit(this);
    layoutGenerale->addRow("Nome attività:", titolo);
    descrizione = new QLineEdit(this);
    layoutGenerale->addRow("Descrizione attività:", descrizione);
    livelloSoddisfazione = new QSpinBox(this);
    livelloSoddisfazione->setRange(0, 10);
    layoutGenerale->addRow("Livello soddisfazione:", livelloSoddisfazione);
    data = new QDateEdit(this);
    layoutGenerale->addRow("Data:", data);
    ore = new QSpinBox(this);
    ore->setRange(0, 23);
    layoutGenerale->addRow("Ore:", ore);
    minuti = new QSpinBox(this);
    minuti->setRange(0, 59);
    layoutGenerale->addRow("Minuti:", minuti);

    // Widget per attivita sport
    paginaCampiSport = new QWidget;
    QFormLayout *layoutSport = new QFormLayout(paginaCampiSport);
    tipoSport = new QLineEdit(paginaCampiSport);
    layoutSport->addRow("Tipo dello sport", tipoSport);
    nCalorie = new QSpinBox(paginaCampiSport);
    nCalorie->setRange(0, 5000);
    layoutSport->addRow("Calorie", nCalorie);
    freCardiaca = new QSpinBox(paginaCampiSport);
    freCardiaca->setRange(0, 220);
    layoutSport->addRow("Frequenza cardiaca media", freCardiaca);

    // Widget per attivita Muisca
    paginaCampiMusica = new QWidget;
    QFormLayout *layoutMusica = new QFormLayout(paginaCampiMusica);
    branoPrefe = new QLineEdit(paginaCampiMusica);
    layoutMusica->addRow("Brano preferio:", branoPrefe);
    atristaPrefe = new QLineEdit(paginaCampiMusica);
    layoutMusica->addRow("Artista preferito:", atristaPrefe);
    generePrinc = new QLineEdit(paginaCampiMusica);
    layoutMusica->addRow("Genere principale ascoltato:", generePrinc);
    nBrani = new QSpinBox(paginaCampiMusica);
    nBrani->setRange(0, 10000);
    layoutMusica->addRow("Numero brani", nBrani);
    scopertaMusica = new QCheckBox(paginaCampiMusica);
    layoutMusica->addRow("Scoperto nuovi brani", scopertaMusica);

    // Widget per attivita Lego
    paginaCampiLego = new QWidget;
    QFormLayout *layoutLego = new QFormLayout(paginaCampiLego);
    nomeSet = new QLineEdit(paginaCampiLego);
    layoutLego->addRow("Nome del set", nomeSet);
    tipoSet = new QLineEdit(paginaCampiLego);
    layoutLego->addRow("Tipo del set", tipoSet);
    nPezziTot = new QSpinBox(paginaCampiLego);
    nPezziTot->setRange(0, 15000);
    layoutLego->addRow("Numero pezzi totali", nPezziTot);
    completatoLego = new QCheckBox(paginaCampiLego);
    layoutLego->addRow("Completato", completatoLego);

    // Widget per attivita Videogiochi
    paginaCampiVideogiochi = new QWidget;
    QFormLayout *layoutVideogiochi = new QFormLayout(paginaCampiVideogiochi);
    nomeGioco = new QLineEdit(paginaCampiVideogiochi);
    layoutVideogiochi->addRow("Nome gioco", nomeGioco);
    piattaforma = new QLineEdit(paginaCampiVideogiochi);
    layoutVideogiochi->addRow("Piattaforma su cui è presente il gioco: ", piattaforma);
    genereGioco = new QLineEdit(paginaCampiVideogiochi);
    layoutVideogiochi->addRow("Genere del gioco", genereGioco);
    completatoGioco = new QCheckBox(paginaCampiVideogiochi);
    layoutVideogiochi->addRow("Completato", completatoGioco);

    // indici partono sempre da 0
    stackCampiSpecifici->addWidget(paginaCampiSport);
    stackCampiSpecifici->addWidget(paginaCampiMusica);
    stackCampiSpecifici->addWidget(paginaCampiLego);
    stackCampiSpecifici->addWidget(paginaCampiVideogiochi);

    // collego il comboBox con lo stack per fare in moodo di visualizzare determinati Widget
    connect(selettoreAttivita, &QComboBox::currentIndexChanged, stackCampiSpecifici,
        &QStackedWidget::setCurrentIndex);

    layoutPrincipale->addWidget(selettoreAttivita);
    layoutPrincipale->addLayout(layoutGenerale);
    layoutPrincipale->addWidget(stackCampiSpecifici);

    QHBoxLayout *layoutBottoni = new QHBoxLayout;
    layoutBottoni->addWidget(indietro);
    layoutBottoni->addWidget(creazione);

    layoutPrincipale->addLayout(layoutBottoni);

    connect(indietro, &QPushButton::clicked, this, &PaginaCreazioneAttivita::tornaIndietro);

    // per creazione di ogni attività
    connect(creazione, &QPushButton::clicked, this, [this]() {
        // mi prendo i campi comuni a ogni attività
        std::string tit = titolo->text().toStdString();
        std::string desc = descrizione->text().toStdString();
        int sodd = livelloSoddisfazione->value();
        QDateTime dt(data->date(), QTime(0, 0));
        int tempoTotale = ore->value() * 60 + minuti->value();

        // creo un nuovo attività per poi metterci l'attività giusta da creare
        Attivita *nuova = nullptr;

        // controllo il comboBox per capire quale tipo di attività creare e in base all'indice
        // costruisco l'attività
        int indiceTipo = selettoreAttivita->currentIndex();
        switch (indiceTipo) {
        case 0: // Sport
            nuova = new Sport(tit, desc, sodd, dt, tempoTotale, tipoSport->text().toStdString(),
                nCalorie->value(), freCardiaca->value());
            break;
        case 1: // Musica
            nuova = new Musica(tit, desc, sodd, dt, tempoTotale, branoPrefe->text().toStdString(),
                atristaPrefe->text().toStdString(), generePrinc->text().toStdString(),
                nBrani->value(), scopertaMusica->isChecked());
            break;
        case 2: // Lego
            nuova = new Lego(tit, desc, sodd, dt, tempoTotale, nomeSet->text().toStdString(),
                tipoSet->text().toStdString(), nPezziTot->value(), completatoLego->isChecked());
            break;
        case 3: // Videogiochi
            nuova = new Videogiochi(tit, desc, sodd, dt, tempoTotale,
                nomeGioco->text().toStdString(), piattaforma->text().toStdString(),
                genereGioco->text().toStdString(), completatoGioco->isChecked());
            break;
        }

        emit aggiungiAttivita(nuova);
    });
}
