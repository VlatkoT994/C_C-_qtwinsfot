#ifndef VLEKAC_H
#define VLEKAC_H
#include "zivotno.h"
#include<iostream>
using namespace std;
class Vlekac: public Zivotno
{
    int meseciMegjuVakcina;
    Datum datumSlednaVakcinacija;
public:
    Vlekac(int,int,int,int,int,int,char,char*,int,int,int,int,int,int);
    ~Vlekac(){cout<<ime<<" destroyed<<endl";}
    void prikaziPodatoci();
    Datum PresmetajVakcinacija();
};

#endif // VLEKAC_H
