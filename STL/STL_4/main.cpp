#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Imenik{
    string ime;
    string broj;
public:
    Imenik(string i,string b){
        ime = i;
        broj = b;
    }
    Imenik(const Imenik &imen){
        ime = imen.ime;
        broj = imen.broj;
    }
    bool operator<(Imenik &desno){
        return ime<desno.ime;
    }
    void print(){
        cout<<"ime: "<<ime<<" broj: "<<broj<<endl;
    }
};

int main()
{
    //1
    vector<Imenik> imenik;
    imenik.push_back(Imenik("prv","000-123456"));
    imenik.push_back(Imenik("abcd","122-565322"));
    imenik.push_back(Imenik("bbb","111-223111"));
    sort(imenik.begin(),imenik.end());
    for (auto i = imenik.begin();i<imenik.end();i++){
        i->print();
    }
    //2
    vector<char> zbor1 = {'s','t','a','k','l','o'};
    vector<char> zbor2 = {'s','l','a','t','k','o'};
    sort(zbor1.begin(),zbor1.end());
    sort(zbor2.begin(),zbor2.end());
    cout<<(zbor1==zbor2?"e anagram":"ne e anagram")<<endl;

    string input;
    cout<<"vnesi recenica: ";
    getline(cin,input);
    vector<string> oddeleni;
    unsigned start = 0;
    for (unsigned i = 0; i<input.length();i++){
        if (input.at(i)==' '){
            oddeleni.push_back(input.substr(start,i-start));
            start = i+1;
        }
    }
    if (start != input.length())
        oddeleni.push_back(input.substr(start,input.length()-start));
    sort(oddeleni.begin(),oddeleni.end());
    for(auto i = oddeleni.begin();i<oddeleni.end();i++)
        if ((i == oddeleni.begin()) || ((*i)!=(*(i-1))))
            cout<<*i<<endl;


    return 0;
}
