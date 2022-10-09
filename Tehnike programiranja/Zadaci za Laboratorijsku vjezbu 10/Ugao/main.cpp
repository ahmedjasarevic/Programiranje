#include <iostream>

using namespace std;

class Ugao{
float ugaoUradijanima;
public:
Ugao(float radijani = 0){
ugaoUradijanima = radijani;
}
Ugao(int stepeni, int minute, int sekunde){
    if(stepeni > 360){
        stepeni = stepeni - 360;
    }
    if(stepeni < 0){
        stepeni = 360 + stepeni;
  }
    ugaoUradijanima = stepeni + (minute / 60.) + (sekunde / 3600.);
}
void Postavi(float radijani){
ugaoUradijanima = radijani;
}
void Postavi(int stepeni, int minute, int sekunde){
 if(stepeni > 360){
        stepeni = stepeni - 360;
    }
    if(stepeni < 0){
        stepeni = 360 + stepeni;
  }
    ugaoUradijanima = stepeni + (minute / 60.) + (sekunde / 3600.);
}
double DajRadijane() const{
return ugaoUradijanima;
}
void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde){
stepeni = int(ugaoUradijanima);
minute = int((ugaoUradijanima - stepeni) * 60);
sekunde = (ugaoUradijanima - stepeni - (minute/60.)) * 3600;
}
int DajStepene() const{
return  int(ugaoUradijanima);
}
int DajMinute() const{
return int((ugaoUradijanima - DajStepene()) * 60);
}
int DajSekunde() const{
return (ugaoUradijanima - DajStepene() - (DajMinute()/60.)) * 3600;
}
void Ispisi() const{
cout << ugaoUradijanima <<endl;
}
void IspisiKlasicno() const{
cout << DajStepene() <<"deg " << DajMinute() << "min " << DajSekunde() << "sec" <<endl;
}
Ugao &SaberiSa(const Ugao &u){
    Ugao c;
    c.ugaoUradijanima = ugaoUradijanima + u.ugaoUradijanima;
    c.IspisiKlasicno();
    return c;
}
Ugao &PomnoziSa(double x){
    Ugao c;
c = ugaoUradijanima * x;
c.IspisiKlasicno();
return c;
}
friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
Ugao c;
c = u1.ugaoUradijanima + u2.ugaoUradijanima;
c.IspisiKlasicno();
return c;
}
friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
Ugao c;
c = u.ugaoUradijanima * x;
c.Ispisi();
}
};

int main()
{
        Ugao a(120,13,14);
    a.Ispisi();
    a.Postavi(34,2,8);
    a.Ispisi();
    cout << a.DajRadijane();
      cout << endl;
    int f,b,c;
    a.OcitajKlasicneJedinice(f,b,c);
    cout << endl;
    cout << f << " " << b << " " << c << endl;
    cout << a.DajStepene() << " " << a.DajMinute() << " " << a.DajSekunde() << endl;
    a.IspisiKlasicno();
    Ugao v3(2,2,3);
    a.SaberiSa(v3);
    a.PomnoziSa(3);
    Ugao a1,a2;
    a1.Postavi(34,2,8);
    a2.Postavi(34,2,8);
    ZbirUglova(a1,a2);
    ProduktUglaSaBrojem(v3,2);
    return 0;
}
