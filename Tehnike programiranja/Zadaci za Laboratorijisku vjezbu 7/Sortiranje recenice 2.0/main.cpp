#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
        int broj;
         vector<string> nizRecenica;
        string *pok;
         try{
    pok = new string[1000];
    cout << "Koliko zelite recenica: ";;
    cin >> broj;
    cout << "Unesite recenice: ";
    for(int i=0; i<=broj; i++){
        getline(cin,*pok);
        nizRecenica.push_back(*pok);
    }
         }
         catch(...){
         cout << "Problemi sa memorijom";
         delete[] pok;
         }
    cout << "Sortirane recenice: ";
    sort(begin(nizRecenica),
         end(nizRecenica),
         [](string a, string b) {return a < b; });

    for(string i : nizRecenica ){
        cout << i <<endl;
    }
    delete[] pok;
    return 0;
}
