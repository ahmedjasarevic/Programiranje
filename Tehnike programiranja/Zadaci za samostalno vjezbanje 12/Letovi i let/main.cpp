#include <iostream>
#include <string.h>
#include <iomanip>
#include <algorithm>

using namespace std;

class Let{
char nazivOdredista[30];
char oznakaLeta[10] ;
int izlaznaKapija;
int vrijemePolijetanja;
int letUminutama;
int trajanjeLeta;
int kasnjenjeSati = 0;
int kasnjenjeUminutama = 0;
int brKasnjenja;
public:
Let(const char odrediste[], const char oznaka_leta[], int kapija, int sat_polaska,int minute_polaska, int trajanje_leta){
strncpy(nazivOdredista, odrediste, 30);
strncpy(oznakaLeta, oznaka_leta, 10);
izlaznaKapija = kapija;
vrijemePolijetanja = sat_polaska;
letUminutama = minute_polaska;
trajanjeLeta = trajanje_leta;
kasnjenjeUminutama = 0;
kasnjenjeSati = 0;
}
void PostaviKasnjenje(int kasnjenje){
    brKasnjenja = kasnjenje;
    kasnjenjeSati = vrijemePolijetanja;
    kasnjenjeUminutama = kasnjenje +letUminutama;
    while(kasnjenjeUminutama >= 60){
        kasnjenjeUminutama -= 60;
        kasnjenjeSati+=1;
    }
}
bool DaLiKasni() const{
if(kasnjenjeSati > vrijemePolijetanja || kasnjenjeUminutama > letUminutama) return true;
return false;
}
int DajTrajanjeLeta() const{
    return trajanjeLeta;
}
std::pair<int, int> DajcekivanoVrijemePolijetanja() const{
pair<int, int> a;
a.first = vrijemePolijetanja;
a.second = letUminutama;
return a;
}
std::pair<int, int> DajOcekivanoVrijemeSlijetanja() const{
pair<int, int> a;
a.first = vrijemePolijetanja+trajanjeLeta;
a.second = letUminutama;
return a;
}
friend ostream& operator<<(ostream& os, const Let& dt);
friend Let operator+(Let &a,int broj);
friend Let operator+=(Let &a,int broj);
friend bool operator!(Let &a);
friend Let operator ++(Let &c);
friend Let operator ++(Let &c, int);
friend bool operator<(Let &a,Let &b);
friend bool operator>(Let &a,Let &b);
friend class Letovi;
};

ostream& operator<<(ostream& os, const Let& dt){
if(dt.DaLiKasni() == false){
        os << setw(10) << left << dt.oznakaLeta << setw(20) << dt.nazivOdredista << right << dt.vrijemePolijetanja <<":"  << fixed << dt.letUminutama << setw(7)<< dt.DajOcekivanoVrijemeSlijetanja().first << ":" << dt.DajOcekivanoVrijemeSlijetanja().second << setw(5) <<dt.izlaznaKapija;
    }
    else{
       os << setw(10) << left << dt.oznakaLeta << setw(20) << dt.nazivOdredista << dt.kasnjenjeSati << " " <<dt.kasnjenjeUminutama << "(Planirano  "<< dt.vrijemePolijetanja <<":"  << fixed << dt.letUminutama << ", Kasni  " << dt.brKasnjenja << "min)" <<endl ;
    }
    return os;
}

Let operator+(Let &a,int broj){
a.letUminutama += broj;
return a;
}

Let operator+=(Let &a,int broj){
a.letUminutama += broj;
return a;
}

bool operator!(Let &a){
if(a.kasnjenjeSati > a.vrijemePolijetanja || a.kasnjenjeUminutama > a.letUminutama) return true;
return false;
}

Let operator ++(Let &c){
c.vrijemePolijetanja += 1;
    return c;
}

Let operator ++(Let &c, int){
 c.vrijemePolijetanja += 1;
    return c;
 }

bool operator<(Let &a,Let &b){
if(a.vrijemePolijetanja < b.vrijemePolijetanja) return true;
return false;
}

bool operator>(Let &a,Let &b){
if(a.vrijemePolijetanja > b.vrijemePolijetanja) return true;
return false;
}


class Letovi{
Let** pok;
int brLetova = 0;
int maxLetova;
int kasnjenje = 0;
int kasnjenjeSati = 0;
public:
explicit Letovi(int max_broj_letova){
pok = new Let*[max_broj_letova];
maxLetova = max_broj_letova;
}
~Letovi(){
    for(int i = 0; i<brLetova; i++){
        delete pok[i];
    }
}



Letovi(const Letovi &letovi){
}
Letovi(Letovi &&letovi);
Letovi &operator =(const Letovi &letovi);
Letovi &operator =(Letovi &&letovi);
void RegistrirajLet(const char odrediste[], const char oznaka_leta[], int kapija, int sat_polaska, int minute_polaska, int trajanje_leta){
pok[brLetova] = new  Let(odrediste,oznaka_leta,kapija,sat_polaska,minute_polaska,trajanje_leta);
brLetova++;
if (brLetova > maxLetova) throw domain_error("Dostignut max. broj letova");
}
void RegistrirajLet(Let *let){
pok[brLetova] = new Let(let->nazivOdredista,let->oznakaLeta,let->izlaznaKapija,let->vrijemePolijetanja,let->letUminutama,let->trajanjeLeta);
brLetova++;
if (brLetova > maxLetova) throw domain_error("Dostignut max. broj letova");
}
int DajBrojLetova() const{
return brLetova;
}

int DajBrojLetovaKojiKasne() const{
    int suma = 0;
    for(int i = 0; i<brLetova; i++){
        suma += pok[i]->trajanjeLeta;
    }
    return suma/brLetova;
}
int DajProsjecnoTrajanjeLetova() const;
Let &DajPrviLet() const;
Let &DajPosljednjiLet() const;
void IsprazniKolekciju();
void Ispisi(int sati, int minute) const{
     for(int i = 0; i < brLetova; i++){
    pok[1]->PostaviKasnjenje(50);
    }

      for(int i = 0; i < brLetova; i++){
            for(int j = 0; j < (brLetova - i - 1); j++){
                if(pok[j]->vrijemePolijetanja > pok[j+1]->vrijemePolijetanja){
                        swap(pok[j],pok[j+1]);

                }
            }
        }
    cout << endl;
    cout << setw(10) << left << "Let" << setw(20) << "Odrediste"  << setw(5) << "Polazak "<<setw(5) <<  " Dolazak" << setw(5) <<  " Kapija" <<endl;
    cout << "---------------------------------------------------" << endl;
    for(int i = 0; i < brLetova; i++){
    cout << *pok[i] << endl;
    }
}

};


int main()
{
    Let a("New York","JFK 203",7,12,30,5);
    a.PostaviKasnjenje(50);
    cout << a;
    Letovi svi(5);
    svi.RegistrirajLet("New York","JFK 327",7,12,30,5);
    svi.RegistrirajLet("Istanbul","IST 327",7,12,30,5);
    svi.Ispisi(2,3);
    return 0;
}
