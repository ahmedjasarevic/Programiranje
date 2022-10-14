#include <iostream>

typedef std::tuple<double, double, double> Vektor3d;

void UnesiVektor(Vektor3d &v) {
std::cout << "X = "; std::cin >> v.x;
std::cout << "Y = "; std::cin >> v.y;
std::cout << "Z = "; std::cin >> v.z;
}
Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}
Vektor3d VektorskiProizvod(const Vektor3d &v1, const Vektor3d &v2) {
return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
v1.x * v2.y - v1.y * v2.x};
}
void IspisiVektor(const Vektor3d &v) {
std::cout << "{" << v.x << "," << v.y << "," << v.z << "}";
}
int main() {
Vektor3d a, b;
std::cout << "Unesi prvi vektor:\n";
UnesiVektor(a);
std::cout << "Unesi drugi vektor:\n";
UnesiVektor(b);
std::cout << "Suma ova dva vektora je: ";
IspisiVektor(ZbirVektora(a, b));
std::cout << std::endl << "Njihov vektorski prozivod je: ";
IspisiVektor(VektorskiProizvod(a, b));
return 0;
}
