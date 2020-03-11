#include "covek.h"
#include<iostream>
#include<cstring>

using namespace std;
Covek::Covek(char *name,char *lastname,char *address,char *telephone)
{
    strncpy(ime,name,20);
    strncpy(prezime,lastname,20);
    strncpy(adresa,address,50);
    strncpy(telefon,telephone,15);
}
void Covek::print(){
    cout<<"ime i prezime: "<<ime<<" "<<prezime<<endl;
    cout<<"adresa: "<<adresa;
}
