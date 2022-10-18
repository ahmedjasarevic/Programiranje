#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class ApstraktniStudent
{
    string ime,prezime;
    int indeks;
    int brPolozenih;
    double prosjek;
public:
    ApstraktniStudent(string i, string p,int ind)
    {
        ime = i;
        prezime = p;
        indeks = ind;
        brPolozenih = 0;
        prosjek = 5;
    }

    string DajIme()
    {
        return ime;
    }

    string DajPrezime()
    {
        return prezime;
    }

    int DajBrojIndeksa()
    {
        return indeks;
    }

    int DajBrojPolozenih()
    {
        return brPolozenih;
    }

    double DajProsjek()
    {
        return prosjek;
    }

    void RegistrirajIspit(int ocjena)
    {
        if(ocjena < 5 || ocjena < 0 || ocjena > 10) throw domain_error("Neisrpavna ocjena");
        if(ocjena > 5)
        {
            brPolozenih += 1;
            prosjek += (ocjena / brPolozenih);
        }
    }

    void PonistiOcjene()
    {
        brPolozenih = prosjek = 0;
    }

    virtual void IspisiPodatke() = 0;
    virtual ApstraktniStudent *DajKopiju() const = 0;

};

class StudentBachelor : public ApstraktniStudent
{
public:

    StudentBachelor(string i, string p,int ind) :  ApstraktniStudent(i, p,ind) {}

    void IspisiPodatke()
    {
        cout <<"Student bachelor studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << endl;
        cout << ", ima prosjek " <<DajProsjek() <<endl;
    }

    ApstraktniStudent *DajKopiju() const override
    {
        return new StudentBachelor(*this);
    }
};

class StudentMaster : public ApstraktniStudent
{
    int krajPrvogstepena;
public:
    StudentMaster(string i, string p,int ind,int kraj) :  ApstraktniStudent(i, p,ind)
    {
        krajPrvogstepena = kraj;
    }
    ApstraktniStudent *DajKopiju() const override
    {
        return new StudentMaster(*this);
    }

    void IspisiPodatke()
    {
        cout <<"Student master studija " << DajIme() << " " << DajPrezime() << ", sa brojem indeksa " << DajBrojIndeksa() << endl;
        cout << "zavrsio bachelor studij godine " <<krajPrvogstepena << " , ima prosjek " <<DajProsjek() << endl;
    }

};

class Fakultet : public ApstraktniStudent
{
    ApstraktniStudent **pok;
    vector<ApstraktniStudent*> vec;
    int brStudenata = 0;
    int maxbrStudenata;
public:
    ~Fakultet()
    {
        delete [] pok;
    }
    void UpisStudenta(int ind,string ime,string prezime)
    {
        pok[brStudenata] = new StudentBachelor(ime,prezime,ind);
        brStudenata++;
        for(int i = 0; i<brStudenata; i++)
        {
            if(pok[i]->DajBrojIndeksa() == ind)
            {
                throw domain_error("Student sa zadanim brojem idneksa vec postoji");
            }
        }
    }

    void UpisStudenta(int ind,string ime,string prezime,int kraj)
    {
        pok[brStudenata] = new StudentMaster(ime,prezime,ind,kraj);
        brStudenata++;
    }

    void ObrisiStudenta(int indeks)
    {
        bool flag = false;
        for(int i = 0; i<brStudenata; i++)
        {
            if(pok[i]->DajBrojIndeksa() == indeks)
            {
                flag = true;
                delete pok[i];
            }
        }

        if(flag == false) throw logic_error("Student sa zadanim idneksom  ne postoji");
    }

    ApstraktniStudent& operator[](const int& indeks)
    {
        for(int i = 0; i<brStudenata; i++)
        {
            if(pok[i]->DajBrojIndeksa() == indeks)
            {
                return *pok[i];
            }
        }
    }

    ApstraktniStudent& operator[](int indeks)
    {
        for(int i = 0; i<brStudenata; i++)
        {
            if(pok[i]->DajBrojIndeksa() == indeks)
            {
                return *pok[i];
            }
        }
    }

    void IspisiSveStudente() {
          for(int i = 0; i<brStudenata; i++)
        {
            IspisiPodatke();
        }
    }



};


int main()
{


    return 0;
}
