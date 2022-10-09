#include <iostream>
#include <algorithm>
using namespace std;

class Temperature{
    int max;
    double *pok;
    int brojac = 0;
public:
    explicit Temperature(int maxbr){
        pok = new double[maxbr];
        max = maxbr;
        }
        ~Temperature(){
        delete [] pok;
        }
        Temperature(Temperature &a){
        max = a.max;
        pok = a.pok;
        }
        Temperature operator = (Temperature &a){
        pok = a.pok;
        return *this;
        }
        double* RegistrujTemp (double a){
            for(int i = 0; i<max; i++){
    pok[brojac] = a;
            }
    brojac++;
    if(brojac > max) throw domain_error("Dostignut maksimalan broj temperatura");
    return pok;
        }
        void IzbrisiSveTemp(){
         delete this;
        }
        double prosjek(Temperature &a){
            double suma = 0;
         for(int i = 0; i<brojac; i++){
            suma += pok[i];
    }
    return suma/brojac;
        }
        double minimalna(Temperature &a){
            double min = INT_MAX;
         for(int i = 0; i<brojac; i++){
            if(pok[i] < min){
                min = pok[i];
            }
    }
    return min;
        }
         double maksimalna(Temperature &a){
            double max = INT_MIN;
         for(int i = 0; i<brojac; i++){
            if(pok[i] > max){
                max = pok[i];
            }
    }
    return max;
        }
    void ispisTemp(){
         sort(pok, pok + brojac, greater<int>());
    for(int i = 0; i<brojac; i++){
            cout << pok[i];
    }
    cout << endl;
    }

};

int main()
{

    Temperature a(5);
   a.RegistrujTemp(1);
    a.RegistrujTemp(4);
 a.RegistrujTemp(3);
 a.ispisTemp();
 cout << a.prosjek(a) << endl;
 cout << a.minimalna(a) << endl;
 cout << a.maksimalna(a);
    return 0;
}
