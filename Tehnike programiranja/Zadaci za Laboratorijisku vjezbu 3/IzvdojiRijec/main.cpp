#include <iostream>
#include <string>


using namespace std;
int flag = 0;

string ocistiRazmake (string recenica)
{
    string rijec = "";
    for(int i = 0; recenica[i] != '\0'; i++)
    {
        if(recenica[i] == ' ' && recenica[i+1] == ' ')
        {
            continue;
        }
        else
        {
            rijec += recenica[i];
        }
    }
    return rijec;
}


string IzdvojiRijec (string recenica, int broj)
{
    string rijec = " "  ;
    int brojac = 1;
    for(int i = 0; recenica[i] != '\0'; i++)
    {
        if(recenica[i] == ' ')
        {
            brojac++;
        }
        if(brojac == broj)
        {
            flag = 1;
            rijec += recenica[i];
        }
    }
    return rijec;
}


int main()
{
    int br,brojac=1;
    string recenica;
    cout << "Unesite redni broj rijeci: " ;
    cin >> br;
    cin.ignore(256, '\n');
    cout << "Unesite recenicu: ";
    getline(cin,recenica);
    string razmak = ocistiRazmake(recenica);
    if(razmak[0] == ' ')
    {
        razmak.erase(razmak.begin());
    }

    IzdvojiRijec(razmak, br);
    if (flag == 1)
    {
        cout  << "Rijec na poziciji " << br << " je" <<  IzdvojiRijec(razmak, br);
    }
    else
    {
        cout << "IZUZETAK: Pogresan redni broj rijeci!";
    }
    return 0;
}
