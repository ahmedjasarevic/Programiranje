#include <iostream>

using namespace std;

class Polinom{
    double *sPolinoma;
    int indeksStepena;
    char iVarijable;
public:
    Polinom(int stepen,char imeVarijable){
    sPolinoma = new double[stepen];
    indeksStepena = stepen;
    iVarijable = imeVarijable;
    }

    ~Polinom(){
    delete [] sPolinoma;
    }
    Polinom(const Polinom& pol){
     iVarijable = pol.iVarijable;
    }

    void PostaviKoeficijente(int indeks,int koeficijent){
    for(int i = 0; i<indeksStepena; i++){
        if(i == indeks){
        sPolinoma[i] = koeficijent;
        }
    }
    }

    double& operator[](int indeks){
        if(indeks < 0 || indeks > indeksStepena) throw logic_error("Neispravan indeks");
    return sPolinoma[indeks];
    }

    double& operator()(int indeks){
        if(indeks < 0 || indeks > indeksStepena) throw logic_error("Neispravan indeks");
    return sPolinoma[indeks];
    }

};

int main()
{
    char znak = 'x';
    Polinom a(5,znak);
    a.PostaviKoeficijente(0,1);
    return 0;
}
