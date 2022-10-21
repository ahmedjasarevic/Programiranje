#include <iostream>
#include <math.h>
using namespace std;

class Lik
{
    double specGustina;
public:
    Lik(double g)
    {
        specGustina = g;
    }
    double DajZapreminu();
    double DajTezinu();
    virtual void Ispisi() = 0;


};

class Kvadar : public Lik
{
    double a,b,c,gustina;
public:
    Kvadar(double g,double p,double d,double t) : Lik(g)
    {
        a = p;
        b = d;
        c = t;
        gustina = g;
    }

    double DajZapreminu()
    {
        return a * b * c;
    }

    double DajTezinu()
    {
        return DajZapreminu() * gustina;
    }

    void Ispisi()
    {
        cout <<"Kvadar stranica" <<  a << b <<c <<endl;
        cout << "Zapremina: " << DajZapreminu() << " Tezine: " << DajTezinu() << endl;

    }

};

class Lopta : public Lik
{
    double r,gustina;
public:
    Lopta(double g,double r) : Lik(g){
        Lopta::r = r;
        gustina = g;
    }

    double DajZapreminu()
    {
        return 4 * 3.14 * pow(r,3) / 3;
    }

    double DajTezinu()
    {
        return DajZapreminu() * gustina;
    }

    void Ispisi()
    {
        cout <<"Lopta poluprecnika" <<  r <<endl;
        cout << "Zapremina: " << DajZapreminu() << " Tezine: " << DajTezinu() << endl;

    }

};

class Valjak : public Lik
{
    double r,h,gustina;
public:
    Valjak(double g,double r,double h) : Lik(g)
    {
       Valjak::r = r;
       Valjak::h = h;
        gustina = g;
    }

    double DajZapreminu()
    {
        return h * r * r * 3.14;
    }

    double DajTezinu()
    {
        return DajZapreminu() * gustina;
    }

    void Ispisi()
    {
        cout <<"Valjak poluprecnika i visine: " <<  r << h<<endl;
        cout << "Zapremina: " << DajZapreminu() << " Tezine: " << DajTezinu() << endl;

    }

};

class KontejnerskaKlasa{
    Lik** pok;
    int brojac = 0;
public:
    KontejnerskaKlasa() {}
    KontejnerskaKlasa(int br) {
    pok = new Lik*[br];
    }
    void KreirajKvadar(double gustina,double a,double b,double c){
    pok[brojac] = new Kvadar(gustina,a,b,c);
    }

    void KreirajLoptu(double gustina,double r){
    pok[brojac] = new Lopta(gustina,r);
    brojac++;
    }

    void KreirajValjak (double gustina,double r,double h){
    pok[brojac] = new Valjak(gustina,r,h);
    brojac++;
    }


};


int main()
{
    Lik* pok[2];
    pok[0] = new Kvadar(2,3,4,5);
    pok[0]->Ispisi();
    KontejnerskaKlasa a(5);
    a.KreirajKvadar(2,3,4,5);
    return 0;
}
