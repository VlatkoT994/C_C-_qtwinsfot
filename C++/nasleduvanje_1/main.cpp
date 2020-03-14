#include <iostream>
#include "profesor.h"
#include "vraboten.h"
#include <vector>
#include "asistent.h"
#include "demonstrator.h"
using namespace std;
int main()
{
   vector<Profesor> profesori;
   vector<Asistent> asistenti;
   vector<Demonstrator> demonstratori;
   int naredba1;
   cout<<"1. Dodavanje na vraboten"<<endl;
   cout<<"2. Prikazuvanje na lista"<<endl;
   cout<<"3. izlez"<<endl;
   cin>>naredba1;
   while(naredba1 != 3){
   if (naredba1 == 1){
       int naredba2;
       cout<<"1. profesor"<<endl;
       cout<<"2. asistent"<<endl;
       cout<<"3. demonstrator"<<endl;
       cin>>naredba2;
       if (naredba2!=1 && naredba2!=2 && naredba2!=3)
           cout<<"nepostoecka naredba"<<endl;
       else{
           char ime[20],prezime[20];
           int godinaVrabotuvanje;
           cout<<"ime: ";
           cin>>ime;
           cout<<"prezime: ";
           cin>>prezime;
           cout<<"godina na vrabotuvanje: ";
           cin>>godinaVrabotuvanje;
           if(naredba2 == 1){
               char zvanje[20],oblast[20];
               int brPredmeti;
               cout<<"zvanje: ";
               cin>>zvanje;
               cout<<"oblast: ";
               cin>>oblast;
               cout<<"broj na predmeti: ";
               cin>>brPredmeti;
               profesori.push_back(Profesor(ime,prezime,godinaVrabotuvanje,zvanje,oblast,brPredmeti));
           }
           else if(naredba2 == 2){
               char zvanje[20],mentor[20];
               int brPredmeti;
               cout<<"zvanje: ";
               cin>>zvanje;
               cout<<"mentor: ";
               cin>>mentor;
               cout<<"broj na predmeti: ";
               cin>>brPredmeti;
               asistenti.push_back(Asistent(ime,prezime,godinaVrabotuvanje,zvanje,mentor,brPredmeti));
           }
           else{
               char start[5],kraj[5];
               cout<<"start na rabotno vreme: ";
               cin>>start;
               cout<<"kraj na rabotno vreme: ";
               cin>>kraj;
               demonstratori.push_back(Demonstrator(ime,prezime,godinaVrabotuvanje,start,kraj));
           }
       }

       }
   else if (naredba1 == 2){
       int naredba2;
       cout<<"1.Profesori"<<endl;
       cout<<"2.Asistenti"<<endl;
       cout<<"3.Demonstratori"<<endl;
       cin>>naredba2;
       if (naredba2 == 1)
           for (unsigned i =0; i<profesori.size();i++)
               profesori[i].prikazi_podatoci();
       else if(naredba2==2)
           for(unsigned i =0; i<asistenti.size();i++)
               asistenti[i].prikazi_podatoci();
       else if(naredba2==3)
           for (unsigned i = 0; i<demonstratori.size();i++)
               demonstratori[i].prikazi_podatoci();
       else
           cout<<"nepostoecka naredba"<<endl;
   }
   else
       cout<<"nepostoecka naredba"<<endl;
   cout<<"1. Dodavanje na vraboten"<<endl;
   cout<<"2. Prikazuvanje na lista"<<endl;
   cout<<"3. izlez"<<endl;
   cin>>naredba1;
   }



   return 0;
}
