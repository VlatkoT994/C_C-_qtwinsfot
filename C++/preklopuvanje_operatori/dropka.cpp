#include "dropka.h"
#include <iostream>
using namespace std;
Dropka::Dropka(){
    delenik = 1;
    delitel = 1;}
Dropka::Dropka(int delen,int deli)
{
    delenik = delen;
    delitel = (deli==0)?1:deli;
}
Dropka::Dropka(int broj){
    delenik = broj;
    delitel = 1;
}
int Dropka::getDelenik(){return delenik;}
int Dropka::getDelitel(){return delitel;}
int Dropka::getNzd(int num1, int num2){
    int brojac = num1<num2?num1:num2;
        for(;brojac>1;brojac--){
            if ((num1%brojac == 0) && (num2%brojac == 0))
                return brojac;
        }
        return 1;
}
int Dropka::getNzs(int num1, int num2){
    int brojac = num1>num2?num1:num2;
        for (;brojac<num1*num2;brojac++ ){
            if ((brojac%num1==0) && (brojac%num2 == 0))
                return brojac;
        }
        return num1*num2;
}
void Dropka::reduciraj(){
    int reducer = getNzd(delenik,delitel);
        if (reducer != 1){
            delenik/=reducer;
            delitel/=reducer;
        }
}
void Dropka::printDropka(){
    cout<<delenik<<'/'<<delitel<<endl;
}
void Dropka::printRealen(){
    cout<<static_cast<double>(delenik)/delitel<<endl;
}
Dropka Dropka::operator+(Dropka dropka){
    int nzs = getNzs(delitel,dropka.getDelitel());
    int del = delenik*nzs/delitel + dropka.getDelenik()*nzs/dropka.getDelitel();
    Dropka result(del,nzs);
    result.reduciraj();
    return result;
}
Dropka Dropka::operator+(int broj){
    Dropka dropka(broj);
    return *this+dropka;
}
Dropka Dropka::operator-(Dropka dropka){
    int nzs = getNzs(delitel,dropka.getDelitel());
    int del = delenik*nzs/delitel - dropka.getDelenik()*nzs/dropka.getDelitel();
    Dropka result(del,nzs);
    result.reduciraj();
    return result;
}
Dropka Dropka::operator-(int broj){
    Dropka dropka(broj);
    return *this-dropka;
}
Dropka Dropka::operator*(Dropka dropka){
    Dropka result(delenik*dropka.getDelenik(),delitel*dropka.getDelitel());
    result.reduciraj();
    return result;
}
Dropka Dropka::operator*(int broj){
    Dropka dropka(broj);
    return *this*dropka;
}
Dropka Dropka::operator/(Dropka dropka){
    Dropka result(delenik*dropka.getDelitel(),delitel*dropka.getDelenik());
    result.reduciraj();
    return result;
}
Dropka Dropka::operator/(int broj){
    Dropka dropka(broj);
    return (*this)/dropka;
}
