#include "PaginaCreazioneAttivita.h"
#include "Lego.h"
#include "MainWindow.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QVBoxLayout>

PaginaCreazioneAttivita::PaginaCreazioneAttivita(GestoreAttivita *gestore, QWidget *parent) :
    QWidget(parent), gestoreAtt(gestore) {

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
    freCardiaca->setRange(60, 220);
    layoutSport->addRow("Frequenza cardiaca media", freCardiaca);

    // Widget per attivita Muisca
    paginaCampiMusica = new QWidget;
    QFormLayout *layoutMusica = new QFormLayout(paginaCampiMusica);
    branoPrefe = new QLineEdit(paginaCampiMusica);
    layoutMusica->addRow("Brano preferio:", branoPrefe);
    artistaPrefe = new QLineEdit(paginaCampiMusica);
    layoutMusica->addRow("Artista preferito:", artistaPrefe);
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
    connect(creazione, &QPushButton::clicked, this, &PaginaCreazioneAttivita::creaAttivita);
}

bool PaginaCreazioneAttivita::campiValidi() {
    if (titolo->text().trimmed().isEmpty() || descrizione->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Campi mancanti",
            "Il titolo e la descrizione sono obbligatori.");
        return false;
    }
    switch (selettoreAttivita->currentIndex()) {
    case 0: // Sport
        if (tipoSport->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campo mancante", "Specifica il tipo di sport.");
            return false;
        }
        break;
    case 1: // Musica
        if (branoPrefe->text().trimmed().isEmpty() || artistaPrefe->text().trimmed().isEmpty() ||
            generePrinc->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campi mancanti",
                "Brano, artista e genere sono obbligatori.");
            return false;
        }
        break;
    case 2: // Lego
        if (nomeSet->text().trimmed().isEmpty() || tipoSet->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campi mancanti",
                "nome del set e tipologia del set sono obbligatori.");
            return false;
        }
        break;
    case 3: // Videogiochi
        if (nomeGioco->text().trimmed().isEmpty() || piattaforma->text().trimmed().isEmpty() ||
            genereGioco->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campi mancanti",
                "Nome, piattaforma e genere del gioco sono campi obbligatori.");
            return false;
        }
        break;
    }
    return true;
}

void PaginaCreazioneAttivita::pulisciCampi() {
    titolo->clear();
    descrizione->clear();
    livelloSoddisfazione->setValue(0);
    data->setDate(QDate::currentDate());
    ore->setValue(0);
    minuti->setValue(0);
    selettoreAttivita->setCurrentIndex(0);

    // sport
    tipoSport->clear();
    nCalorie->setValue(0);
    freCardiaca->setValue(0);

    // musica
    branoPrefe->clear();
    artistaPrefe->clear();
    generePrinc->clear();
    nBrani->setValue(0);
    scopertaMusica->setChecked(false);

    // lego
    nomeSet->clear();
    tipoSet->clear();
    nPezziTot->setValue(0);
    completatoLego->setChecked(false);

    // Videogiochi
    nomeGioco->clear();
    piattaforma->clear();
    genereGioco->clear();
    completatoGioco->setChecked(false);
}

void PaginaCreazioneAttivita::creaAttivita() {
    // controllo che non ci siano campi nulli
    if (!campiValidi())
        return;

    try {
        // mi prendo i campi comuni a ogni attività
        std::string tit = titolo->text().toStdString();
        std::string desc = descrizione->text().toStdString();
        int sodd = livelloSoddisfazione->value();
        QDateTime dt(data->date(), QTime(0, 0));
        int tempoTotale = ore->value() * 60 + minuti->value();

        Attivita *nuova = nullptr;

        // controllo il comboBox per capire quale tipo di attività creare e in base all'indice
        // costruisco l'attività
        int indiceTipo = selettoreAttivita->currentIndex();
        switch (indiceTipo) {
        case 0: // Sport

            nuova = gestoreAtt->creaAttivitaSport(tit, desc, sodd, dt, tempoTotale,
                tipoSport->text().toStdString(), nCalorie->value(), freCardiaca->value());

            break;
        case 1: // Musica

            nuova = gestoreAtt->creaAttivitaMusica(tit, desc, sodd, dt, tempoTotale,
                branoPrefe->text().toStdString(), artistaPrefe->text().toStdString(),
                generePrinc->text().toStdString(), nBrani->value(), scopertaMusica->isChecked());
            break;
        case 2: // Lego

            nuova = gestoreAtt->creaAttivitaLego(tit, desc, sodd, dt, tempoTotale,
                nomeSet->text().toStdString(), tipoSet->text().toStdString(), nPezziTot->value(),
                completatoLego->isChecked());

            break;
        case 3: // Videogiochi

            nuova = gestoreAtt->creaAttivitaVideogioco(tit, desc, sodd, dt, tempoTotale,
                nomeGioco->text().toStdString(), piattaforma->text().toStdString(),
                genereGioco->text().toStdString(), completatoGioco->isChecked());

            break;
        }

        emit aggiungiAttivita(nuova);

    } catch (const std::invalid_argument &e) {
        QMessageBox::warning(this, "Valore non valido", QString::fromStdString(e.what()));
        return;
    }
}