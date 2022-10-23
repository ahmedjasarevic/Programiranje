#include <iostream>
#include <map>

using namespace std;

struct Student{
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
protected:
    virtual ostream& Ispisi(ostream& os)
    {
        os << naslov <<" " << imePisca <<" " <<zanr <<" " <<izdanjeKnjige <<endl;
        return os;
    }
public:
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

    void zaduziKnjigu(Student &s){
    raspolozivostKnjige = &s;
    }

    void razduziKnjigu(){
    raspolozivostKnjige = nullptr;
    }

    bool DaLiJeZaduzena(){
    if(raspolozivostKnjige == nullptr) return true;
    return false;
    }

    Student& DajKodKogaJe(){
        if(raspolozivostKnjige == nullptr) throw domain_error("Knjiga nije zaduzena");
    return *raspolozivostKnjige;
    }

     Student* DajPokKodKogaJe(){
        if(raspolozivostKnjige == nullptr) return nullptr;
    return raspolozivostKnjige;
    }




};


class Biblioteka
{
   map<int,Student**> mapKorisnika;
   map<int,int> mapKnjiga;

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
