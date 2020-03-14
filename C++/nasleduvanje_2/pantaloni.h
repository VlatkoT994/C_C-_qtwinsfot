#ifndef PANTALONI_H
#define PANTALONI_H
#include "datum.h"
#include "artikl.h"
class Pantaloni:Artikl
{
    Datum slednaNabavka;
public:

    Pantaloni(char *,int,int,int,int,int);
    void prikaziPodatoci();
    int presmetajNabavka(int);
    int ostanatiDenovi(Datum);
};

#endif // PANTALONI_H
