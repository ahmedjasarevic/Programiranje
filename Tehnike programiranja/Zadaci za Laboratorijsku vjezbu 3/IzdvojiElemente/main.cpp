#include <iostream>
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

vector<int> IzdvojiElemente (vector<int> vektor,bool sumaParna){
    vector<int> vektor1;
    vector<int> vektor2;
for(int i = 0; i<vektor.size(); i++){
    if(DaLiSuCifreParne(vektor[i]) == true){
        vektor1.push_back(vektor[i]);
    }
    else vektor2.push_back(vektor[i]);
}
if (sumaParna == true)
    return vektor1;
else return vektor2;


}

int main()
{   int broj,velicina;
    cout <<" Koliko zelite unijeti elemenata: ";
    cin >> velicina;
    vector<int> unosVektora;
    cout << "Unesite elemente: ";
for(int i=0; i<velicina; i++){
        cin >> broj;
       unosVektora.push_back(broj);

}
vector<int> vektorSumaParna;
vector<int> vektorSumaNeparna;
vektorSumaParna = IzdvojiElemente(unosVektora, true);
vektorSumaNeparna = IzdvojiElemente(unosVektora, false);
    for (int x : vektorSumaParna) cout << x << " ";
    cout << endl;
    for (int y : vektorSumaNeparna) cout << y << " ";

}

