#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main()
{
  int brElemenata;
  float z,fi;
    cout << "Unesite broj elemenata: ";
    cin >>brElemenata;
         complex<double> suma(0, 0);
         complex<double> zU(0, 0);
    for(int i=0; i<brElemenata; i++){
    cout << "Z" <<i+1<<" = ";
    cin >> z;
     cout << "fi" <<i+1<<" = ";
    cin >> fi;
    cout << endl;
    complex<double> unosVektora(z, fi);
    abs(unosVektora);
    polar(z,arg(unosVektora));

     zU = 1./polar(z,fi);
    suma += zU;
    }
    cout << endl;
    complex<double> sumaUkupna(0, 0);

}
