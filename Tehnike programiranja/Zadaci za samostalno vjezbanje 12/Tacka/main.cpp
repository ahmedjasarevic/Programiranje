#include <iostream>
#include <math.h>


using namespace std;

class Tacka{
double x,y;
public:

Tacka(){
x = y = 0;
}

Tacka(double x, double y){
Tacka::x = x;
Tacka::y = y;
}

void Postavi(double x, double y){
Tacka::x = x;
Tacka::y = y;
}

void PostaviPolarno(double ro, double theta){
x = ro * cos(theta);
y = ro * sin(theta);
}

double DajX() const{
return x;
}

double DajY() const{
return y;
}

double DajRo() const{
return sqrt(pow(x,2) + pow(y,2));
}

double DajTheta() const{
return atan2(y,x);
}

void PostaviX(double x){
Tacka::x = x;
}

void PostaviY(double y){
Tacka::y = y;
}

void Transliraj(double delta_x, double delta_y){
x = x + delta_x;
y = y + delta_y;
}

void Rotiraj(double alpha, const Tacka &centar = Tacka()){
Tacka nova;
nova.x = x * cos(alpha) - y * sin(alpha);
nova.y = y * sin(alpha) + y * cos(alpha);
}

friend bool operator == (const Tacka &a,const Tacka &b);
friend bool operator != (const Tacka &a,const Tacka &b);
friend bool operator !(const Tacka &a);
friend double operator - (const Tacka &a,const Tacka &b);
friend ostream& operator<<(ostream& os, const Tacka& dt);

};

bool operator == (const Tacka &a,const Tacka &b){
if(a.x == b.x && a.y == b.y) return true;
return false;
}

bool operator != (const Tacka &a,const Tacka &b){
if(a.x != b.x && a.y != b.y) return true;
return false;
}

bool operator !(const Tacka &a){
if(a.x == 0 && a.y == 0) return true;
return false;
}

double operator - (const Tacka &a,const Tacka &b){
return sqrt(pow((b.x-a.x),2) + pow((b.y-a.y),2));
}

ostream& operator<<(ostream& os, const Tacka& dt){
    os <<"(" << dt.x << "," << dt.y<<")" << endl ;
    return os;
}

int main()
{
    Tacka t(2,3);
    cout << t;

    return 0;
}
