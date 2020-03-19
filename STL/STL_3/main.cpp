#include <iostream>
#include<cstring>
using namespace std;
//1
template<class T>
class Zapis{
    T x;
    T y;
    T z;
public:
    Zapis(T X,T Y,T Z){
        x=X;
        y=Y;
        z=Z;
    }
    T zbir(){return x+y+z;}
    friend bool kontroler(Zapis<T> &);
};
template<class  T>
bool kontroler(Zapis<T> &zapis){
    T *cont = new T(10000);
    return (*cont<zapis.zbir());
}
//2
template<class T>
class Mnozestvo{
    T *arr;
public:
    static int brojac;
    Mnozestvo(unsigned si){
        arr = new T[si];
    }
    T &at(int ind){return arr[ind];}
    void add(T el){arr[Mnozestvo<T>::brojac++]=el;}
    T findMax(){
        T max = arr[Mnozestvo<T>::brojac-1];
        for (int i = Mnozestvo<T>::brojac - 2;i>=0;i--)
            if (max<arr[i])
                max = arr[i];
        return max;
    }
    void print(){
        for (int i = 0; i<Mnozestvo<T>::brojac;i++)
            cout<<arr[i]<<", ";
        cout<<endl;
    }
};
template<>
char *Mnozestvo<char*>::findMax(){
    char *max = new char[30];
    strncpy(max,arr[Mnozestvo<char *>::brojac-1],29);
    for (int i = Mnozestvo<char *>::brojac - 2;i>=0;i--)
        if (strcmp(max,arr[i])<0)
            strncpy(max,arr[i],29);
    return max;
}
template <class T> int Mnozestvo<T>::brojac = 0 ;

template<class T>
void vnes(Mnozestvo<T> &mnoz){
    T el;
    cout<<"vnesi element: ";
    cin>>el;
    mnoz.add(el);
}
template<>
void vnes(Mnozestvo<char*> &mnoz){
    cout<<"vnesi element: ";
    char *el = new char[20];
    cin>>el;
    cout<<el;
    mnoz.add(el);
}
int main()
{
    //1
    Zapis<int> z1(4000,3000,5000);
    Zapis<int> z2(2000,3000,1233);
    Zapis<double> z3(255.5,155.2,999.9);
    Zapis<double> z4(4444.4,5555.5,6666.6);
    cout<<"z1: "<<kontroler<int>(z1)<<" z2: "<<kontroler<int>(z2)<<"z3: "<<kontroler<double>(z3)<<" z4: "<<kontroler<double>(z4)<<endl;
    Mnozestvo<int> intMn(100);
    Mnozestvo<char*> charMn(100);
    Mnozestvo<double> doubMn(100);
    short naredba;
    cout<<"1. Dodaj element vo A"<<endl<<"2. Dodaj element vo B"<<endl<<"3. dodaj element vo C"<<endl<<"4. Prikazi go A"<<endl<<"5. Prikazi go B"<<endl<<"6. Prikazi go C"<<endl<<"7. Prikazi najgolemi elementi"<<endl<<"8. Prikazi broj na elementi vo mnozestva"<<endl<<"9. Kraj"<<endl;
    cin>>naredba;
    while(naredba!=9)
    {
        switch (naredba) {
        case 1:
            vnes(intMn);
            break;
        case 2:
            vnes(doubMn);
            break;
        case 3:
            vnes(charMn);
            break;
        case 4:
            intMn.print();
            break;
        case 5:
            doubMn.print();
            break;
        case 6:
            charMn.print();
            break;
        case 7:
            cout<<"najgolemi elementi: "<<endl<<"A: "<<intMn.findMax()<<" B: "<<doubMn.findMax()<<" C: "<<charMn.findMax()<<endl;
            break;
        case 8:
            cout<<"broj na clenovi: "<<endl<<"A: "<<intMn.brojac<<" B: "<<doubMn.brojac<<" C: "<<charMn.brojac<<endl;
            break;
        default:
            cout<<"pogresna naredba"<<endl;
            break;
        }
        cout<<"1. Dodaj element vo A"<<endl<<"2. Dodaj element vo B"<<endl<<"3. dodaj element vo C"<<endl<<"4. Prikazi go A"<<endl<<"5. Prikazi go B"<<endl<<"6. Prikazi go C"<<endl<<"7. Prikazi najgolemi elementi"<<endl<<"8. Prikazi broj na elementi vo mnozestva"<<endl<<"9. Kraj"<<endl;
        cin>>naredba;
    }
    return 0;
}
