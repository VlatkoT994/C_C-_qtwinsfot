#include <iostream>
#include<vector>
#include<time.h>
#include<numeric>
#include<algorithm>
#include<deque>
#include<string>
using namespace std;
bool eParni(int x){
    return (x%2 == 0);
}
int randomNumber(){

    int br = rand()%9999;
    return br;
}
class Karta{
    string boja;
    short broj;
public:
    Karta(string bo,short br){
        boja = bo;
        broj = br;
    }
    Karta(const Karta &dod){
        boja = dod.boja;
        broj = dod.broj;
    }
    string getBoja(){return boja;}
    int getBroj(){return broj;}
    void print() const {cout<<broj<<" "<<boja<<" "<<endl;}
};
void newSpil(vector<Karta> &spil){
    string boi[] ={"srce","baklava","list","detelina"};
    for(int i = 0; i<4;i++)
        for(int j = 1; j < 14;j++)
            spil.push_back(Karta(boi[i],j));
    random_shuffle(spil.begin(),spil.end());
}
int main()
{
    srand(time(nullptr));
    int parni,m2i4,m4i6,m6i8,m8i10,zbir;
    vector<int> rands(10000);
    generate(rands.begin(),rands.end(),randomNumber);
    parni = count_if(rands.begin(),rands.end(),eParni);
    m2i4 = count_if(rands.begin(),rands.end(),[](int x){
        return (x>=2000 && x<4000);});
    m4i6 = count_if(rands.begin(),rands.end(),[](int x){return (x>=4000 && x<6000);});
    m6i8 = count_if(rands.begin(),rands.end(),[](int x){return (x>=6000 && x<8000);});
    m8i10 = count_if(rands.begin(),rands.end(),[](int x){return (x>=8000 && x<10000);});
    zbir = accumulate(rands.begin(),rands.end(),0);
    cout<<"broj na parni elementi: "<<parni<<endl<<"broj na elementi megju 2000 i 4000: "<<m2i4<<endl<<"broj na elementi megju 4000 i 6000: "<<m4i6<<endl<<"broj na elementi megju 6000 i 8000: "<<m6i8<<endl<<"broj na elementi megju 8000 i 10000: "<<m8i10<<endl<<"prosek na site broevi: "<<zbir/10000<<endl;
    vector<Karta> spil;
    int igra,igraci;
    cout<<"br na igra (1/2)";
    cin>>igra;
    cout<<"br na igraci?";
    cin>>igraci;
    newSpil(spil);
    vector<vector<Karta>> race(igraci);
    for (unsigned i = 0;i<igraci;i++)
        for (int j = 0; j< 5;j++){
            race.at(i).push_back(*(spil.end()-1));
            spil.pop_back();
        }
    unsigned pobednik,max = 0;
    for (unsigned i = 0;i<igraci;i++){
        unsigned zbir = 0;
        cout<<"igrac "<<i + 1<<":"<<endl;
        for (unsigned j = 0; j< 5;j++){
            race.at(i).at(j).print();
            zbir+=(igra==2 && race.at(i).at(j).getBoja()=="srce")?race.at(i).at(j).getBroj()*2:race.at(i).at(j).getBroj();
        }
        cout<<"zbir :"<<zbir<<endl;
        if (zbir>max){
            pobednik = i;
            max = zbir;
        }
    }
    cout<<"pobednik: igrac "<<pobednik + 1;
    return 0;
}
