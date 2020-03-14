#include "profesor.h"
#include<cstring>
#include<iostream>
using namespace std;
Profesor::Profesor(char *i,char *p,int g,char *z, char *o,int b):Vraboten(i,p,g)
{
    zvanje = new char[strlen(z)+1];
    strcpy(zvanje,z);
    oblast = new char[strlen(o)+1];
    strcpy(oblast,o);
    brPredmeti = b;
}
void Profesor::postavi(char *i,char *p,int g,char *z, char *o,int b){
    Vraboten::postavi(i,p,g);
    zvanje = new char[strlen(z)+1];
    strcpy(zvanje,z);
    oblast = new char[strlen(o)+1];
    strcpy(oblast,o);
    brPredmeti = b;
}
void Profesor::prikazi_podatoci(){
    cout<<"profesor:"<<endl;
    Vraboten::prikazi_podatoci();
    cout<<"zvanje: "<<zvanje<<endl;
    cout<<"oblast: "<<oblast<<endl;
    cout<<"broj na predmeti: "<<brPredmeti<<endl;
    cout<<endl;
}
