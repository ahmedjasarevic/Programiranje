#include <iostream>
#include <math.h>


using namespace std;

class Perpleksnibrojevi{
int realni,hiperbolni;
public:
    Perpleksnibrojevi(int r,int h){
    realni = r;
    hiperbolni = h;
    }

    Perpleksnibrojevi(int r){
    realni = r;
    hiperbolni = 0;
    }

     Perpleksnibrojevi(){
    realni = hiperbolni = 0;
    }

    int vratiRealni(){
    return realni;
    }

    int vratiHiperbolni(){
    return hiperbolni;
    }

    double dajApsolutnuvrijednost(){
    if(pow(realni,2) >= pow(hiperbolni,2)) return sqrt(pow(realni,2) - pow(hiperbolni,2));
    else return (sqrt(pow(realni,2) - pow(hiperbolni,2))) * (-1);
    }

    Perpleksnibrojevi dajNegaciju(){
        Perpleksnibrojevi a;
        a.realni = a.realni * (-1);
        a.hiperbolni = a.hiperbolni * (-1);
    return a;
    }

     Perpleksnibrojevi dajKonjugaciju(){
        Perpleksnibrojevi a;
        a.hiperbolni = a.hiperbolni * (-1);
    return a;
    }

    friend Perpleksnibrojevi operator +(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi operator +=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi operator -(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi operator -=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi operator *(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi operator *=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi operator /(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi operator /=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend Perpleksnibrojevi &operator ++(Perpleksnibrojevi &d);
    friend Perpleksnibrojevi operator ++(Perpleksnibrojevi &d, int);
    friend Perpleksnibrojevi &operator --(Perpleksnibrojevi &d);
    friend Perpleksnibrojevi operator --(Perpleksnibrojevi &d, int);
    friend bool operator ==(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend bool operator !=(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b);
    friend ostream& operator<<(ostream& os, const Perpleksnibrojevi& dt);
    friend istream& operator>> (istream& is, Perpleksnibrojevi& dt);

};

Perpleksnibrojevi operator +(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    Perpleksnibrojevi c;
    c.realni = a.realni + b.realni;
    c.hiperbolni = a.hiperbolni + b.hiperbolni;
    return c;
}

Perpleksnibrojevi operator +=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    a.realni = a.realni + b.realni;
    a.hiperbolni = a.hiperbolni + b.hiperbolni;
    return a;
}

Perpleksnibrojevi operator -(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    Perpleksnibrojevi c;
    c.realni = a.realni - b.realni;
    c.hiperbolni = a.hiperbolni - b.hiperbolni;
    return c;
}

Perpleksnibrojevi operator -=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    a.realni = a.realni - b.realni;
    a.hiperbolni = a.hiperbolni - b.hiperbolni;
    return a;
}

Perpleksnibrojevi operator *(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    Perpleksnibrojevi c;
    c.realni = (a.realni * b.realni)+(a.hiperbolni * b.hiperbolni);
    c.hiperbolni = (a.realni * b.hiperbolni)+(b.realni * a.hiperbolni);
    return c;
}

Perpleksnibrojevi operator *=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    a.realni = a.realni * b.realni;
    a.hiperbolni = a.hiperbolni * b.hiperbolni;
    return a;
}

Perpleksnibrojevi operator /(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    Perpleksnibrojevi c;
    c.realni = ((a.realni * b.realni)-(a.hiperbolni * b.hiperbolni)) / (pow(b.realni,2) - pow(b.hiperbolni,2));
    c.hiperbolni = ((b.realni * a.hiperbolni)-(a.realni * b.hiperbolni)) / (pow(b.realni,2) - pow(b.hiperbolni,2));
    return c;
}

Perpleksnibrojevi operator /=(Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    a.realni = a.realni / b.realni;
    a.hiperbolni = a.hiperbolni / b.hiperbolni;
    return a;
}

Perpleksnibrojevi &operator ++(Perpleksnibrojevi &d) {
    d.realni++;
return d;
}
Perpleksnibrojevi operator ++(Perpleksnibrojevi &d, int) {
    ++d.realni;
    Perpleksnibrojevi pomocni = d;
return pomocni;
}

Perpleksnibrojevi &operator --(Perpleksnibrojevi &d) {
    d.realni--;
return d;
}

Perpleksnibrojevi operator --(Perpleksnibrojevi &d, int) {
    --d.realni;
    Perpleksnibrojevi pomocni = d;
return pomocni;
}

bool operator ==(const Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    if(a.realni == b.realni && a.hiperbolni == b.hiperbolni) return true;
    return false;
}

bool operator != (const Perpleksnibrojevi &a,const Perpleksnibrojevi &b){
    if(a.realni != b.realni && a.hiperbolni != b.hiperbolni) return true;
    return false;
}

ostream& operator<<(ostream& os, const Perpleksnibrojevi& dt){
    os <<"(" << dt.realni << "|" << dt.hiperbolni<<")" << endl ;
    return os;
}

istream& operator>> (istream& is, Perpleksnibrojevi& dt)
{
    is>> dt.realni>> dt.hiperbolni;
    return is;
}

int main()
{
    Perpleksnibrojevi a(2,3);
    cout << a;
    ++a;
    cout << a;
    cin >> a;
    cout << a;
    return 0;
}
