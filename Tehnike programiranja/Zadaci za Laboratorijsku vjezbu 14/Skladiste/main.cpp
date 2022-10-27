#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>
#include <sstream>
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
        int brojac = 0;
        string line1;
        bool DaLiJeSanduk = false;
        bool DaLiJeBure = false;
        vector<string> nazivi;
        vector<int> brojevi;
        int brojNeki;
        ifstream novifajl(imeDatoteke, ios::in);
        string novi;
        string ukupnaRijec;
        if(novifajl.fail())
        {
            cerr << "Gteska" << endl;
        }
        if(novifajl.is_open())
        {
            while(getline(novifajl,line1))
            {
                if(brojac == 0)
                {
                    if(line1[0] == 'S')
                    {
                        DaLiJeSanduk = true;
                        DaLiJeBure = false;
                        for(int i = 2; i <line1.size(); i++)
                        {
                            ukupnaRijec += line1[i];
                        }
                        nazivi.push_back(ukupnaRijec);
                    }
                    if(line1[0] == 'B')
                    {
                        DaLiJeBure = true;
                        DaLiJeSanduk = false;
                        for(int i = 2; i <line1.size(); i++)
                        {
                            ukupnaRijec += line1[i];
                        }
                        nazivi.push_back(ukupnaRijec);
                    }
                    brojac++;
                }
                else
                {
                    stringstream ss(line1);
                    while(ss >> brojNeki)
                    {
                        brojevi.push_back(brojNeki);
                    }
                    if(DaLiJeBure == true && DaLiJeSanduk == false)
                    {

                        KreirajBure(ukupnaRijec,brojevi[0],brojevi[1]);
                        ukupnaRijec = "";
                    }
                    if(DaLiJeSanduk == true && DaLiJeBure == false)
                    {
                        KreirajSanduk(ukupnaRijec,brojevi[0],brojevi[1],brojevi[2]);
                        ukupnaRijec = "";
                    }
                    brojevi.clear();

                    brojac = 0;
                }
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
