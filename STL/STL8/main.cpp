#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Vraboten{
    string ime;
    double bodovi;
public:
    Vraboten(string i,double b){
        ime = i;
        bodovi = b;
    }
    Vraboten(const Vraboten &dod){
        ime = dod.ime;
        bodovi = dod.bodovi;
    }
    double getBodovi() const {return bodovi;}
    void print(){cout<<"ime: "<<ime<<" bodovi: "<<bodovi<<endl;}
    bool operator<(Vraboten &spo){
        return bodovi<spo.bodovi;
    }
};

int main()
{
    vector<Vraboten> vraboteni;
    vraboteni.push_back(Vraboten("prv",50));
    vraboteni.push_back(Vraboten("vtor",90));
    vraboteni.push_back(Vraboten("tret",40));
    vraboteni.push_back(Vraboten("cetvrt",60));
    vraboteni.push_back(Vraboten("pet",70));
    vraboteni.push_back(Vraboten("sest",50));

    sort(vraboteni.begin(),vraboteni.end());
    for (vector<Vraboten>::iterator i = vraboteni.begin();i!=vraboteni.end();i++)
        i->print();
    double vkupna = accumulate(vraboteni.begin(),vraboteni.end(),0.0,[](double acc, const Vraboten &v){return acc+v.getBodovi()*10;});
    cout<<"vkupna plata: "<<vkupna<<endl;
    return 0;
}
