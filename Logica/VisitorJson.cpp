#include "VisitorJson.h"
#include "Lego.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"

QJsonObject VisitorJson::getJsonObject() {
    return jsonobject;
}

void VisitorJson::visita(Sport &s) {
    QJsonObject tempJsonObject;
    tempJsonObject["tipoAtt"] = "Sport";
    tempJsonObject["nome"] = QString::fromStdString(s.getNome());
    tempJsonObject["descrizione"] = QString::fromStdString(s.getDescrizione());
    tempJsonObject["soddisfazione"] = s.getSoddisfazione();
    tempJsonObject["data"] = s.getDataInizio().toString("dd/MM/yyyy");
    tempJsonObject["tempo"] = s.getTempoDedicato();
    tempJsonObject["tipoSport"] = QString::fromStdString(s.getTipoSport());
    tempJsonObject["calorie"] = s.getCalorie();
    tempJsonObject["frecCardiaca"] = s.getfreqCardiacaMedia();
    jsonobject = tempJsonObject;
}

void VisitorJson::visita(Musica &m) {
    QJsonObject tempJsonObject;
    tempJsonObject["tipoAtt"] = "Musica";
    tempJsonObject["nome"] = QString::fromStdString(m.getNome());
    tempJsonObject["descrizione"] = QString::fromStdString(m.getDescrizione());
    tempJsonObject["soddisfazione"] = m.getSoddisfazione();
    tempJsonObject["data"] = m.getDataInizio().toString("dd/MM/yyyy");
    tempJsonObject["tempo"] = m.getTempoDedicato();
    tempJsonObject["brano"] = QString::fromStdString(m.getBranoPreferito());
    tempJsonObject["artista"] = QString::fromStdString(m.getArtistaPreferito());
    tempJsonObject["genere"] = QString::fromStdString(m.getGenerePrincipale());
    tempJsonObject["numeroBrani"] = m.getNumeroBrani();
    tempJsonObject["scopertaMusica"] = m.getScopertaMusicale();
    jsonobject = tempJsonObject;
}

void VisitorJson::visita(Lego &l) {
    QJsonObject tempJsonObject;
    tempJsonObject["tipoAtt"] = "Lego";
    tempJsonObject["nome"] = QString::fromStdString(l.getNome());
    tempJsonObject["descrizione"] = QString::fromStdString(l.getDescrizione());
    tempJsonObject["soddisfazione"] = l.getSoddisfazione();
    tempJsonObject["data"] = l.getDataInizio().toString("dd/MM/yyyy");
    tempJsonObject["tempo"] = l.getTempoDedicato();
    tempJsonObject["nomeSet"] = QString::fromStdString(l.getNomeSet());
    tempJsonObject["tipoSet"] = QString::fromStdString(l.getTipologiaSet());
    tempJsonObject["pezziTot"] = l.getPezziTot();
    tempJsonObject["completato"] = l.getCompletato();
    jsonobject = tempJsonObject;
}

void VisitorJson::visita(Videogiochi &v) {
    QJsonObject tempJsonObject;
    tempJsonObject["tipoAtt"] = "Videogiochi";
    tempJsonObject["nome"] = QString::fromStdString(v.getNome());
    tempJsonObject["descrizione"] = QString::fromStdString(v.getDescrizione());
    tempJsonObject["soddisfazione"] = v.getSoddisfazione();
    tempJsonObject["data"] = v.getDataInizio().toString("dd/MM/yyyy");
    tempJsonObject["tempo"] = v.getTempoDedicato();
    tempJsonObject["nomeGioco"] = QString::fromStdString(v.getNomeGioco());
    tempJsonObject["piattaforma"] = QString::fromStdString(v.getPiattaforma());
    tempJsonObject["genere"] = QString::fromStdString(v.getGenere());
    tempJsonObject["completato"] = v.getCompletato();
    jsonobject = tempJsonObject;
}
