#include <iostream>

using namespace std;

class Polazak
{
    string naziv;
    int brVoza;
    int brPerona;
    bool DaLiJeBrziVoz;
    int vrijemePolaska;
    int voznjaUminutama;
    int kasnjenje;
public:
    Polazak(std::string odrediste, int broj_voza, int broj_perona, bool brzi_voz,int sat_polaska, int minute_polaska, int trajanje_voznje);
    void PostaviKasnjenje(int kasnjenje);
    bool DaLiKasni() const;
    int DajTrajanjeVoznje() const;
    std::pair<int, int> DajcekivanoVrijemePolaska() const;
    std::pair<int, int> DajOcekivanoVrijemeDolaska() const;
    void Ispisi() const;

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
