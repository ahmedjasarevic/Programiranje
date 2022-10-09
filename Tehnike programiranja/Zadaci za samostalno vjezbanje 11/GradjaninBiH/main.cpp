#include <iostream>
#include <vector>


using namespace std;

    enum Pol {Musko, Zensko};

class GradjaninBiH{
string imeiPrezime;
long long int JMBG = 0;
vector<long long int> ukupniJMBG;
Pol mz;
GradjaninBiH* pok;
static int br;
public:
    GradjaninBiH(string imePrezime,long long int jmbg){
        long long int formula;
        vector<long long int> cifre;
        int cifra;
        long long int pomocna = jmbg;
    while(pomocna > 0){
        cifra = pomocna % 10;
        cifre.push_back(cifra);
        pomocna /= 10;
    }
    formula = 11 - (7*(cifre[1]+cifre[7])+6*(cifre[2]+cifre[8])+5*(cifre[3]+cifre[9])+4*(cifre[4]+cifre[10])+3*(cifre[5]+cifre[11])+2*(cifre[6]+cifre[12])) % 11;
    if(formula == 10) {
            br++;
        JMBG = jmbg;
        pok = this;
        }
    if(formula == 11) JMBG = 0;
      ukupniJMBG.push_back(JMBG);
        if(pok->DajJMBG() == jmbg && br != 1) throw domain_error("duplikat");
    }

    GradjaninBiH(int dan,int mjesec,int god,int sifra,Pol spol){
    if(dan < 0 || dan > 31 || mjesec < 0 || mjesec > 12 || god < 0 || god > 2022 || sifra < 0 || sifra > 99 ) throw logic_error("Neispravni podaci");
    mz = spol;
    long long int formula;
    int cifra;
     vector<int> danCifre;
    while(dan > 0){
        cifra = dan % 10;
        danCifre.push_back(cifra);
        dan /= 10;
    }
    vector<int> godineCifre;
    while(god > 0){
        cifra = god % 10;
        godineCifre.push_back(cifra);
        god /= 10;
    }
    vector<int> mjesecCifre;
    while(mjesec > 0){
        cifra = mjesec % 10;
        mjesecCifre.push_back(cifra);
        mjesec /= 10;
    }
    vector<int> regijaCifre;
    while(sifra > 0){
        cifra = sifra % 10;
        regijaCifre.push_back(cifra);
        sifra /= 10;
    }
    int kod = 0;
    if(spol == Pol::Musko){
           kod = 1;
    }
    else{
           kod = 500;
    }
    vector<int> kodCifre;
    while(kod > 0){
         cifra = kod % 10;
        kodCifre.push_back(cifra);
        kod /= 10;
    }
    formula = 11 -(7*(danCifre[1]+godineCifre[0])+6*(danCifre[0]+godineCifre[1])+5*(mjesecCifre[1]+regijaCifre[0])+4*(mjesecCifre[0]+kodCifre[2])+3*(godineCifre[2]+kodCifre[1])+2*(godineCifre[1]+kodCifre[0])) % 11;
    kod++;
    }

    string DajImeIPrezime(){
    return imeiPrezime;
    }

    long long int DajJMBG(){
    return JMBG;
    }

     int DajDanRodjenja(){
return JMBG/100000000000;
    }

    int DajMjesecRodjenja(){
      int cifra,mjesec;
      vector<int> mj;
      int pomocna ;
      pomocna = JMBG/1000000000;
      cifra = pomocna % 10;
      mj.push_back(cifra);
     pomocna /= 10;
     cifra = pomocna % 10;
     mj.push_back(cifra);
     int result = 0;
     for (int i = mj.size() - 1; i>=0; i--){
            result = result * 10 + mj[i];
     }
    return result;
    }

    int DajGodinuRodjenja(){
    int cifra,godina;
      vector<int> g;
      int  pomocna;
        pomocna = JMBG/1000000;
           cifra = pomocna % 10;
      g.push_back(cifra);
     pomocna /= 10;
     cifra = pomocna % 10;
     g.push_back(cifra);
    pomocna /= 10;
    cifra = pomocna % 10;
     g.push_back(cifra);
     int result = 0;
     for (int i = g.size() - 1; i>=0; i--){
            result = result * 10 + g[i];
     }
     if(result < 1000) g.push_back(1);
     else g.push_back(2);
     int pomocniRezultat = 0;
      for (int i = g.size() - 1; i>=0; i--){
            pomocniRezultat = pomocniRezultat * 10 + g[i];
     }
    return pomocniRezultat;
    }

    int DajSifruRegije(){
   long long int pomocna = 0;
   pomocna = JMBG / 10;
   vector<int> sifraReg;
   int cifra = 0;
   cifra = pomocna % 10;
   sifraReg.push_back(cifra);
    pomocna /= 10;
    cifra = pomocna % 10;
   sifraReg.push_back(cifra);
     pomocna /= 10;
    cifra = pomocna % 10;
   sifraReg.push_back(cifra);
   int result = 0;
     for (int i = sifraReg.size() - 1; i>=0; i--){
            result = result * 10 + sifraReg[i];
     }
    return result;
    }

    void DajPol(){
    if(mz == Pol::Musko) cout << "Musko";
    else cout << "Zensko";
    }

    void PromijeniImeiPrezime(string novo){
    imeiPrezime = novo;
    }


};
int GradjaninBiH::br = 0;


int main()
{
GradjaninBiH g1("Rambo Sulejmanovic", 1305956174235);
GradjaninBiH g2("Zan Klod Sejdic", 1305956174235);
Pol a;
GradjaninBiH g3(26,9,2004,22,a);
cout << g1.DajDanRodjenja() << endl;
cout << g1.DajMjesecRodjenja() << endl;
cout << g1.DajGodinuRodjenja() << endl;
cout << g1.DajSifruRegije() << endl;
g1.DajPol();
    return 0;
}
