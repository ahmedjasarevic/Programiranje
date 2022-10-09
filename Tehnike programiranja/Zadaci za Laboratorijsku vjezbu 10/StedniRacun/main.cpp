#include <iostream>

using namespace std;

class StedniRacun {
double stanjeRacuna;
public:
        StedniRacun(){ stanjeRacuna =  0;}
    StedniRacun(double x){
        if(x < 0) throw logic_error("Nedozvoljeno pocetno stanje");
        stanjeRacuna = x;
    }
    double Ulozi (double x){
        return         stanjeRacuna += x;;
    }
     double Podigni (double x){
         if(x > stanjeRacuna) throw logic_error("Transakcija odbijena");
        return         stanjeRacuna -= x;;
    }
    double DajStanje(){
    return stanjeRacuna;
    }
    double ObracunajKamatu (double x){
    if(x < 0) throw logic_error("Nedozvoljeno kamatna stopa");
    return     stanjeRacuna *= x;
    }
};

int main()
{
    StedniRacun a(3);
   a.Ulozi(5);
  cout << a.DajStanje() << endl;
   a.Podigni(3);
    cout << a.DajStanje() << endl;
    a.ObracunajKamatu(3);
       cout << a.DajStanje() << endl;
    return 0;
}
