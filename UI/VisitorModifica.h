#ifndef VISITORMODIFICA_H
#define VISITORMODIFICA_H
#include "VisitorAttivita.h"

// forwarding
class PaginaModificaAttivita;

class VisitorModifica : public VisitorAttivita {

private:
    PaginaModificaAttivita *pagina;

public:
    VisitorModifica(PaginaModificaAttivita *paginaModifica);

    void visita(Sport &s) override;
    void visita(Musica &m) override;
    void visita(Lego &l) override;
    void visita(Videogiochi &v) override;
};

#endif