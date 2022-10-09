#include <iostream>
#include <math.h>

using namespace std;

class Tacka3D{
double rho,phi,theta;
public:
Tacka3D(){
rho = phi = theta;
}
Tacka3D(double x, double y, double z){
rho = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
phi = atan2(y,x);
theta = acos(y/(DajRho()));
}
void Postavi(double x, double y, double z){
rho = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
phi = atan2(y,x);
theta = acos(y/(DajRho()));
}
void PostaviSferno(double rho, double phi, double theta){
Tacka3D::rho = rho;
Tacka3D::phi = phi;
Tacka3D::theta = theta;
}
double DajX() const{
return rho * cos(phi) * sin(theta);
}
double DajY() const{
return rho * sin(phi) * cos(theta);
}
double DajZ() const{
return rho * cos(theta);
}
double DajRho() const{
return rho;
}
double DajPhi() const{
return phi;
}
double DajTheta() const{
return theta;
}
void PostaviX(double x){
phi =DajX();
}
void PostaviY(double y){
rho = DajY();
}
void PostaviZ(double z){
theta = DajZ();
}
bool DaLiJeKoordinatniPocetak() const{
if(DajX() == 0 && DajY() == 0 && DajZ() == 0)return true;
return false;
}
void Transliraj(double delta_x, double delta_y, double delta_z){
delta_x += DajX();
delta_y += DajY();
delta_z += DajZ();
}
friend bool DaLiSuIdenticne(const Tacka3D &t1, const Tacka3D &t2){
if(t1.DajX() == t2.DajX() && t1.DajY() == t2.DajY() && t1.DajZ() == t2.DajZ()) return true;
return false;
}
friend double Rastojanje(const Tacka3D &t1, const Tacka3D &t2){
return sqrt(pow((t2.DajX() - t1.DajX()),2)+pow((t2.DajY()-t1.DajY()),2)+pow((t2.DajZ()-t2.DajZ()),2));
}


};

int main()
{
    Tacka3D a(2,3,4);
   cout << a.DajX() << endl;
   a.PostaviX(5);
   cout << a.DajX();

    return 0;
}
