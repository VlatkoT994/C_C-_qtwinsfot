#include <iostream>


using namespace std;

inline void circleArea(){
    double radius;
    double pi = 3.14;
    cout<<"vnesi radius na krug :";
    cin>>radius;
    cout<<radius*pi*pi<<endl;
}
double tripleCallByValue(double num);
void tripleCallByReference(double &num);
template<class T>
inline T minimum(T a,T b){
    return a<b?a:b;
}
int main()
{
    circleArea();
    double a = 2.61;
    cout<<tripleCallByValue(a)<<endl;
    cout<<a<<endl;
    tripleCallByReference(a);
    cout<<a<<endl;
    cout<<minimum(2.1,5.4)<<endl;
    cout<<minimum(3,4)<<endl;
    cout<<minimum('a','d')<<endl;


    return 0;
}
double tripleCallByValue(double num){
    return 3*num;
}
void tripleCallByReference(double &num){
    num *= 3;
}
