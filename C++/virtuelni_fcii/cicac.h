#ifndef CICAC_H
#define CICAC_H
#include "zivotno.h"
#include<iostream>
using namespace std;
class Cicac: public Zivotno
{
    char prezivar;
public:
    Cicac(int,int,int,int,int,int,char,char*,int,int,int,char);
    ~Cicac(){cout<<ime<<" destroyed<<endl";}
    void prikaziPodatoci();
    Datum PresmetajVakcinacija();
};
#endif // CICAC_H
