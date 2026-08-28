#include "MainWindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    stack = new QStackedWidget(this);

    pagHome = new PaginaHome(this);
    pagDettaglio = new PaginaDettaglio(this);
    pagNewAttivita = new PaginaCreazioneAttivita(this);

    stack->addWidget(pagHome);
    stack->addWidget(pagDettaglio);
    stack->addWidget(pagNewAttivita);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(stack);

    stack->setCurrentIndex(0);

    connect(pagHome, &PaginaHome::richiestaDettaglio, this, [this](Attivita *elem) {
        pagDettaglio->leggiAttivita(elem);
        stack->setCurrentIndex(1);
    });

    // collegamento per passare alla pagine di creazione delle attività
    connect(pagHome, &PaginaHome::richiestaCreazioneAttivita, this, &MainWindow::swtichPagina2);

    // collegamenti per tornare indietro alla pagina home
    connect(pagDettaglio, &PaginaDettaglio::tornaIndietro, this, &MainWindow::swtichPagina0);
    connect(pagNewAttivita, &PaginaCreazioneAttivita::tornaIndietro, this,
        &MainWindow::swtichPagina0);

    // collegamento per la creazione di nuove attività
    connect(pagNewAttivita, &PaginaCreazioneAttivita::aggiungiAttivita, this, [this](Attivita *a) {
        pagHome->aggiungiAttivita(a);
        swtichPagina0();
    });
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
