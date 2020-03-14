#include "vlekac.h"

Vlekac::Vlekac(int denRagjanje,int mesecRagjanje,int godinaRagjanje,int denDoagjanje,int mesecDoagjanje,int godinaDagjanje,char p,char *im,int denVak,int mesVak,int godVak,int denSled,int mesSled,int godSled):Zivotno(denRagjanje,mesecRagjanje,godinaDagjanje,denDoagjanje,mesecDoagjanje,godinaDagjanje,p,im,denVak,mesVak,godVak),
    datumSlednaVakcinacija(denSled,mesSled,godSled)
{
    meseciMegjuVakcina = (datumSlednaVakcinacija-datumPoslednaVakcinacija)/28; // ne e povekje od 2 godini
}
void Vlekac::prikaziPodatoci(){
    cout<<"vlekac: "<<endl;
    Zivotno::prikaziPodatoci();
}
Datum Vlekac::PresmetajVakcinacija(){return datumSlednaVakcinacija;}
