#ifndef GESTOREJSON_H
#define GESTOREJSON_H

#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class Attivita;

class GestoreJson {

public:
    static void salvaInFile(const QString &nomeFile, const std::vector<Attivita *> &att);

    static void CaricaDaFile(const QString &nomeFile, std::vector<Attivita *> &att);
};

#endif