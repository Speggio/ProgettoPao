#ifndef VISITORSALVAMODIFICA_H
#define VISITORSALVAMODIFICA_H
#include "VisitorAttivita.h"

// forwarding
class PaginaModificaAttivita;

class VisitorSalvaModifiche : public VisitorAttivita {
private:
    PaginaModificaAttivita *pagina;

public:
    VisitorSalvaModifiche(PaginaModificaAttivita *paginaModifica);

    void visita(Sport &s) override;
    void visita(Musica &m) override;
    void visita(Lego &l) override;
    void visita(Videogiochi &v) override;
};

#endif