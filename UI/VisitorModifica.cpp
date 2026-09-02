#include "VisitorModifica.h"
#include "Lego.h"
#include "Musica.h"
#include "PaginaModificaAttivita.h"
#include "Sport.h"
#include "Videogiochi.h"

VisitorModifica::VisitorModifica(PaginaModificaAttivita *paginaModifica) : pagina(paginaModifica) {
}

void VisitorModifica::visita(Sport &s) {
    pagina->impostaCampiSport(s);
}

void VisitorModifica::visita(Musica &m) {
    pagina->impostaCampiMusica(m);
}

void VisitorModifica::visita(Lego &l) {
    pagina->impostaCampiLego(l);
}

void VisitorModifica::visita(Videogiochi &v) {
    pagina->impostaCampiVideogiochi(v);
}
