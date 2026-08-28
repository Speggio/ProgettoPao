#ifndef PAGINADETTAGLIO_H
#define PAGINADETTAGLIO_H
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class PaginaDettaglio : public QWidget {
    Q_OBJECT

private:
    QLabel *testo;
    QPushButton *indietro;

signals:
    void tornaIndietro();

public:
    PaginaDettaglio(QWidget *parent = nullptr);
};

#endif