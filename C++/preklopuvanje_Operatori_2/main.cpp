#include <iostream>
#include"complex.h"
using namespace std;

int main()
{
//    Complex prv,vtor,tret,cetvrt,pet,sest,sedum;
//    cin>>prv>>vtor>>tret>>cetvrt;
//    cout<<prv<<vtor<<tret<<cetvrt;
//    pet = prv*vtor;
//    sest = 4*tret;
//    sedum = cetvrt*12.5;
//    cout<<pet<<sest<<sedum;
    Complex a(2,1),b(3,5),c(2,2),d(3,5),temp;
    cout<<a;
    cout<<(b==d)<<endl;
    cout<<(a!=b)<<endl;
    cout<<(b!=d)<<endl;
    cout<<(b-=d);
    cout<<(c*=a);


    return 0;
}
