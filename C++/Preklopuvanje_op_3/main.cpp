#include <iostream>
#include"array.h"
#include"matrica.h"
using namespace std;

int main()
{
    Matrica mat1(2,2);
    cin>>mat1;
    Matrica mat2(mat1);
    cout<<mat1;
    cout<<mat2;
    cout<<(mat1==mat2)<<endl;
    cout<<(mat1*mat2);

}
