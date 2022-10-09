#include <iostream>
#include <vector>

using namespace std;

vector<string> Sortiraj (vector<string> recenica)
{
    string temp;
    for(int i=0; i<recenica.size(); i++)
    {
        for(int j=i+1; j<recenica.size(); j++)
        {

            if(recenica[i]>recenica[j])
            {

                temp=recenica[i];
                recenica[i]=recenica[j];
                recenica[j]=temp;

            }

        }

    }
    return recenica;

}

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
    for(string i :  Sortiraj(nizRecenica)){
        cout << i <<endl;
    }
    delete[] pok;
    return 0;
}
