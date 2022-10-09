#include <iostream>
#include <tuple>
#include <iomanip>


using namespace std;

class Datum{
int dan,mjesec,godina;
public:
    Datum(int d, int m, int g){
        if(d < 0 || d > 31 || m < 0 || m > 12 || g < 0 || g >2022) throw domain_error("Neisrpavan datum");
    dan = d;
    mjesec = m;
    godina = g;
    }

    void PostaviDatum(int d,int m,int g){
         if(d < 0 || d > 31 || m < 0 || m > 12 || g < 0 || g >2022) throw domain_error("Neisrpavan datum");
    dan = d;
    mjesec = m;
    godina = g;
    }

    tuple<int,int,int> Ocitaj(){
        return  make_tuple(dan,mjesec,godina);
    }

    void Ispisi(){
    cout << dan << "/" << mjesec << "/" << godina <<endl;
    }
    friend class Pregled;
};

class Vrijeme{
int sati,minute;
public:
    Vrijeme(int s,int m){
        if(s < 0 || s > 23 || m < 0 || m > 59) throw domain_error("Neispravno vrijeme");
        sati = s;
        minute = m;
    }

    void PostaviVrijeme(int s,int m){
         if(s < 0 || s > 23 || m < 0 || m > 59) throw domain_error("Neispravno vrijeme");
        sati = s;
        minute = m;
    }

    pair<int,int> Ocitaj(){
        return make_pair(sati,minute);
    }

    void Ispisi(){
    cout << sati << ":" << minute << endl;
    }
    friend class Pregled;
};

class Pregled{
string ime;
int dan,mjesec,godina;
int minute,sati;
public:
    Pregled(string i,Datum d,Vrijeme v){
        ime = i;
        dan = d.dan;
        mjesec = d.mjesec;
        godina = d.godina;
        sati = v.sati;
        minute = v.minute;
    }

     Pregled(string i,int d,int mj,int g,int s,int minute){
        ime = i;
        dan = d;
        mjesec = mj;
        godina = g;
        sati = s;
        minute = minute;
    }

    string& PromijeniPacijenta(string novoIme){
    ime = novoIme;
    return ime;
    }

     Datum& PromijeniDatum(Datum d){
        Datum a(d.dan,d.mjesec,d.godina);
        return a;
    }

    Vrijeme& PromijeniVrijeme(Vrijeme d){
        Vrijeme a(d.sati,d.minute);
        return a;
    }

    void PomjeriDanUnaprijed() {
    dan += 1;
    }

    void PomjeriDanUnazad() {
    dan -= 1;
    }

    string DajImePacijenta(){
    return ime;
    }


    Datum DajDatumPregleda(){
        Datum a(dan,mjesec,godina);
    return a;
    }

    Vrijeme DajVrijemePregleda(){
        Vrijeme a(sati,minute);
    return a;
    }

    static bool DolaziPrije(Pregled a,Pregled b){
    if(a.DajDatumPregleda().dan < b.DajDatumPregleda().dan && a.DajDatumPregleda().mjesec < b.DajDatumPregleda().mjesec && a.DajDatumPregleda().godina < b.DajDatumPregleda().godina ) return true;
    return false;
    }

    void Ispisi(){
    cout << left << setw(30) << ime << DajDatumPregleda().dan << "/" << DajDatumPregleda().mjesec << "/"  << DajDatumPregleda().godina << " " << DajVrijemePregleda().sati <<":" << DajVrijemePregleda().minute << endl;
    }
};

class Pregledi{
Pregled** pok;
int maxbr;
public:

    explicit Pregledi(int m){
    maxbr = m;
    pok = new Pregled[m];
    }
    Pregledi(initializer_list<Pregled> listaPregleda){
        for(auto a : listaPregleda){
        }
    }


};

int main()
{
    Datum dan(23,4,2022);
    Vrijeme vrijeme(12,22);
    Pregled a("Jasarevic Ahmed",dan,vrijeme);
    a.Ispisi();
    return 0;
}
