#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QStackedWidget>
#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT

private:
    QStackedWidget *stack;

public:
    MainWindow(QWidget *parent = nullptr);

public slots:
    void swtichPagina0();
    void swtichPagina1();
    void swtichPagina2();
};

#endif