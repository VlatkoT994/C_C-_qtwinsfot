#include "array.h"
#include<cassert>
#include<iostream>
#include<iomanip>
using namespace std;
Array::Array(int s)
{
    size = s>0?s:3;
    ptr = new int[size];
    for (int i = 0; i<size;i++)
        ptr[i] = 0;
}
int &Array::operator[](int index){
    assert(0<=index && index<size);
    return ptr[index];
}
const int &Array::operator[](int index) const{
    assert(0<=index && index<size);
    return ptr[index];
}
bool Array::operator==(Array &right){
    if (size != right.size)
        return false;
    for (int i = 0;i<size;i++)
        if (right.ptr[i]!=ptr[i])
            return false;
    return true;
}
ostream &operator<<(ostream &output, const Array &arr){
    for (int i = 0; i < arr.size;i++){
        output<<setw(4)<<arr[i];
    }
    return output;
}
istream &operator>>(istream &input,Array &arr){
    for (int i = 0;i< arr.size;i++)
        input>>arr[i];
    return input;
}
