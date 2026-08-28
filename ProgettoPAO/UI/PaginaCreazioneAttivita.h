#ifndef PAGINACREAZIONEATTIVITA_H
#define PAGINACREAZIONEATTIVITA_H
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class PaginaCreazioneAttivita : public QWidget {
    Q_OBJECT

private:
    QLabel *testo;
    QPushButton *indietro;

signals:
    void tornaIndietro();

public:
    PaginaCreazioneAttivita(QWidget *parent = nullptr);
};

#endif