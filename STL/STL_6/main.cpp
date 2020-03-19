#include <iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
#include<iterator>
#include<queue>
using namespace std;
class Uplata{
    string ime;
    string prezime;
    double uplata;
public:
    Uplata(string i,string p,double up){
        ime = i;
        prezime = p;
        uplata = up;
    }
    Uplata(const Uplata &dod){
        ime = dod.ime;
        prezime = dod.prezime;
        uplata = dod.uplata;
    }
    void dodadiVoMultimap(multimap<string,double,less<string>> &cont){
        string iP = ime + " " + prezime;
        pair<string, double> newP(iP,uplata);
        cont.insert(newP);
    }
    void print(){
        cout<<"ime i prezime: "<<ime<<" "<<prezime<<" uplata: "<<uplata<<endl;
    }
};
typedef multimap<string,double,less<string>> mmap;
class Proces{
    int priority;
    int id;
public:
    Proces(int p,int i){
        priority = p;
        id = i;
    }
    Proces(const Proces &dod){
        priority = dod.priority;
        id = dod.id;
    }
    friend bool operator<(const Proces,const Proces);
    void print() const {cout<<"id: "<<id<<endl;}
};
bool operator<(const Proces first, const Proces second){
    return first.priority>second.priority;
}
int main()
{

    multimap<string,double,less<string>> cont;
    int naredba1;
    cout<<"1. dodaj uplata"<<endl<<"2. prikazi upati za daden stedac"<<endl<<"3. kraj"<<endl;
    cin>>naredba1;
    while (naredba1!=3){
        switch (naredba1){
        case 1:{
            string ime,prezime;
            double uplata;
            cout<<"ime: ";
            cin>>ime;
            cout<<"prezime: ";
            cin>>prezime;
            cout<<"uplata: ";
            cin>>uplata;
            Uplata(ime,prezime,uplata).dodadiVoMultimap(cont);
            break;
        }
        case 2:{
            string imePrezime;
            cout<<"vnesi korisnik: "<<endl;
            cin.ignore();
            getline(cin,imePrezime);
            for (mmap::iterator i = cont.begin();i!=cont.end();i++){
                if ((i->first)==imePrezime)
                    cout<<(i->second)<<endl;
            }
            cout<<naredba1<<endl;
            break;
        }
        default:{
            cout<<"nema takva naredba"<<endl;
            break;
        }
        }
        cout<<"1. dodaj uplata"<<endl<<"2. prikazi upati za daden stedac"<<endl<<"3. kraj"<<endl;
        cin>>naredba1;
    }
    priority_queue<Proces> procesi;
    procesi.push(Proces(4,1));
    procesi.push(Proces(1,2));
    procesi.push(Proces(10,3));
    procesi.push(Proces(2,4));
    while (!procesi.empty()){
        procesi.top().print();
        procesi.pop();
    }
    return 0;
}
