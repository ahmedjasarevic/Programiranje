#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

template <typename t1, typename t2>
vector<double> ZbirKontejnera (t1 d,t2 v){
    vector<double> zbir;
auto it = d.begin();
auto it2 = v.begin();
while(it != d.end() && it2 != v.end()){
        *it+=*it2;
zbir.push_back(*it);
*it++;
*it2++;
if(it == d.end() && it2 != v.end()){
    while(it2 != v.end()){
    zbir.push_back(*it2);
    *it2++;
}
}
if(it != d.end() && it2 == v.end()){
       while(it != d.end()){
    zbir.push_back(*it);
    *it++;
}
}
}
return zbir;
}

int main()
{
    int br1,br2,element1,element2;
    deque<int> prvi;
    vector<double> drugi;
    cout << "Duzina prvog kontejnera: " ;
    cin >> br1;
    cout << "Elementi prvog kontejnera: ";
    for(int i = 0; i<br1; i++){
        cin >> element1;
        prvi.push_back(element1);
    }
    cout << "Duzina drugog kontejnera: " ;
    cin >> br2;
     cout << "Elementi druge sekvence: ";
    for(int i = 0; i<br2; i++){
        cin >> element2;
           drugi.push_back(element2);
    }
    vector<double> a = ZbirKontejnera(prvi,drugi);
    cout << "Zbir kontejnera: ";
    for(int i: a){
        cout << i << " ";
    }
    return 0;
}
