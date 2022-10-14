#include <iostream>

using namespace std;

void KreirajIzvrnutiNiz(double *pocetak, double *iza_kraja){
    cout <<"Kreirani niz: ";
while(pocetak != iza_kraja){
           iza_kraja--;
    cout << *iza_kraja << " " ;
}


}

int main()
{
    int n;
try{
    cout <<"Koliko zelite elemenata: ";
    cin >> n;
}
catch(...){
    cout << "s";

}
    double a[n];
    for(int i = 0; i<n ; i++){
        cin >> a[i];
    }
    KreirajIzvrnutiNiz(&a[0], &a[0] + n);
    return 0;
}
