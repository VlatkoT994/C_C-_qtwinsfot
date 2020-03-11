#include<iostream>
#ifndef DATUM_H
#define DATUM_H
using namespace std;
class Datum{
    int den;
    int mesec;
    int godina;
public:
    Datum(int d = 1,int m = 1,int g = 2010){
        den = (d>0 && d<31)?d:1;
        mesec = (m>0 && d<12)?m:1;
        godina = g;
    }
    int getDay() const{return den;}
    int getMonth() const{return mesec;}
    int getYear() const{return godina;}
    int ostanatiDenovi(Datum denes) const{
        //site meseci imaat 30 dena
        int daysLeft;
        daysLeft = (denes.getYear()-godina)*365;
        daysLeft += (denes.getMonth()-mesec)*30;
        daysLeft += (denes.getDay()-den);
        return daysLeft;
    }
    void pecatiDatum() const{
       cout<<(den<10?"0":"")<<den<<'-'<<(mesec<10?"0":"")<<mesec<<'-'<<godina<<endl;
    }
};

#endif // DATUM_H
