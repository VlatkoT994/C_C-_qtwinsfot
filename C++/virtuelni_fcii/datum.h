#ifndef DATUM_H
#define DATUM_H


class Datum
{
    int denVoMesec[20] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int den;
    int mesec;
    int godina;
public:
    Datum();
    Datum(int = 1,int = 1,int = 2020);
    int getDay() const{return den;}
    int getMonth() const{return mesec;}
    int getYear() const{return godina;}
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    int operator-(Datum);
    void print();
    void dodajMesec(int);

};

#endif // DATUM_H
