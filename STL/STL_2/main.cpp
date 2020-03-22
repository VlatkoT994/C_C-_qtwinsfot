#include <iostream>
#include<vector>
#include<cstring>
#include<type_traits>
using namespace std;
class Kvadrat{
    double strana;
public: Kvadrat(double s){
        strana = s;
    }
    Kvadrat(const Kvadrat &dod){
        strana = dod.strana;
    }
    bool operator>(const Kvadrat sporeduva){
        return (getPlostina()> sporeduva.getPlostina());
    }
    void operator=(const Kvadrat &dod){
        strana = dod.strana;
    }
    double getPlostina()const{return strana * strana;}
    void pecati()const{
        cout<<"kvadrat so strana "<<strana<<" i plostina "<<getPlostina()<<endl;
    }
};
class Pravoagolnik{
    double dolzina;
    double sirina;
public:
    Pravoagolnik(double d,double s){
        dolzina = d;
        sirina = s;
    }
    Pravoagolnik(const Pravoagolnik &dod){
        dolzina = dod.dolzina;
        sirina = dod.sirina;
    }
    void operator=(const Pravoagolnik dod){
        dolzina = dod.dolzina;
        sirina = dod.sirina;
    }
    bool operator>(const Pravoagolnik sporeduva){
        return (getPlostina()> sporeduva.getPlostina());
    }
    double getPlostina() const{return dolzina * sirina;}
    void pecati() const{
        cout<<"pravoagolnik so dolzina "<<dolzina<<", sirina "<<sirina<<" i plostina "<<getPlostina()<<endl;
    }
};
template<typename T>
void sortVector(vector<T> &vec){
    T *temp;
    for (unsigned i = 0; i<vec.size()-1;i++)
        for(unsigned j = 0;j<vec.size()-1-i;j++)
            if (vec[j]>vec[j+1]){
                temp = new T(vec[j]);
                vec[j] = vec[j+1];
                vec[j+1] = *temp;
               }

}
template <class T>
void pecatiVector(vector<T> vec){
    for (int i = 0; i<vec.size();i++)
        vec[i].pecati();
}
template <typename T>
T sum(T *pole, int start, int kraj,T *pocetna = new T()){
    for (int i = start;i <= kraj; i++)
        *pocetna += pole[i];
    return *pocetna;
}
template<class T>
class Lica{
    char *imePrezime;
    char *matbroj;
    int vozrast;
    char *adresa;
    T *kod;
public:
    Lica(char *i,char *mat, int v,char *ad, T *k){
        imePrezime = new char[strlen(i)];
        strncpy(imePrezime,i,20);
        imePrezime = new char[strlen(mat)];
        strncpy(matbroj,mat,20);
        vozrast = v;
        adresa = new char[strlen(ad)];
        strncpy(adresa,ad,20);
        if (is_same<T,int>::value)
            kod = k;
        else{
            kod = new T[strlen(k)]; // kako da gi oddelam alokacija za array i alokacija za vrednost kaj int
            strncpy(kod,k,20);
        }
    }
    void pecati() const{
        cout<<"ime i prezime: "<<imePrezime<<endl<<"vozrast: "<<vozrast<<endl<<"maticen broj: "<<matbroj<<endl<<"adresa: "<<adresa<<endl<<"kod: "<<kod<<endl;
    }

};
int main()
{
    //1
    int a[4] = {1,2,3,4};
    double b[8] = {2.2,4.1,5.5,1.1,2.4,5,6.1,2.3};
    cout<<sum(a,1,3)<<endl;
    cout<<sum(b,2,5)<<endl;
    //2
    vector<Kvadrat> kvadrati;
    kvadrati.push_back(Kvadrat(5));
    kvadrati.push_back(Kvadrat(7));
    kvadrati.push_back(Kvadrat(9));
    kvadrati.push_back(Kvadrat(10));
    kvadrati.push_back(Kvadrat(2));
    sortVector(kvadrati);
    pecatiVector(kvadrati);
    vector<Pravoagolnik> pravoagolnici;
    pravoagolnici.push_back(Pravoagolnik(2,2));
    pravoagolnici.push_back(Pravoagolnik(3,6));
    pravoagolnici.push_back(Pravoagolnik(1,2));
    pravoagolnici.push_back(Pravoagolnik(4,4));
    sortVector(pravoagolnici);
    pecatiVector(pravoagolnici);
    //3
    vector<Lica<char>> klienti;
    vector<Lica<int>> vraboteni;
    int naredba1;
    cout<<"!: vnesuvanje na podatoci za vraboten \n 2. vnesuvanje podatoci za klient \n 3.pecatenje lista na vraboteni \n 4.pecatenje lista na klienti \n 5.kraj"<<endl;
    cin>>naredba1;
    while (naredba1 != 5){
        switch (naredba1) {
        case 1:{
            char imeP[20];
            char adresa[20];
            char mat[20];
            int vozrast,kod;
            cout<<"vnesi ime"<<endl;
            cin.ignore();
            cin.getline(imeP,20);
            cout<<"vnesi adresa"<<endl;
            cin.ignore();
            cin.getline(imeP,20);
            cout<<"vnesi maticen broj"<<endl;
            cin.ignore();
            cin.getline(imeP,20);
            cout<<"vnesi vozrast"<<endl;
            cin>>vozrast;
            cout<<"vnesi kod"<<endl;
            cin>>kod;
            vraboteni.push_back(Lica<int>(imeP,mat,vozrast,adresa,&kod));
            break;
        }
        case 2:{
            char imeP[20];
            char adresa[20];
            char mat[20];
            char kod[20];
            int vozrast;
            cout<<"vnesi ime"<<endl;
            cin.ignore();
            cin.getline(imeP,20);
            cout<<"vnesi adresa"<<endl;
            cin.ignore();
            cin.getline(imeP,20);
            cout<<"vnesi maticen broj"<<endl;
            cin.ignore();
            cin.getline(imeP,20);
            cout<<"vnesi vozrast"<<endl;
            cin>>vozrast;
            cout<<"vnesi kod"<<endl;
            cin.ignore();
            cin.getline(kod,20);
            klienti.push_back(Lica<char>(imeP,mat,vozrast,adresa,kod));
            break;
        }
        case 3:{
            pecatiVector(vraboteni);
            break;
        }
        case 4:{
            pecatiVector(klienti);
            break;
        }
        default:{
            cout<<"ne postoi takva naredba"<<endl;
            break;
        }
        cout<<"!: vnesuvanje na podatoci za vraboten \n 2. vnesuvanje podatoci za klient \n 3.pecatenje lista na vraboteni \n 4.pecatenje lista na klienti \n 5.kraj"<<endl;
        cin>>naredba1;
        }
    }

    return 0;
}
