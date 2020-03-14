#include <iostream>
#include "zivotno.h"
#include "vlekac.h"
#include "cicac.h"
#include "ptica.h"
#include "datum.h"
using namespace std;

int main()
{
    Datum denes(14,3,2020);
    int naredba1;
    int naredba2;
    int noZivotni = 0;
    int cicaci[50];
    int vlekaci[50];
    int ptici [50];
    int brCicaci = 0,brVlekaci=0,brPtici=0;
    Zivotno *zivotni[50];
    cout<<"0. izlezi"<<endl;
    cout<<"1. dodavanje na novo zivotni"<<endl;
    cout<<"2. prikazuvanje na brojna sostojba"<<endl;
    cout<<"3. prikazuvanje na zivotni od odreden tip"<<endl;
    cout<<"3. prikazuvanje na cela lista"<<endl;
    cout<<"4. zivotni koi treba da se vakciniraat vo rok od edna nedela"<<endl;
    cin>>naredba1;
    while(naredba1!=0){
        switch(naredba1){
        case 1:
            cout<<"1 za cicac,2 za ptica, 3 za vlekac"<<endl;
            cin>>naredba2;
            if (naredba2<1||naredba2>3)
                break;
            int dR,mR,gR,dD,mD,gD,dV,mV,gV;
            char pol,ime[20];
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
            cout<<"pol: ";
            cin>>pol;
            cout<<"ime: ";
            cin>>ime;
            cout<<"den na posledno vakciniranje: ";
            cin>>dV;
            cout<<"mesec na posledno vakciniranje: ";
            cin>>mV;
            cout<<"godina na posledno vakciniranje: ";
            cin>>gV;
            if (naredba2 == 1){
                char prezivar;
                cout<<"prezivar? d/n"<<endl;
                cin>>prezivar;
                Cicac *c = new Cicac(dR,mR,gR,dD,mD,gD,pol,ime,dV,mV,gV,prezivar);
                zivotni[noZivotni] = c;
                cicaci[brCicaci]=noZivotni;
                brCicaci++;
                noZivotni++;
            }
            else if(naredba2 == 2){
                char letac;
                cout<<"letac? d/n"<<endl;
                cin>>letac;
                Ptica *p = new Ptica(dR,mR,gR,dD,mD,gD,pol,ime,dV,mV,gV,letac);
                zivotni[noZivotni] = p;
                ptici[brPtici] = noZivotni;
                brPtici++;
                noZivotni++;
            }
            else if (naredba2 == 3){
                int dSV,mSV,gSV;
                cout<<"den na sledno vakciniranje: ";
                cin>>dSV;
                cout<<"mesec na sledno vakciniranje: ";
                cin>>mSV;
                cout<<"godina na sledno vakciniranje: ";
                cin>>gSV;
                Vlekac *v = new Vlekac(dR,mR,gR,dD,mD,gD,pol,ime,dV,mV,gV,dSV,mSV,gSV);
                zivotni[noZivotni] = v;
                vlekaci[brVlekaci]=noZivotni;
                brVlekaci++;
                noZivotni++;
            }
            else
                cout<<"nepostoecka naredba"<<endl;
            break;
        case 2:
            cout<<"vkupen broj na zivotni: "<<noZivotni<<endl;
            break;
        case 3:
            char naredba3;
            cout<<"koj tip? c,v,p"<<endl;
            cin>>naredba3;
            if (naredba3 == 'c')
                for (int i = 0; i<brCicaci;i++)
                    (*zivotni[cicaci[i]]).prikaziPodatoci();
            else if(naredba3 == 'p')
                for (int i = 0; i<brPtici;i++)
                    (*zivotni[ptici[i]]).prikaziPodatoci();
            else if(naredba3=='v')
                for(int i = 0;i<brVlekaci;i++)
                    (*zivotni[vlekaci[i]]).prikaziPodatoci();
            else
                cout<<"pogresna naredba"<<endl;
            break;
        case 4:
            for (unsigned i = 0; i<noZivotni;i++)
                (*zivotni[i]).prikaziPodatoci();
            break;
        case 5:
            for (unsigned i = 0; i< noZivotni;i++)
            {
                (*zivotni[i]).PresmetajVakcinacija().print();
                if(((*zivotni[i]).PresmetajVakcinacija()-denes)<=7)
                    (*zivotni[i]).prikaziPodatoci();
            }
            break;
        default:
            cout<<"ne postoi takva komanda"<<endl;
            break;
        }
        cout<<"0. izlezi"<<endl;
        cout<<"1. dodavanje na novo zivotni"<<endl;
        cout<<"2. prikazuvanje na brojna sostojba"<<endl;
        cout<<"3. prikazuvanje na zivotni od odredenTip"<<endl;
        cout<<"4. prikazuvanje na cela lista"<<endl;
        cout<<"5. zivotni koi treba da se vakciniraat vo rok od edna nedela"<<endl;
        cin>>naredba1;

    }

    return 0;
}
