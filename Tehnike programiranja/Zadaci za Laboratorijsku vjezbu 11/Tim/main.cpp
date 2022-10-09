#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class Tim{
char ime_tima[20];
int broj_odigranih,broj_pobjeda,broj_nerijesenih,broj_poraza,broj_datih,broj_primljenih,broj_poena;
public:
    Tim(const char ime[]){
        size_t len = strlen(ime);
        if(len > 20 ) throw range_error("Predugo");
for(int i = 0; i<len-1; i++){
    ime_tima[i] = ime[i];
}
    broj_odigranih = broj_pobjeda = broj_nerijesenih = broj_poraza = broj_datih = broj_primljenih = broj_poena = 0;
    }
void ObradiUtakmicu(int broj_datih, int broj_primljenih){
    if(broj_datih < 0 || broj_primljenih < 0) throw range_error("Negativan broj");
broj_odigranih += 1;
if ( broj_datih > broj_primljenih){
    broj_pobjeda += 1;
    broj_poena += 3;
}
if ( broj_datih == broj_primljenih){
    broj_nerijesenih += 1;
    broj_poena += 1;
}
if ( broj_datih < broj_primljenih){
    broj_poraza += 1;
}
Tim::broj_datih += broj_datih;
Tim::broj_primljenih += broj_primljenih;
}
const char *DajImeTima() const{
return ime_tima;
}
int DajBrojPoena() const{
return broj_poena;
}
int DajGolRazliku() const{
return broj_datih-broj_primljenih;
}
void IspisiPodatke() const{
cout <<setw(20) << left << ime_tima;
cout <<setw(4) << right << broj_odigranih;
cout <<setw(4) << right << broj_pobjeda;
cout <<setw(4) << right << broj_nerijesenih;
cout <<setw(4) << right << broj_poraza;
cout <<setw(4) << right << broj_datih;
cout <<setw(4) << right << broj_primljenih;
cout <<setw(4) << right << broj_poena << endl;
}

};

int main()
{
    char naziv[20] ={'a','h','m','e','d',' '};
    Tim a(naziv);
    cout << *a.DajImeTima() << endl;
  a.IspisiPodatke();
  a.ObradiUtakmicu(2,4);
  a.IspisiPodatke();


    return 0;
}
