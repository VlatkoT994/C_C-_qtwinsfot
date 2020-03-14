#include <iostream>
#include "datum.h"
using namespace std;
#include "pantaloni.h"
#include "kosula.h"
#include "artikl.h"
int main()
{
    Datum today(13,3,2020);
    Pantaloni *pantaloni[20];
    Kosula *kosuli[20];
    int sizePantaloni =0;
    int sizeKosuli = 0;
    int naredba1;
    int naredba2;
    cout<<"1: nov artikl"<<endl;
    cout<<"2: prikazi site"<<endl;
    cout<<"3: prikazi tip"<<endl;
    cout<<"4: prikazi za nareacka"<<endl;
    cout<<"5: izlez"<<endl;
    cin>>naredba1;
    while(naredba1!=5){
        if (naredba1 == 1){
            char ime[20];
            int golemina,cena,dD,mD,gD;
            cout<<"ime: ";
            cin>>ime;
            cout<<"golemina: ";
            cin>>golemina;
            cout<<"cena: ";
            cin>>cena;
            cout<<"den koga e donesen: ";
            cin>>dD;
            cout<<"mesec koga e donesen: ";
            cin>>mD;
            cout<<"godina koga e donesen: ";
            cin>>gD;
            cout<<"1 za pantaloni,2 za kosula";
            cin>>naredba2;
            if (naredba2==1){
                pantaloni[sizePantaloni] = new Pantaloni(ime,golemina,cena,dD,mD,gD);
                sizePantaloni++;
            }
            else if (naredba2==2){
                kosuli[sizeKosuli] = new Kosula(ime,golemina,cena,dD,mD,gD);
                sizeKosuli++;
            }
            else
                cout<<"pogresna komanda"<<endl;
        }
        else if (naredba1 == 2){
            for (int i = 0; i<sizePantaloni;i++)
                pantaloni[i]->prikaziPodatoci();
            for (int i = 0;i<sizeKosuli;i++)
                kosuli[i]->prikaziPodatoci();
        }
        else if(naredba1==3){
            int total = 0;
            cout<<"1 za pantaloni,2 za kosula";
            cin>>naredba2;
            if (naredba2==1){
                for (int i = 0; i<sizePantaloni;i++){
                    pantaloni[i]->prikaziPodatoci();
                    total+=pantaloni[i]->presmetajNabavka(1);
                }
        cout<<"totalna cena :"<<total<<endl;
            }
            else if (naredba2==2){
                for (int i = 0;i<sizeKosuli;i++){
                    kosuli[i]->prikaziPodatoci();
                    total+=kosuli[i]->presmetajNabavka(1);
            }
        cout<<"totalna cena :"<<total<<endl;
        }

            else
                cout<<"pogresna komanda"<<endl;
    }
        else if(naredba1 == 4){
            int total = 0;
            for (int i = 0; i<sizePantaloni;i++){
                if(pantaloni[i]->ostanatiDenovi(today)<=7){
                    pantaloni[i]->prikaziPodatoci();
                    total+= pantaloni[i]->presmetajNabavka(1);
                }
            }
            for (int i = 0;i<sizeKosuli;i++)
                if(kosuli[i]->ostanatiDenovi(today)<=7){
                kosuli[i]->prikaziPodatoci();
                total+=kosuli[i]->presmetajNabavka(1);
                }
        cout<<"totalna cena :"<<total<<endl;

        }
        else
            cout<<"gresna komanda"<<endl;
        cout<<"1: nov artikl"<<endl;
        cout<<"2: prikazi site"<<endl;
        cout<<"3: prikazi tip"<<endl;
        cout<<"4: prikazi za nareacka"<<endl;
        cout<<"5: izlez"<<endl;
        cin>>naredba1;
    }
    return 0;
}
