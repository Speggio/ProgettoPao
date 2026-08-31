#ifndef GESTOREATTIVITA_H
#define GESTOREATTIVITA_H
#include "Attivita.h"
#include <QWidget>
#include <memory>

class GestoreAttivita : public QObject {
    Q_OBJECT

private:
    std::vector<std::unique_ptr<Attivita>> attivita;

public:
    GestoreAttivita(QObject *parent = nullptr);
    void aggiungiAttivita(Attivita *a);
    void eliminaAttivita(Attivita *a);
    const std::vector<std::unique_ptr<Attivita>> &elencoAttivita() const;

signals:
    void attivitaCambiate(); // il modello notifica che i dati sono cambiati
};

#endif