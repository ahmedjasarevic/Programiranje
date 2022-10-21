#include <iostream>
#include <vector>

using namespace std;

class ApstraktnoVozilo{
int tezinaVozila;
public:
    ApstraktnoVozilo(int t){
    tezinaVozila = t;
    }

    int DajTezinu(){
    return tezinaVozila;
    }
    virtual int DajUkupnuTezinu() = 0;
    virtual void IspisiPodatke() = 0;
    virtual ApstraktnoVozilo *DajKopiju() const = 0;

};

class Automobil : public ApstraktnoVozilo{
vector<int> tezinaPutnika;
public:
    Automobil(int t,vector<int> tP) : ApstraktnoVozilo(t){
    tezinaPutnika = tP;
    }

    int DajUkupnuTezinu(){
        int ukupno = 0;
        for(auto a : tezinaPutnika){
            ukupno+= a;
        }
        return ukupno+DajTezinu();
    }

    void IspisiPodatke(){
    cout <<endl;
    cout <<"Vrsta vozila: Automobil" <<endl;
    cout << "Vlastita tezina : " << DajTezinu() <<endl;
    cout <<"Tezine putnika : " ;
    for(auto a : tezinaPutnika){
        cout << a << " kg ";
    }
    cout << endl;
    cout <<"Ukupna tezina : " << DajUkupnuTezinu() << " kg" <<endl;
    }

    ApstraktnoVozilo *DajKopiju() const override {
    return new Automobil(*this);
    }
};

class Kamion : public ApstraktnoVozilo{
int tezinaTereta;
public:
    Kamion(int t,int tT) : ApstraktnoVozilo(t){
    tezinaTereta = tT;
    }

    int DajUkupnuTezinu(){
        return tezinaTereta+DajTezinu();
    }

    void IspisiPodatke(){
    cout <<endl;
    cout <<"Vrsta vozila: Kamion" <<endl;
    cout << "Vlastita tezina : " << DajTezinu() << " kg " <<endl;
    cout <<"Tezine tereta : "  << tezinaTereta << " kg " <<endl;
    cout <<"Ukupna tezina : " << DajUkupnuTezinu() << " kg" <<endl;
    }

    ApstraktnoVozilo *DajKopiju() const override {
    return new Kamion(*this);
    }
};

class Autobus : public ApstraktnoVozilo{
int  brojPutnika;
double prosjecnaTezina;
public:
    Autobus(int t,int bP,double pT) : ApstraktnoVozilo(t){
    brojPutnika = bP;
    prosjecnaTezina = pT;
    }

    int DajUkupnuTezinu(){
        return brojPutnika*prosjecnaTezina+DajTezinu();
    }

    void IspisiPodatke(){
    cout <<endl;
    cout <<"Vrsta vozila: Autobus" <<endl;
    cout << "Vlastita tezina : " << DajTezinu() <<endl;
    cout <<"Broj putnika : " << brojPutnika <<endl;
    cout << "Prosjecna tezina putnika: " <<prosjecnaTezina << " kg" <<endl;
    cout <<"Ukupna tezina : " << DajUkupnuTezinu() << " kg" <<endl;
    }

    ApstraktnoVozilo *DajKopiju() const override {
    return new Autobus(*this);
    }
};

int main()
{
    ApstraktnoVozilo* pok[5];
    pok[0] = new Automobil(700,{80,90,60});
    pok[1] = new Kamion(1600,850);
    pok[2] = new Autobus(2500,30,75);
    pok[0]->IspisiPodatke();
    pok[1]->IspisiPodatke();
    pok[2]->IspisiPodatke();
    return 0;
}
