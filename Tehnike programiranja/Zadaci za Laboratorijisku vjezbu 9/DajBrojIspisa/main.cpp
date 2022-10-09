#include <iostream>
#include <math.h>

using namespace std;

class Vektor3d {
double x, y, z;
	 int brojac = 0;
public:

void Postavi(double x, double y, double z) {
Vektor3d::x = x; Vektor3d::y = y; Vektor3d::z = z;
}
void Ocitaj(double &x, double &y, double &z) const {
x = Vektor3d::x; y = Vektor3d::y; z = Vektor3d::z;
}

void Ispisi()  {
std::cout << "{" << x << "," << y << "," << z << "}";
brojac++;
}
int DajBrojIspisa() {
return brojac;
}
double DajX() const { return x; }
double DajY() const { return y; }
double DajZ() const { return z; }
double DajDuzinu() const { return std::sqrt(x * x + y * y + z * z); }
Vektor3d &PomnoziSaSkalarom(double s) {
x *= s; y *= s; z *= s;
return *this;
}
Vektor3d &SaberiSa(const Vektor3d &v) {
x += v.x; y += v.y; z += v.z;
return *this;
}
friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};



int main()
{
Vektor3d v1, v2;
v1.Postavi(3, 4, 2); v2.Postavi(2, 0, 5);
v1.Ispisi(); v1.Ispisi(); v1.Ispisi(); v2.Ispisi(); v2.Ispisi();
std::cout << std::endl;
std::cout << "Objekat v1 je ispisan " << v1.DajBrojIspisa() << "puta , a objekat v2 "
<< v2.DajBrojIspisa() << " puta" << std::endl;

    return 0;
}
