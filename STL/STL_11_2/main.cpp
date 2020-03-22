#include <iostream>
#include<fstream>
#include<string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream in_file{"../STL_11_2/za_input.txt",std::ios::in};
    ofstream out_file{"../STL_11_2/za_output.txt",std::ios::trunc};
    if(!in_file || !out_file){
        cerr<<"greska pri otvaranje"<<endl;
        exit(1);
    }
    string zbor;
    while(in_file>>zbor)
        if(zbor.size()<10)
            out_file<<zbor<<" ";
    return 0;
}
