#include <iostream>
#include <tuple>
#include <math.h>
#include <vector>
#include <memory>
#include <limits>
#include <algorithm>

using namespace std;

class Kugla
{
    double x,y,z,r;
public:
    explicit Kugla(double r = 0)
    {
        Kugla::r = 0;
    }
    Kugla(double x, double y, double z, double r = 0)
    {
        try
        {
            if(x < 0 || y < 0 || z < 0 || r < 0) throw domain_error("Negativan unos");
        }
        catch(...)
        {
            while(x < 0 || y < 0 || z < 0 || r < 0)
            {
                cout <<"Ponovite unos: " ;
                cin >> x >> y >>z >>r;
            }
        }
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        Kugla::r = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0)
    {
        if(r < 0 ) throw domain_error("Ilegalan poluprecnik");
        x = get<0>(centar);
        y = get<1>(centar);
        z = get<2>(centar);
        Kugla::r = r;
    }
    double DajX() const
    {
        return x;
    }
    double DajY() const
    {
        return y;
    }
    double DajZ() const
    {
        return z;
    }
    std::tuple<double, double, double> DajCentar() const
    {
        std::tuple<double, double, double> centar;
        centar = make_tuple(x,y,z);
        return centar;
    }
    double DajPoluprecnik() const
    {
        return r;
    }
    double DajPovrsinu() const
    {
        return 4 * r * r *3.14;
    }
    double DajZapreminu() const
    {
        return 4 * r * r * r * 3.14 / 3;
    }
    Kugla &PostaviX(double x)
    {
        Kugla::x = x;
        return *this;
    }
    Kugla &PostaviY(double y)
    {
        Kugla::y = y;
        return *this;
    }
    Kugla &PostaviZ(double z)
    {
        Kugla::z = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z)
    {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        x = get<0>(centar);
        y = get<1>(centar);
        z = get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r)
    {
        if(r < 0 ) throw domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        return *this;
    }
    void Ispisi() const
    {
        cout << "{(" << x << "," << y << "," << z <<"),"<< r<<"}"<< endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
    {
        if(k1.x == k2.x && k1.y == k2.y && k1.z == k2.z && k1.r == k2.r) return true;
        return false;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
    {
        if(k1.r == k2.r) return true;
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
    {
        if(k1.x == k2.x && k1.y == k2.y && k1.z == k2.z) return true;
        return false;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
    {
        double sumaPoluprecnika = k1.r + k2.r;
        double k1Udaljenost = sqrt(pow(k1.x,2) + pow(k1.y,2) + pow(k1.z,2));
        double k2Udaljenost = sqrt(pow(k2.x,2) + pow(k2.y,2) + pow(k2.z,2));
        double Ukupna = k1Udaljenost - k2Udaljenost;
        if(Ukupna < sumaPoluprecnika) return false;
        return true;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
    {
        double sumaPoluprecnika = k1.r + k2.r;
        double k1Udaljenost = sqrt(pow(k1.x,2) + pow(k1.y,2) + pow(k1.z,2));
        double k2Udaljenost = sqrt(pow(k2.x,2) + pow(k2.y,2) + pow(k2.z,2));
        double Ukupna = k1Udaljenost - k2Udaljenost;
        if(Ukupna < sumaPoluprecnika) return true;
        return false;
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {}
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
    {
        double distanca = sqrt( pow( k1.x - k2.x, 2 ) + pow( k1.y - k2.y, 2 ) + pow( k1.z - k2.z, 2 ) );
        if(distanca < k1.r + k2.r) return true;
        return false;
    }
    bool DaLiSadrzi(const Kugla &k) const
    {
        if(k.r < 0 ) throw domain_error ("Ilegalan poluprecnik");
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
    {
        return sqrt( pow( k1.x - k2.x, 2 ) + pow( k1.y - k2.y, 2 ) + pow( k1.z - k2.z, 2 ) );
    }

};


int main()
{
    int n;
    double x,y,z,r;
    cout << "Unesi n : ";
    cin >> n;
    vector<shared_ptr<Kugla>> vec;
    shared_ptr<Kugla> pok[n];
    for(int i = 0; i < n; i++)
    {
        cout << "Unesite " << i + 1 << ". kuglu: ";
        cin >> x >>y >> z >>r;
        Kugla a(x,y,z,r);
        pok[i] = make_shared<Kugla>(a);
        vec.push_back(pok[i]);
    }
    for(int i = 0; i < n; i++)
    {
        vec[i]->Ispisi();
    }

    return 0;
}
