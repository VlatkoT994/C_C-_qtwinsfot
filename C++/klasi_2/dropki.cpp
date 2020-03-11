#include<iostream>
using namespace std;
#include "dropki.h"
Dropka::Dropka(int dele,int deli){
    delenik = dele==0?1:dele;
    delitel = deli==0?1:deli;
}
int Dropka::getDelitel(){
    return delitel;
}
int Dropka::getDelenik(){
    return delenik;
}
int Dropka::nzs(int num1,int num2){
    int brojac = num1>num2?num1:num2;
    for (;brojac<num1*num2;brojac++ ){
        if ((brojac%num1==0) && (brojac%num2 == 0))
            return brojac;
    }
    return num1*num2;
}
int Dropka::nzd(int num1,int num2){
    int brojac = num1<num2?num1:num2;
    for(;brojac>1;brojac--){
        if ((num1%brojac == 0) && (num2%brojac == 0))
            return brojac;
    }
    return 1;
}
void Dropka::reduciraj(){
    int reducer = nzd(delenik,delitel);
    if (reducer != 1){
        delenik/=reducer;
        delitel/=reducer;
    }
}
void Dropka::zbir(Dropka dropka1, Dropka dropka2){
    int zaednickiSodrzatel = nzs(dropka1.getDelitel(),dropka2.getDelitel());
    delenik = dropka1.getDelenik()*(zaednickiSodrzatel/dropka1.getDelitel()) + dropka2.getDelenik()*(zaednickiSodrzatel/dropka2.getDelitel());
    delitel = zaednickiSodrzatel;
    reduciraj();
}
void Dropka::razlika(Dropka dropka1, Dropka dropka2){
    int zaednickiSodrzatel = nzs(dropka1.getDelitel(),dropka2.getDelitel());
    delenik = dropka1.getDelenik()*(zaednickiSodrzatel/dropka1.getDelitel()) - dropka2.getDelenik()*(zaednickiSodrzatel/dropka2.getDelitel());
    delitel = zaednickiSodrzatel;
    reduciraj();
}
void Dropka::proizvod(Dropka dropka1, Dropka dropka2){
    delenik = dropka1.getDelenik()*dropka2.getDelenik();
    delitel = dropka1.getDelitel()*dropka2.getDelitel();
    reduciraj();
}
void Dropka::kolicnik(Dropka dropka1, Dropka dropka2){
    delenik = dropka1.getDelenik()*dropka2.getDelitel();
    delitel = dropka2.getDelenik()*dropka1.getDelitel();
    reduciraj();
}
void Dropka::printDropka(){
    cout<<getDelenik()<<'/'<<getDelitel()<<endl;
}
void Dropka::printRealen(){
    double realen = static_cast<double>(delenik)/static_cast<double>(delitel);
    cout<<realen<<endl;
}
