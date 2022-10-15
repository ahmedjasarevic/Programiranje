#include <iostream>
#include <math.h>


using namespace std;

class Dualnibrojevi{
int vidljivi,skriveni;
public:
    Dualnibrojevi(int v,int s){
    vidljivi = v;
    skriveni = s;
    }

    Dualnibrojevi(int r){
    vidljivi = r;
    skriveni = 0;
    }

     Dualnibrojevi(){
    vidljivi = skriveni = 0;
    }

    int vratiSkriveni(){
    return skriveni;
    }

    int vratiVdiljivi(){
    return vidljivi;
    }

    double dajApsolutnuvrijednost(){
    return abs(vidljivi);
    }

    Dualnibrojevi dajNegaciju(){
        Dualnibrojevi a;
        a.vidljivi = a.vidljivi * (-1);
        a.skriveni = a.skriveni * (-1);
    return a;
    }

     Dualnibrojevi dajKonjugaciju(){
        Dualnibrojevi a;
        a.skriveni = a.skriveni * (-1);
    return a;
    }

    friend Dualnibrojevi operator +(const Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi operator +=(Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi operator -(const Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi operator -=(Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi operator *(const Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi operator *=(Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi operator /(const Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi operator /=(Dualnibrojevi &a,const Dualnibrojevi &b);
    friend Dualnibrojevi &operator ++(Dualnibrojevi &d);
    friend Dualnibrojevi operator ++(Dualnibrojevi &d, int);
    friend Dualnibrojevi &operator --(Dualnibrojevi &d);
    friend Dualnibrojevi operator --(Dualnibrojevi &d, int);
    friend bool operator ==(const Dualnibrojevi &a,const Dualnibrojevi &b);
    friend bool operator !=(const Dualnibrojevi &a,const Dualnibrojevi &b);
    friend ostream& operator<<(ostream& os, const Dualnibrojevi& dt);
    friend istream& operator>> (istream& is, Dualnibrojevi& dt);

};

Dualnibrojevi operator +(const Dualnibrojevi &a,const Dualnibrojevi &b){
    Dualnibrojevi c;
    c.vidljivi = a.vidljivi + b.vidljivi;
    c.skriveni = a.skriveni + b.skriveni;
    return c;
}

Dualnibrojevi operator +=(Dualnibrojevi &a,const Dualnibrojevi &b){
    a.vidljivi = a.vidljivi + b.vidljivi;
    a.skriveni = a.skriveni + b.skriveni;
    return a;
}

Dualnibrojevi operator -(const Dualnibrojevi &a,const Dualnibrojevi &b){
    Dualnibrojevi c;
    c.vidljivi = a.vidljivi - b.vidljivi;
    c.skriveni = a.skriveni - b.skriveni;
    return c;
}

Dualnibrojevi operator -=(Dualnibrojevi &a,const Dualnibrojevi &b){
    a.vidljivi = a.vidljivi - b.vidljivi;
    a.skriveni = a.skriveni - b.skriveni;
    return a;
}

Dualnibrojevi operator *(const Dualnibrojevi &a,const Dualnibrojevi &b){
    Dualnibrojevi c;
    c.vidljivi = (a.vidljivi * b.vidljivi);
    c.skriveni = (a.vidljivi * b.skriveni)+(b.vidljivi * a.skriveni);
    return c;
}

Dualnibrojevi operator *=(Dualnibrojevi &a,const Dualnibrojevi &b){
    a.vidljivi = a.vidljivi * b.vidljivi;
    a.skriveni = a.skriveni * b.skriveni;
    return a;
}

Dualnibrojevi operator /(const Dualnibrojevi &a,const Dualnibrojevi &b){
    Dualnibrojevi c;
    c.vidljivi = a.vidljivi / a.skriveni;
    c.skriveni = ((b.vidljivi * a.skriveni)-(a.vidljivi * b.skriveni)) / (pow(b.vidljivi,2) - pow(b.skriveni,2));
    return c;
}

Dualnibrojevi operator /=(Dualnibrojevi &a,const Dualnibrojevi &b){
    a.vidljivi = a.vidljivi / b.vidljivi;
    a.skriveni = a.skriveni / b.skriveni;
    return a;
}

Dualnibrojevi &operator ++(Dualnibrojevi &d) {
    d.vidljivi++;
return d;
}
Dualnibrojevi operator ++(Dualnibrojevi &d, int) {
    ++d.vidljivi;
    Dualnibrojevi pomocni = d;
return pomocni;
}

Dualnibrojevi &operator --(Dualnibrojevi &d) {
    d.vidljivi--;
return d;
}

Dualnibrojevi operator --(Dualnibrojevi &d, int) {
    --d.vidljivi;
    Dualnibrojevi pomocni = d;
return pomocni;
}

bool operator ==(const Dualnibrojevi &a,const Dualnibrojevi &b){
    if(a.vidljivi == b.vidljivi && a.skriveni == b.skriveni) return true;
    return false;
}

bool operator != (const Dualnibrojevi &a,const Dualnibrojevi &b){
    if(a.vidljivi != b.vidljivi && a.skriveni != b.skriveni) return true;
    return false;
}

ostream& operator<<(ostream& os, const Dualnibrojevi& dt){
    os <<"(" << dt.vidljivi << "|" << dt.skriveni<<")" << endl ;
    return os;
}

istream& operator>> (istream& is, Dualnibrojevi& dt)
{
    is>> dt.vidljivi>> dt.skriveni;
    return is;
}

int main()
{
    Dualnibrojevi a(2,3);
    cout << a;
    ++a;
    cout << a;
    cin >> a;
    cout << a;
    return 0;
}
