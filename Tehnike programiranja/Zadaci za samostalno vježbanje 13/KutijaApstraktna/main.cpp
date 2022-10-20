#include <iostream>
#include <vector>

using namespace std;

class KutijaApstraktna{
double tezinaKutije;
public:
    KutijaApstraktna(double t){
        tezinaKutije = t;
    }

    double DajTezinu(){
    return tezinaKutije;
    }

    virtual double DajUkupnuTezinu() = 0;
};

class KutijaObicna : public KutijaApstraktna{
double tezinasadrzajaKutije;
public:
    KutijaObicna(double tez1,double tez2) : KutijaApstraktna(tez1){
    tezinasadrzajaKutije = tez2;
    }

    double DajUkupnuTezinu(){
    tezinasadrzajaKutije += DajTezinu();
    return tezinasadrzajaKutije;
    }
};

class KutijaSaPregradama : public KutijaApstraktna{
vector<double> vec;
public:
    KutijaSaPregradama(double tez1,vector<double> a) : KutijaApstraktna(tez1){
    vec = a;
    }

    double DajUkupnuTezinu(){
        double ukupno;
        for(auto a : vec){
            a += DajTezinu();
            ukupno += a;
        }
        return ukupno;
    }


};

int main()
{
    KutijaObicna d(5,2);
    cout << d.DajUkupnuTezinu();

    return 0;
}
