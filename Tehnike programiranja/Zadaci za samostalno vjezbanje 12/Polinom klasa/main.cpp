#include <iostream>

using namespace std;
class Polinom{
int stepenPolinoma;
int* pok;
int brojac = 0;
public:
    explicit Polinom(int najveciStepen){
    stepenPolinoma = najveciStepen;
    pok = new int[najveciStepen];
     for(int i = 0; i <stepenPolinoma; i++){
        pok[i] = 0;
        }
    }

    Polinom(int najveciStepen, double niz[]){
    pok = new int[najveciStepen];
        for(int i = 0; i <najveciStepen; i++){
        pok[i] = niz[i];
        }
        stepenPolinoma = najveciStepen;
    }

    ~Polinom(){
    delete [] pok;
    }

    Polinom(const Polinom& objekat){
    stepenPolinoma = objekat.stepenPolinoma;
    }

    Polinom& operator=(const Polinom& objekat){
    stepenPolinoma = objekat.stepenPolinoma;
    return *this;
    }

    int VratiStepen(){
    return stepenPolinoma;
    }

    int vratiStalniStepen(){
    for(int i = 0; i<stepenPolinoma; i++){
        if(pok[i] == 0) break;
        brojac++;
    }
    return brojac;
    }


    int& operator[](int indeks){
    return pok[indeks];
    }

    int& operator()(int indeks){
    }

    void promjeniStepen(int noviStepen){
        for(int i =noviStepen ; i>0; i--){
            pok[i] = 0;
            if(i == stepenPolinoma) break;
        }
    }

    void redukcijaStepena(){
    }

    bool operator!(){
        for(int i = 0; i<stepenPolinoma; i++){
        if(pok[i] == 0) return true;
        return false;
        }
    }

    friend Polinom operator+(Polinom& a,const Polinom& b);
    friend ostream &operator << (ostream &out, const Polinom &o);

};

    ostream &operator << (ostream &out,const Polinom &o) {
        for(int i = 0; i <o.stepenPolinoma; i++){
        out << o.pok[i];
        if(i != 0) out << "x^" << i;
        if(i != o.stepenPolinoma - 1) out << " + ";
        }
    out <<endl;
    return out;
    }

   Polinom operator+(Polinom& a,const Polinom& b){
        int stepen = 0;
        if(a.stepenPolinoma > b.stepenPolinoma) stepen = a.stepenPolinoma;
        else stepen = b.stepenPolinoma;
        Polinom c(stepen);
        for(int i = 0; i<stepen; i++){
            c.pok[i] = a.pok[i] + b.pok[i];
       }
    return c;
    }

int main()
{
    double niz[2] = {1,2};
    Polinom a(2,niz);
     double niz2[2] = {3,4};
    Polinom b(2,niz2);
    cout << a;
    cout << b;
    Polinom c(2);
    c = a + b;
    cout << c;
    return 0;
}
