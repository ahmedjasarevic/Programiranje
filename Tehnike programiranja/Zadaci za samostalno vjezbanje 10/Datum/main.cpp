#include <iostream>

using namespace std;
        enum Mjeseci {Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar,
Oktobar, Novembar, Decembar};
enum Dani {Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
    const char *mjes[] = {"","j","f","m","a","m","j","j","a","s","o","n","d"};
    const char *djes[] = {"","p","u","s","c","p","s"};
int days[] = { 31, 28, 31, 30, 31, 30,
               31, 31, 30, 31, 30, 31 };


std::ostream& operator << (std::ostream& os, const Mjeseci& obj)
{
   os << static_cast<std::underlying_type<Mjeseci>::type>(obj);
   return os;
}

class Datum{
    int dan,mjesec,godina;
    Mjeseci mj;
    Dani dj;
    public:
Datum(int dan, Mjeseci mjesec, int godina){
    if(mjesec < 0 && mjesec > 12) throw  logic_error("Pogresan mjesec");
Datum::dan = dan;
Datum::godina = godina;
mj = mjesec;
}
Datum(int dan, int mjesec, int godina){
Datum::dan = dan;
Datum::godina = godina;
Datum::mjesec = mjesec;
}
void Postavi(int dan, Mjeseci mjesec, int godina){
Datum::dan = dan;
Datum::godina = godina;
mj = mjesec;
}
void Postavi(int dan, int mjesec, int godina){
Datum::dan = dan;
Datum::godina = godina;
Datum::mjesec = mjesec;
}
int DajDan() const{
return dan;
}
Mjeseci DajMjesec() const{
return mj;
}
const char *DajImeMjeseca() const{
return  mjes[mj];
}
int DajBrojDanaUMjesecu() const{
    if(mj == 2){
if ((godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0)){
    return 29;
}
else {
   return 28;
}
    }
else if(mj == 1 || mj == 3 || mj == 5 || mj == 7 || mj == 8
	||mj == 10 || mj==12)
		return 31;
	else
		return 30;
}
int DajGodinu() const{
return godina;
}
bool DaLiJePrestupna() const{
if ((godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0)) return true;
return false;
}
int DajDanUGodini() {
    int daniUkupni = 0;
for(int i = 0; i<mj-1; i++){
    daniUkupni = daniUkupni + days[i];
}
if(DaLiJePrestupna()) return daniUkupni+dan+1;
    return daniUkupni+dan;
}
Dani DajDanUSedmici() const{
}
const char *DajImeDanaUSedmici() const{
return  djes[dj];
}
void IdiNaSljedeciDan(){
    dan += 1;
    if(dan == 31 ){
        if(mj == 1 || mj == 3 || mj == 5 || mj == 7 || mj == 8
	||mj == 10 || mj==12)
	mj=Mjeseci(int(mj)+1);
    }
 if(dan == 30 ){
        if(mj != 1 || mj != 3 || mj != 5 || mj != 7 || mj != 8
	||mj != 10 || mj!=12)
	mj=Mjeseci(int(mj)+1);
    }
    }
void IdiNaPrethodniDan(){
    dan -= 1;
        if(dan < 1 ){
        if(mj == 1 || mj == 3 || mj == 5 || mj == 7 || mj == 8
	||mj == 10 || mj==12)
	mj=Mjeseci(int(mj)-1);
    }
 if(dan < 1 ){
        if(mj != 1 || mj != 3 || mj != 5 || mj != 7 || mj != 8
	||mj != 10 || mj!=12)
	mj=Mjeseci(int(mj)-1);
    }
    }
void PomjeriZa(int broj_dana){
    int br = 0;
    while(broj_dana > 31){
        broj_dana -= 31;
        br++;
    }
dan += broj_dana;
mj=Mjeseci(int(mj)+br);
}
void Unesi(){
    int d,m,g;
    cin >> d >> m >> g;
Datum(d,m,g);
}
void Ispisi() const{
cout << dan << ". " <<  mj << " " << godina << ".";
}
friend int BrojDanaIzmedju(const Datum &d1, const Datum &d2);

};

int main()
{

    Datum v3(2,Mjeseci(5),2022);
    cout << v3.DajDan()<< endl;
    cout << v3.DajMjesec()<< endl;
    cout << v3.DajImeMjeseca()<< endl;
    cout << v3.DajBrojDanaUMjesecu() << endl;
    cout << v3.DaLiJePrestupna()  << endl;
    cout << v3.DajDanUGodini()<< endl;
   v3.Ispisi();
    return 0;
}
