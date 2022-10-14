#include <iostream>
#include <vector>

using namespace std;

int DaLiJeProst(int n){
    for (int i=2; i<n; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

vector<int> ProstiBrojeviUOpsegu (int a, int b){
    vector<int> Opseg;
     for(int i=a; i<=b; i++){
    Opseg.push_back(i);
   }
    return Opseg;

}
int main()
{
   int pocetna,zadnja,flag=0;
   cout << "Unesite pocetnu i krajnju vrijednost: ";
   cin >> pocetna >> zadnja;
      for (int i:   ProstiBrojeviUOpsegu(pocetna,zadnja)){
    if(DaLiJeProst(i)) {
            flag = 1;
    }
   }
    if(flag == 0){
    cout << "Nema prostih brojeva u rasponu od " << pocetna << " do " << zadnja << " !";
   }
   else{
   cout << "Prosti brojevi u rasponu od " << pocetna << " do " << zadnja << " su: ";
   for (int i:   ProstiBrojeviUOpsegu(pocetna,zadnja)){
    if(DaLiJeProst(i)) {
       cout << i <<  ", ";
    }
   }
   }


    return 0;
}
