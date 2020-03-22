#include <iostream>
#include <vector>
#include<algorithm>
#include<stdexcept>
using namespace std;
class Bukva{
    char bukva;
    bool pogoden;
public:
    Bukva(char b){
        bukva = b;
        pogoden = false;
    }
    Bukva(const Bukva &dod){
        bukva = dod.bukva;
        pogoden = dod.pogoden;
    }
    char prikazi(){return pogoden?bukva:'_';}
    void pogodi(){pogoden = true;}
    char getBukva(){return bukva;}
};
bool pogodiBukva(char buk, vector<Bukva> &vec,int &lettersLeft){
    bool exists = false;
    if(!isalpha(buk) || !islower(buk))
        throw runtime_error("nevaliden karakter");
    for_each(vec.begin(),vec.end(),[&lettersLeft,&exists,buk](Bukva &el){
        if (buk==el.getBukva()){
            exists = true;
            el.pogodi();
            lettersLeft--;
        }
    });
    return exists;
}
int main()
{
    int lives = 3;
    vector <Bukva> zbor ={('h'),('a'),('n'),('g'),('m'),('a'),('n')};
    int lettersLeft = zbor.size();
    char guess;
    while(lives > 0 && lettersLeft>0){
        for (auto i = zbor.begin();i!=zbor.end();i++)
            cout<<i->prikazi();
        cout<<endl<<"ostanati zivoti: "<<lives<<endl;
        cout<<"vnesi bukva: ";
        cin>>guess;
        try {
            bool exists = pogodiBukva(guess,zbor,lettersLeft);
            if (!exists)
                lives--;
        } catch (runtime_error &err) {
            cout<<err.what();
        }

    }
for (auto i = zbor.begin();i!=zbor.end();i++)
    cout<<i->prikazi();
    cout<<endl<<((lettersLeft==0)?"pobedivte":"izgubivte")<<endl;
    return 0;
}
