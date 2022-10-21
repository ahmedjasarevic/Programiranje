#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class ApstraktnaKlasa
{
    double brPredmeta;
    double tezinaObjekta;
    string nazivObjekta;
    double tezina;
public:
    ApstraktnaKlasa(string i,double a,double b,double p)
    {
        nazivObjekta = i;
        tezinaObjekta = a;
        tezina = b;
        brPredmeta = p;
    }
    string DajNaziv(){
    return nazivObjekta;
    }
    double DajTezinu(){
    return tezinaObjekta;
    }
    double DajTezinuTecnosti(){
    return tezina;
    }
    double DajBrPredmeta(){
    return brPredmeta;
    }
    virtual void IspisiPodatke() = 0;
};

class Sanduk : public ApstraktnaKlasa
{
public:
    Sanduk(string i,double a,double b,double c) : ApstraktnaKlasa(i,a,b,c){}
    void IspisiPodatke()
    {
        cout << DajNaziv() << " " << DajTezinu() <<" " << DajBrPredmeta() <<" " <<DajTezinuTecnosti() <<endl;
    }
};

class Bure : public ApstraktnaKlasa
{
public:
    Bure(string i,double a,double b) : ApstraktnaKlasa(i,a,b,0) {}
    void IspisiPodatke()
    {
        cout << DajNaziv() << " " << DajTezinu() <<" " << DajTezinuTecnosti() <<endl;
    }
};

class Skladiste
{
    int kapacitet;
    vector<ApstraktnaKlasa*> pok;
    int brojPredmeta = 0;
public:
    explicit Skladiste(int maxb)
    {
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

    void KreirajSanduk(string naziv,double tezina,double tezina2,double tezina3)
    {
        pok.push_back(new Sanduk(naziv,tezina,tezina2,tezina3));
        brojPredmeta++;
    }


    void KreirajBure(string naziv,double tezina,double tezina2)
    {
        pok.push_back(new Bure(naziv,tezina,tezina2));
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

    void IspisSkladista(){
    for(int i = 0; i<brojPredmeta; i++)
      pok[i]->IspisiPodatke();
    }


};

int main()
{
    Skladiste s(5);
    s.KreirajBure("bure1",23,2);
    s.KreirajSanduk("sanduk1",1,3,2);
    s.IspisSkladista();
    return 0;
}
