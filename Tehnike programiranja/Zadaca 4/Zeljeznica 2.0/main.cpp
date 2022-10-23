#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

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
    vector<shared_ptr<Polazak>> vec;
    int brojVoznji = 0;
public:
    explicit RedVoznje(){
    brojVoznji = 0;
    }
    RedVoznje(std::initializer_list<Polazak> lista_polazaka)
    {
        shared_ptr<Polazak> pok[lista_polazaka.size()];
        for(auto a : lista_polazaka)
        {
            pok[brojVoznji] = make_shared<Polazak>(a);
            vec.push_back(pok[brojVoznji]);
            brojVoznji++;
        }
    }
    RedVoznje(const RedVoznje &red_voznje)
    {
        for(int i = 0; i <brojVoznji; i++)
        {
            vec[i] = red_voznje.vec[i];
        }
        brojVoznji = red_voznje.brojVoznji;
    }
    RedVoznje(RedVoznje &&red_voznje)
    {
        for(int i = 0; i <brojVoznji; i++)
        {
            vec[i] = red_voznje.vec[i];
        }
        brojVoznji = red_voznje.brojVoznji;
    }
    RedVoznje &operator =(const RedVoznje &red_voznje)
    {
        for(int i = 0; i <brojVoznji; i++)
        {
            vec[i] = red_voznje.vec[i];
        }
        brojVoznji = red_voznje.brojVoznji;
        return *this;
    }
    RedVoznje &operator =(RedVoznje &&red_voznje)
    {
        swap(brojVoznji,red_voznje.brojVoznji);
        for(int i = 0; i <brojVoznji; i++)
        {
            swap(vec[i],red_voznje.vec[i]);
        }
        return *this;
    }
    void RegistrirajPolazak(string odrediste, int broj_voza, bool brzi_voz,int broj_perona, int sat_polaska, int minute_polaska, int trajanje_voznje)
    {
        shared_ptr<Polazak> pok[(brojVoznji+1)];
        pok[brojVoznji] = make_shared<Polazak>(odrediste,broj_voza,brzi_voz,broj_perona,sat_polaska,minute_polaska,trajanje_voznje);
        vec.push_back(pok[brojVoznji]);
        brojVoznji++;
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
            if(vec[i]->DaLiKasni() == true) brojacKojikasni++;
        }
        return brojacKojikasni;
    }
    int DajProsjecnoTrajanjeVoznji() const
    {
        double suma = 0;
        for(int i = 0; i <brojVoznji; i++)
        {
            suma += vec[i]->DajTrajanjeVoznje();
        }
        return suma / brojVoznji;
    }
    Polazak &DajPrviPolazak() const
    {
        Polazak a = *vec[0];
        return a;
    }
    Polazak &DajPosljednjiPolazak() const
    {
        Polazak a = *vec[0];
        for(int i = brojVoznji; i>0; i--)
        {
            Polazak a = *vec[i];
            break;
        }
        return a;
    }
    void IsprazniRedVoznje()
    {
        for(int i = 0; i<brojVoznji; i++)
        {
            vec[i] = 0;
        }
    }
    void Ispisi(int sati, int minute) const
    {

        for(int i = 0; i<brojVoznji; i++)
        {
            vec[i]->Ispisi();
        }

    }


};



int main()
{
    Polazak a("Sarajevo",3423,2,false,15,40,1);
    a.PostaviKasnjenje(90);
    a.Ispisi();
    RedVoznje b;
    b.RegistrirajPolazak("Zenica",123,2,false,19,40,1);
    b.RegistrirajPolazak("Tuzla",567,2,true,15,40,1);
    b.Ispisi(13,40);

    return 0;
}
