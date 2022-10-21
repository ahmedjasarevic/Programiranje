#include <iostream>

using namespace std;

class ApstraktnaKlasa
{
    double tezinaObjekta;
    string nazivObjekta;
    double tezina;
public:
    ApstraktnaKlasa(string i,double a,double b)
    {
        nazivObjekta = i;
        tezinaObjekta = a;
        tezina = b;
    }
    virtual void IspisiPodatke() = 0;
};

class Sanduk : public ApstraktnaKlasa
{
    double tezinaSanduka;
    string nazivSanduka;
    int brojPredmetauSanduku;
    double tezinaPredmeta;
public:
    Sanduk(string i,double a,double b,double c) : ApstraktnaKlasa(i,a,b)
    {
        tezinaPredmeta = c;
    }
    void IspisiPodatke()
    {
        cout << nazivSanduka << " " << tezinaSanduka <<" " << brojPredmetauSanduku <<" " <<tezinaPredmeta <<endl;
    }
};

class Bure : public ApstraktnaKlasa
{
    double tezinaB;
    string nazivTecnosti;
    double tezinaTecnosti;
public:
    Bure(string i,double a,double b) : ApstraktnaKlasa(i,a,b) {}
    void IspisiPodatke()
    {
        cout << nazivTecnosti << " " << tezinaB <<" " << tezinaTecnosti <<endl;
    }
};

class Skladiste
{
    int kapacitet;
    ApstraktnaKlasa** pok;
public:
    explicit Skladiste(int maxb)
    {
        pok = new *ApstraktnaKlasa[maxb];
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

    void KreirajSanduk(double tS,string naziv,int brP,double tez)
    {

    }


};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
