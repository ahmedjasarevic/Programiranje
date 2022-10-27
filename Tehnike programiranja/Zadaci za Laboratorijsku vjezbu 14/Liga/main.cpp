#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;



class Tim
{
    friend class Liga;
    char ime_tima[20];
    int broj_odigranih,broj_pobjeda,broj_nerijesenih,broj_poraza,broj_datih,broj_primljenih,broj_poena;
public:
    Tim(const char ime[])
    {
        int len = strlen(ime);
        if(len > 20 ) throw range_error("Predugo");
        memcpy(ime_tima,ime,sizeof(ime_tima));
        broj_odigranih = broj_pobjeda = broj_nerijesenih = broj_poraza = broj_datih = broj_primljenih = broj_poena = 0;
    }
    void ObradiUtakmicu(int broj_datih, int broj_primljenih)
    {
        if(broj_datih < 0 || broj_primljenih < 0) throw range_error("Negativan broj");
        broj_odigranih += 1;
        if ( broj_datih > broj_primljenih)
        {
            broj_pobjeda += 1;
            broj_poena += 3;
        }
        if ( broj_datih == broj_primljenih)
        {
            broj_nerijesenih += 1;
            broj_poena += 1;
        }
        if ( broj_datih < broj_primljenih && broj_datih != broj_primljenih)
        {
            broj_poraza += 1;
        }
        Tim::broj_datih += broj_datih;
        Tim::broj_primljenih += broj_primljenih;
    }
    const char *DajImeTima() const
    {
        const char *pok = NULL;
        pok = ime_tima;
        return pok;
    }
    int DajBrojPoena() const
    {
        return broj_poena;
    }
    int DajGolRazliku() const
    {
        return broj_datih-broj_primljenih;
    }
    void IspisiPodatke() const
    {
        cout <<setw(20) << left << ime_tima;
        cout <<setw(4) << right << broj_odigranih;
        cout <<setw(4) << right << broj_pobjeda;
        cout <<setw(4) << right << broj_nerijesenih;
        cout <<setw(4) << right << broj_poraza;
        cout <<setw(4) << right << broj_datih;
        cout <<setw(4) << right << broj_primljenih;
        cout <<setw(4) << right << broj_poena << endl;
    }

};



class Liga
{
    friend class Tim;
    Tim **broj_timova = NULL;
    const int max_br_timova = 0;
    int timovi ;
    int brojac = 0;
public:
    explicit Liga(int velicina_lige)
    {
        broj_timova = new Tim*[velicina_lige];

    }
    Liga(std::initializer_list<Tim> lista_timova)
    {
        broj_timova = new Tim*[lista_timova.size()];
        for(auto v : lista_timova)
        {
            broj_timova[brojac] = new Tim(v);
            brojac++;
        }
    }
    ~Liga()
    {
        for(int i = 0; i<brojac; i++)
        {
            delete broj_timova[i];
        }
    }

    Liga(const Liga &l)
    {
        broj_timova = l.broj_timova;
    }
    Liga(Liga &&l)
    {
        move(l.broj_timova);
    }
    Liga &operator =(const Liga &l);
    Liga &operator =(Liga &&l);
    void DodajNoviTim(const char ime_tima[])
    {
        Tim a("test");
        broj_timova[brojac] = new Tim(ime_tima);
        brojac++;
    }
    void RegistrirajUtakmicu(const char tim1[], const char tim2[],int rezultat_1, int rezultat_2)
    {
        cout << tim1 << " " << rezultat_1 << " : " << rezultat_2 << " "<< tim2 << endl;
        int flag = 0,flag2 = 0;
        for(auto i = 0; i <brojac; i++)
        {
            if(strcmp(tim1,broj_timova[i]->ime_tima) ==  0)
            {
                flag = 1;
            }
            if(strcmp(tim2,broj_timova[i]->ime_tima) ==  0) flag2 = 1;
        }
        if(flag == 0 || flag2 == 0)
        {
            cout << "Tim nije naden" << endl;
        }
        else
        {
            for(auto i = 0; i <brojac; i++)
            {
                if(strcmp(tim1,broj_timova[i]->ime_tima) ==  0)
                {
                    broj_timova[i]->broj_odigranih += 1;

                    if(rezultat_1 > rezultat_2)
                    {
                        broj_timova[i]->broj_pobjeda += 1;
                        broj_timova[i]->broj_poena += 3;
                    }
                    if(rezultat_1 == rezultat_2)
                    {
                        broj_timova[i]->broj_nerijesenih += 1;
                        broj_timova[i]->broj_poena +=1;
                    }
                    if(rezultat_1 < rezultat_2)
                    {
                        broj_timova[i]->broj_poraza += 1;
                    }

                    broj_timova[i]->broj_primljenih += rezultat_2;
                    broj_timova[i]->broj_datih += rezultat_1;

                }
                if(strcmp(tim2,broj_timova[i]->ime_tima) ==  0)
                {
                    broj_timova[i]->broj_odigranih += 1;

                    if(rezultat_1 < rezultat_2)
                    {
                        broj_timova[i]->broj_pobjeda += 1;
                        broj_timova[i]->broj_poena += 3;
                    }
                    if(rezultat_1 == rezultat_2)
                    {
                        broj_timova[i]->broj_nerijesenih+= 1;
                        broj_timova[i]->broj_poena +=1;
                    }
                    if(rezultat_1 > rezultat_2)
                    {
                        broj_timova[i]->broj_poraza += 1;
                    }
                    broj_timova[i]->broj_primljenih += rezultat_1;
                    broj_timova[i]->broj_datih+= rezultat_2;
                }
            }
        }

    }
    void IspisiTabelu()
    {


        for(int i = 0; i < brojac; i++)
        {
            for(int j = 0; j < (brojac - i - 1); j++)
            {
                if(broj_timova[j]->broj_poena == broj_timova[j+1]->broj_poena)
                {
                    if((broj_timova[j]->broj_datih - broj_timova[j]->broj_primljenih) < (broj_timova[j+1]->broj_datih - broj_timova[j+1]->broj_primljenih))
                    {
                        swap(broj_timova[j],broj_timova[j+1]);
                    }
                }
            }
        }




        for(int i = 0; i < brojac; i++)
        {
            for(int j = 0; j < (brojac - i - 1); j++)
            {
                if(broj_timova[j]->broj_poena < broj_timova[j+1]->broj_poena)
                {
                    swap(broj_timova[j],broj_timova[j+1]);
                }
            }
        }

        for(int i = 0; i<brojac; i++)
        {
            broj_timova[i]->IspisiPodatke();

        }

    }

    void ObrisiSve()
    {
        for(int i = 0; i<brojac; i++)
        {
            delete broj_timova[i];
        }
    }

    void SacuvajStanje(string imeDatoteke)
    {
        ofstream wf(imeDatoteke, ios::out | ios::binary);
        if(wf)
        {
            wf.write(reinterpret_cast<char*>(broj_timova), sizeof(broj_timova[0]) * brojac);
        }
    }

    void AzurirajIzDatoteke(string imeDatoteke)
    {
        fstream dat(imeDatoteke);
        string line;
        string t1,t2;
        int brojac = 0;
        int brojPrvi,brojDrugi;
        char znak;
        char tim1[20];
        char tim2[20];
        if(dat.is_open())
        {
            while(getline(dat,line))
            {
                if(brojac == 0)
                {
                    if (!line.empty() && line[line.size() - 1] == '\r')
                        line.erase(line.size() - 1);
                    for(int i = 0; i <line.size()-1; i++)
                    {
                        tim1[i] = line[i];
                    }
                    brojac++;
                }
                else if(brojac == 1)
                {
                    if (!line.empty() && line[line.size() - 1] == '\r')line.erase(line.size() - 1);
                    for(int i = 0; i <line.size(); i++)
                    {
                        tim2[i] = line[i];
                    }
                    brojac++;

                }
                else if (brojac == 2)
                {
                    brojPrvi = line[0] - '0';
                    brojDrugi = line[2] - '0';
                    brojac = 0;
                    break;
                }



            }
            RegistrirajUtakmicu(tim1,tim2,brojPrvi,brojDrugi);
            IspisiTabelu();
        }
    }
};



int main()
{
    Liga b(5);
    Liga a({"Borac","Celik","Jedinstvo","Sarajevo","Zeljeznicar","Zrinjski"});
    a.IspisiTabelu();
    a.RegistrirajUtakmicu("Sarajevo","Zeljeznicar",1,0);
    a.IspisiTabelu();
    a.AzurirajIzDatoteke("ligatxt.txt");

    return 0;
}
