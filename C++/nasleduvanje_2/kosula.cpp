#include "kosula.h"
#include "artikl.h"
#include <iostream>
using namespace std;
Kosula::Kosula(char *name,int size,int price,int denD,int mesecD,int godinaD):Artikl(name,size,price,denD,mesecD,godinaD),slednaNabavka(31,12,2050){};
void Kosula::prikaziPodatoci(){
    cout<<"kosula: "<<endl;
    Artikl::prikaziPodatoci();
    cout<<"data na naredna naracka: ";
    slednaNabavka.print();
}
int Kosula::presmetajNabavka(int kolicina){return kolicina*getCena();}
int Kosula::ostanatiDenovi(Datum today){return today-slednaNabavka;}
