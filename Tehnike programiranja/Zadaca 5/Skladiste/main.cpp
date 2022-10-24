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
};

class Sanduk : public Spremnik
{
    vector<int> vecPredmeta;
public:
    Sanduk(double tezina,string naziv,vector<int> v) : Spremnik(tezina,naziv) {
    vecPredmeta = v;
    }
    double DajUkupnuTezinu()
    {
        double  suma = 0;
        for(auto a : vecPredmeta){
            suma += a;
        }
        return DajTezinu()+suma;
    }
    void IspisiPodatke()
    {
        cout << "Vrsta spremnika: Sanduk " << endl;
        cout << "Sadrzaj: " <<   DajNaziv() << endl;
        cout << "Tezine predmeta: ";
        for(auto a : vecPredmeta){
            cout << a << " ";
        }
        cout << endl;
        cout << "Vlastita tezina: " <<DajTezinu() <<endl;
        cout << "Ukupna tezina: " << DajUkupnuTezinu() << endl;
        cout << endl;
    }
};

class Vreca : public Spremnik{
    double VrecatezinaMaterije;
public:
    Vreca(string naziv,double tezinaVrece,double tezinaMaterije) : Spremnik(tezinaVrece,naziv){
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

};


class Bure : public Spremnik
{
    double zapreminaTecnosti,tecnost;
public:
    Bure(double tezina,string nazivTec,double tezinaT,double zapremina) : Spremnik(tezina,nazivTec) {
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
};

class Skladiste
{
    int kapacitet;
    vector<shared_ptr<Spremnik>> vec;
    int brojPredmeta = 0;
public:
    Skladiste() {}
    Skladiste(const Skladiste &&o)
    {
        kapacitet = o.kapacitet;
    }

    void operator =(Skladiste &o)
    {
        swap(kapacitet,o.kapacitet);
    }

    void KreirajSanduk(double tezina,string naziv,vector<int> v)
    {
        shared_ptr<Spremnik> pok[(brojPredmeta+1)];
        pok[brojPredmeta] = make_shared<Sanduk>(tezina,naziv,v);
        vec.push_back(pok[brojPredmeta]);
        brojPredmeta++;
    }


    void KreirajBure(double tezina,string nazivTec,double tezinaT,double zapremina)
    {
        shared_ptr<Spremnik> pok[(brojPredmeta+1)];
        pok[brojPredmeta] = make_shared<Bure>(tezina,nazivTec,tezinaT,zapremina);
        vec.push_back(pok[brojPredmeta]);
        brojPredmeta++;
    }

      void KreirajVrecu(string naziv,double tezinaVrece,double tezinaMaterije)
    {
        shared_ptr<Spremnik> pok[(brojPredmeta+1)];
        pok[brojPredmeta] = make_shared<Vreca>(naziv,tezinaVrece,tezinaMaterije);
        vec.push_back(pok[brojPredmeta]);
        brojPredmeta++;
    }


    int& vratiNajlaksiPredmet()
    {
        int Min = INT_MAX;
        for(int i = 0; i<brojPredmeta; i++)
        {

            if(vec[i]->DajTezinu() < Min)
            {
                Min = vec[i]->DajTezinu();
            }
        }
        return Min;
    }

    int vratiBrojVecih(int broj)
    {
        int brojac = 0;
        for(int i = 0; i<brojPredmeta; i++)
        {
            if(vec[i]->DajTezinu() > broj)
            {
                brojac++;
            }
        }
        return brojac;
    }

    void DodajSpremnik(Spremnik *pok,bool vlasnik){

    }
    void IspisSkladista()
    {
        for(int i = 0; i<brojPredmeta; i++)
            vec[i]->IspisiPodatke();
            cout << endl;
    }





};
int main()
{
   Skladiste s;
   s.KreirajSanduk(10,"Trofazni kataklingeri za auspuhe",{2,3,1,2,2,4,3,1,3});
   s.KreirajBure(5,"Rafinirana kalamuta iz Katange",1300,150);
   s.KreirajVrecu("Praskaste cincozne za glajfanje",0.2,5);
   s.IspisSkladista();
    return 0;
}
