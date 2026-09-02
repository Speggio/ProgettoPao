#include "VisitorFiltraAttivita.h"
#include "Lego.h"
#include "Musica.h"
#include "Sport.h"
#include "Videogiochi.h"

VisitorFiltraAttivita::VisitorFiltraAttivita(TipoAttivita target) : tipoTarget(target) {
}

void VisitorFiltraAttivita::visita(Sport &) {
    corrisponde = (tipoTarget == TipoAttivita::Sport);
}

void VisitorFiltraAttivita::visita(Musica &) {
    corrisponde = (tipoTarget == TipoAttivita::Musica);
}

void VisitorFiltraAttivita::visita(Lego &) {
    corrisponde = (tipoTarget == TipoAttivita::Lego);
}

void VisitorFiltraAttivita::visita(Videogiochi &) {
    corrisponde = (tipoTarget == TipoAttivita::Videogiochi);
}

bool VisitorFiltraAttivita::risultato() const {
    return corrisponde;
}
