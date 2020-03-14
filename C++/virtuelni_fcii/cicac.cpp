#include "cicac.h"

Cicac::Cicac(int denRagjanje,int mesecRagjanje,int godinaRagjanje,int denDoagjanje,int mesecDoagjanje,int godinaDagjanje,char p,char *im,int denVak,int mesVak,int godVak,char pre):Zivotno(denRagjanje,mesecRagjanje,godinaDagjanje,denDoagjanje,mesecDoagjanje,godinaDagjanje,p,im,denVak,mesVak,godVak)
{
    prezivar = pre;
}
void Cicac::prikaziPodatoci(){
    cout<<"cicac: "<<endl;
    Zivotno::prikaziPodatoci();
}
Datum Cicac::PresmetajVakcinacija(){
    Datum d(datumPoslednaVakcinacija.getDay(),datumPoslednaVakcinacija.getMonth(),datumPoslednaVakcinacija.getYear());
    d.dodajMesec(12);
    return d;
}
