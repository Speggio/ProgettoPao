#include "VisitorSalvaModifica.h"
#include "Lego.h"
#include "Musica.h"
#include "PaginaModificaAttivita.h"
#include "Sport.h"
#include "Videogiochi.h"

VisitorSalvaModifiche::VisitorSalvaModifiche(PaginaModificaAttivita *paginaModifica) :
    pagina(paginaModifica) {
}

void VisitorSalvaModifiche::visita(Sport &s) {
    pagina->applicaCampiSport(s);
}

void VisitorSalvaModifiche::visita(Musica &m) {
    pagina->applicaCampiMusica(m);
}

void VisitorSalvaModifiche::visita(Lego &l) {
    pagina->applicaCampiLego(l);
}

void VisitorSalvaModifiche::visita(Videogiochi &v) {
    pagina->applicaCampiVideogiochi(v);
}