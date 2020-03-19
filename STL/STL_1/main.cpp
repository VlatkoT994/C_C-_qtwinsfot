#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
int printArray(const T *arr,const int size,const int lowSubscript,const int highSubscript){
    if (lowSubscript<0 || highSubscript>=size || lowSubscript>highSubscript)
        return 0;
    else{
    for (int i = lowSubscript;i<=highSubscript;i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
    return highSubscript-lowSubscript;
    }
}
void printArray(int const *arr,const int size){
   for (int i = 0;i <size;i++){
        cout<<setw(5)<<arr[i];
        if (((i+1) % 4) ==0)
            cout<<endl;
   }
   cout<<endl;
}
template<typename T>
void sort(T *arr,int size){
    T temp;
    for (int i = 0; i< size - 1;i++)
        for (int j = size-1; j>i;j--)
            if (arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
}

template<typename R, typename P>

R implicit_cast(const P& p) {

  return p;  // neznae koj tip treba da bide returnot

}
template <typename T>
class Array{
    int size;
    T *arr;
public:
    Array(int s = 10){
        size = s;
        arr = new T(size);
    }
    T &at(int index){
        return arr[index];}
};
int main()
{
    int newArr[7] = {1,4,2,6,7,1,3};
    double doubArr[5] = {6.5,2.1,4.1,4,1.1};
    sort(newArr,7);
    printArray(newArr,7,0,6);
    printArray(newArr,7);
    sort(doubArr,5);
    cout<<printArray(doubArr,5,0,4)<<endl;

    Array<int> objArr(10);
    objArr.at(4) = 2;
    cout<<objArr.at(4)<<endl;
    Array<double> doubObj(3);
    doubObj.at(1) = 4.3;
    cout<<doubObj.at(1)<<endl;
//    int i = 1;
//    float x = implicit_cast<float>(i);
//    int j = implicit_cast<int>(x);
//    return 0;
}
