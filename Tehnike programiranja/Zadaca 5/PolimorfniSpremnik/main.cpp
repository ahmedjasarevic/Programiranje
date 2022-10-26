#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <limits.h>
using namespace std;

class Spremnik
{
    double tezinaObjekta;
    string nazivObjekta;
public:
    Spremnik(double tezina,string naziv)
    {
        nazivObjekta = naziv;
        tezinaObjekta = tezina;
    }
    string DajNaziv()
    {
        return nazivObjekta;
    }
    double DajTezinu()
    {
        return tezinaObjekta;
    }
    virtual double DajUkupnuTezinu() = 0;
    virtual void IspisiPodatke() = 0;
    virtual Spremnik *DajKopiju() const = 0;
};

class Sanduk : public Spremnik
{
    vector<double> vecPredmeta;
public:
    Sanduk(double tezina,string naziv,vector<double> v) : Spremnik(tezina,naziv)
    {
        vecPredmeta = v;
    }
    double DajUkupnuTezinu()
    {
        double  suma = 0;
        for(auto a : vecPredmeta)
        {
            suma += a;
        }
        return DajTezinu()+suma;
    }
    void IspisiPodatke()
    {
        cout << "Vrsta spremnika: Sanduk " << endl;
        cout << "Sadrzaj: " <<   DajNaziv() << endl;
        cout << "Tezine predmeta: ";
        for(auto a : vecPredmeta)
        {
            cout << a << " ";
        }
        cout << endl;
        cout << "Vlastita tezina: " <<DajTezinu() <<endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
        cout << endl;
    }
    Spremnik *DajKopiju() const override
    {
        return new Sanduk(*this);
    }
};

class Vreca : public Spremnik
{
    double VrecatezinaMaterije;
public:
    Vreca(double tezinaVrece,string naziv,double tezinaMaterije) : Spremnik(tezinaVrece,naziv)
    {
        VrecatezinaMaterije = tezinaMaterije;
    }
    double DajUkupnuTezinu()
    {
        return DajTezinu()+VrecatezinaMaterije;
    }
    void IspisiPodatke()
    {
        cout << "Vrsta spremnika: Vreca " << endl;
        cout << "Sadrzaj: " <<   DajNaziv() << endl;
        cout << "Vlastita tezina: " <<DajTezinu() <<endl;
        cout << "Tezina pohranjene materije: " << VrecatezinaMaterije << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
        cout << endl;
    }
    Spremnik *DajKopiju() const override
    {
        return new Vreca(*this);
    }
};


class Bure : public Spremnik
{
    double zapreminaTecnosti,tecnost;
public:
    Bure(double tezina,string nazivTec,double tezinaT,double zapremina) : Spremnik(tezina,nazivTec)
    {
        tecnost = tezinaT;
        zapreminaTecnosti = zapremina;
    }
    double DajUkupnuTezinu()
    {
        return DajTezinu()+zapreminaTecnosti;
    }
    void IspisiPodatke()
    {
        cout << "Vrsta spremnika: Bure " << endl;
        cout << "Sadrzaj: " <<   DajNaziv() << endl;
        cout << "Vlastita tezina: " << DajTezinu() << endl;
        cout << "Specificna tezina tecnosti: " <<tecnost << endl;
        cout << "Zapremina tecnosti: " << zapreminaTecnosti << endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
        cout << endl;
    }
    Spremnik *DajKopiju() const override
    {
        return new Bure(*this);
    }
};

class PolimorfniSpremnik
{
    Spremnik *p_lik;
public:
    PolimorfniSpremnik() : p_lik(nullptr) {}
    PolimorfniSpremnik(const Spremnik &lik) : p_lik(lik.DajKopiju()) {}
    PolimorfniSpremnik(const PolimorfniSpremnik &lik)
    {
        if(!lik.p_lik) p_lik = nullptr;
        else p_lik = lik.p_lik->DajKopiju();
    }
    PolimorfniSpremnik(PolimorfniSpremnik &&lik)
    {
        p_lik = lik.p_lik;
        lik.p_lik = nullptr;
    }
    PolimorfniSpremnik &operator =(const PolimorfniSpremnik &lik)
    {
        Spremnik *p_novi = nullptr;
        if(lik.p_lik != nullptr) p_novi = lik.p_lik->DajKopiju();
        delete p_lik;
        p_lik = p_novi;
        return *this;
    }
    PolimorfniSpremnik &operator =(PolimorfniSpremnik &&lik)
    {
        std::swap(p_lik, lik.p_lik);
        return *this;
    }
    void Ispisi() const
    {
        p_lik->IspisiPodatke();
    }
    double DajTezinu()
    {
        return p_lik->DajTezinu();
    }
    double DajUkupnuTezinu()
    {
        return p_lik->DajUkupnuTezinu();
    }
};


int main()
{
    PolimorfniSpremnik s1(Bure(5,"Benzin", 930, 70)); // s1 je bure
    PolimorfniSpremnik s2, s3; // s2 i s3 su nespecificirani
    s2 = Sanduk(3, "Tepsije", {0.5, 0.8, 0.6, 0.5}); // s2 je sada sanduk
    s3 = Vreca(0.4, "Brasno", 30); // a s3 vreca
    std::cout << s1.DajTezinu() << std::endl;
    std::cout << s2.DajUkupnuTezinu() << std::endl;
    s3.Ispisi();
    s1 = s2; // sad je i s1 sanduk...
    s1.Ispisi();
    return 0;
}
