#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

class Array
{
    friend ostream &operator<<(ostream &, const Array&);
    friend istream &operator>>(istream &,Array&);

public:
    Array(int = 3);
    int &operator[](int);
    const int &operator[](int) const;
    bool operator==(Array &);
    bool operator!=(Array &desno){
        return (!(*this==desno));
    }
private:
    int *ptr;
    int size;

};

#endif // ARRAY_H
