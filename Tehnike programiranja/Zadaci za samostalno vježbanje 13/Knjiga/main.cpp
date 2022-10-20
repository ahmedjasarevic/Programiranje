#include <iostream>

using namespace std;

class Knjiga{
int brojKnjige;
string naslov,imePisca,zanr;
int clanskaKartica;
int izdanjeKnjige;
bool raspolozivostKnjige;
int brojDanaCitanja;
virtual ostream& Ispisi(ostream& os){
    os << naslov <<" " << imePisca <<" " <<zanr <<" " <<izdanjeKnjige <<endl;
    return os;
    }
public:
    Knjige(int eb,string n,string ime,string z,int god){
    brojKnjige = eb;
    naslov = n;
    imePisca = ime;
    zanr = z;
    izdanjeKnjige = god;
    raspolozivostKnjige = true;
    }

    int vratiBrojKnjige(){
    return brojKnjige;
    }

    string vratiNaslov(){
    return naslov;
    }

    string vratiPisca(){
    return imePisca;
    }

    string vratiZanr(){
    return zanr;
    }

    int vratiIzdanje(){
    return izdanjeKnjige;
    }

    int vratiDaneCitanja(){
    int brojDanaCitanja;
    }

    int vratiClanskeKartice(){
    int clanskaKartica;
    }

    void zaduziKnjigu(int clanskiBroj){
    clanskaKartica = clanskiBroj;
    brojDanaCitanja = 0;
    raspolozivostKnjige = false;
    }

    void razduziKnjigu(int clanskiBroj){
    clanskaKartica = clanskiBroj;
    raspolozivostKnjige = true;
    }

    friend bool operator !(Knjiga &a);
    friend bool operator ++(Knjiga &a);
    friend bool operator ++(Knjiga &a,int);
    friend bool operator ==(Knjiga &a,Knjiga &b);
    friend bool operator !=(Knjiga &a,Knjiga &b);
    friend ostream& operator<<(ostream& os, const Knjiga& dt);

};

 bool operator !(Knjiga &a){
 if(a.raspolozivostKnjige == true)return true;
 return false;
 }

 bool operator ++(Knjiga &a){
 a.brojDanaCitanja += 1;
 }

  bool operator ++(Knjiga &a,int){
 a.brojDanaCitanja += 1;
 }

bool operator ==(Knjiga &a,Knjiga &b){
if(a.imePisca == b.imePisca && a.naslov == b.naslov && a.zanr == b.zanr && a.izdanjeKnjige == b.izdanjeKnjige) return true;
return false;
}

bool operator !=(Knjiga &a,Knjiga &b){
if(a.imePisca != b.imePisca && a.naslov != b.naslov && a.zanr != b.zanr && a.izdanjeKnjige != b.izdanjeKnjige) return true;
return false;
}

 ostream& operator<<(ostream& os, const Knjiga& dt){
os << dt.Ispisi(os);

 }



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
