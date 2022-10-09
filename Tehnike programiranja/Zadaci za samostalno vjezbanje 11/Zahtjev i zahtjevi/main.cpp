#include <iostream>

using namespace std;

class Zahtjev
{
    string ime;
    string prezime;
    int brIndeksa;
    string tekst;
    int dan,mjesec,godina;
public:
    Zahtjev(string i,string p,int indeks,string tekst1,int dan1,int mjesec1,int godina1)
    {
        ime = i;
        prezime = p;
        brIndeksa = indeks;
        tekst = tekst1;
        dan = dan1;
        mjesec = mjesec1;
        godina = godina1;
    }
    friend class Zahtjevi;
};

class Zahtjevi
{
    Zahtjev** pok;
    int brUpisanih = 0;
    int maxA;
public:
    Zahtjevi(int maxbr)
    {
        pok = new Zahtjev*[maxbr];
        maxA = maxbr;
    }
    void Dodajzahtjev(string im,string p,int indeks,string tekst1,int dan11,int mjesec11,int godina11)
    {
        for(int i = 0; i<maxA; i++)
        {
            pok[brUpisanih] = new Zahtjev(im,p,indeks,tekst1,dan11,mjesec11,godina11);
        }
        brUpisanih++;
    }
    void Ispis()
    {

        for(int i = 0; i < brUpisanih; i++)
        {

            cout << pok[i]->ime << " " << pok[i]->prezime <<" " <<  pok[i]->brIndeksa << " " << pok[i]->tekst << " "  << pok[i]->dan << " " << pok[i]->mjesec << " " << pok[i]->godina << endl;

        }
        for(int i = 0; i < brUpisanih; i++)
        {
            pok[i] = NULL;
            delete pok[i];

        }

    }

    bool ProvjeraEleemnata ()
    {
        if(pok == NULL) return true;
        return false;
    }

};

int main()
{
    Zahtjevi a(5);
    a.Dodajzahtjev("ahmed","jasarevic",33,"nemateksta",2,3,2019);
    a.Ispis();
    cout << a.ProvjeraEleemnata();
    return 0;
}
