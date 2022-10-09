#include <iostream>

using namespace std;

class StedniRacun
{
    double stanjeRacuna;
    static int brojac,brojac2;
public:
    StedniRacun()
    {
        stanjeRacuna =  0;
        brojac++;
    }
    StedniRacun(double x)
    {
        if(x < 0) throw logic_error("Nedozvoljeno pocetno stanje");
        stanjeRacuna = x;
        brojac++;
    }
    ~StedniRacun()
    {
        brojac2 = brojac - brojac2;
    }
    double Ulozi (double x)
    {
        return         stanjeRacuna += x;;
    }
    double Podigni (double x)
    {
        if(x > stanjeRacuna) throw logic_error("Transakcija odbijena");
        return         stanjeRacuna -= x;;
    }
    double DajStanje()
    {
        return stanjeRacuna;
    }
    double ObracunajKamatu (double x)
    {
        if(x < 0) throw logic_error("Nedozvoljeno kamatna stopa");
        return     stanjeRacuna *= x;
    }
    static int DajBrojAktivnih()
    {
        return brojac2;
    }
    static int DajBrojKreiranih()
    {
        return brojac;
    }
};
int StedniRacun::brojac =0 ;
int StedniRacun::brojac2 =1 ;

int main()
{
    StedniRacun s1, s2(100);
    {
        StedniRacun s3(50);
    }
    std::cout << StedniRacun::DajBrojKreiranih() << " " << StedniRacun::DajBrojAktivnih();
    return 0;
}
