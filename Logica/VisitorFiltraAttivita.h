#ifndef VISITORFILTRAATTIVITA_H
#define VISITORFILTRAATTIVITA_H
#include "VisitorAttivita.h"

class VisitorFiltraAttivita : public VisitorAttivita {

private:
    TipoAttivita tipoTarget;
    bool corrisponde = false;

public:
    VisitorFiltraAttivita(TipoAttivita target);

    void visita(Sport &) override;
    void visita(Musica &) override;
    void visita(Lego &) override;
    void visita(Videogiochi &) override;

    bool risultato() const;
};

#endif