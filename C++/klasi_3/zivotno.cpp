#include"datum.h"
#include"zivotno.h"
#include<stdio.h>
#include<cstring>

using namespace std;

Zivotno::Zivotno(int denRagjanje,int mesecRagjanje,int godinaRagjanje,int denDoagjanje,int mesecDoagjanje,int godinaDagjanje,char t,char p,char *im,int denVak,int mesVak,int godVak)
    :datumNaRagjanje(denRagjanje,mesecRagjanje,godinaRagjanje),
      datumnNaDoagjanje(denDoagjanje,mesecDoagjanje,godinaDagjanje)
{
    unsigned length= strlen(im);
    length = (length<20?length:19);
    tip = (t=='c' || t=='v'|| t=='p')?t:'c';
    pol = (p=='z' || p=='m')?p:'z';
    strncpy(ime,im,length);
    ime[length] = '\0';
    datumNaPoslednaVakcina = Datum(denVak,mesVak,godVak);
}
void Zivotno::prikaziPodatoci(){
    cout<<"ime: "<<ime<<endl;
    cout<<"pol: "<<pol<<endl;
    cout<<"tip: "<<tip<<endl;
    cout<<"data na ragjanje: ";
    datumNaRagjanje.pecatiDatum();
    cout<<"data na doagjanje vo zoloskata: ";
    datumnNaDoagjanje.pecatiDatum();
}
int Zivotno::presmetajVakcinacija(Datum denes){
    int odPoslednoVakciniranje = datumNaPoslednaVakcina.ostanatiDenovi(denes);
    if (tip == 'c')
        return 365 - odPoslednoVakciniranje;
    else if (tip == 'v')
        return 240 - odPoslednoVakciniranje;
    else
        return 180 - odPoslednoVakciniranje;
}
char Zivotno::getTip(){return tip;}
