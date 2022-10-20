#include <iostream>

using namespace std;

class ApstraktnaKlasa{
string naziv;
int brojac = 0;
public:
    ApstraktnaKlasa(){}
    ApstraktnaKlasa(string ime){
    naziv = ime;
    brojac = 1;
    }

    string DajNazivLika(){
    return naziv;
    }

    int DajBrojac(){
    return brojac;
    }

    virtual double ObimLika() = 0;
    friend ostream &operator << (ostream &out,  ApstraktnaKlasa &o);
    friend bool operator > (ApstraktnaKlasa &a,ApstraktnaKlasa &b);
    friend bool operator < (ApstraktnaKlasa &a,ApstraktnaKlasa &b);
    friend operator ++(ApstraktnaKlasa &a);
};

 ostream &operator << (ostream &out,  ApstraktnaKlasa &o) {
 out <<"Lik: " << o.naziv <<" Obim: " << o.ObimLika() << endl;
 }

 bool operator >(ApstraktnaKlasa &a,ApstraktnaKlasa &b){
 if(a.ObimLika() > b.ObimLika() ) return true;
 return false;
 }

  bool operator <(ApstraktnaKlasa &a,ApstraktnaKlasa &b){
 if(a.ObimLika() < b.ObimLika() ) return true;
 return false;
 }

 operator ++(ApstraktnaKlasa &a){
     a.brojac += 1;

 }

 class Krug : public ApstraktnaKlasa{
double poluprecnik;
public:
    Krug(){
    poluprecnik = 0;
    }

    Krug(double a, string naziv): ApstraktnaKlasa(naziv){
    poluprecnik = a;
    }


    double ObimLika() {
          return 2 * 3.1415 * poluprecnik;
    }


};

class Pravougaonik : public ApstraktnaKlasa{
double a,b;
public:
    Pravougaonik(){
    a = b = 0;
    DajNazivLika() = "Pravougaonik";
    }

    Pravougaonik(double a,double b, string naziv): ApstraktnaKlasa(naziv){
    if(b <= 0 || a <= 0) throw domain_error("Neispravni parametri");
    Pravougaonik::a = a;
    Pravougaonik::b = b;
    DajNazivLika() = "Pravougaonik";
    }

    double ObimLika() {
     return 2 * a + 2 * b;
    }


};

class Trougao : public ApstraktnaKlasa{
double a,b,c;
public:
    Trougao(){
     a = b = c = 0;
     DajNazivLika() = "Trougao";
    }

    Trougao(double a,double b,double c ,string naziv): ApstraktnaKlasa(naziv){
    if(b <= 0 || a <= 0 || c <= 0) throw domain_error("Neispravni parametri");
    Trougao::a = a;
    Trougao::b = b;
    Trougao::c = c;
    DajNazivLika() = "Trougao";
    }

    double ObimLika() {
        return a+b+c;
    }
};

class KontejnerskaKlasa {
ApstraktnaKlasa** pok;
int brojLikova = 0;
int kapacitet;
int *poknaBrojac;
public:
    explicit KontejnerskaKlasa(int maxs){
    pok = new ApstraktnaKlasa*[maxs];
    kapacitet = maxs;

    }

    KontejnerskaKlasa(KontejnerskaKlasa &&objekat){
    for(int i = 0; i<kapacitet; i++){
        pok[i] = objekat.pok[i];
    }
    kapacitet = objekat.kapacitet;
    objekat.poknaBrojac += 1;
    poknaBrojac = objekat.poknaBrojac;
    }

    ~KontejnerskaKlasa(){
    poknaBrojac -= 1;
    if(poknaBrojac == 0) delete [] pok;
    }

    void DodajKrug(double r){
    pok[brojLikova] = new Krug(r,"Krug");
    brojLikova++;
    }


    void DodajPravougaonik(double a,double b){
    pok[brojLikova] = new Pravougaonik(a,b,"Pravougaonik");
    brojLikova++;
    }


    void DodajTrougao(double a,double b,double c){
    pok[brojLikova] = new Trougao(a,b,c,"Trougao");
    brojLikova++;
    }

    int vratiBrojLikova(){
    return brojLikova;
    }

    ApstraktnaKlasa& vratiNajveciObim(){
        int maxs = INT_MIN;
        for(int i = 0; i<kapacitet; i++){
            if(pok[i]->ObimLika() > maxs){
                maxs = pok[i]->ObimLika();
            }
        }

        for(int i = 0; i<kapacitet; i++){
            if(pok[i]->ObimLika() == maxs){
                return *pok[i];
            }
        }
    }

    int vratiBrKrugova(){
     int brojac = 0;
        for(int i = 0; i<kapacitet; i++){
            if(pok[i]->DajNazivLika() == "Krug"){
                brojac++;
            }
        }
    return brojac;
    }

    void sortirajLikove(){
        for(int i = 0; i < kapacitet; i++){
            for(int j = 0; j < (kapacitet - i - 1); j++){
                if(pok[j]->ObimLika() < pok[j+1]->ObimLika()){
                    swap(pok[j],pok[j+1]);
                }
            }
        }
    }

    friend bool operator !(KontejnerskaKlasa &a);
    friend ostream &operator << (ostream &out,  KontejnerskaKlasa &o);
};

bool operator !(KontejnerskaKlasa &a){
if(a.brojLikova == 0) return true;
return false;
}

 ostream &operator << (ostream &out,  KontejnerskaKlasa &o) {
     for(int i = 0; i<o.brojLikova; i++){
        out << o.pok[i]->DajNazivLika() <<" ";
        out << o.pok[i]->ObimLika() << endl;
     }
 }


int main()
{
    KontejnerskaKlasa a(5);
    a.DodajKrug(5);
    a.DodajPravougaonik(5,2);
    cout << a;

    return 0;
}
