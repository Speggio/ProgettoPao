#include "Lego.h"
#include "MainWindow.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <QApplication>
#include <QDateTime>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MainWindow finestra;
    finestra.show();

    return app.exec();
}