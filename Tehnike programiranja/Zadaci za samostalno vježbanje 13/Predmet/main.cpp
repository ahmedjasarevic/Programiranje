#include <iostream>
#include <math.h>

using namespace std;

class Predmet{
double gustinaPredmeta;
public:
    Predmet(double g){
    gustinaPredmeta = g;
    }
    virtual double dajZapreminu() = 0;
    double dajMasu(){
    return gustinaPredmeta * dajZapreminu();
    }
};

class Lopta : public Predmet{
double poluprecnikLopte;
public:
     Lopta(double g) : Predmet(g){
     poluprecnikLopte = g;
     }
    double dajZapreminu(){
    return 4 * 3.14 * pow(poluprecnikLopte,3) / 3;
    }

};

class Cigla : public Predmet{
double a,b,c;
public:
    Cigla(double p,double d,double t,double gustina) : Predmet(gustina){
    a = p;
    b = d;
    c = t;
    }

    double dajZapreminu(){
    return a * b * c;
    }

};



int main()
{
    Predmet* pok[5];
    pok[0] = new Cigla(3,5,6,7);
    pok[0] = new Lopta(3);
    return 0;
}
