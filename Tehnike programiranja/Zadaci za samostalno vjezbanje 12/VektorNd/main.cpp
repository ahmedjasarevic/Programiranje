#include <iostream>
#include <math.h>


using namespace std;

class VektorNd
{
    int Nvektora = 0;
    int* pok;
public:
    VektorNd(int dimenzija,int incijalnaVrijednost)
    {
        pok = new int[dimenzija];
        Nvektora = dimenzija;
        for(int i = 0; i<dimenzija; i++)
        {
            pok[i] = incijalnaVrijednost;
        }
    }

    VektorNd(int dimenzija)
    {
        pok = new int[dimenzija];
        Nvektora = dimenzija;
        for(int i = 0; i<dimenzija; i++)
        {
            pok[i] = 0;
        }
    }

    VektorNd(int dimenzija,double niz[])
    {
        pok = new int[dimenzija];
        for(int i = 0; i<dimenzija; i++)
        {
            pok[i] = niz[i];
        }
    }

    ~VektorNd()
    {
        delete [] pok;
    }

    VektorNd(const VektorNd& v)
    {
        Nvektora = v.Nvektora;
    }

    int vratiDimenziju()
    {
        return Nvektora;
    }

    int indeksKordiante(int indeks)
    {
        for(int i = 0; i < Nvektora; i++)
        {
            if(i == indeks)
                return pok[i];
        }
        return 0;
    }

    void zadajKordinatu(int indeks,int vrijednost)
    {
        if(indeks < 1 || indeks > Nvektora) throw logic_error("Neispravan indeks");
        for(int i = 0; i < Nvektora; i++)
        {
            if(i == (indeks-1))
            {
                pok[i] = vrijednost;
                break;
            }
        }
    }

    double vratiDuzinu()
    {
        double suma = 0;
        for(int i = 0; i<Nvektora; i++)
        {
            suma += pok[i];
        }
        return sqrt(suma);
    }

    int dajRang()
    {
        int brojac;
        for(int i = 0; i<Nvektora; i++)
        {
            if(pok[i] != 0) brojac++;
        }
        return brojac;
    }




    friend double vratiDuzinu(VektorNd a,int kordinata);
    friend ostream &operator << (ostream &out, VektorNd &o);
    friend VektorNd operator+(VektorNd& a, VektorNd& b);
};

ostream &operator << (ostream &out, VektorNd &o)
{
    out<< "{" ;
    for(int i = 0; i<o.Nvektora; i++)
    {
        if(i == (o.Nvektora-1)) out<< o.indeksKordiante(i) ;
        else out<< o.indeksKordiante(i) <<" ,";
    }
    out << "}";
    return out;
}


double vratiDuzinu(VektorNd a,int kordinata)
{
    double suma = 0;
    for(int i = 0; i<kordinata; i++)
    {
        suma += a.pok[i];
    }
    return sqrt(suma);
}

VektorNd operator+(VektorNd& a,VektorNd& b)
{
    if(a.Nvektora != b.Nvektora) throw domain_error("Neisrpavna velicina");
    VektorNd c(a.Nvektora);
    for(int i = 0; i<a.Nvektora; i++)
    {
    c.pok[i] += a.pok[i] + b.pok[i];
    cout << c.pok[i];
    }
    return c;
}

int main()
{
    VektorNd a(2);
    a.zadajKordinatu(1,1);
    a.zadajKordinatu(2,2);
    VektorNd b(2);
    b.zadajKordinatu(1,3);
    b.zadajKordinatu(2,4);
    cout << a;
   VektorNd c(2);
   c = a + b;
   cout << c;
    return 0;
}
