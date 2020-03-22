#include <iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
    int n,m;
    cout<<"vnesi sirina na koloni";
    cin>>m;
    cout<<"vnesi broj na redovi";
    cin>>n;
    ofstream out_file{"../STL_11_1/tabelirajI.dat",std::ios::trunc}; //samo vaka mi iskacase vo pravata papka
    if ( !out_file ) {
       cerr << "Datotekata ne moze da se otvori" << endl;
       exit( 1 );
    }
    for (double i = 1; i<=n;i++){
        out_file<<setw(m)<<i<<setw(m)<<i*i<<setw(m)<<sqrt(i)<<setw(m)<<pow(i,(1.0/3))<<endl;
    }
    out_file.close();
    return 0;
}
