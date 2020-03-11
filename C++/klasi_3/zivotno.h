#include "datum.h"
#ifndef ZIVOTNO_H
#define ZIVOTNO_H

class Zivotno{
    char tip;
    char pol;
    char ime[20];
    const Datum datumNaRagjanje;
    const Datum datumnNaDoagjanje;
    Datum datumNaPoslednaVakcina;
public:
    Zivotno(int denRagjanje,int mesecRagjanje,int godinaRagjanje,int denDoagjanje,int mesecDoagjanje,int godinaDagjanje,char t,char p,char *im,int denVak,int mesVak,int godVak);
    void prikaziPodatoci();
    char getTip();
    int presmetajVakcinacija(Datum denes);
};

#endif // ZIVOTNO_H
