#include <iostream>
#include <math.h>

using namespace std;

class Vektor3d {
double niz[3];
public:
void PostaviX(double x)  {
Vektor3d::niz[1] = x;
}
void PostaviY(double y)  {
Vektor3d::niz[2] = y;
}
void PostaviZ(double z)  {
Vektor3d::niz[3] = z;
}
void Ocitaj(double &x, double &y, double &z) const {
x = Vektor3d::niz[1]; y = Vektor3d::niz[2]; z = Vektor3d::niz[3];
}
void IspisiX() const {
std::cout << "{" << niz[1] <<"}";
}
void IspisiY() const {
std::cout << "{" << niz[2] <<"}";
}
void IspisiZ() const {
std::cout << "{" << niz[3] <<"}";
}
double DajX() const { return niz[1]; }
double DajY() const { return niz[2]; }
double DajZ() const { return niz[3]; }
double DajDuzinu() const { return std::sqrt(niz[1] * niz[1] + niz[2] * niz[2] + niz[3]* niz[3]); }
Vektor3d &PomnoziSaSkalarom(double s) {
niz[1] *= s; niz[2] *= s; niz[3] *= s;
return *this;
}
Vektor3d &SaberiSa(const Vektor3d &v) {
niz[1] += v.niz[1]; niz[2]+= v.niz[2]; niz[3] += v.niz[3];
return *this;
}

friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2);
};


int main()
{
    int x,y,z;

    Vektor3d v1;
v1.PostaviX(3);
v1.PostaviY(10);
v1.PostaviZ(4);
v1.IspisiX(); v1.IspisiY(); v1.IspisiZ();
cout << v1.DajDuzinu();

    return 0;
}
