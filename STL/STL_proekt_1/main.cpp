#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Pravoagolnik{
    double a;
    double b;
public:
    Pravoagolnik(double A,double B){
        a = A;
        b = B;
    }
    Pravoagolnik(const Pravoagolnik &dodeluva){
        a = dodeluva.a;
        b = dodeluva.b;
    }
    bool operator==(const Pravoagolnik &sporeduva) const{
        return ((sporeduva.a == a && sporeduva.b == b)||(sporeduva.b == a && sporeduva.a ==b));
    }
    double plostina() const {return a*b;}
    bool operator<(const Pravoagolnik &sporeduva){return plostina()<sporeduva.plostina();}
    void print() const{cout<<"Pravoagolnik: "<<"a: "<<a<<" b: "<<b<<" plostina: "<<plostina()<<endl;}
};
class Kvadrat{
    double a;
public:
    Kvadrat(double A){a = A;}
    Kvadrat(const Kvadrat &dod){a = dod.a;}
    bool operator==(const Kvadrat &sporeduva)const{return a==sporeduva.a;}
    double plostina() const {return a*a;}
    bool operator<(const Kvadrat &sporeduva){return plostina()<sporeduva.plostina();}
    void print() const{cout<<"Kvadrat: "<<"a: "<<a<<" plostina: "<<plostina()<<endl;}
};
class Krug{
    double r;
public:
    Krug(double R){r = R;}
    Krug(const Krug &dod){
        r = dod.r;
    }
    bool operator==(const Krug &sporeduva)const{return r == sporeduva.r;}
    double plostina() const{return r*r*3.14;}
    bool operator<(const Krug &sporeduva){return plostina()<sporeduva.plostina();}
    void print() const{cout<<"Krug:  radius: "<<r<<" plostina: "<<plostina()<<endl;}
};
template<class T>
bool postoi(const vector<T> &vec, T el){
    for (typename vector<T>::const_iterator i = vec.begin();i!=vec.end();i++)
        if (el==(*i))
            return false;
    return true;
}
template<class T>
void print(const vector<T> vec){
    for (typename vector<T>::const_iterator i = vec.begin();i!=vec.end();i++)
        i->print();
}
int main()
{
    vector<Pravoagolnik> pravoagolnici;
    vector<Kvadrat> kvadrati;
    vector<Krug> krugovi;
    int naredba1;
    cout<<"1. dodaj pravoagolnik"<<endl<<"2.dodaj kvadrat "<<endl<<"3. dodaj krug"<<endl<<"4. prikazi pravoagolnici"<<endl<<"5. prikazi kvadrati"<<endl<<"6. prikazi krugovi"<<endl<<"7. prikazi najgolemi"<<endl<<"8. prikazi broj elementi"<<endl<<"9. kraj"<<endl;
    cin>>naredba1;
    while (naredba1!=9){
        switch (naredba1){
        case 1:{
            double a,b;
            cout<<"vnesi dolzina: ";
            cin>>a;
            cout<<"vnesi sirina: ";
            cin>>b;
            Pravoagolnik temp(a,b);
            if (postoi(pravoagolnici,temp))
                pravoagolnici.push_back(Pravoagolnik(a,b));
            else
                cout<<"vekje postoi";
            break;
        }
        case 2:{
            double a;
            cout<<"vnesi strana: ";
            cin>>a;
            Kvadrat temp(a);
            if (postoi(kvadrati,temp))
                kvadrati.push_back(Kvadrat(a));
            else
                cout<<"vekje postoi";
            break;
        }
        case 3:{
            double r;
            cout<<"vnesi radius: ";
            cin>>r;
            Krug temp(r);
            if (postoi(krugovi,temp))
                krugovi.push_back(Krug(r));
            else
                cout<<"vekje postoi"<<endl;
            break;
        }
        case 4:{
            print(pravoagolnici);
            break;
        }
        case 5:{
            print(kvadrati);
            break;
        }
        case 6:{
            print(krugovi);
            break;
        }
        case 7:{
            sort(pravoagolnici.begin(),pravoagolnici.end());
            sort(kvadrati.begin(),kvadrati.end());
            sort(krugovi.begin(),krugovi.end());
            cout<<"najgolemi elementi: "<<endl;
            (pravoagolnici.end()-1)->print();
            (krugovi.end()-1)->print();
            (kvadrati.end()-1)->print();
            break;
        }
        case 8:{
            cout<<"broj na: "<<endl<<"pravoagolnici: "<<pravoagolnici.size()<<" kvadrati: "<<kvadrati.size()<<" krugovi: "<<krugovi.size()<<endl;
            break;
        }
        default:{
            cout<<"ne postoi taa naredba";
            break;
        }
    }
        cout<<"1. dodaj pravoagolnik"<<endl<<"2.dodaj kvadrat "<<endl<<"3. dodaj krug"<<endl<<"4. prikazi pravoagolnici"<<endl<<"5. prikazi kvadrati"<<endl<<"6. prikazi krugovi"<<endl<<"7. prikazi najgolemi"<<endl<<"8. prikazi broj elementi"<<endl<<"9. kraj"<<endl;
        cin>>naredba1;
    }

    return 0;
}
