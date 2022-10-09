#include <iostream>
#include <math.h>


using namespace std;

typedef std::pair<double, double> Tacka;
enum Pozicija {GoreLijevo, GoreDesno, DoljeLijevo, DoljeDesno};
enum Smjer {Nalijevo, Nadesno};

class Pravougaonik{
Tacka a;
Tacka b;
public:
Pravougaonik(const Tacka &t1, const Tacka &t2){
a.first = t1.first;
a.second = t1.second;
b.first = t2.first;
b.second = t2.second;
}
void Postavi(const Tacka &t1, const Tacka &t2){
a.first = t1.first;
a.second = t1.second;
b.first = t2.first;
b.second = t2.second;
}
void Postavi(Pozicija p, const Tacka &t){
if(p == Pozicija::DoljeDesno){
    b.first = t.first;
    a.second = t.second;
}
if(p == Pozicija::GoreDesno){
    b.first = t.first;
    b.second = t.second;
}
if(p == Pozicija::DoljeLijevo){
    a.first = t.first;
    a.second = t.second;
}
if(p == Pozicija::GoreLijevo){
    a.first = t.first;
    b.second = t.second;
}
}
void Centriraj(const Tacka &t){
    Tacka nova;
nova.first = (t.first + a.first) / 2;
nova.second = (t.second + b.second) / 2;
}
Tacka DajTjeme(Pozicija p) const{
if(p == Pozicija::DoljeDesno){
return b;
}
if(p == Pozicija::GoreDesno){
return b;
}
if(p == Pozicija::DoljeLijevo){
return a;
}
if(p == Pozicija::GoreLijevo){
return a;
}
}
Tacka DajCentar() const{
    Tacka nova;
    nova.first = (a.first + b.first) / 2;
    nova.second = (a.second + b.second) / 2;
return nova;
}
double DajHorizontalnu() const{
double sirina = sqrt(pow((b.first-a.first),2)+pow((a.second-a.second),2));
return sirina;
}
double DajVertikalnu() const{
double visina = sqrt(pow((a.first-a.first),2)+pow((b.second-a.second),2));
return visina;
}
double DajObim() const{
return ( 2 *  DajHorizontalnu() )+ (2* DajVertikalnu());
}
double DajPovrsinu() const{
return DajHorizontalnu() * DajVertikalnu();
}
static Pravougaonik Presjek(const Pravougaonik &p1, const Pravougaonik &p2){
if((p1.a.first == p2.a.first || p1.a.second == p2.a.second || p1.b.first == p2.b.first || p1.b.second == p2.b.second )== true)

}
void Transliraj(double delta_x, double delta_y){
a.first += delta_x;
b.first += delta_x;
a.second+= delta_y;
b.second += delta_y;
}
void Rotiraj(const Tacka &t, Smjer s){
if(s == Smjer::Nadesno){

}
}
void Ispisi() const{
cout << "{{" << a.first << "," << a.second << "},{" << b.first << "," << b.second << "}}";
}
friend bool DaLiSePoklapaju(const Pravougaonik &p1, const Pravougaonik &p2){
}
friend bool DaLiSuPodudarni(const Pravougaonik &p1, const Pravougaonik &p2);
friend bool DaLiSuSlicni(const Pravougaonik &p1, const Pravougaonik &p2);
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
