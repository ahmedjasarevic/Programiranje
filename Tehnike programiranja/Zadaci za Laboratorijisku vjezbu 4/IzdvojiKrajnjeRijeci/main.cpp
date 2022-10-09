#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



vector<string> Sortiraj (vector<string> &spisakRijeci)
{
    string temp;
    for(int i=0; i<spisakRijeci.size(); i++)
    {
        for(int j=i+1; j<spisakRijeci.size(); j++)
        {

            if(spisakRijeci[i]>spisakRijeci[j])
            {

                temp=spisakRijeci[i];
                spisakRijeci[i]=spisakRijeci[j];
                spisakRijeci[j]=temp;

            }

        }

    }
    return spisakRijeci;

}

void  IzdvojiKrajnjeRiejci (vector<string> recenica, string &prvaRijec, string &posljednjaRijec)
{
    string temp;
   Sortiraj(recenica);
    prvaRijec = recenica[0];
    posljednjaRijec = recenica[recenica.size() - 1];
}

vector<string>  ZadrziDuplikate (vector<string> spisakRijeci)
{
    vector<string> duplikati;
    Sortiraj(spisakRijeci);
    for(int i = 0; i<spisakRijeci.size(); i++)
    {
        if(spisakRijeci[i] == spisakRijeci[i+1])
        {
            duplikati.push_back(spisakRijeci[i]);
        }
        else
        {
            continue;
        }
    }
    return duplikati;
}



int main()
{
    int brRijeci,i,j;
    string prva,zadnja;
    string rijec,temp;
    string duplikati;
    vector<string> recenica;
    cout << "Koliko zelite unijeti rijeci: " << endl;
    cin >> brRijeci;
    cout << "Unesite rijeci: ";
    for(int i=0; i<brRijeci; i++)
    {
        cin >> rijec;
        recenica.push_back(rijec);
    }
    IzdvojiKrajnjeRiejci(recenica,prva,zadnja);
    cout << "Prva rijec po abecednom poretku je: " << prva << endl;
    cout << "Posljednja rijec po abecednom poretku je: " << zadnja<< endl;
    cout << "Rijeci koje se ponavljaju su: ";
    vector<string> a;
    a = ZadrziDuplikate(recenica);
    for(int i = a.size() - 1; i>=0; i--)
    {
        if(a[i] == a[i-1]) continue;
        else
        {
            cout << a[i] << " ";
        }

    }


    return 0;
}
