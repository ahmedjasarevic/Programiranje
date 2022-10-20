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
 out <<"Lik: " << o.naziv <<" Obim: " << o.ObimLika();
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
    DajNazivLika() = "Krug";
    }

    Krug(double a){
    poluprecnik = a;
    DajNazivLika() = "Krug";
    }

    double DajObim() const {
        return 2 * 3.1415 * poluprecnik;
    }
    double ObimLika() {}


};

class Pravougaonik : public ApstraktnaKlasa{
double a,b;
public:
    Pravougaonik(){
    a = b = 0;
    DajNazivLika() = "Pravougaonik";
    }

    Pravougaonik(double a,double b){
    if(b <= 0 || a <= 0) throw domain_error("Neispravni parametri");
    Pravougaonik::a = a;
    Pravougaonik::b = b;
    DajNazivLika() = "Pravougaonik";
    }

    double DajObim() const {
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

    Trougao(double a,double b,double c){
    if(b <= 0 || a <= 0 || c <= 0) throw domain_error("Neispravni parametri");
    Trougao::a = a;
    Trougao::b = b;
    Trougao::c = c;
    DajNazivLika() = "Trougao";
    }

    double DajObim() const {
        return a+b+c;
    }
};





int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
