#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

int main()
{
        int broj;
         vector<string> nizRecenica;
         try{
             shared_ptr<string>pok(new string);
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
         }
    cout << "Sortirane recenice: ";
    sort(begin(nizRecenica),
         end(nizRecenica),
         [](string a, string b) {return a < b; });

    for(string i : nizRecenica ){
        cout << i <<endl;
    }
    return 0;
}
