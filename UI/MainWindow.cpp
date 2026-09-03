#include "MainWindow.h"
#include <QFileDialog>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    //-------------------IMPOSTAZIONE LAYER-------------------//
    stack = new QStackedWidget(this);

    gestore = new GestoreAttivita(this);
    pagHome = new PaginaHome(gestore, this);
    pagDettaglio = new PaginaDettaglio(this);
    pagNewAttivita = new PaginaCreazioneAttivita(gestore, this);
    pagModifica = new PaginaModificaAttivita(this);

    stack->addWidget(pagHome);
    stack->addWidget(pagDettaglio);
    stack->addWidget(pagNewAttivita);
    stack->addWidget(pagModifica);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(stack);

    stack->setCurrentIndex(0);
    //-------------------FINE LAYER//-------------------//

    //-------------------VARI CONNECT-------------------//
    // collegamento per la richiesta di dettaglio di un'attività
    connect(pagHome, &PaginaHome::richiestaDettaglio, this, [this](Attivita *elem) {
        pagDettaglio->leggiAttivita(elem);
        stack->setCurrentIndex(1);
    });

    //  collegamento per passare alla pagina di creazione delle attività
    connect(pagHome, &PaginaHome::richiestaCreazioneAttivita, this, [this]() {
        pagNewAttivita->pulisciCampi();
        stack->setCurrentIndex(2);
    });

    // collegamenti per tornare indietro alla pagina home
    connect(pagDettaglio, &PaginaDettaglio::tornaIndietro, this, &MainWindow::swtichPagina0);
    connect(pagNewAttivita, &PaginaCreazioneAttivita::tornaIndietro, this,
        &MainWindow::swtichPagina0);
    connect(pagModifica, &PaginaModificaAttivita::tornaIndietro, this, &MainWindow::swtichPagina1);

    // collegamento per la creazione effettiva di una nuova attività
    connect(pagNewAttivita, &PaginaCreazioneAttivita::aggiungiAttivita, this, [this](Attivita *a) {
        gestore->aggiungiAttivita(a);
        swtichPagina0();
    });

    // collegamento per la rimozione di un'attività
    connect(pagDettaglio, &PaginaDettaglio::eliminazioneAttivita, this, [this](Attivita *a) {
        gestore->eliminaAttivita(a);
        swtichPagina0();
    });

    // collegamento per notificare l'avvenuta eliminazione di attività e quindi aggiornare la lista
    connect(gestore, &GestoreAttivita::attivitaCambiate, pagHome, &PaginaHome::aggiornaPagina);

    // collegamento per la richiesta di modifica di attività
    connect(pagDettaglio, &PaginaDettaglio::modificaAttivita, this, [this](Attivita *a) {
        pagModifica->impostaAttivita(a);
        stack->setCurrentIndex(3);
    });

    // collegamento per quando si preme il pulsante salva in modifica attività
    connect(pagModifica, &PaginaModificaAttivita::modificheSalvate, this, [this]() {
        pagHome->aggiornaPagina();
        swtichPagina0();
    });

    // connect per caricare e salvare su file Json, chiedo all'utente il file da scegliere
    connect(pagHome, &PaginaHome::richiestaCaricaFile, this, [this]() {
        QString nomeFile =
            QFileDialog::getOpenFileName(this, "Carica attività", "", "JSON (*.json)");
        if (!nomeFile.isEmpty()) {
            gestore->caricaJson(nomeFile);
        }
    });
    connect(pagHome, &PaginaHome::richiestaSalvaFile, this, [this]() {
        QString nomeFile =
            QFileDialog::getSaveFileName(this, "Salva attività", "", "JSON (*.json)");
        if (!nomeFile.isEmpty()) {
            gestore->salvaJson(nomeFile);
        }
    });
    //-------------------FINE CONNECT-------------------//
}

void MainWindow::swtichPagina0() {
    stack->setCurrentIndex(0);
}
void MainWindow::swtichPagina1() {
    stack->setCurrentIndex(1);
}
void MainWindow::swtichPagina2() {
    stack->setCurrentIndex(2);
}
void MainWindow::swtichPagina3() {
    stack->setCurrentIndex(3);
}
