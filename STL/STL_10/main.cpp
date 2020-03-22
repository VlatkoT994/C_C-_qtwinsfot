#include <iostream>
#include <stdexcept>
using namespace std;
class Avtomobil{
public: Avtomobil(){throw runtime_error("greska vo motorot");}
};
class Garaza{
public:
    Avtomobil *avtomobil;
    Garaza(){
        try {
            avtomobil = new Avtomobil();
        } catch (runtime_error &err) {
            cout<<err.what()<<endl;
            throw runtime_error("greska so avtomobilot vo garazata");
        }
    }
};

class Test{
public:
    int a;
    int b;
    Test(int z,int x){a = z;b = x; throw *this;}
};

int main()
{
    try {
      Test test = Test(1,2);
    } catch (Test &err) {
        cout<<"fatena greska"<<endl;
        cout<<err.a<<","<<err.b<<endl;
    }
    try {
        Garaza garaza = Garaza ();
    } catch (runtime_error &err) {
        cout<<err.what()<<endl;
     }
    return 0;
}
