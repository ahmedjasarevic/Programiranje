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
    StudentBachelor(string i, string p,int ind) :  ApstraktniStudent(i, p,ind){}

    void IspisiPodatke(){
    cout <<"Student bachelor studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << endl;
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

class Student{
ApstraktniStudent *p_lik;
void Test() const { if(!p_lik) throw std::logic_error("Nespecificiran lik!"); }
public:
Student() : p_lik(nullptr) {}
~Student() { delete p_lik; }
Student(const ApstraktniStudent &lik) : p_lik(lik.DajKopiju()) {}
Student(const Student &lik) {
if(!lik.p_lik) p_lik = nullptr;
else p_lik = lik.p_lik->DajKopiju();
}
Student(Student &&lik) { p_lik = lik.p_lik; lik.p_lik = nullptr; }
Student &operator =(const Student &lik) {
ApstraktniStudent *p_novi = nullptr;
if(lik.p_lik != nullptr) p_novi = lik.p_lik->DajKopiju();
delete p_lik;
p_lik = p_novi;
return *this;
}


Student &operator =(Student &&lik) {
swap(p_lik, lik.p_lik);
return *this;
}
void IspisiPodatke() const { Test(); p_lik->IspisiPodatke(); }
void RegistrirajIspit(int ocjena){ Test(); p_lik->IspisiPodatke(); }
};

int main()
{
    Student s1, s2;
s1 = StudentBachelor("Dusko", "Dugousko", 1234); // "s1" je bachelor
s2 = StudentMaster("Paja", "Patak", 4312, 2015); // a "s2" master
s1.RegistrirajIspit(6); s1.RegistrirajIspit(9);
s2.RegistrirajIspit(8);
s1.IspisiPodatke(); s2.IspisiPodatke();
s1 = s2; // sad je i "s1" master
s1.IspisiPodatke();
    return 0;
}
