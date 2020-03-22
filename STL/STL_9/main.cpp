#include <iostream>
#include <vector>
#include <exception>
#include<algorithm>
#include<iterator>
#include<time.h>
using namespace std;
void copyVectors(vector<int> &prv,vector<int> &vtor){
    if (vtor.size()>prv.size())
        throw exception();
    copy(vtor.begin(),vtor.end(),prv.begin());
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i<10;i++){
        int prv = rand()%999 +1;
        int vtor = rand()%999 +1;
        cout<<prv<<"   "<<vtor<<endl;
        vector<int> prvV(prv);
        vector<int> vtorV(vtor);
        try{
            copyVectors(prvV,vtorV);
        }
        catch(exception){
            cout<<"pregolem"<<endl;
    }
    }
    return 0;
}
