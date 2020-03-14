#include "demonstrator.h"

#include<cstring>
#include<iostream>
using namespace std;
Demonstrator::Demonstrator(char *i,char *p,int g,char *s, char *k):Vraboten(i,p,g)
{
    startRabota = new char[strlen(s)+1];
    strcpy(startRabota,s);
    krajRabota = new char[strlen(k)+1];
    strcpy(krajRabota,k);
}
void Demonstrator::postavi(char *i,char *p,int g,char *s, char *k){
    Vraboten::postavi(i,p,g);
    startRabota = new char[strlen(s)+1];
    strcpy(startRabota,s);
    krajRabota = new char[strlen(k)+1];
    strcpy(krajRabota,k);
}
void Demonstrator::prikazi_podatoci(){
    cout<<"demonstrator:"<<endl;
    Vraboten::prikazi_podatoci();
    cout<<"rabotno vreme: "<<endl;
    cout<<"od:  "<<startRabota<<endl;
    cout<<"do: "<<krajRabota<<endl;
    cout<<endl;
}
