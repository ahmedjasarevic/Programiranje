#include <iostream>
#include <algorithm>

using namespace std;

class Polazak
{
    string naziv;
    int brVoza;
    int brPerona;
    bool DaLiJeBrziVoz;
    int vrijemePolaskaSAT;
    int vrijemePolaskaMIN;
    int voznjaUminutama;
    int ukupnaVoznja;
    int kasnjenje;
public:
    Polazak(std::string odrediste, int broj_voza, int broj_perona, bool brzi_voz,int sat_polaska, int minute_polaska, int trajanje_voznje)
    {
        naziv = odrediste;
        brVoza = broj_voza;
        brPerona = broj_perona;
        DaLiJeBrziVoz = brzi_voz;
        vrijemePolaskaSAT = sat_polaska;
        vrijemePolaskaMIN = minute_polaska;
        ukupnaVoznja = trajanje_voznje;
    }
    void PostaviKasnjenje(int kasnjenje)
    {
        Polazak::kasnjenje = kasnjenje;
    }
    bool DaLiKasni() const
    {
        if(kasnjenje+ukupnaVoznja > ukupnaVoznja ) return true;
        return false;
    }
    int DajTrajanjeVoznje() const
    {
        return ukupnaVoznja;
    }
    std::pair<int, int> DajcekivanoVrijemePolaska() const
    {
        pair<int,int> a;
        a.first = vrijemePolaskaSAT;
        a.second = vrijemePolaskaMIN;
        return a;
    }
    std::pair<int, int> DajOcekivanoVrijemeDolaska() const
    {
        pair<int,int> a;
        a.first = vrijemePolaskaSAT+ukupnaVoznja;
        a.second = vrijemePolaskaMIN;
        return a;
    }

    pair<int,int> dajKasnjenjePOLAZAK()const
    {
        pair<int,int> par;
        par.second = DajcekivanoVrijemePolaska().second + kasnjenje;
        par.first = DajcekivanoVrijemePolaska().first;
        while(par.second > 60)
        {
            par.second = par.second - 60;
            par.first += 1;
        }
        return par;
    }

    void Ispisi() const
    {
        if(DaLiKasni() == false)
        {
            if(DaLiJeBrziVoz == true)
            {
                cout << "Brzi voz ";
            }
            else
            {
                cout << "Lokalni voz ";
            }
            cout << brVoza << " , odrediste " << naziv <<", polazi s perona " << brPerona << " u " << DajcekivanoVrijemePolaska().first <<":" << DajcekivanoVrijemePolaska().second <<", a na odrediste stize u " << DajOcekivanoVrijemeDolaska().first <<":"
                 << DajOcekivanoVrijemeDolaska().second << ".Putnicima i voznom osoblju zelimo ugodno putovanje. " << endl;
        }
        else
        {
            if(DaLiJeBrziVoz == true)
            {
                cout << "Brzi voz ";
            }
            else
            {
                cout << "Lokalni voz ";
            }
            cout << brVoza << " , odrediste " << naziv <<", sa predvidenim vremenom polaska u " << DajcekivanoVrijemePolaska().first <<":" << DajcekivanoVrijemePolaska().second <<", kasni oko " << kasnjenje <<" minuta, te ce poci oko "
                 << dajKasnjenjePOLAZAK().first << ":" << dajKasnjenjePOLAZAK().second<< " Ocekuje se da voz stigne na odrediste oko " << dajKasnjenjePOLAZAK().first +ukupnaVoznja << ":" << dajKasnjenjePOLAZAK().second
                 << " Izvinjavamo se putnicima  zbog eventualnih neugodnosti" << endl;
        }
    }
    friend class RedVoznje;
};

class RedVoznje
{
    Polazak** pok;
    int brojVoznji = 0;
public:
    explicit RedVoznje(int max_broj_polazaka)
    {
        pok = new Polazak*[max_broj_polazaka];
    }
    RedVoznje(std::initializer_list<Polazak> lista_polazaka)
    {
        pok = new Polazak*[lista_polazaka.size()];
        for(auto a : lista_polazaka)
        {
            pok[brojVoznji] = new Polazak(a);
            brojVoznji++;
        }
    }
    ~RedVoznje()
    {
        for(int i = 0; i<brojVoznji; i++)
        {
            delete pok[i];
        }
    }
    RedVoznje(const RedVoznje &red_voznje)
    {
        for(int i = 0; i <brojVoznji; i++)
        {
            pok[i] = red_voznje.pok[i];
        }
        brojVoznji = red_voznje.brojVoznji;
    }
    RedVoznje(RedVoznje &&red_voznje)
    {
        for(int i = 0; i <brojVoznji; i++)
        {
            pok[i] = red_voznje.pok[i];
        }
        brojVoznji = red_voznje.brojVoznji;
    }
    RedVoznje &operator =(const RedVoznje &red_voznje)
    {
        for(int i = 0; i <brojVoznji; i++)
        {
            pok[i] = red_voznje.pok[i];
        }
        brojVoznji = red_voznje.brojVoznji;
        return *this;
    }
    RedVoznje &operator =(RedVoznje &&red_voznje)
    {
        swap(brojVoznji,red_voznje.brojVoznji);
        for(int i = 0; i <brojVoznji; i++)
        {
            swap(pok[i],red_voznje.pok[i]);
        }
        return *this;
    }
    void RegistrirajPolazak(string odrediste, int broj_voza, bool brzi_voz,int broj_perona, int sat_polaska, int minute_polaska, int trajanje_voznje)
    {
        pok[brojVoznji] = new Polazak(odrediste,broj_voza,brzi_voz,broj_perona,sat_polaska,minute_polaska,trajanje_voznje);
        brojVoznji++;
    }
    void RegistrirajPolazak(Polazak *polazak)
    {
        pok[brojVoznji] = polazak;
    }
    int DajBrojPolazaka() const
    {
        return brojVoznji;
    }
    int DajBrojPolazakaKojiKasne() const
    {
        int brojacKojikasni;
        for(int i = 0; i <brojVoznji; i++)
        {
            if(pok[i]->DaLiKasni() == true) brojacKojikasni++;
        }
        return brojacKojikasni;
    }
    int DajProsjecnoTrajanjeVoznji() const
    {
        double suma = 0;
        for(int i = 0; i <brojVoznji; i++)
        {
            suma += pok[i]->DajTrajanjeVoznje();
        }
        return suma / brojVoznji;
    }
    Polazak &DajPrviPolazak() const
    {
        Polazak a = *pok[0];
        return a;
    }
    Polazak &DajPosljednjiPolazak() const
    {
        Polazak a = *pok[0];
        for(int i = brojVoznji; i>0; i--)
        {
            Polazak a = *pok[i];
            break;
        }
        return a;
    }
    void IsprazniRedVoznje()
    {
        for(int i = 0; i<brojVoznji; i++)
        {
            delete pok[i];
        }
    }
    void Ispisi(int sati, int minute) const
    {
        for(int i = 0; i < brojVoznji; i++)
        {
            for(int j = 0; j < (brojVoznji - i - 1); j++)
            {
                if(pok[j]->vrijemePolaskaSAT > pok[j+1]->vrijemePolaskaSAT)
                {
                    swap(pok[j],pok[j+1]);

                }
            }
        }

        for(int i = 0; i<brojVoznji; i++)
        {
            pok[i]->Ispisi();
        }

    }


};



int main()
{
    Polazak a("Sarajevo",3423,2,false,15,40,1);
    a.PostaviKasnjenje(90);
    a.Ispisi();
    RedVoznje b(5);
    b.RegistrirajPolazak("Zenica",123,2,false,19,40,1);
    b.RegistrirajPolazak("Tuzla",567,2,true,15,40,1);
    b.Ispisi(13,40);
    return 0;
}
