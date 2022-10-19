

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
    ApstraktniStudent(){}
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
    vector<ApstraktniStudent*> vec;
    int brStudenata = 0;
public:
    virtual ~Fakultet()
    {
        for (int i = 0; i < vec.size(); i++)
        {
            delete vec[i];
        }
    }
    void UpisStudenta(int ind,string ime,string prezime)
    {
            for(int i = 0; i<brStudenata; i++)
        {
            if(vec[i]->DajBrojIndeksa() == ind && brStudenata != 1)
            {
                cout << vec[2]->DajBrojIndeksa() << " " << ind << endl;
                throw domain_error("Student sa zadanim brojem idneksa vec postoji");
            }
        }

        vec.push_back( new StudentBachelor(ime,prezime,ind));
        brStudenata++;
    }

    void UpisStudenta(int ind,string ime,string prezime,int kraj)
    {
        vec.push_back( new StudentMaster(ime,prezime,ind,kraj));
        brStudenata++;
    }

    void ObrisiStudenta(int indeks)
    {
        bool flag = false;
        for(int i = 0; i<brStudenata; i++)
        {
            if(vec[i]->DajBrojIndeksa() == indeks)
            {
                flag = true;
                delete vec[i];
            }
        }

        if(flag == false) throw logic_error("Student sa zadanim idneksom  ne postoji");
    }

    ApstraktniStudent& operator[](const int& indeks)
    {
        for(int i = 0; i<brStudenata; i++)
        {
            if(vec[i]->DajBrojIndeksa() == indeks)
            {
                return *vec[i];
            }
        }
    }

     ApstraktniStudent& operator[](int indeks)
    {
        for(int i = 0; i<brStudenata; i++)
        {
            if(vec[i]->DajBrojIndeksa() == indeks)
            {
                return *vec[i];
            }
        }
    }

    void IspisiSveStudente()
    {
        for(int i = 0; i<brStudenata; i++)
        {
           IspisiPodatke();
           break;
        }
    }

     void IspisiPodatke() {
         for(int i = 0; i<brStudenata; i++)
        {
           vec[i]->IspisiPodatke();

        }
     }
      ApstraktniStudent *DajKopiju() const override
    {
        return new Fakultet(*this);
    }

};


int main()
{
   Fakultet f;
   string ime = "ahmed";
   string prezime = "jasarevic";
   f.UpisStudenta(55,ime,prezime);
   f.UpisStudenta(35,ime,prezime,3);
   f.UpisStudenta(13,ime,prezime);
   f.IspisiSveStudente();
    return 0;

}
