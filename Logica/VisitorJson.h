#ifndef VISITORJSON_H
#define VISITORJSON_H

#include "VisitorAttivita.h"
#include <QJsonObject>

class VisitorJson : public VisitorAttivita {

private:
    QJsonObject jsonobject;

public:
    QJsonObject getJsonObject();

    void visita(Sport &s);
    void visita(Musica &m);
    void visita(Lego &l);
    void visita(Videogiochi &v);
};

#endif