#ifndef ZIVOTNO_H
#define ZIVOTNO_H
#include"datum.h"

class Zivotno
{
protected:
    Datum datumRagjanje;
    Datum datumDonesuvanje;
    char pol;
    char *ime;
    Datum datumPoslednaVakcinacija;
public:
    Zivotno(int,int,int,int,int,int,char,char*,int,int,int);
    void prikaziPodatoci();
    Datum virtual PresmetajVakcinacija()=0;
};

#endif // ZIVOTNO_H
