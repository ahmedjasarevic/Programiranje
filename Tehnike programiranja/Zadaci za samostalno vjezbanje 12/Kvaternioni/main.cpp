#include <iostream>
#include <math.h>


using namespace std;

class Kvaternioni{
int x,y,z,t;
public:
    Kvaternioni(int prva){
    x = prva;
    y = z = t= 0;
    }

    Kvaternioni(){
    x = y = z = t= 0;
    }

    Kvaternioni(int pr,int dr,int tr,int ct){
    x = pr;
    y = dr;
    z = tr;
    t = ct;
    }

    int vratiX(){
    return x;
    }

    int vratiY(){
    return y;
    }

     int vratiZ(){
    return z;
    }

     int vratiT(){
    return t;
    }

    double dajApsolutnuvrijednost(){
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2) + pow(t,2));
    }

    Kvaternioni dajNegaciju(){
        Kvaternioni a;
        a.x = a.x * (-1);
        a.y = a.y * (-1);
        a.z = a.z * (-1);
        a.t = a.t * (-1);
    return a;
    }

    friend Kvaternioni operator +(const Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni operator +=(Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni operator -(const Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni operator -=(Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni operator *(const Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni operator *=(Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni operator /(const Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni operator /=(Kvaternioni &a,const Kvaternioni &b);
    friend Kvaternioni &operator ++(Kvaternioni &d);
    friend Kvaternioni operator ++(Kvaternioni &d, int);
    friend Kvaternioni &operator --(Kvaternioni &d);
    friend Kvaternioni operator --(Kvaternioni &d, int);
    friend bool operator ==(const Kvaternioni &a,const Kvaternioni &b);
    friend bool operator !=(const Kvaternioni &a,const Kvaternioni &b);
    friend ostream& operator<<(ostream& os, const Kvaternioni& dt);
    friend istream& operator>> (istream& is, Kvaternioni& dt);

};

Kvaternioni operator +(const Kvaternioni &a,const Kvaternioni &b){
    Kvaternioni c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    c.t = a.t + b.t;
    return c;
}

Kvaternioni operator +=(Kvaternioni &a,const Kvaternioni &b){
    a.x = a.x + b.x;
    a.y = a.y + b.y;
    a.z = a.z + b.z;
    a.t = a.t + b.t;
    return a;
}

Kvaternioni operator -(const Kvaternioni &a,const Kvaternioni &b){
    Kvaternioni c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    c.t = a.t - b.t;
    return c;
}

Kvaternioni operator -=(Kvaternioni &a,const Kvaternioni &b){
    a.x = a.x - b.x;
    a.y = a.y - b.y;
    a.z = a.z - b.z;
    a.t = a.t - b.t;
    return a;
}

Kvaternioni operator *(const Kvaternioni &a,const Kvaternioni &b){
    Kvaternioni c;
    c.x = (a.x * b.x) - (a.y * b.y) - (a.z * b.z) - (a.t * b.t);
    c.y = (a.x * b.y) + (a.y * b.x) + (a.z * b.t) + (a.t * b.z);
    c.z = (a.x * b.z) - (a.y * b.t) + (a.z * b.x) + (a.t * b.y);
    c.t = (a.x * b.t) + (a.y * b.z) - (a.z * b.y) + (a.t * b.x);
    return c;
}

Kvaternioni operator *=(Kvaternioni &a,const Kvaternioni &b){
    a.x = a.x * b.x;
    a.y = a.y * b.y;
    a.z = a.z * b.z;
    a.t = a.t * b.t;
    return a;
}

Kvaternioni operator /(const Kvaternioni &a,const Kvaternioni &b){
    Kvaternioni c;
    c.x = ((a.x * b.x) - (a.y * b.y) - (a.z * b.z) - (a.t * b.t)) / (pow(b.x,2) + pow(b.y,2) + pow(b.z,2) + pow(b.t,2));
    c.y = ((a.x*(-1)) * b.y) + (a.y * b.x) + (a.z * b.t) + (a.t * b.z)/ (pow(b.x,2) + pow(b.y,2) + pow(b.z,2) + pow(b.t,2));
    c.z = ((a.x*(-1)) * b.z) - (a.y * b.t) + (a.z * b.x) + (a.t * b.y)/ (pow(b.x,2) + pow(b.y,2) + pow(b.z,2) + pow(b.t,2));
    c.t = ((a.x*(-1)) * b.t) + (a.y * b.z) - (a.z * b.y) + (a.t * b.x)/ (pow(b.x,2) + pow(b.y,2) + pow(b.z,2) + pow(b.t,2));
    return c;
}

Kvaternioni operator /=(Kvaternioni &a,const Kvaternioni &b){
    a.x = a.x / b.x;
    a.y = a.y / b.y;
    a.z = a.z / b.z;
    a.t = a.t / b.t;
    return a;
}

Kvaternioni &operator ++(Kvaternioni &d) {
    d.x++;
return d;
}
Kvaternioni operator ++(Kvaternioni &d, int) {
    ++d.x;
    Kvaternioni pomocni = d;
return pomocni;
}

Kvaternioni &operator --(Kvaternioni &d) {
    d.x--;
return d;
}

Kvaternioni operator --(Kvaternioni &d, int) {
    --d.x;
    Kvaternioni pomocni = d;
return pomocni;
}

bool operator ==(const Kvaternioni &a,const Kvaternioni &b){
    if(a.x == b.x && a.y == b.y && a.z == b.z && a.t == a.t) return true;
    return false;
}

bool operator != (const Kvaternioni &a,const Kvaternioni &b){
     if(a.x != b.x && a.y != b.y && a.z != b.z && a.t != a.t) return true;
    return false;
}

ostream& operator<<(ostream& os, const Kvaternioni& dt){
    os <<"(" << dt.x << "," << dt.y<< "," << dt.z << "," <<dt.t << ")" << endl ;
    return os;
}

istream& operator>> (istream& is, Kvaternioni& dt)
{
    is >> dt.x>> dt.y >> dt.z >>dt.t;
    return is;
}

int main()
{
    Kvaternioni a(2,3,4,5);
    cout << a;
    ++a;
    cout << a;
    cin >> a;
    cout << a;
    return 0;
}
