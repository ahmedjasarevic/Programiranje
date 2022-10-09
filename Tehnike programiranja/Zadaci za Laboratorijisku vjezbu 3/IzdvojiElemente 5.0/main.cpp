#include <iostream>
#include <deque>
#include <vector>

using namespace std;
bool DaLiSuCifreParne (int element){
    int suma = 0,ostatak;
 while (element != 0){
        ostatak = element % 10;
        suma = suma + ostatak;
        element /= 10;
 }
 if(suma % 2 == 0)
    return true;
 else return false;

}

deque<int> IzdvojiElemente (deque<int> vektor,bool sumaParna){
    deque<int> vektor1;
    deque<int> vektor2;
for(int i = 0; i<vektor.size(); i++){
    if(DaLiSuCifreParne(vektor[i]) == true){
        vektor1.push_front(vektor[i]);
    }
    else vektor2.push_front(vektor[i]);
}
if (sumaParna == true)
    return vektor1;
else return vektor2;


}

int main()
{   int broj,velicina;
    cout <<" Koliko zelite unijeti elemenata: ";
    cin >> velicina;
    deque<int> unosVektora;
    cout << "Unesite elemente: ";
for(int i=0; i<velicina; i++){
        cin >> broj;
       unosVektora.push_back(broj);

}
deque<int> vektorSumaParna;
deque<int> vektorSumaNeparna;
vektorSumaParna = IzdvojiElemente(unosVektora, true);
vektorSumaNeparna = IzdvojiElemente(unosVektora, false);
    for (int i = vektorSumaParna.size() -1; i>=0; i--){
        if(i == 0){
     cout << vektorSumaParna[i] << " ";
    }
    else{
         cout << vektorSumaParna[i]  << ",";
    }
}
cout <<endl;
      for (int i = vektorSumaNeparna.size() -1; i>=0; i--){
        if(i == 0){
     cout << vektorSumaNeparna[i] << " ";
    }
    else{
         cout << vektorSumaNeparna[i]  << ",";
    }
}
}
