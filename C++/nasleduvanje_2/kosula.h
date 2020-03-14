#ifndef KOSULA_H
#define KOSULA_H
#include "datum.h"
#include "artikl.h"
class Kosula:Artikl
{
    Datum slednaNabavka;
public:

    Kosula(char *,int,int,int,int,int);
    void prikaziPodatoci();
    int presmetajNabavka(int);
    int ostanatiDenovi(Datum);
    void setNabavka(Datum den){slednaNabavka=den;}
};
#endif // KOSULA_H
