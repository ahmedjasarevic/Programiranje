#include <iostream>

using namespace std;

struct Tjeme{
double x, y;
};

class Poligon{
double* pok1;
double* pok2;
int brTjemena;
Tjeme a;
public:
    explicit Poligon(int tjeme){
    if(tjeme < 3) throw domain_error("Ne postoji poligon sa tjemenom manjeimod 3");
    brTjemena = tjeme;
    pok1 = new double[tjeme]();
    pok2 = new double[tjeme]();
    }

    ~Poligon(){
    delete [] pok1;
    delete [] pok2;
    }

    int dajBrojtjemena(){
    return brTjemena;
    }

    void PostaviTjeme(int redniBroj,int x,int y){
    if(redniBroj > brTjemena || redniBroj < 0) throw domain_error("Neispravan redni broj tjemena");
    pok1[redniBroj] = x;
    pok2[redniBroj] = y;
    }

    Tjeme saznajTjeme (int indeks){
        Tjeme a;
        for(int i = 0; i < brTjemena; i++){
                if(i == indeks){
                    a.x = pok1[i];
                    a.y = pok2[i];
                    break;
                }
        }
    return a;
    }

    void ispisiTjeme(int indeks){
          for(int i = 0; i < brTjemena; i++){
                if(i == indeks){
                   cout << pok1[i] << " " << pok2[i] ;
                    break;
                }
        }
    }

    double dajPovrsinu(int n){
        double formula = 0.0;
    int j = n - 1;
    for(int i = 0; i<brTjemena; i++){
        formula += (pok1[j] + pok1[i]) * (pok2[j]-pok2[i]);
        j = i;
    }
    return abs(formula / 2.0);
    }

    bool DaLiJeDegeneriran(){};
};

int main()
{
   Poligon a(3);
     a.PostaviTjeme(0,1,2);
   a.PostaviTjeme(1,2,3);
   a.saznajTjeme(1);
   a.ispisiTjeme(1);
    return 0;
}
