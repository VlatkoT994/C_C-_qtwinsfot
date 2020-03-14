#include "zivotno.h"
#include<cstring>
#include<iostream>
using namespace std;
Zivotno::Zivotno(int denRagjanje,int mesecRagjanje,int godinaRagjanje,int denDoagjanje,int mesecDoagjanje,int godinaDagjanje,char p,char *im,int denVak,int mesVak,int godVak)
    :datumRagjanje(denRagjanje,mesecRagjanje,godinaRagjanje),
     datumDonesuvanje(denDoagjanje,mesecDoagjanje,godinaDagjanje),
     datumPoslednaVakcinacija(denVak,mesVak,godVak)
{
    ime = new char[strlen(im)+1];
    strcpy(ime,im);
    pol = (p=='z' || p=='m')?p:'z';
}
void Zivotno::prikaziPodatoci(){
    cout<<"ime: "<<ime<<endl;
    cout<<"pol: "<<pol<<endl;
    cout<<"data na ragjanje: ";
    datumRagjanje.print();
    cout<<"data na doagjanje vo zoloskata: ";
    datumDonesuvanje.print();
    cout<<"data na posledna vakcinacija: ";
    datumPoslednaVakcinacija.print();
}
