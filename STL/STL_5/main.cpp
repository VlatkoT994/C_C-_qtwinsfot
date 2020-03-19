#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <deque>
using namespace std;
template <class T>
void printList(const list<T> li){
    typename list<T>::const_iterator i;
    for(i = li.begin();i!=li.end();i++)
        cout<<*i<<", ";
    cout<<endl;
}
template<class T>
void printVector(const vector<T> vec){
    typename vector<T>::const_iterator i;
    for(i = vec.begin();i!=vec.end();i++)
        cout<<*i<<", ";
    cout<<endl;
}
template<class T>
bool ePalindrom(const vector<T> &vec);
int main()
{
    vector<int> vec ={1,2,3,2,1};
    cout<<ePalindrom(vec);
    list<string> eList1 ={"ss","aa","cd"};
    list<string> eList2 ={"a","aa","lis"};
    list<string> eList3 ={"ss","li3","cd"};
    eList1.sort();
    eList2.sort();
    eList3.sort();
    eList1.merge(eList2);
    eList1.merge(eList3);
    eList1.unique();
    printList(eList1);
    deque <int> deq = {2,3,4,5,6,1,8};
    vector <int> rev;
    while(!deq.empty()){
        rev.push_back(*(deq.end()-1));
        deq.pop_back();
    }
    printVector(rev);
    return 0;
}

template<class T>
bool ePalindrom(const vector<T> &vec){
    for (unsigned i = 0;i<vec.size()/2;i++)
        if (vec.at(i)!= vec.at(vec.size()-1-i))
            return false;
    return true;
}



