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

    /*std::vector<std::unique_ptr<Attivita>> attivita;

    QDateTime data(QDate(2025, 10, 10), QTime(0, 0));

    attivita.push_back(std::make_unique<Sport>("Sessione di calcio", "Allenamento di calcio", 10,
        data, 180, "Calcio", 350, 145));
    attivita.push_back(std::make_unique<Musica>("Ascolto", "Sessione di ascolto", 8, data, 150,
        "Fame", "Nayt", "Indie", 15, true));
    attivita.push_back(std::make_unique<Lego>("Costruzione", "Sessione Lego", 9, data, 120,
        "Porsche", "Technic", 1580, false));
    attivita.push_back(std::make_unique<Videogiochi>("Gioco", "Sessione videogiochi", 6, data, 25,
        "Fortnite", "Epic", "Battle Royale", false));

    for (const auto &a : attivita) {
        std::cout << a->riepilogo() << std::endl;
    }
    // return 0;*/

    QApplication app(argc, argv);

    MainWindow finestra;
    finestra.show();

    return app.exec();
}