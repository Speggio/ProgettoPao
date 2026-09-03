#ifndef VISITORJSON_H
#define VISITORJSON_H

#include "VisitorAttivita.h"
#include <QJsonObject>

class VisitorJson : public VisitorAttivita {

private:
    QJsonObject jsonobject;

public:
    QJsonObject getJsonObject();

    void visita(Sport &s) override;
    void visita(Musica &m) override;
    void visita(Lego &l) override;
    void visita(Videogiochi &v) override;
};

#endif