#include <iostream>
#include <vector>


using namespace std;

bool TestPerioda (vector<double> v ,int p){
if(p > v.size()) return false;
for(int i = 0; i < v.size() - p; i++){
    if(v[i] != v[i+p]) return false;
}
return true;
}
 int OdrediOsnovniPeriod (vector<double> v){
 for(int i = 1; i<v.size(); i++){
    if(TestPerioda(v,i)) return i;
 }
 return 0;
 }

int main()
{
     double broj;
    vector<double> unosVektora;
    vector<double> unosVektora2 = {1,3,1,4,2,1,3,1,4,2,1,3};
    cout << "Unesite sljed brojeva (0 za kraj): ";
     do
     {
        cin >> broj;

        unosVektora.push_back(broj);

     } while (broj != 0);
     cout << OdrediOsnovniPeriod(unosVektora2);
     for(int i = 0; i< unosVektora.size(); i++){
    OdrediOsnovniPeriod(i);
     }
     cout << OdrediOsnovniPeriod(unosVektora);
}
