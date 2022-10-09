#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




template <typename Tip>
vector<Tip> Presjek (vector<Tip> p, vector<Tip> d)
{
    vector<Tip> t;
    for(int i = 0; i<p.size(); i++)
    {
        for(int j =0; j < d.size(); j++)
        {
            if(p[i] == d[j])
            {
                t.push_back(p[i]);
            }
        }
    }

    for(int i=0; i<t.size(); i++)
    {
        for(int j=i+1; j<t.size(); j++)
        {
            if(t[i] == t[j])
            {
                for(int k = j; k<t.size(); k++)
                {
                    t[k] = t[k+1];
                }
                t.resize(t.size() - 1);
                j--;
            }
        }
    }
    return t;
}


int main()
{
    string pr,dr;
    int velicinaPrva,velicinaDruga;
    cout << "Unesite broj elemenata prvog vektora: ";
    cin >> velicinaPrva;
    vector<string> prvi;
    cout <<"Unesite elemente prvog vektora:";
    for(int i = 0; i<=velicinaPrva; i++)
    {
        getline(cin,pr);
        prvi.push_back(pr);
    }
    cout << "Unesite broj elemenata drugog vektora: ";
    cin >> velicinaDruga;
    vector<string> drugi;
    cout <<"Unesite elemente drugog vektora:";
    for(int i = 0; i<=velicinaDruga; i++)
    {
        getline(cin,dr);
        drugi.push_back(dr);
    }
    cout << "Zajednicki elementi su: ";
    for(string i :  Presjek(prvi,drugi))
    {
        cout << i <<" " << endl;
    }


    return 0;
}
