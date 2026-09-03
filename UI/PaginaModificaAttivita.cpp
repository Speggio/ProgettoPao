#include "PaginaModificaAttivita.h"
#include "Lego.h"
#include "MainWindow.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include "VisitorModifica.h"
#include "VisitorSalvaModifica.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QVBoxLayout>

PaginaModificaAttivita::PaginaModificaAttivita(QWidget *parent) : QWidget(parent) {

    QVBoxLayout *layoutPrincipale = new QVBoxLayout(this);

    //-------------LAYOUT DELLA PAGINA-------------

    // creazione widget principali per il layout
    stackCampiSpecifici = new QStackedWidget(this);
    annulla = new QPushButton("Annulla", this);
    salva = new QPushButton("Salva le modifiche", this);

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
    data->setReadOnly(true);
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

    layoutPrincipale->addLayout(layoutGenerale);
    layoutPrincipale->addWidget(stackCampiSpecifici);

    QHBoxLayout *layoutBottoni = new QHBoxLayout;
    layoutBottoni->addWidget(annulla);
    layoutBottoni->addWidget(salva);

    layoutPrincipale->addLayout(layoutBottoni);
    //-------------LAYOUT DELLA PAGINA-------------

    // per tornare indietro
    connect(annulla, &QPushButton::clicked, this, &PaginaModificaAttivita::tornaIndietro);

    // quando si vuole salvare la modifica
    connect(salva, &QPushButton::clicked, this, &PaginaModificaAttivita::cliccaSalva);
}

// controllo anche qua per i campi
bool PaginaModificaAttivita::campiValidi() {
    if (titolo->text().trimmed().isEmpty() || descrizione->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Campi mancanti",
            "Il titolo e la descrizione sono obbligatori.");
        return false;
    }
    switch (tipoCorrente) {
    case TipoAttivita::Sport: // Sport
        if (tipoSport->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campo mancante", "Specifica il tipo di sport.");
            return false;
        }
        break;
    case TipoAttivita::Musica: // Musica
        if (branoPrefe->text().trimmed().isEmpty() || artistaPrefe->text().trimmed().isEmpty() ||
            generePrinc->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campi mancanti",
                "Brano, artista e genere sono obbligatori.");
            return false;
        }
        break;
    case TipoAttivita::Lego: // Lego
        if (nomeSet->text().trimmed().isEmpty() || tipoSet->text().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Campi mancanti",
                "nome del set e tipologia del set sono obbligatori.");
            return false;
        }
        break;
    case TipoAttivita::Videogiochi: // Videogiochi
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

// si imposta la modifica pper i dati generali
void PaginaModificaAttivita::impostaAttivita(Attivita *a) {
    attivitaCorrente = a;

    titolo->setText(QString::fromStdString(a->getNome()));
    descrizione->setText(QString::fromStdString(a->getDescrizione()));
    livelloSoddisfazione->setValue(a->getSoddisfazione());
    data->setDate(a->getDataInizio().date());
    ore->setValue(a->oreDaTempoDedicato());
    minuti->setValue(a->minutiDaTempoDedicato());

    VisitorModifica vm(this);
    a->accetta(vm);
}

// impostazione e applicazione dei vari campi specifici per ogni attività
void PaginaModificaAttivita::impostaCampiSport(Sport &s) {
    stackCampiSpecifici->setCurrentWidget(paginaCampiSport);
    tipoCorrente = TipoAttivita::Sport;
    tipoSport->setText(QString::fromStdString(s.getTipoSport()));
    nCalorie->setValue(s.getCalorie());
    freCardiaca->setValue(s.getfreqCardiacaMedia());
}

void PaginaModificaAttivita::applicaCampiSport(Sport &s) const {
    s.setTipoSport(tipoSport->text().toStdString());
    s.setCalorie(nCalorie->value());
    s.setfreqCardiacaMedia(freCardiaca->value());
}

void PaginaModificaAttivita::impostaCampiMusica(Musica &m) {
    stackCampiSpecifici->setCurrentWidget(paginaCampiMusica);
    tipoCorrente = TipoAttivita::Musica;
    branoPrefe->setText(QString::fromStdString(m.getBranoPreferito()));
    artistaPrefe->setText(QString::fromStdString(m.getArtistaPreferito()));
    generePrinc->setText(QString::fromStdString(m.getGenerePrincipale()));
    nBrani->setValue(m.getNumeroBrani());
    scopertaMusica->setChecked(m.getScopertaMusicale());
}

void PaginaModificaAttivita::applicaCampiMusica(Musica &m) const {
    m.setBranoPreferito(branoPrefe->text().toStdString());
    m.setArtistaPreferito(artistaPrefe->text().toStdString());
    m.setGenerePrincipale(generePrinc->text().toStdString());
    m.setNumeroBrani(nBrani->value());
    m.setScopertaMusicale(scopertaMusica->isChecked());
}

void PaginaModificaAttivita::impostaCampiLego(Lego &l) {
    stackCampiSpecifici->setCurrentWidget(paginaCampiLego);
    tipoCorrente = TipoAttivita::Lego;
    nomeSet->setText(QString::fromStdString(l.getNomeSet()));
    tipoSet->setText(QString::fromStdString(l.getTipologiaSet()));
    nPezziTot->setValue(l.getPezziTot());
    completatoLego->setChecked(l.getCompletato());
}

void PaginaModificaAttivita::applicaCampiLego(Lego &l) const {
    l.setNomeSet(nomeSet->text().toStdString());
    l.setTipologiaSet(tipoSet->text().toStdString());
    l.setPezziTot(nPezziTot->value());
    l.setCompletato(completatoLego->isChecked());
}

void PaginaModificaAttivita::impostaCampiVideogiochi(Videogiochi &v) {
    stackCampiSpecifici->setCurrentWidget(paginaCampiVideogiochi);
    tipoCorrente = TipoAttivita::Videogiochi;
    nomeGioco->setText(QString::fromStdString(v.getNomeGioco()));
    piattaforma->setText(QString::fromStdString(v.getPiattaforma()));
    genereGioco->setText(QString::fromStdString(v.getGenere()));
    completatoGioco->setChecked(v.getCompletato());
}

void PaginaModificaAttivita::applicaCampiVideogiochi(Videogiochi &v) const {
    v.setNomeGioco(nomeGioco->text().toStdString());
    v.setPiattaforma(piattaforma->text().toStdString());
    v.setGenere(genereGioco->text().toStdString());
    v.setCompletato(completatoGioco->isChecked());
}

void PaginaModificaAttivita::cliccaSalva() {
    if (!campiValidi())
        return;

    try {
        attivitaCorrente->setNome(titolo->text().toStdString());
        attivitaCorrente->setDescrizione(descrizione->text().toStdString());
        attivitaCorrente->setSoddisfazione(livelloSoddisfazione->value());
        attivitaCorrente->setTempoDedicato(ore->value() * 60 + minuti->value());

        VisitorSalvaModifiche vsm(this);
        attivitaCorrente->accetta(vsm);
    } catch (const std::invalid_argument &e) {
        QMessageBox::warning(this, "Valore non valido", QString::fromStdString(e.what()));
        return;
    }

    emit modificheSalvate();
}