#include <iostream>

using namespace std;

class Kugla{
double x,y,z,r;
public:
explicit Kugla(double r = 0){ Kugla::r = 0;}
Kugla(double x, double y, double z, double r = 0){
Kugla::x = x;
Kugla::y = y;
Kugla::z = z;
Kugla::r = r;
}
explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
double DajX() const;
double DajY() const;
double DajZ() const;
std::tuple<double, double, double> DajCentar() const;
double DajPoluprecnik() const;
double DajPovrsinu() const;
double DajZapreminu() const;
Kugla &PostaviX(double x);
Kugla &PostaviY(double y);
Kugla &PostaviZ(double z);
Kugla &PostaviCentar(double x, double y, double z);
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
Kugla &PostaviPoluprecnik(double r);
void Ispisi() const;
void Transliraj(double delta_x, double delta_y, double delta_z);
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
bool DaLiSadrzi(const Kugla &k) const;
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
