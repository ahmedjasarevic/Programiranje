#include <iostream>

using namespace std;

class Zaposlenik{
int brZaposlenika;
int maxBr;
int topliObrok;
int sedPlata;
int minSatnica;
int evidencijaSati;
int evidencijaMinute;
int ukupnaEvidencija;
bool dolazak;
int prekovremeniSati,prekovremenaPlata = 0;
Zaposlenik** pok;
string imeiPrezime;
public:
    Zaposlenik(int maxb,int topli,int minsat){
        pok = new Zaposlenik*[maxb];
        maxBr = maxb;
        topliObrok = topli;
        minSatnica = minsat;
        brZaposlenika = 0;
    }
    Zaposlenik(int pB,string imeprezime,int p ,int brsati){
    brZaposlenika = pB;
    imeiPrezime = imeprezime;
    sedPlata = p;
    minSatnica = brsati;
    }
    ~Zaposlenik(){
        delete [] pok;
    }

    Zaposlenik (const Zaposlenik &a){
    maxBr = a.maxBr;
    topliObrok = a.topliObrok;
    minSatnica = a.minSatnica;
    }

    Zaposlenik& operator=(const Zaposlenik& a){
    maxBr = a.maxBr;
    topliObrok = a.topliObrok;
    minSatnica = a.minSatnica;
    }

    void RegistrujZaposlenika(int pB,string imeprezime,int p,int brsati){
    pok[brZaposlenika] = new  Zaposlenik(pB,imeprezime,p,brsati);
    brZaposlenika++;
    }

    void EvindacijaDolaskaZaposlenika (int pB,int sati,int minute){
        if(sati < 8 || sati > 16) throw domain_error("Greska");
        for(int i = 0; i<brZaposlenika; i++){
            if(pok[i]->brZaposlenika == pB) {
                    if(pok[i]-> dolazak == true) throw domain_error("Vec evidentiran dolazak");
                pok[i]->dolazak = true;
                pok[i]->evidencijaSati = sati;
                break;
            }
            throw domain_error("Nema zaposlenika sa platnim brojem");
        }
    }

      void EvindacijaOdlaskaZaposlenika (int pB,int sati,int minute){
          int ukupniSati = 0;
        if(sati < 8 || sati > 20) throw domain_error("Greska");
        for(int i = 0; i<brZaposlenika; i++){
            if(pok[i]->brZaposlenika == pB) {
                ukupniSati = sati - pok[i]->evidencijaSati;
                pok[i]->ukupnaEvidencija += ukupniSati;
                pok[i]->dolazak = false;
                break;
            }
             throw domain_error("Nema zaposlenika sa platnim brojem");
        }
    }

    void IspisZaposlenika(int pB){
        for(int i = 0; i<brZaposlenika; i++){
                if(pok[i]->brZaposlenika == pB) {
                    if(pok[i]->ukupnaEvidencija > pok[i]->minSatnica){
                        pok[i]->prekovremeniSati =pok[i]->ukupnaEvidencija - pok[i]->minSatnica;
                        pok[i]->prekovremenaPlata = (pok[i]->prekovremeniSati * 1.5)+pok[i]->sedPlata;
                        cout << pok[i]->imeiPrezime << " " << pok[i]->brZaposlenika << " " << pok[i]->ukupnaEvidencija <<  " " << pok[i]->prekovremeniSati << " " << pok[i]->sedPlata <<  " " << pok[i]->prekovremenaPlata << " " << topliObrok << endl;
                    }
                    if(pok[i]->ukupnaEvidencija == pok[i]->minSatnica){
                        pok[i]->prekovremeniSati = 0;
                        cout << pok[i]->imeiPrezime << " " << pok[i]->brZaposlenika << " " << pok[i]->ukupnaEvidencija <<  " " << pok[i]->prekovremeniSati << " " << pok[i]->sedPlata << " " << topliObrok << endl;
                    }
                }
         }
    }

    void Ispis(){
        for(int i = 0; i<brZaposlenika; i++){
            cout << pok[i]->imeiPrezime << " " << pok[i]->brZaposlenika << " " << pok[i]->ukupnaEvidencija <<  " " << pok[i]->prekovremeniSati << " " << pok[i]->sedPlata <<  " " << pok[i]->prekovremenaPlata << " " << topliObrok << endl;
         }
    }

    void Restart(){
     for(int i = 0; i<brZaposlenika; i++){
         pok[i]->ukupnaEvidencija = 0;
         pok[i]->prekovremeniSati = 0;
        pok[i]->prekovremenaPlata = 0;
     }
    }

};

class Fakultet{


};


int main()
{
   Zaposlenik a(4,3,2);
   a.RegistrujZaposlenika(321,"Jasarevic Ahmed",600,10);
a.EvindacijaDolaskaZaposlenika(321,9,3);
a.EvindacijaOdlaskaZaposlenika(321,19,3);
a.EvindacijaDolaskaZaposlenika(321,9,3);
a.EvindacijaOdlaskaZaposlenika(321,19,3);

a.IspisZaposlenika(321);
a.Ispis();

    return 0;
}
