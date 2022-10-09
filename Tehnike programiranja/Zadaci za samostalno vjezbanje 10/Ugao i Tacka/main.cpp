#include <iostream>
#include <math.h>


using namespace std;

struct Ugao {
 int stepeni, minute, sekunde;
};
struct Tacka {
 double x, y;
};

class Trougao{
    double kateta1,kateta2,hipotenuza;
    public:
explicit Trougao(double a){
kateta1=kateta2=hipotenuza=a;
}
Trougao(double a, double b){
kateta1 = a;
kateta2 = b;
hipotenuza = sqrt(pow(a,2)+pow(b,2));
}
Trougao(double a, double b, double c){
kateta1 = a;
kateta2 = b;
hipotenuza = c;
}
Trougao(double a, double c, Ugao gamma){
kateta1 = a;
hipotenuza = c;
kateta2 = gamma.stepeni;

}
Trougao(Tacka t1, Tacka t2, Tacka t3){
kateta1 = t2.x - t1.x;
kateta2 = t2.y - t1.y;
hipotenuza = sqrt(pow(kateta1,2) + pow(kateta2,2));
}


void Postavi(double a){
    kateta1 = kateta2 = hipotenuza = a;
if(kateta1 < 0 || kateta2 < 0 || hipotenuza < 0) throw domain_error("ILEGALNO");
if(kateta1+kateta2 < hipotenuza || kateta1+hipotenuza < kateta2 || kateta2+hipotenuza < kateta1)  throw domain_error("ILEGALNO");
}
void Postavi(double a, double b);
void Postavi(double a, double b, double c){
    if(a < 0 || b < 0 || c < 0) throw domain_error("ILEGALNO");
if(a+b < c || a+c < b || b+c < a)  throw domain_error("ILEGALNO");
kateta1 = a;
kateta2 = b;
hipotenuza = c;

}
void Postavi(double a, double b, Ugao gamma){
kateta1 = a;
kateta2 = b;
hipotenuza = gamma.stepeni;
}
void Postavi(Tacka t1, Tacka t2, Tacka tC){
kateta1 = t2.x - t1.x;
kateta2 = t2.y - t1.y;
hipotenuza = sqrt(pow(kateta1,2) + pow(kateta2,2));
}
static bool DaLiJeMoguc(double a, double b, double c){
     if(a < 0 || b < 0 || c < 0)  return false;
if(a+b < c || a+c < b || b+c < a)  return false;
return true;
}
double DajA() const{
return kateta1;
}
double DajB() const{
return kateta1;
}
double DajC() const{
return hipotenuza;
}
Ugao DajAlpha() const{

}
Ugao DajBeta() const;
Ugao DajGamma() const;
double DajObim() const;
double DajPovrsinu() const;
void Skaliraj(double s);
void Ispisi() const;
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);


};

int main()
{
    cout << "Hello world!" << endl;
    Trougao a(2,3,4);
    a.Postavi(-2);
    return 0;
}
