#include <iostream>

using namespace std;

class ApstraktniStudent{
string ime,prezime;
int indeks;
int brPolozenih;
double prosjek;
public:
    ApstraktniStudent(string i, string p,int ind){
    ime = i;
    prezime = p;
    indeks = ind;
    brPolozenih = 0;
    prosjek = 5;
    }

    string DajIme(){
    return ime;
    }

    string DajPrezime(){
    return prezime;
    }

    int DajBrojIndeksa(){
    return indeks;
    }

    int DajBrojPolozenih(){
    return brPolozenih;
    }

    double DajProsjek(){
    return prosjek;
    }

    void RegistrirajIspit(int ocjena){
        if(ocjena < 5 || ocjena < 0 || ocjena > 10) throw domain_error("Neisrpavna ocjena");
        if(ocjena > 5)  {
            brPolozenih += 1;
            prosjek += (ocjena / brPolozenih);
        }
    }

    void PonistiOcjene(){
    brPolozenih = prosjek = 0;
    }

    virtual void IspisiPodatke() = 0;
    virtual ApstraktniStudent *DajKopiju() const = 0;

};

class StudentBachelor : public ApstraktniStudent{
    public:
    void IspisiPodatke(){
    cout <<"Student bachelor studij a" << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << endl;
    cout << ", ima prosjek " <<DajProsjek() <<endl;
    }
    ApstraktniStudent *DajKopiju() const override {
    return new StudentBachelor(*this);
    }
};

class StudentMaster : public ApstraktniStudent{
int krajPrvogstepena;
public:
     StudentMaster(string i, string p,int ind,int kraj) :  ApstraktniStudent(i, p,ind){
    krajPrvogstepena = kraj;
    }
    ApstraktniStudent *DajKopiju() const override {
    return new StudentMaster(*this);
    }

    void IspisiPodatke(){
    cout <<"Student master studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << endl;
    cout << "zavrsio bachelor studij godine " <<krajPrvogstepena << " , ima prosjek " <<DajProsjek() << endl;
    }

};

int main()
{
    string ime,prezime;
    cin >> ime >> prezime;
   StudentBachelor a(ime,prezime,55);
   a.IspisiPodatke();
    return 0;
}
