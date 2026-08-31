#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "GestoreAttivita.h"
#include "PaginaCreazioneAttivita.h"
#include "PaginaDettaglio.h"
#include "PaginaHome.h"
#include <QStackedWidget>
#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT

private:
    QStackedWidget *stack;
    PaginaHome *pagHome;
    PaginaDettaglio *pagDettaglio;
    PaginaCreazioneAttivita *pagNewAttivita;
    GestoreAttivita *gestore;

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void swtichPagina0();
    void swtichPagina1();
    void swtichPagina2();
};

#endif