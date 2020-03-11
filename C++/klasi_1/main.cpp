#include <iostream>

using namespace std;
    class Kvadar
    {
        int dolzina;
        int sirina;
        int visina;
    public:
        int volumen(){return dolzina*sirina*visina;}
        int plostina(){return 2*dolzina*sirina+2*dolzina*visina+2*sirina*visina;}
        bool eKocka(){return dolzina==visina && visina == sirina;}
        void set(){cout<<"dolzina: ";
                  cin>>dolzina;
                  cout<<"visina: ";
                  cin>>visina;
                  cout<<"sirina";
                  cin>>sirina;
                  }
        void dimenzii(){
            cout<<"dolzina: "<<dolzina<<endl;
            cout<<"sirina: "<<sirina<<endl;
            cout<<"visina: "<<visina<<endl;
        }
    };
    class Stedac
    {
    public:
        void vnesi_podatoci(){cout<<"broj: ";
                              cin>>broj;
                              cout<<"ime i prezime: ";
                              cin>>imeprezime;
                              cout<<"adresa: ";
                              cin>>adresa;
                              cout<<"saldo: ";
                              cin>>saldo;}
        void prikazi_podatoci(){
          cout<<"broj: "<<broj<<endl;
          cout<<"ime i prezime: "<<imeprezime<<endl;
          cout<<"adresa: "<<adresa<<endl;
          cout<<"saldo: "<<saldo<<endl;
        }
        void uplata(unsigned long i){saldo+=i;}
        void isplata(unsigned long i){
            if (saldo > i)
                saldo-=i;
            else
                cout<<"nema dovolno sredstva"<<endl;
        }
        long sostojba(){return saldo;}
    private:
        int broj;
        char imeprezime[30],adresa[50];
        long saldo;
    };

int main()
{
    int naredbaKvad;
    Kvadar arrKvad[50];
    int brojacKvad = 0;
    cout<<"0:izlezi"<<endl;
    cout<<"1:nov kvadar"<<endl;
    cout<<"2:pecati site"<<endl;
    cout<<"3:pecati eden"<<endl;
    cout<<"4:najmala plostina, a ne e kocka"<<endl;
    cin>>naredbaKvad;
    while(naredbaKvad!=0){
        if (naredbaKvad == 1){
            arrKvad[brojacKvad].set();
            brojacKvad++;
        }
        else if (naredbaKvad == 2){
            for (int i = 0; i<brojacKvad;i++)
                arrKvad[i].dimenzii();
        }
        else if(naredbaKvad == 3){
            int brojKvad;
            cout<<"koj kvadar? ";
            cin>>brojKvad;
            arrKvad[brojKvad].dimenzii();
        }
        else if(naredbaKvad == 4){
            Kvadar min;
            bool prvNajden = false;
            for (int i = 0; i<brojacKvad;i++){
                if (!prvNajden){
                    if(!arrKvad[i].eKocka()){
                        min = arrKvad[i];
                        prvNajden = true;
                    }
                }
                else if((min.plostina()>arrKvad[i].plostina())&& !arrKvad[i].eKocka()){
                    min = arrKvad[i];
                }
            }
            min.dimenzii();
        }
        else
            cout<<"nepostoecka naredba"<<endl;
        cout<<"0:izlezi"<<endl;
        cout<<"1:nov kvadar"<<endl;
        cout<<"2:pecati site"<<endl;
        cout<<"3:pecati eden"<<endl;
        cout<<"4:najmala plostina, a ne e kocka"<<endl;
        cin>>naredbaKvad;
    }
    //2
    int naredbaStedac;
    Stedac arrStedac[50];
    int brojacStedac = 0;
    cout<<"0:izlezi"<<endl;
    cout<<"1:nov stedac"<<endl;
    cout<<"2:saldo stedac"<<endl;
    cout<<"3:uplata"<<endl;
    cout<<"4:isplata"<<endl;
    cin>>naredbaStedac;
    while(naredbaStedac!=0){
        if (naredbaStedac == 1){
            arrStedac[brojacStedac].vnesi_podatoci();
            brojacStedac++;
        }
        else if (naredbaStedac == 2){
            int brojStedac;
            cout<<"koj stedac? ";
            cin>>brojStedac;
            arrStedac[brojStedac].sostojba();
        }
        else if(naredbaStedac == 3){
            unsigned long suma;
            int brojStedac;
            cout<<"koj stedac? ";
            cin>>brojStedac;
            cout<<"vnesi suma";
            cin>>suma;
            arrStedac[brojStedac].uplata(suma);
        }
        else if(naredbaStedac == 4){
            unsigned long suma;
            int brojStedac;
            cout<<"koj stedac? ";
            cin>>brojStedac;
            cout<<"vnesi suma";
            cin>>suma;
            arrStedac[brojStedac].isplata(suma);
        }
        else
            cout<<"nepostoecka naredba"<<endl;
        cout<<"0:izlezi"<<endl;
        cout<<"1:nov stedac"<<endl;
        cout<<"2:saldo stedac"<<endl;
        cout<<"3:uplata"<<endl;
        cout<<"4:isplata"<<endl;
        cin>>naredbaStedac;
    }
    return 0;
}
