#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename t>
set<t> Unija (set<t> a, set<t> b){
    set<t> unija;
for(auto it = a.begin(); it != a.end(); it++){
           unija.insert(*it);
        }
for(auto it2 = b.begin(); it2 != b.end(); it2++){
       unija.insert(*it2);
}
return unija;
}

template <typename t>
set<t> Presjek (set<t> a, set<t> b){
    set<t> presjek;
for(auto it = a.begin(); it != a.end(); it++){
for(auto it2 = b.begin(); it2 != b.end(); it2++){
      if(*it == *it2)
      {
          presjek.insert(*it2);
      }
}
}
return presjek;
}


int main()
{
  set<int> skup;
  set<int> skup1;
  int n,n2,unos,unos2;
  cout << "Unesite duzinu skupa1: ";
  cin >> n;
  for(int i = 0; i<n; i++){
    cin >> unos;
    skup.insert(unos);
  }
  cout << "Unesite duzinu skupa2: ";
 cin >> n2;
  for(int i = 0; i<n2; i++){
    cin >> unos;
    skup1.insert(unos);
  }
set<int> a;
a = Presjek(skup,skup1);
 for(auto it = a.begin(); it != a.end(); it++){
    cout << *it << " ";
 }
    return 0;
}
