#ifndef VISITORATTIVITA_H
#define VISITORATTIVITA_H

// per filtraggio
enum class TipoAttivita {
    Sport,
    Musica,
    Lego,
    Videogiochi
};

// forwarding
class Sport;
class Musica;
class Lego;
class Videogiochi;

class VisitorAttivita {
public:
    virtual ~VisitorAttivita() = default;
    virtual void visita(Sport &s) = 0;
    virtual void visita(Musica &m) = 0;
    virtual void visita(Lego &l) = 0;
    virtual void visita(Videogiochi &v) = 0;
};

#endif