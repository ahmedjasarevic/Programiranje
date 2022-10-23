#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

class ApstraktnaKlasa
{
    double brPredmeta;
    double tezinaObjekta;
    string nazivObjekta;
    double tezinaPredmeta;
public:
    ApstraktnaKlasa(double tezina,string naziv,double brPredmeta,double tezinapredmeta)
    {
        nazivObjekta = naziv;
        tezinaObjekta = tezina;
        ApstraktnaKlasa::tezinaPredmeta = tezinapredmeta ;
        ApstraktnaKlasa::brPredmeta = brPredmeta;
    }
    string DajNaziv()
    {
        return nazivObjekta;
    }
    double DajtezinaObjekta()
    {
        return tezinaObjekta;
    }
    double DajBrPredmeta()
    {
        return brPredmeta;
    }
    double DajTezinu()
    {
        return tezinaPredmeta;
    }
    virtual double DajUkupnuTezinu() = 0;
    virtual void IspisiPodatke() = 0;
};

class Sanduk : public ApstraktnaKlasa
{
public:
    Sanduk(double tezina,string naziv,double brPredmeta,double tezinaPredmeta) : ApstraktnaKlasa(tezina,naziv,brPredmeta,tezinaPredmeta) {}
    double DajUkupnuTezinu()
    {
        return DajTezinu()+DajtezinaObjekta();
    }
    void IspisiPodatke()
    {
        cout << "Vrsta spremnika: Sanduk " << endl;
        cout << "Sadrzaj: " <<   DajNaziv() << endl;
        cout << "Broj predmeta: " << DajBrPredmeta()<< endl;
        cout << "Tezina predmeta: " << DajtezinaObjekta()<< endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
    }
};

class Bure : public ApstraktnaKlasa
{
public:
    Bure(double tezina,string nazivTec,double tezinaT) : ApstraktnaKlasa(tezina,nazivTec,0,tezinaT) {}
    double DajUkupnuTezinu()
    {
        return DajTezinu()+DajtezinaObjekta();
    }
    void IspisiPodatke()
    {
        cout << "Vrsta spremnika: Bure " << endl;
        cout << "Sadrzaj: " <<   DajNaziv() << endl;
        cout << "Vlastita tezina: " << DajtezinaObjekta() << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
    }
};

class Skladiste
{
    int kapacitet;
    ApstraktnaKlasa** pok;
    int brojPredmeta = 0;
public:
    explicit Skladiste(int maxb)
    {
        pok = new ApstraktnaKlasa*[maxb];
        kapacitet = maxb;
    }

    Skladiste(const Skladiste &&o)
    {
        kapacitet = o.kapacitet;
    }

    void operator =(Skladiste &o)
    {
        swap(kapacitet,o.kapacitet);
    }

    void KreirajSanduk(string naziv,double tezina,double brPredmeta,double tezinaPredmeta)
    {
        pok[brojPredmeta] = new Sanduk(tezina,naziv,brPredmeta,tezinaPredmeta);
        brojPredmeta++;
    }


    void KreirajBure(string naziv,double tezina,double tezinaTecnosti)
    {
        pok[brojPredmeta] = new Bure(tezina,naziv,tezinaTecnosti);
        brojPredmeta++;
    }

    int& vratiNajlaksiPredmet()
    {
        int Min = INT_MAX;
        for(int i = 0; i<brojPredmeta; i++)
        {

            if(pok[i]->DajTezinu() < Min)
            {
                Min = pok[i]->DajTezinu();
            }
        }
        return Min;
    }

    int vratiBrojVecih(int broj)
    {
        int brojac = 0;
        for(int i = 0; i<brojPredmeta; i++)
        {
            if(pok[i]->DajTezinu() > broj)
            {
                brojac++;
            }
        }
        return brojac;
    }

    void IspisSkladista()
    {
        for(int i = 0; i<brojPredmeta; i++)
            pok[i]->IspisiPodatke();
    }

    void UcitajIzDatoteke(string imeDatoteke)
    {
        string line1,line2;
        char znak,znak2;
        int num;
        ifstream novifajl(imeDatoteke);
        if(novifajl.fail())
        {
            cerr << "Gteska" << endl;
        }
        while(getline(novifajl,line1)){
        string novi;
        if(line1[0] == 'S' )
        {
            for(int i = 1; i<line1.size(); i++)
            {
                if(line1[i] == ' ') continue;
                novi += line1[i];
            }
            vector<int> vektorBrojeva;
            while(novifajl >> num)
            {
                vektorBrojeva.push_back(num);
            }
            KreirajSanduk(novi,vektorBrojeva[0],vektorBrojeva[1],vektorBrojeva[2]);
        }
        if(line1[0] == 'B' )
        {
            for(int i = 1; i<line1.size(); i++)
            {
                if(line1[i] == ' ') continue;
                novi += line1[i];
            }
            vector<int> vektorBrojeva;
            while(novifajl >> num)
            {
                vektorBrojeva.push_back(num);
            }
            KreirajBure(novi,vektorBrojeva[0],vektorBrojeva[1]);
        }
    }
    }


};

int main()
{

    Skladiste s(5);
    s.UcitajIzDatoteke("ROBA.txt");
    s.IspisSkladista();
    return 0;
}
