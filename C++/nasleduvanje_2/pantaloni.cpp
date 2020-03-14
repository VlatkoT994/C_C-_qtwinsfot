#include "pantaloni.h"
#include <iostream>
using namespace std;
Pantaloni::Pantaloni(char *name,int size,int price,int denD,int mesecD,int godinaD):Artikl(name,size,price,denD,mesecD,godinaD),slednaNabavka(denD,mesecD+1,godinaD){};
void Pantaloni::prikaziPodatoci(){
    cout<<"patntaloni: "<<endl;
    Artikl::prikaziPodatoci();
    cout<<"data na naredna naracka: ";
    slednaNabavka.print();
}
int Pantaloni::presmetajNabavka(int kolicina){return kolicina*getCena();}
int Pantaloni::ostanatiDenovi(Datum today){return slednaNabavka-today;}

