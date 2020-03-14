#include "vraboten.h"
#include<cstring>
#include<iostream>
using namespace std;
Vraboten::Vraboten(char *i,char *p,int g)
{
    ime = new char[strlen(i)+1];
    strcpy(ime,i);
    prezime = new char[strlen(p)+1];
    strcpy(prezime,p);
    godinaNaVrabotuvanje = g;
}
void Vraboten::postavi(char *i, char *p, int g){
    ime = new char[strlen(i)+1];
    strcpy(ime,i);
    prezime = new char[strlen(p)+1];
    strcpy(prezime,p);
    godinaNaVrabotuvanje = g;
}
void Vraboten::prikazi_podatoci(){
    cout<<"ime: "<<ime<<endl;
    cout<<"prezime: "<<prezime<<endl;
    cout<<"godina na vrabotuvanje: "<<godinaNaVrabotuvanje<<endl;
}
