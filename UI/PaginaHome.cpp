#include "PaginaHome.h"
#include "Lego.h"
#include "MainWindow.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include <QDateTime>
#include <QHBoxLayout>
#include <QVBoxLayout>

PaginaHome::PaginaHome(GestoreAttivita *gestore, QWidget *parent) :
    QWidget(parent), gestoreAtt(gestore) {

    //----------------LAYER E VISUALIZZAZIONE DELLA PAGINA----------------//
    barraRicerca = new QLineEdit(this);
    selettoreAttivita = new QComboBox(this);
    aggiuntaAttivita = new QPushButton("Aggiungi attivita", this);
    listaAttivita = new QListWidget(this);
    caricaFile = new QPushButton("Carica File", this);
    salvaFile = new QPushButton("Salva File", this);

    barraRicerca->setPlaceholderText("Cerca attività");
    selettoreAttivita->addItems({"Tutte", "Sport", "Musica", "Videogiochi", "Lego"});

    QVBoxLayout *layoutGen = new QVBoxLayout(this);
    QHBoxLayout *layoutParteAlta = new QHBoxLayout;
    QHBoxLayout *layoutBottoniFile = new QHBoxLayout;

    layoutGen->addLayout(layoutParteAlta, 0);
    layoutBottoniFile->addWidget(caricaFile);
    layoutBottoniFile->addWidget(salvaFile);

    layoutParteAlta->addWidget(barraRicerca);
    layoutParteAlta->addWidget(selettoreAttivita);
    layoutParteAlta->addWidget(aggiuntaAttivita);
    layoutGen->addWidget(listaAttivita);
    layoutGen->addLayout(layoutBottoniFile);

    //----------------FINE LAYER E VISUALIZZAZIONE DELLA PAGINA----------------//

    connect(aggiuntaAttivita, &QPushButton::clicked, this, &PaginaHome::richiestaCreazioneAttivita);

    connect(listaAttivita, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        Attivita *a = static_cast<Attivita *>(item->data(Qt::UserRole).value<void *>());
        emit richiestaDettaglio(a);
    });

    connect(selettoreAttivita, &QComboBox::currentIndexChanged, this, &PaginaHome::aggiornaPagina);

    // per filtrare con la barra di ricerca
    connect(barraRicerca, &QLineEdit::textChanged, this, &PaginaHome::aggiornaPagina);

    // connect quando si preme carica o salva File manda a MainWindow
    connect(caricaFile, &QPushButton::clicked, this, &PaginaHome::richiestaCaricaFile);
    connect(salvaFile, &QPushButton::clicked, this, &PaginaHome::richiestaSalvaFile);

    aggiornaPagina();
}

void PaginaHome::aggiornaPagina() {

    listaAttivita->clear();
    QString testoRicerca = barraRicerca->text().trimmed().toLower();
    int indiceFiltro = selettoreAttivita->currentIndex();

    for (const auto &a : gestoreAtt->elencoAttivita()) {
        if (indiceFiltro != 0) {
            VisitorFiltraAttivita vf(static_cast<TipoAttivita>(indiceFiltro - 1));
            a->accetta(vf);
            if (!vf.risultato())
                continue;
        }
        if (!testoRicerca.isEmpty() &&
            !QString::fromStdString(a->getNome()).toLower().contains(testoRicerca)) {
            continue;
        }

        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(a->riepilogo()));
        item->setData(Qt::UserRole, QVariant::fromValue(static_cast<void *>(a.get())));
        listaAttivita->addItem(item);
    }
}