#include <iostream>
#include <algorithm>
using namespace std;

struct triTemp
{
    double jutarnja,dnevna,vecernja;
};


bool kriterij(const triTemp &temp1, const triTemp &temp2)
{
    if(temp1.jutarnja + temp1.dnevna + temp1.vecernja / 3 > temp2.jutarnja + temp2.dnevna + temp2.vecernja / 3) return true;

    return false;
}

class Temperature
{
    int max;
    triTemp *pok;
    int brojac = 0;
public:
    explicit Temperature(int maxbr)
    {
        pok = new triTemp[maxbr];
        max = maxbr;
    }
    ~Temperature()
    {
        delete [] pok;
    }
    Temperature(Temperature &a)
    {
        max = a.max;
        pok = a.pok;
    }
    Temperature operator = (Temperature &a)
    {
        pok = a.pok;
        return *this;
    }
    void RegistrujTemp (double j,double d,double v)
    {
        for(int i = 0; i<max; i++)
        {
            pok[brojac].jutarnja = j;
            pok[brojac].dnevna = d;
            pok[brojac].vecernja = v;
        }
        brojac++;
        if(brojac > max) throw domain_error("Dostignut maksimalan broj temperatura");
    }
    void IzbrisiSveTemp()
    {
    delete [] pok;
    pok = NULL;
    }
    void ispisTemp()
    {
        sort(pok, pok+brojac, &kriterij);

        for(int i = 0; i<brojac; i++)
        {
            cout << pok[i].jutarnja << " " << pok[i].dnevna << " " << pok[i].vecernja <<  endl;

        }
        cout << endl;
    }

};

int main()
{

    Temperature a(5);
    a.RegistrujTemp(1,2,3);
    a.RegistrujTemp(4,5,6);
    a.ispisTemp();
    a.IzbrisiSveTemp();
    a.ispisTemp();
     a.RegistrujTemp(4,5,6);
     a.ispisTemp();

    return 0;
}
