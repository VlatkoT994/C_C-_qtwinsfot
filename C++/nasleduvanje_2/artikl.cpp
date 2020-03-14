#include "artikl.h"
#include<cstring>
#include<iostream>
using namespace std;

Artikl::Artikl(char *name,int size,int price, int dayB,int monthB,int yearB)
    :donesen(dayB,monthB,yearB)
{
    ime = new char[strlen(name)+1];
    strcpy(ime,name);
    golemina = size;
    cena = price;
}
void Artikl::prikaziPodatoci(){
    cout<<"ime :"<<ime<<endl;
    cout<<"golemina: "<<golemina<<endl;
    cout<<"cena: "<<cena<<endl;
    cout<<"datum na donesuvanje: ";
    donesen.print();
}
