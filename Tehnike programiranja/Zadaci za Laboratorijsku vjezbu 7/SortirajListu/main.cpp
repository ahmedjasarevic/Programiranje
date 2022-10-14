#include <iostream>
#include <list>
using namespace std;

template<typename T>
list<T> SortirajListu (list<T> lista){
    typename list<T>::iterator it ;
 typename list<T>::iterator it2 ;
 for(auto it = lista.begin(); it != lista.end(); it++){
     for(auto it2 = lista.begin(); it2 != it; it2++){
     if(*it < *it2){
        iter_swap(it,it2);
     }
}
}
return lista;
}



int main()
{
    int n,unos;
    list<int> a;
    cout << "Koliko ima elemenata: ";
    cin >> n;
    cout <<"Unesite elemenete ";
    for(int i =0; i<n; i++){
        cin >> unos;
        a.push_back(unos);
    }
     list<int> lista = SortirajListu(a);
    list<int>::iterator it = lista.begin();
    while (it != lista.end()){
        cout << *it++ << " ";
    }
    return 0;
}
