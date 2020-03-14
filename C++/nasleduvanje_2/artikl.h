#ifndef ARTIKL_H
#define ARTIKL_H
#include"datum.h"

class Artikl
{
    char *ime;
    int golemina;
    int cena;
protected:
    Datum donesen;
public:
    Artikl(char*,int,int,int,int,int);
    void prikaziPodatoci();
    int getCena(){return cena;}
};

#endif // ARTIKL_H
