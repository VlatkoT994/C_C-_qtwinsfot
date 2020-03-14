#include "ptica.h"

Ptica::Ptica(int denRagjanje,int mesecRagjanje,int godinaRagjanje,int denDoagjanje,int mesecDoagjanje,int godinaDagjanje,char p,char *im,int denVak,int mesVak,int godVak,char let):Zivotno(denRagjanje,mesecRagjanje,godinaDagjanje,denDoagjanje,mesecDoagjanje,godinaDagjanje,p,im,denVak,mesVak,godVak)
{
    letac = let;
}
void Ptica::prikaziPodatoci(){
    cout<<"ptica: "<<endl;
    Zivotno::prikaziPodatoci();
}
Datum Ptica::PresmetajVakcinacija(){
    Datum d(datumPoslednaVakcinacija.getDay(),datumPoslednaVakcinacija.getMonth(),datumPoslednaVakcinacija.getYear());
    d.dodajMesec(6);
    return d;
}
