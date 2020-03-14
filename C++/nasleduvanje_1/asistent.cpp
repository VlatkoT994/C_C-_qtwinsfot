#include "asistent.h"
#include<cstring>
#include<iostream>
using namespace std;
Asistent::Asistent(char *i,char *p,int g,char *z, char *m,int b):Vraboten(i,p,g)
{
    zvanje = new char[strlen(z)+1];
    strcpy(zvanje,z);
    mentor = new char[strlen(m)+1];
    strcpy(mentor,m);
    brPredmeti = b;
}
void Asistent::postavi(char *i,char *p,int g,char *z, char *m,int b){
    Vraboten::postavi(i,p,g);
    zvanje = new char[strlen(z)+1];
    strcpy(zvanje,z);
    mentor = new char[strlen(m)+1];
    strcpy(mentor,m);
    brPredmeti = b;
}
void Asistent::prikazi_podatoci(){
    cout<<"asistent:"<<endl;
    Vraboten::prikazi_podatoci();
    cout<<"zvanje: "<<zvanje<<endl;
    cout<<"mentor: "<<mentor<<endl;
    cout<<"broj na predmeti: "<<brPredmeti<<endl;
    cout<<endl;
}
