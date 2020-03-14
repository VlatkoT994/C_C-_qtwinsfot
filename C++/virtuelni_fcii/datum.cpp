#include "datum.h"
#include<iostream>
using namespace std;
Datum::Datum()
{
    den = 1;
    mesec = 1;
    godina = 1;
}
Datum::Datum(int day,int month,int year){
    godina = year;
    mesec = (month>=1&&month<=12)?month:1;
    den = (day>=1 && day<=denVoMesec[month-1])?day:1;
}
void Datum::setDay(int day){
    if(day>=1 && day<=denVoMesec[mesec-1])
        den = day;
}
void Datum::setMonth(int month){
    if (month>=1&&month<=12){
        mesec = month;
        if (den<denVoMesec[mesec-1])
            den = 1;
    }
}
void Datum::setYear(int year){
    godina = year;
}
int Datum::operator-(Datum desno){
    int days = (godina - desno.getYear())*365;
    if (mesec>desno.getMonth())
        for (int i = desno.getMonth();i<mesec;i++)
            days+=denVoMesec[i-1];
    else if(mesec<desno.getMonth())
        for (int i = mesec;i<desno.getMonth();i++)
            days-=denVoMesec[i-1];
    days+=(den-desno.getDay());
    return days;
}
void Datum::print(){
    cout<<(den<10?"0":"")<<den<<'/'<<(mesec<10?"0":"")<<mesec<<'/'<<godina<<endl;
}
void Datum::dodajMesec(int m){
    int vkupno = mesec + m;
    if (vkupno<=12)
        mesec = mesec+m;
    else{
        godina ++;
        dodajMesec(m-12);
    }
}
