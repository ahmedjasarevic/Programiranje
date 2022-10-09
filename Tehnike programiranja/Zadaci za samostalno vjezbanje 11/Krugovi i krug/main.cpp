#include <iostream>
#include <algorithm>


using namespace std;

struct Krug { double x, y, r; };

class Krugovi{
    Krug a;
    Krug *pok;
    int brojKrugova = 0;
public:
    explicit Krugovi(int maxbr){
    pok = new Krug[maxbr];
    }

    ~Krugovi(){
        delete [] pok;
    }

    void DodajKrug(double x,double y,double r){
    pok[brojKrugova].x = x;
    pok[brojKrugova].y = y;
    pok[brojKrugova].r = r;
    brojKrugova++;
    }

    Krug& vratiReferencu(int indeks){
       for(int i = 0; i<brojKrugova; i++){
            if(i == indeks){
        return a;
            }
       }
    }

    void ispis(){

    for(int i = 0; i < brojKrugova; i++) {
        for(int j = 0; j < (brojKrugova - i - 1); j++) {
            if((pok[j].r * pok[j].r * 3.14) > (pok[j+1].r * pok[j+1].r * 3.14)) {
            swap(pok[j], pok[j+1]);
            }
        }
    }

    for(int i = 0; i<brojKrugova; i++){

        cout << "[(" << pok[i].x  << "," << pok[i].y << ")," << pok[i].r << "]"<< endl;
    }
    }
};

int main()
{
    Krugovi a(5);
    a.DodajKrug(2,3,4);
    a.DodajKrug(1,3,1);
    a.ispis();
    a.vratiReferencu(0);
    return 0;
}
