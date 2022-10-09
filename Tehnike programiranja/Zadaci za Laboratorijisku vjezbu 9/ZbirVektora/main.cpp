#include <iostream>
#include <math.h>

using namespace std;

class Vektor3d {
double x, y, z;
public:
void PostaviX(double x)  {
Vektor3d::x = x;
}
void PostaviY(double y)  {
Vektor3d::y = y;
}
void PostaviZ(double z)  {
Vektor3d::z = z;
}
void Ocitaj(double &x, double &y, double &z) const {
x = Vektor3d::x; y = Vektor3d::y; z = Vektor3d::z;
}
void IspisiX() const {
std::cout << "{" << x <<"}";
}
void IspisiY() const {
std::cout << "{" << y <<"}";
}
void IspisiZ() const {
std::cout << "{" << z <<"}";
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
    int x,y,z;

    Vektor3d v1;
v1.PostaviX(3);
v1.PostaviY(10);
v1.PostaviZ(4);
v1.IspisiX(); v1.IspisiY(); v1.IspisiZ();
cout << v1.DajDuzinu();

    return 0;
}
