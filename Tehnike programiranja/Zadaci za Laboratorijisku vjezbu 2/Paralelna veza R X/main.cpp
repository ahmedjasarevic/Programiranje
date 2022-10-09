#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main()
{
  int brElemenata;
  float real,imag;
    cout << "Unesite broj elemenata: ";
    cin >>brElemenata;
         complex<double> suma(0, 0);
         complex<double> zU(0, 0);
    for(int i=0; i<brElemenata; i++){
    cout << "R" <<i+1<<" = ";
    cin >> real;
     cout << "X" <<i+1<<" = ";
    cin >> imag;
    cout << endl;
    complex<double> unosVektora(real, imag);
     zU = 1./unosVektora;
    suma += zU;
    }
    cout << endl;
    complex<double> sumaUkupna(0, 0);
    sumaUkupna = 1. / suma;
    cout <<"Paralelna veza ovih elemata ima R = " << sumaUkupna.real() << " i X = " << sumaUkupna.imag();
}
