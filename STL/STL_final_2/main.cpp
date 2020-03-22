#include <iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
class Inventar{
    int id;
    int kolicina;
    double cena;
public:
    Inventar(int i,int k,double c){
        id = i;
        kolicina = k;
        cena =c;
    }
    Inventar(const Inventar &dod){
        id = dod.id;
        kolicina = dod.kolicina;
        cena = dod.cena;
    }
    double getVkupnaCena(){return kolicina*cena;}
    int getKolicina(){return kolicina;}
    void print(){
        cout<<"id: "<<id<<endl<<"kolicina: "<<kolicina<<endl<<"cena: "<<cena<<endl;
    }
};

int main()
{
    ifstream inventar_input("../STL_final_2/inventar.txt",std::ios::in);
    if(!inventar_input){
        cout<<"inventar ne postoi"<<endl;
        exit(1);
    }
    vector <Inventar> inventar;
    int iD,kol;
    double price;
    while (inventar_input>>iD){
        inventar_input>>kol;
        inventar_input>>price;
        inventar.push_back(Inventar(iD,kol,price));
    }
    double vkupnaCena = accumulate(inventar.begin(),inventar.end(),0.0,[](double acc,Inventar el){return acc+el.getVkupnaCena();});
    cout<<"vkupnata cena na site proizvodi e: "<<vkupnaCena<<endl;
    cout<<"elementi so kolicina pomala od 10 se: "<<endl;
    for_each(inventar.begin(),inventar.end(),[](Inventar el){if(el.getKolicina()<10)
                                                            el.print();});
    return 0;
}
