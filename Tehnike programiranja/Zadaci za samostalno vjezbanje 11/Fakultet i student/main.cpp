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
strncpy(nazivOdredista, odrediste, sizeof(odrediste));
strncpy(oznakaLeta, oznaka_leta, sizeof(oznaka_leta));
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
void Ispisi() const{
    if(DaLiKasni() == false){
        cout << setw(10) << left << oznakaLeta << setw(20) << nazivOdredista << right << vrijemePolijetanja <<":"  << fixed << letUminutama << " " << DajOcekivanoVrijemeSlijetanja().first << ":" << DajOcekivanoVrijemeSlijetanja().second << " " <<izlaznaKapija;
    }
    else{
       cout << setw(10) << left << oznakaLeta << setw(20) << nazivOdredista << kasnjenjeSati << " " <<kasnjenjeUminutama << "(Planirano  "<< vrijemePolijetanja <<":"  << fixed << letUminutama << ", Kasni  " <<brKasnjenja << "min)" <<endl ;
    }
}
friend class Letovi;
};

class Letovi{
Let** pok;
int brLetova = 0;
int maxLetova;
int kasnjenje = 0;
public:
explicit Letovi(int max_broj_letova){
pok = new Let*[max_broj_letova];
maxLetova = max_broj_letova;
}
Letovi(std::initializer_list<Let> lista_letova){
for(auto a : lista_letova){
    pok[brLetova] = new  Let(a.nazivOdredista,a.oznakaLeta,a.izlaznaKapija,a.vrijemePolijetanja,a.letUminutama ,a.trajanjeLeta);
    brLetova++;
}
}
~Letovi(){
for (int i = 0; i != brLetova; ++i)
        {
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
void Ispisi(int sati, int minute) const;

};

int main()
{
    Letovi a({{"Ahmed","saddas",7,12,30,4},{"Ahmed","jasar",7,11,20,2}});
cout<< a.DajBrojLetova();

    return 0;
}
