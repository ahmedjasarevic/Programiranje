#include <iostream>

using namespace std;

class Ugao{
int step,min,sek;
public:
Ugao(float radijani = 0){
step = min = sek = radijani;
}
Ugao(int stepeni, int minute, int sekunde){
    if(stepeni > 360){
        stepeni = stepeni - 360;
    }
    if(stepeni < 0){
        stepeni = 360 + stepeni;
  }
    step = stepeni;
    min = minute;
    sek = sekunde;
}
void Postavi(float radijani){
step = min = sek = radijani;
}
void Postavi(int stepeni, int minute, int sekunde){
  if(stepeni > 360){
        stepeni = stepeni - 360;
    }
    if(stepeni < 0){
        stepeni = 360 + stepeni;
  }
    step = stepeni;
    min = minute;
    sek = sekunde;
}
double DajRadijane() const{
return step + (min / 60.) + (sek / 3600.);
}
void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde){
    float ugaoUradijanima = step + (min / 60.) + (sek / 3600.);
stepeni = int(ugaoUradijanima);
minute = int((ugaoUradijanima - stepeni) * 60);
sekunde = (ugaoUradijanima - stepeni - (minute/60.)) * 3600;
}
int DajStepene() const{
return  step;
}
int DajMinute() const{
return min;
}
int DajSekunde() const{
return sek;
}
void Ispisi() const{
cout << step + (min / 60.) + (sek / 3600.) <<endl;
}
void IspisiKlasicno() const{
cout << DajStepene() <<"deg " << DajMinute() << "min " << DajSekunde() << "sec" <<endl;
}
Ugao &SaberiSa(const Ugao &u){
    Ugao c;
    c.step = step + u.step;
    c.min = min + u.min;
    c.sek = sek + u.sek;
    c.IspisiKlasicno();
    return c;
}
Ugao &PomnoziSa(double x){
 Ugao c;
    c.step = step * x;
    c.min = min  * x;
    c.sek = sek * x;
    c.IspisiKlasicno();
    return c;
}
friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2){
    Ugao c;
    c.step = u1.step + u2.step;
      c.IspisiKlasicno();
return c;
}
friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x){
Ugao c;
c = u.step * x;
c.Ispisi();
return c;
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
