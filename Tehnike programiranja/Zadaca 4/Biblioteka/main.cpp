#include <iostream>
#include <map>

using namespace std;

struct Student
{
    int broj_indeksa;
    string ime,prezime;
    int godina_studija;
    int adresa;
    int telefon;
};


class Knjiga
{
    string naslov,imePisca,zanr;
    int clanskaKartica;
    int izdanjeKnjige;
    Student* raspolozivostKnjige;
public:
    Knjiga(){}
    Knjiga(string n,string ime,string z,int god)
    {
        naslov = n;
        imePisca = ime;
        zanr = z;
        izdanjeKnjige = god;
        raspolozivostKnjige = nullptr;
    }
    string DajNaslov()
    {
        return naslov;
    }

    string DajAutora()
    {
        return imePisca;
    }

    string DajZanr()
    {
        return zanr;
    }

    int DajGodinuIzdavanja()
    {
        return izdanjeKnjige;
    }

    void zaduziKnjigu(Student &s)
    {
        raspolozivostKnjige = &s;
    }

    void razduziKnjigu()
    {
        raspolozivostKnjige = nullptr;
    }

    bool DaLiJeZaduzena()
    {
        if(raspolozivostKnjige == nullptr) return true;
        return false;
    }

    Student& DajKodKogaJe()
    {
        if(raspolozivostKnjige == nullptr) throw domain_error("Knjiga nije zaduzena");
        return *raspolozivostKnjige;
    }

    Student* DajPokKodKogaJe()
    {
        if(raspolozivostKnjige == nullptr) return nullptr;
        return raspolozivostKnjige;
    }




};


class Biblioteka
{
    map<int,Student> mapKorisnika;
    map<int,Knjiga> mapKnjiga;
public:
    Biblioteka() {}
    ~Biblioteka() {}
    Biblioteka(const Biblioteka &obj)
    {
        mapKorisnika = obj.mapKorisnika;
        mapKnjiga = obj.mapKnjiga;
    }
    Biblioteka(Biblioteka &&obj)
    {
        mapKorisnika = obj.mapKorisnika;
        mapKnjiga = obj.mapKnjiga;
    }
    Biblioteka &operator= (Biblioteka &obj)
    {
        swap(mapKorisnika,obj.mapKorisnika);
        swap(mapKnjiga,obj.mapKnjiga);
    }
    void RegistrirajNovogStudenta(int brIND,string i,string pr,int god,int adres,int brTel)
    {
        Student pokazivac;
        pokazivac.ime = i;
        pokazivac.prezime = pr;
        pokazivac.broj_indeksa = brIND;
        pokazivac.godina_studija = god;
        pokazivac.adresa = adres;
        pokazivac.telefon = brTel;
        mapKorisnika[brIND] = pokazivac;
    }
    void RegistrirajNovuKnjigu(int evid,string nas,string im,string zan,int god)
    {
        Knjiga* pokazivac;
        pokazivac = new Knjiga(nas,im,zan,god);
        mapKnjiga[evid] = *pokazivac;
    }
    map<int, Student>::iterator NadjiKorisnika(int brIndeksa)
    {
        map<int, Student>::iterator it;
        for(it=mapKorisnika.begin(); it!=mapKorisnika.end(); ++it)
        {
            if(it->first  == brIndeksa)
            {
                return it;
            }
        }
    }
    map<int, Knjiga>::iterator NadjiKnjigu(int evBroj)
    {
        map<int, Knjiga>::iterator it;
        for(it=mapKnjiga.begin(); it!=mapKnjiga.end(); ++it)
        {
            if(it->first  == evBroj)
            {
                return it;
            }
        }
    }

    void izlistajKorisnike()
    {
        for(auto const& d : mapKorisnika)
        {
            cout << "Broj indeksa: "<< d.first << endl;
            cout << "Ime i prezime : " << d.second.ime << " " << d.second.prezime<< endl;
            cout <<"Godina studija : " << d.second.godina_studija <<endl;
            cout <<"Adresa: " <<d.second.adresa <<endl;
            cout << "Telefon : " <<d.second.telefon << endl;
        }

    }

     void izlistajKnjige()
    {
        for(auto d : mapKnjiga)
        {
            cout << "Evidencijski broj: "<< d.first << endl;
            cout << "Naslov : " << d.second.DajNaslov() <<endl;
            cout << "Pisac : " << d.second.DajAutora() <<endl;
            cout << "Zanr : " << d.second.DajZanr() <<endl;
            cout << "Godina izdavanja : " << d.second.DajGodinuIzdavanja() <<endl;
        }

    }
};

int main()
{
    Biblioteka a;
    a.RegistrirajNovogStudenta(3,"ahmed","jasarevic",2022,12,62);
    a.RegistrirajNovogStudenta(234,"s","jasarevic",2022,12,62);
    a.RegistrirajNovuKnjigu(23,"string","ime","zanr",2022);
    a.izlistajKorisnike();
    cout << endl;
    a.izlistajKnjige();
    return 0;
}
