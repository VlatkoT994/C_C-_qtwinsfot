#ifndef PTICA_H
#define PTICA_H
#include "zivotno.h"
#include<iostream>
using namespace std;
class Ptica: public Zivotno
{
    char letac;
public:
    Ptica(int,int,int,int,int,int,char,char*,int,int,int,char);
    ~Ptica(){cout<<ime<<" destroyed<<endl";}
    void prikaziPodatoci();
    Datum PresmetajVakcinacija();
};
#endif // PTICA_H
