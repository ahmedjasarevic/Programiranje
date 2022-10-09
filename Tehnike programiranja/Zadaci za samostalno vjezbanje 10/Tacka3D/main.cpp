#include <iostream>
#include <math.h>

using namespace std;

class Tacka3D{
double x,y,z;
public:
Tacka3D(){
x = y = z = 0;
}
Tacka3D(double x, double y, double z){
Tacka3D::x = x;
Tacka3D::y = y;
Tacka3D::z = z;
}
void Postavi(double x, double y, double z){
Tacka3D::x = x;
Tacka3D::y = y;
Tacka3D::z = z;
}
void PostaviSferno(double rho, double phi, double theta){
x = rho * cos(phi) * sin(theta);
y = rho * sin(phi) * cos(theta);
z = rho * cos(theta);
}
double DajX() const{
return x;
}
double DajY() const{
return y;
}
double DajZ() const{
return z;
}
double DajRho() const{
return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}
double DajPhi() const{
return atan2(y,x);
}
double DajTheta() const{
return acos(y/(DajRho()));
}
void PostaviX(double x){
Tacka3D::x = x;
}
void PostaviY(double y){
Tacka3D::y = y;
}
void PostaviZ(double z){
Tacka3D::z = z;
}
bool DaLiJeKoordinatniPocetak() const{
if(x == 0 && y == 0 && z == 0)return true;
return false;
}
void Transliraj(double delta_x, double delta_y, double delta_z){
x += delta_x;
y += delta_y;
z += delta_z;
}
friend bool DaLiSuIdenticne(const Tacka3D &t1, const Tacka3D &t2){
if(t1.x == t2.x && t1.y == t2.y && t1.z == t2.z) return true;
return false;
}
friend double Rastojanje(const Tacka3D &t1, const Tacka3D &t2){
return sqrt(pow((t2.x - t1.x),2)+pow((t2.y-t1.y),2)+pow((t2.z-t2.z),2));
}

};

int main()
{
    Tacka3D a(2,3,4);
    cout << a.DajY() << endl;
    cout << a.DajPhi() << endl;
    a.PostaviY(23);
    cout << a.DajY() << endl;
    cout << a.DaLiJeKoordinatniPocetak();
    a.Transliraj(2,3,5);
    return 0;
}
