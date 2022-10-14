#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

typedef std::vector<std::vector<int>> Matrica;

using namespace std;

Matrica KroneckerovProizvod (vector<int> v1, vector<int> v2)
{
    Matrica gotovProizvod(v1.size(), vector<int> (v2.size()) );
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            gotovProizvod[i][j] = v1[i] * v2[j] ;
        }
    }
    return gotovProizvod;
}

int NajvecaSirina (Matrica m)
{
    int max = -2147483647;
    int min = 2147483647;
    int red = m.size();
    int kol = m[0].size();

    for(int i = 0; i < red; i++) {
        for(int j = 0; j < kol; j++) {
            if(  m[i][j]  > max )
                max = m[i][j];
            if(  m[i][j]  < min )
                min = m[i][j];
        }
    }

    int maximalni, br=0;
    if(maximalni > 0)
        maximalni = max;
    else maximalni = min;
    while (maximalni != 0) {
        br ++;
        maximalni /= 10;
    }

    if (maximalni = min)
        return br + 2;
    else return br + 1;
}

int main()
{
    int velicina1, velicina2;
    int elVektora1, elVektora2;
    vector<int> v1;
    vector<int> v2;

    cout << "Unesite broj elemenata prvog vektora: ";
    cin >> velicina1;
    cout << "Unesite elemente prvog vektora: ";
    for (int i = 0; i < velicina1; i++) {
        cin >> elVektora1;
        v1.push_back(elVektora1);
    }

    cout << "Unesite broj elemenata drugog vektora: ";
    cin >> velicina2;
    cout << "Unesite elemente drugog vektora: ";
    for (int i = 0; i < velicina2; i++) {
        cin >> elVektora2;
        v2.push_back(elVektora2);
    }
    cout << endl;
    Matrica tenzor= KroneckerovProizvod(v1, v2);
    int razmaci = NajvecaSirina(tenzor);

    for(vector<int> red : tenzor) {
        for(int x : red)
            cout << setw(razmaci) << x;
        cout<< endl;
    }
    cout << endl;
}

