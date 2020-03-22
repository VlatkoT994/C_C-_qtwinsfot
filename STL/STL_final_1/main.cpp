#include <iostream>
#include<vector>
#include<string>
using namespace std;
template<class T>
class Pole{
    T *pole;
    int elements = 0;
    int size;
public:
    Pole(int s){
        pole = new T[s];
        size = s;
    }
    void add(T el){
        if (elements >=size)
            cout<<"poleto e polno"<<endl;
        else pole[elements++] = el;
    }
    T findMax(){
        T max = pole[0];
        for(int i = 0; i <elements;i++)
            if(pole[i]>max)
                max = pole[i];
        return max;
    }
};
int main()
{
    Pole<int> intPole(10);
    Pole<string> stringPole(10);
    Pole<char> charPole(10);
    intPole.add(2);
    intPole.add(3);
    intPole.add(5);
    intPole.add(6);
    intPole.add(2);
    intPole.add(1);
    intPole.add(8);
    intPole.add(2);
    intPole.add(3);
    intPole.add(2);
    intPole.add(2);
    charPole.add('a');
    charPole.add('c');
    charPole.add('f');
    charPole.add('b');
    stringPole.add("aaa");
    stringPole.add("baa");
    stringPole.add("caa");
    cout<<intPole.findMax()<<endl<<charPole.findMax()<<endl<<stringPole.findMax()<<endl;


    return 0;
}
