#include "MainWindow.h"
#include "PaginaCreazioneAttivita.h"
#include "PaginaDettaglio.h"
#include "PaginaHome.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    stack = new QStackedWidget(this);

    PaginaHome *pagHome = new PaginaHome(this);
    PaginaDettaglio *pagDettaglio = new PaginaDettaglio(this);
    PaginaCreazioneAttivita *pagNewAttivita = new PaginaCreazioneAttivita(this);

    stack->addWidget(pagHome);
    stack->addWidget(pagDettaglio);
    stack->addWidget(pagNewAttivita);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(stack);

    stack->setCurrentIndex(0);

    connect(pagHome, &PaginaHome::richiestaDettaglio, this, &MainWindow::swtichPagina1);
    connect(pagHome, &PaginaHome::richiestaCreazioneAttivita, this, &MainWindow::swtichPagina2);
    connect(pagDettaglio, &PaginaDettaglio::tornaIndietro, this, &MainWindow::swtichPagina0);
    connect(pagNewAttivita, &PaginaCreazioneAttivita::tornaIndietro, this,
        &MainWindow::swtichPagina0);
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
