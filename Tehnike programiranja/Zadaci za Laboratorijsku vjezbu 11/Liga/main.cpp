#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <initializer_list>
#include <algorithm>


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
    int *broj_timova;
    const int max_br_timova = 0;
    int timovi ;
    vector<Tim> listaTimova;
    Tim a( const char imena[])
    {
        listaTimova.push_back(imena);
    }
public:
    explicit Liga(int velicina_lige)
    {
        broj_timova = new int;
        *broj_timova = velicina_lige;

    }
    explicit Liga(std::initializer_list<Tim> lista_timova)
    {
        for(Tim v : lista_timova)
        {
            listaTimova.push_back(v);
        }
    }
    ~Liga()
    {
        delete broj_timova;
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
        listaTimova.push_back(ime_tima);
        broj_timova += 1;
    }
    void RegistrirajUtakmicu(const char tim1[], const char tim2[],int rezultat_1, int rezultat_2)
    {
        cout << tim1 << " " << rezultat_1 << " : " << rezultat_2 << " "<< tim2 << endl;
        int flag = 0,flag2 = 0;
        for(auto i = 0; i <listaTimova.size(); i++)
        {
            if(strcmp(tim1,listaTimova[i].ime_tima) ==  0)
            {
                flag = 1;
            }
            if(strcmp(tim2,listaTimova[i].ime_tima) ==  0) flag2 = 1;
        }
        if(flag == 0 || flag2 == 0)
        {
            cout << "Tim nije naden" << endl;
        }
        else
        {
            for(auto i = 0; i <listaTimova.size(); i++)
            {
                if(strcmp(tim1,listaTimova[i].ime_tima) ==  0)
                {
                    listaTimova[i].broj_odigranih += 1;

                    if(rezultat_1 > rezultat_2)
                    {
                        listaTimova[i].broj_pobjeda += 1;
                        listaTimova[i].broj_poena += 3;
                    }
                    if(rezultat_1 == rezultat_2)
                    {
                        listaTimova[i].broj_nerijesenih += 1;
                        listaTimova[i].broj_poena +=1;
                    }
                    if(rezultat_1 < rezultat_2)
                    {
                        listaTimova[i].broj_poraza += 1;
                    }

                    listaTimova[i].broj_primljenih += rezultat_2;
                    listaTimova[i].broj_datih += rezultat_1;

                }
                if(strcmp(tim2,listaTimova[i].ime_tima) ==  0)
                {
                    listaTimova[i].broj_odigranih += 1;

                    if(rezultat_1 < rezultat_2)
                    {
                        listaTimova[i].broj_pobjeda += 1;
                        listaTimova[i].broj_poena += 3;
                    }
                    if(rezultat_1 == rezultat_2)
                    {
                        listaTimova[i].broj_nerijesenih+= 1;
                        listaTimova[i].broj_poena +=1;
                    }
                    if(rezultat_1 > rezultat_2)
                    {
                        listaTimova[i].broj_poraza += 1;
                    }
                    listaTimova[i].broj_primljenih += rezultat_1;
                    listaTimova[i].broj_datih+= rezultat_2;
                }
            }
        }

    }
    void IspisiTabelu()
    {

        sort( listaTimova.begin( ), listaTimova.end( ), [ ]( const Tim& lhs, const Tim& rhs )
        {
            if( lhs.broj_poena == rhs.broj_poena) return (lhs.broj_datih - lhs.broj_primljenih) > (rhs.broj_datih - rhs.broj_primljenih);
        });
        sort( listaTimova.begin( ), listaTimova.end( ), [ ]( const Tim& lhs, const Tim& rhs )
        {
            return lhs.broj_poena > rhs.broj_poena;
        });
        cout << endl;
        for(auto v : listaTimova)
        {
            v.IspisiPodatke() ;
        }
    }
};



int main()
{
    Liga b(5);
    Liga a({"Borac","Celik","Jedinstvo","Sarajevo","Zeljeznicar","Zrinjski"});
    a.IspisiTabelu();
    char tim1[20],tim2[20];
    int rez1,rez2;
    while(1)
    {
        cout << "Unesite ime prvog tima (ENTER za kraj): ";
        cin >> tim1;
        cout << "Unesite ime drugog tima: ";
        cin >> tim2;
        cout << "Unesite broj postignutih golova za oba tima: ";
        cin >> rez1 >> rez2 ;
        a.RegistrirajUtakmicu(tim1,tim2,rez1,rez2);
        a.IspisiTabelu();
    }
    return 0;
}

