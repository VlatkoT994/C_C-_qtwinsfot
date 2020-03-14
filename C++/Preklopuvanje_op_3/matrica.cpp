#include "matrica.h"
#include "array.h"
#include<cassert>
#include<iostream>
#include<iomanip>
using namespace std;
Matrica::Matrica(int redovi, int koloni)
{
    rows = redovi;
    collumns = koloni;
    ptr = new Array[redovi];
    for (int i = 0; i < redovi; i++)
        ptr[i] = Array(koloni);
}
Matrica::Matrica(const Matrica& dodeluva){
    rows = dodeluva.rows;
    collumns = dodeluva.collumns;
    ptr = new Array[rows];
    for (int i = 0;i<rows;i++){
        ptr[i] = Array(collumns);
        for (int j = 0;j<collumns;j++)
            ptr[i][j] = dodeluva[i][j];
    }
}
Array &Matrica::operator[](int index){
    return ptr[index];
}
const Array &Matrica::operator[](int index) const{
    return ptr[index];
}
bool Matrica::operator==(Matrica &right){
    if (rows != right.rows || collumns!= right.collumns)
        return false;
    for (int i = 0;i<rows;i++)
        if (right[i]!=ptr[i])
            return false;
    return true;
}
Matrica Matrica::operator+(Matrica right){
    if(rows!=right.rows||collumns!=right.collumns)
        return Matrica(0,0);
    else{
        Matrica temp(rows,collumns);
        for (int i = 0;i<rows;i++){
            for (int j = 0; i<collumns;j++)
                temp[i][j]=(*this)[i][j]+right[i][j];
        }
        return temp;
    }
}
Matrica Matrica::operator-(Matrica right){
    if(rows!=right.rows||collumns!=right.collumns)
        return Matrica(0,0);
    else{
        Matrica temp(rows,collumns);
        for (int i = 0;i<rows;i++){
            for (int j = 0; i<collumns;j++)
                temp[i][j]=(*this)[i][j]-right[i][j];
        }
        return temp;
    }
}

ostream &operator<<(ostream &output, const Matrica &mat){
    for (int i = 0; i < mat.rows;i++){
        output<<mat[i]<<endl;
    }
    return output;
}
istream &operator>>(istream &input,Matrica &mat){
    for (int i = 0;i< mat.rows;i++)
        input>>mat[i];
    return input;
}
Matrica operator*(Matrica left,Matrica right){
    if (left.collumns != right.rows)
        return Matrica(0,0);
    Matrica temp(left.rows,right.collumns);
    for (int i = 0;i<left.rows;i++){
        for (int j = 0; j<right.collumns;j++){
            int placeholder = 0;
            for (int z = 0;z<left.collumns;z++)
                placeholder= placeholder + left[i][z]*right[z][j];
            temp[i][j] = placeholder;
        }
    }
    return temp;

}
Matrica operator*(int br,Matrica mat){
    Matrica result(mat.rows,mat.collumns);
    for (int i = 0; i<mat.rows;i++)
        for (int j = 0; j<mat.collumns;j++)
            result[i][j]=mat[i][j]*br;
    return result;
}
Matrica operator*(Matrica mat,int br){
    Matrica result(mat.rows,mat.collumns);
    for (int i = 0; i<mat.rows;i++)
        for (int j = 0; j<mat.collumns;j++)
            result[i][j]=mat[i][j]*br;
    return result;
}
