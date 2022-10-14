#include <iostream>
#include <time.h>
using namespace std;

template<typename T>
class Vreca
{
    int brElemenata;
    int maxElemenata;
    T* pok;
    int indeks = 0;
    int pomBr = 0;
    bool flag;
public:
    Vreca(int maxB);

    ~Vreca()
    {
        delete [] pok;
    }

    Vreca(const Vreca& a)
    {
        brElemenata = a.brElemenata;
        maxElemenata = a.maxElemenata;
    }

    Vreca& operator =(Vreca&& a)
    {
        brElemenata = a.brElemenata;
        maxElemenata = a.maxElemenata;
        return *this;
    }

    void dodajElement (T element)
    {
        if(indeks > maxElemenata) throw domain_error("Dostignut max. broj");
        for(int i = 0; i < indeks; i++)
        {
            if(element == pok[i]) break;

        }
        pok[indeks] = element;
        indeks++;
    }

    int vratiBrElemenata()
    {
        return brElemenata;
    }

    bool provjeraElemenata(int element)
    {
        for(int i = 0; i < indeks; i++)
        {
            if(element == pok[i]) return true;
            return false;
        }
    }

    void ukloniElement(int element)
    {
        pomBr = indeks;
        for(int i = 0; i < pomBr; i++)
        {
            if(element == pok[i])
            {
                flag = true;
                if(i < (pomBr-1))
                    for(int j = i; j<(pomBr-1); j++)
                        pok[j] = pok[j+1];
                pomBr--;
            }
            else i++;
        }
        if(flag == false) throw domain_error("Nije pronaden element");
    }

    T vratiElement()
    {
        srand(time(0));
        int ranIndex = rand() % indeks;
        return  pok[ranIndex];
    }




};

template <typename T>
Vreca<T>::Vreca(int maxB)
{
    pok = new T[maxB];
    maxElemenata = maxB;
    brElemenata = 0;
}

int main()
{
    Vreca<string> a(5);
    int n;
    string rijec;
    cin >> n;
    string niz[n];
    for(int i = 0; i<n; i++)
    {
        cin >> rijec;
        niz[i] = rijec;

    }
    for(int i = 0; i<n; i++)
    {
        a.dodajElement(niz[i]);

    }
    cout << a.vratiElement() << endl;
    cout << a.vratiElement() << endl;

    return 0;
}
