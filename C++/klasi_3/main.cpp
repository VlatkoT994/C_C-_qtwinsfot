#include <iostream>
#include <vector>
#include "zivotno.h"
#include "datum.h"
using namespace std;



void novoZivotno(vector<Zivotno> &zivotni);
int main()
{
    int naredba;
    Datum denes(3,10,2020);
    vector<Zivotno> zivotni;
    cout<<"0. izlezi"<<endl;
    cout<<"1. dodavanje na novo zivotni"<<endl;
    cout<<"2. prikazuvanje na brojna sostojba"<<endl;
    cout<<"3. prikazuvanje na brojna sostojba"<<endl;
    cout<<"4. prikazuvanje na cela lista"<<endl;
    cout<<"5. zivotni koi treba da se vakciniraat vo rok od edna nedela"<<endl;
    cin>>naredba;
    while(naredba!=0){
        switch(naredba){
        case 1:
            novoZivotno(zivotni);
            break;
        case 2:
            cout<<"vkupen broj na zivotni: "<<zivotni.size()<<endl;
            break;
        case 3:
            char tip;
            cout<<"koj tip? "<<endl;
            cin>>tip;
            for (unsigned i = 0; i < zivotni.size();i++)
                if (zivotni[i].getTip()==tip)
                    zivotni[i].prikaziPodatoci();
            break;
        case 4:
            for (unsigned i = 0; i<zivotni.size();i++)
                zivotni[i].prikaziPodatoci();
            break;
        case 5:
            for (unsigned i = 0; i< zivotni.size();i++)
                if(zivotni[i].presmetajVakcinacija(denes)<=7)
                    zivotni[i].prikaziPodatoci();
            break;
        default:
            cout<<"ne postoi takva komanda"<<endl;
        }
        cout<<"0. izlezi"<<endl;
        cout<<"1. dodavanje na novo zivotni"<<endl;
        cout<<"2. prikazuvanje na brojna sostojba"<<endl;
        cout<<"3. prikazuvanje na brojna sostojba"<<endl;
        cout<<"4. prikazuvanje na cela lista"<<endl;
        cout<<"5. zivotni koi treba da se vakciniraat vo rok od edna nedela"<<endl;
        cin>>naredba;

    }

    return 0;

   }
void novoZivotno(vector<Zivotno> &zivotni){
    int dR,mR,gR,dD,mD,gD,dV,mV,gV;
    char tip,pol,ime[20];
    cout<<"den na ragjanje: ";
    cin>>dR;
    cout<<"mesec na ragjanje: ";
    cin>>mR;
    cout<<"godina na ragjanje: ";
    cin>>gR;
    cout<<"den na doagjanje: ";
    cin>>dD;
    cout<<"mesec na doagjanje: ";
    cin>>mD;
    cout<<"godina na doagjanje: ";
    cin>>gD;
    cout<<"tip: ";
    cin>>tip;
    cout<<"pol: ";
    cin>>pol;
    cout<<"ime: ";
    cin>>ime;
    cout<<"den na vakciniranje: ";
    cin>>dV;
    cout<<"mesec na vakciniranje: ";
    cin>>mV;
    cout<<"godina na vakciniranje: ";
    cin>>gV;
    Zivotno newAnimal(dR,mR,gR,dD,mD,gD,tip,pol,ime,dV,mV,gV);
    zivotni.push_back(newAnimal);
}
