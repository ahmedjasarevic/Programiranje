#include <iostream>
#include <algorithm>

using namespace std;

class Vodostaji
{
    int *pok;
    int maxVrijednost;
    int brojac = 0;
public:
    explicit Vodostaji(int vodostajMax)
    {
        pok = new int[vodostajMax];
        maxVrijednost = vodostajMax;
    }
    ~Vodostaji()
    {
        delete [] pok;
    }
    void RegistrujVodostaj(int a)
    {
        for(int i = 0; i<maxVrijednost; i++)
        {
            pok[brojac] = a;
        }
        brojac++;
        if(brojac > maxVrijednost) throw domain_error("Dostignut maksimalan broj temperatura");
    }
    double prosjek(Vodostaji &a)
    {
        double suma = 0;
        for(int i = 0; i<brojac; i++)
        {
            suma += pok[i];
        }
        return suma/brojac;
    }
    void izbrisiSve()
    {
        delete [] pok;
    }
    int brDana(Vodostaji &a)
    {
        int brojacDana = 0;
        for(int i = 0; i < maxVrijednost; i++)
        {
            if(pok[i] > maxVrijednost)
            {
                brojacDana++;
            }
        }
        return brojacDana;
    }
    void ispisVodostaj()
    {
        sort(pok, pok + brojac, greater<int>());
        for(int i = 0; i<brojac; i++)
        {
            cout << pok[i];
        }
        cout << endl;
    }
};


int main()
{
    Vodostaji a(5);
    a.RegistrujVodostaj(6);
    a.RegistrujVodostaj(2);
    a.RegistrujVodostaj(2);
    a.RegistrujVodostaj(8);
    a.ispisVodostaj();
    cout << a.prosjek(a) << endl;
    cout << a.brDana(a);
    return 0;
}
