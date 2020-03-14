#ifndef MATRICA_H
#define MATRICA_H
#include "array.h"

class Matrica
{
    friend ostream &operator<<(ostream &, const Matrica&);
    friend istream &operator>>(istream &,Matrica&);
    friend Matrica operator*(Matrica,Matrica);
    friend Matrica operator*(int,Matrica);
    friend Matrica operator*(Matrica,int);
public:
    Matrica(int = 3,int = 3);
    Matrica(const Matrica& dodeluva);
    const Array &operator[](int) const;
    Array &operator[](int);
    bool operator==(Matrica &);
    bool operator!=(Matrica &desno){
        return (!(*this==desno));
    }
    Matrica operator+(Matrica);
    Matrica operator-(Matrica);
private:
    int rows;
    int collumns;
    Array *ptr;
};

#endif // MATRICA_H
