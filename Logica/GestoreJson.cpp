#include "GestoreJson.h"
#include "Lego.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"
#include "VisitorJson.h"
#include <QDebug>

void GestoreJson::salvaInFile(const QString &nomeFile, const std::vector<Attivita *> &att) {

    QJsonArray jsonArray;
    VisitorJson visitor;

    for (Attivita *a : att) {
        a->accetta(visitor);
        jsonArray.append(visitor.getJsonObject());
    }

    QJsonDocument doc(jsonArray);
    QFile file(nomeFile);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    } else {
        qWarning("Non si può aprire il file per la scrittura");
    }
}

void GestoreJson::CaricaDaFile(const QString &nomeFile, std::vector<Attivita *> &att) {
    QFile file(nomeFile);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Non si può aprire il file per la lettura");
        return;
    }

    QByteArray dati = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(dati);
    QJsonArray jsonArray = doc.array();

    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        QString tipo = obj["tipoAtt"].toString();
        QString nome = obj["nome"].toString();
        QString descr = obj["descrizione"].toString();
        int sodd = obj["soddisfazione"].toInt();
        QString dataStr = obj["data"].toString();
        QDateTime Qdata = QDateTime::fromString(dataStr, "dd/MM/yyyy");
        int tempo = obj["tempo"].toInt();

        if (tipo == "Sport") {
            QString tipoSport = obj["tipoSport"].toString();
            int cal = obj["calorie"].toInt();
            int fCard = obj["frecCardiaca"].toInt();

            att.push_back(new Sport(nome.toStdString(), descr.toStdString(), sodd, Qdata, tempo,
                tipoSport.toStdString(), cal, fCard));

        } else if (tipo == "Musica") {
            QString brano = obj["brano"].toString();
            QString art = obj["artista"].toString();
            QString gen = obj["genere"].toString();
            int nBrani = obj["numeroBrani"].toInt();
            bool scopMus = obj["scopertaMusica"].toBool();

            att.push_back(new Musica(nome.toStdString(), descr.toStdString(), sodd, Qdata, tempo,
                brano.toStdString(), art.toStdString(), gen.toStdString(), nBrani, scopMus));

        } else if (tipo == "Lego") {
            QString nSet = obj["nomeSet"].toString();
            QString tSet = obj["tipoSet"].toString();
            int pezziT = obj["pezziTot"].toInt();
            bool comp = obj["completato"].toBool();

            att.push_back(new Lego(nome.toStdString(), descr.toStdString(), sodd, Qdata, tempo,
                nSet.toStdString(), tSet.toStdString(), pezziT, comp));

        } else if (tipo == "Videogiochi") {
            QString nGioco = obj["nomeGioco"].toString();
            QString piatt = obj["piattaforma"].toString();
            QString gen = obj["genere"].toString();
            bool comp = obj["completato"].toBool();

            att.push_back(new Videogiochi(nome.toStdString(), descr.toStdString(), sodd, Qdata,
                tempo, nGioco.toStdString(), piatt.toStdString(), gen.toStdString(), comp));
        }
    }
}