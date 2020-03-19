#include <iostream>
using namespace std;

template <typename T>
T sum(T *pole, int start, int kraj,T *pocetna = new T()){
    for (int i = start;i <= kraj; i++)
        *pocetna += pole[i];
    return *pocetna;
}
int main()
{
    int a[4] = {1,2,3,4};
    double b[8] = {2.2,4.1,5.5,1.1,2.4,5,6.1,2.3};
    cout<<sum(a,1,3)<<endl;
    cout<<sum(b,2,5)<<endl;
}
