#include <iostream>

using namespace std;

class Knjiga
{
    int brojKnjige;
    string naslov,imePisca,zanr;
    int clanskaKartica;
    int izdanjeKnjige;
    bool raspolozivostKnjige;
    int brojDanaCitanja;
protected:
    virtual ostream& Ispisi(ostream& os)
    {
        os << naslov <<" " << imePisca <<" " <<zanr <<" " <<izdanjeKnjige <<endl;
        return os;
    }
public:
    Knjiga(int eb,string n,string ime,string z,int god)
    {
        brojKnjige = eb;
        naslov = n;
        imePisca = ime;
        zanr = z;
        izdanjeKnjige = god;
        raspolozivostKnjige = true;
    }

    int vratiBrojKnjige()
    {
        return brojKnjige;
    }

    string vratiNaslov()
    {
        return naslov;
    }

    string vratiPisca()
    {
        return imePisca;
    }

    string vratiZanr()
    {
        return zanr;
    }

    int vratiIzdanje()
    {
        return izdanjeKnjige;
    }

    int vratiDaneCitanja()
    {
        int brojDanaCitanja;
    }

    int vratiClanskeKartice()
    {
        int clanskaKartica;
    }

    void zaduziKnjigu(int clanskiBroj)
    {
        clanskaKartica = clanskiBroj;
        brojDanaCitanja = 0;
        raspolozivostKnjige = false;
    }

    void razduziKnjigu(int clanskiBroj)
    {
        clanskaKartica = clanskiBroj;
        raspolozivostKnjige = true;
    }

    friend bool operator !(Knjiga &a);
    friend bool operator ++(Knjiga &a);
    friend bool operator ++(Knjiga &a,int);
    friend bool operator ==(Knjiga &a,Knjiga &b);
    friend bool operator !=(Knjiga &a,Knjiga &b);
    friend ostream& operator<<(ostream& os,  Knjiga& dt);

};

bool operator !(Knjiga &a)
{
    if(a.raspolozivostKnjige == true)return true;
    return false;
}

bool operator ++(Knjiga &a)
{
    a.brojDanaCitanja += 1;
}

bool operator ++(Knjiga &a,int)
{
    a.brojDanaCitanja += 1;
}

bool operator ==(Knjiga &a,Knjiga &b)
{
    if(a.imePisca == b.imePisca && a.naslov == b.naslov && a.zanr == b.zanr && a.izdanjeKnjige == b.izdanjeKnjige) return true;
    return false;
}

bool operator !=(Knjiga &a,Knjiga &b)
{
    if(a.imePisca != b.imePisca && a.naslov != b.naslov && a.zanr != b.zanr && a.izdanjeKnjige != b.izdanjeKnjige) return true;
    return false;
}

ostream& operator<<(ostream& os,  Knjiga& dt)
{
    return  dt.Ispisi(os);
}


class Udzbenik : public Knjiga
{
    string predmet;
public:
    Udzbenik(int eb,string n,string ime,string z,int god,string p) : Knjiga(eb,n,ime,z,god)
    {
        predmet = p;
    }

    string saznajPredmet()
    {
        return predmet;
    }

    ostream& Ispisi(ostream& os)
    {
        cout << predmet <<" ";
        Knjiga::Ispisi(os);
    }

};

class Biblioteka
{
    int brKnjiga = 0;
    int maxBrKnjiga;
    int zaduzeneKnjige = 0;
    Knjiga** pok;
public:
    explicit Biblioteka(int maxBr)
    {
        pok = new Knjiga*[maxBr];
    }

    ~Biblioteka()
    {
        delete [] pok;
    }

    void DodajKnjigu(int eb,string n,string ime,string z,int god)
    {
        pok[brKnjiga] = new Knjiga(eb,n,ime,z,god);
        brKnjiga++;
    }

    void DodajUdzbenik(int eb,string n,string ime,string z,int god,string predmet)
    {
        pok[brKnjiga] = new Udzbenik(eb,n,ime,z,god,predmet);
        brKnjiga++;
    }

    void zaduziKnjigu(int evidencijak,int clanskak)
    {
        for(int i = 0; i<brKnjiga; i++)
        {
            if(pok[i]->vratiClanskeKartice() == clanskak)
            {
                if(pok[i]->vratiBrojKnjige() != evidencijak) throw logic_error("Ne postoji knjiga");
                pok[i]->zaduziKnjigu(clanskak);
                zaduzeneKnjige++;
            }

        }
    }

    void razduziKnjigu(int evidencijak,int clanskak)
    {
        for(int i = 0; i<brKnjiga; i++)
        {
            if(pok[i]->vratiClanskeKartice() == clanskak)
            {
                if(pok[i]->vratiBrojKnjige() != evidencijak) throw logic_error("Ne postoji knjiga");
                pok[i]->razduziKnjigu(clanskak);
            }

        }
    }

    bool zaduzenoistKnjige(int evidencijskibr)
    {
        for(int i = 0; i<brKnjiga; i++)
        {
            if(pok[i]->vratiBrojKnjige() == evidencijskibr)return true;
            return false;
        }
    }

    void ispisiSve(int nDana){
     for(int i = 0; i<brKnjiga; i++)
        {
            if(pok[i]->vratiDaneCitanja() <= nDana){
                cout << brKnjiga << " " << zaduzeneKnjige;
            }
        }
    }





};


int main()
{
    Udzbenik a(3,"naslov","ime","zanr",2022,"matematika");
    cout << a;
    return 0;
}
