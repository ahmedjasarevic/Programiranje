#include <iostream>
#include <vector>
#include <complex>


using namespace std;



int main()
{
  int brElemenata;
  double real,imag;
    cout << "Unesite broj elemenata: ";
    cin >>brElemenata;
       complex<double> suma(0, 0);
         complex<double> zU(0, 0);
    for(int i=0; i<brElemenata; i++){
            cout << "Z_ "<< i+1 <<" =  ";
    cin >> real>> imag;
    complex<double> unosVektora(real, imag);
      cout << "Z_ "<< i+1 <<" =  "<< unosVektora<< endl;
    cout <<endl;
    zU = 1./unosVektora;
    suma += zU;

    }
    cout <<"Paralelna veza ovih elemata ima impedansu Z_ = " << 1. / suma;
}
