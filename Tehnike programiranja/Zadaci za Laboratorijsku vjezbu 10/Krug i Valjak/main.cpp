#include <iostream>
#include <math.h>

using namespace std;

class Krug {
double poluprecnik;
public:
     Krug(double x){
        if(x <= 0) throw domain_error ("Neispravan poluprecnik");
        poluprecnik = x;
    }
    void Postavi (double x){
         if(x <= 0) throw domain_error ("Neispravan poluprecnik");
    poluprecnik = x;
    }
    double DajPoluprecnik (){
    return poluprecnik;
    }
    double DajObim (){
   return 2 * poluprecnik * M_PI;

    }
    double DajPovrsinu (){
        return (pow(poluprecnik,2)) * M_PI;
    }
    double Skaliraj (double x){
         if(x <= 0) throw domain_error ("“Neispravan faktor skaliranja");
         return poluprecnik * x;
    }
    void Ispisi(){
    cout << "R = "<< DajPoluprecnik() << " O = " << DajObim() << " P = " << DajPovrsinu();
    }
};

class Valjak {
    Krug baza;
double visina;
public:
     Valjak(double b,double v) : baza(b){
         visina = v;
     }
     void Postavi (double b,double v){
          if(b < 0) throw domain_error ("“Neispravan poluprecnik");
          if(v< 0) throw domain_error ("“Neispravna visina");
    visina = v;
    baza = b;
    }
    Krug DajBazu() {
    return baza.DajPovrsinu();

    }
    Krug DajPoluprecnikBaze() {
    return baza.DajPoluprecnik();
    }
    Krug DajVisinu (){
    return visina;
    }
    Krug DajPovrsinu(){
    return ( 2 * DajBazu().DajPoluprecnik()) + (DajPoluprecnikBaze().DajObim()) * visina;
    }
      Krug DajZapreminu(){
    return DajBazu().DajPoluprecnik() * visina;
    }
    void IspisiBazu(){
    cout <<"Baza = " << DajBazu().DajPoluprecnik() << endl;
    }
     void Ispisi(){
    cout <<"R = " << DajPoluprecnikBaze().DajPoluprecnik() << " H = " << DajVisinu().DajPoluprecnik() << " P = " << DajPovrsinu().DajPoluprecnik() << " V = "  << DajZapreminu().DajPoluprecnik() << endl;
    }
    double Skaliraj (double x){
         if(x <= 0) throw domain_error ("“Neispravan faktor skaliranja");
         return DajPoluprecnikBaze().DajPoluprecnik() * x;
    }
};

int main()
{
    Krug a(3);
    cout << a.DajPoluprecnik() << endl;
    cout << a.DajObim() << endl;
     cout << a.DajPovrsinu() << endl;
     cout << a.Skaliraj(5) << endl;
     a.Ispisi();
     cout << endl;
     Valjak v(2,3);
     v.Postavi(1,2);
     v.DajBazu();
     v.IspisiBazu();
     v.Ispisi();
    cout << v.Skaliraj(5);


    return 0;
}
