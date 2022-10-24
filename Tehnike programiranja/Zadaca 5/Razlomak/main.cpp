#include <iostream>

using namespace std;

class Razlomak
{
    long long int brojnik,nazivnik;
    bool negativanBrojnik,negativanNazivnik;
    static long long int NZD(long long int brojnik,long long int nazivnik)
    {
        long long int nzd;
        for(int i = 1; i<=brojnik && i <= nazivnik; i++)
        {
            if(brojnik % i == 0 && nazivnik % i == 0)
            {
                nzd = i;
            }
        }
        return nzd;
    }
public:
    Razlomak(long long int b = 0,long long int n = 1)
    {
        int maxBr =  max(b,n);
        if(n < 0) throw logic_error("Nekorektan razlomak");
        if(b < 0) negativanBrojnik = true;
        if(n < 0) negativanNazivnik = true;
        if(b < 0 && n < 0)
        {
            negativanBrojnik = false;
            negativanNazivnik = false;
        }
        for(int i = maxBr; i>1; i--)
        {
            while(b % i == 0 && n % i == 0)
            {
                b /= i;
                n /= i;
            }
            brojnik = b;
            nazivnik = n;

        }
    }
    Razlomak operator ()(int i,int j){
    return Razlomak(i,j);
    }

    long long int DajBrojnik(){
    return brojnik;
    }

    long long int DajNazivnik(){
    return nazivnik;
    }

    friend Razlomak operator +(Razlomak a,Razlomak b);
    friend Razlomak operator -(Razlomak a,Razlomak b);
    friend Razlomak operator *(Razlomak a,Razlomak b);
    friend Razlomak operator /(Razlomak a,Razlomak b);
    friend Razlomak operator +(Razlomak a);
    friend Razlomak operator -(Razlomak a);
    friend Razlomak operator +=(Razlomak a,Razlomak b);
    friend Razlomak operator -=(Razlomak a,Razlomak b);
    friend Razlomak operator *=(Razlomak a,Razlomak b);
    friend Razlomak operator /=(Razlomak a,Razlomak b);
    friend Razlomak operator++(Razlomak a);
    friend Razlomak operator++(Razlomak a,int);
    friend Razlomak operator--(Razlomak a);
    friend Razlomak operator--(Razlomak a,int);
    friend bool operator <(Razlomak a,Razlomak b);
    friend bool operator >(Razlomak a,Razlomak b);
    friend bool operator >=(Razlomak a,Razlomak b);
    friend bool operator <=(Razlomak a,Razlomak b);
    friend bool operator ==(Razlomak a,Razlomak b);
    friend bool operator !=(Razlomak a,Razlomak b);
    friend ostream &operator << (ostream &out, Razlomak &o);
    friend istream &operator >>(istream &in, Razlomak &o);
};

ostream &operator << (ostream &out, Razlomak &o){
if(o.nazivnik == 1) {
    out << o.brojnik << endl;
}
else{
    out << o.brojnik << " / " << o.nazivnik << endl;
}
return out;
}

istream &operator >>(istream &in, Razlomak &o){
    char znak;
in >> o.brojnik >> znak >> o.nazivnik;

}


Razlomak operator +(Razlomak a ,Razlomak b){
    Razlomak c;
    c.brojnik = a.brojnik * (b.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik)) + b.brojnik * (a.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik));
    c.nazivnik = a.nazivnik * (b.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik));
    if(c.nazivnik > 0 && c.brojnik > INT_MAX - c.nazivnik) throw overflow_error("Prekoracenje");
    if(c.nazivnik < 0 && c.brojnik < INT_MIN - c.nazivnik) throw overflow_error("Prekoracenje");
    return Razlomak(c.brojnik,c.nazivnik);
}

Razlomak operator -(Razlomak a ,Razlomak b){
    Razlomak c;
    c.brojnik = a.brojnik * (b.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik)) - b.brojnik * (a.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik));
    c.nazivnik = a.nazivnik * (b.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik));
    if(c.nazivnik > 0 && c.brojnik > INT_MAX + c.nazivnik) throw overflow_error("Prekoracenje");
    if(c.nazivnik < 0 && c.brojnik < INT_MIN + c.nazivnik) throw overflow_error("Prekoracenje");
    return Razlomak(c.brojnik,c.nazivnik);
}

Razlomak operator *(Razlomak a ,Razlomak b){
    Razlomak c;
    c.brojnik = (a.brojnik / Razlomak::NZD(a.brojnik,b.nazivnik)) * (b.nazivnik / Razlomak::NZD(b.nazivnik,a.brojnik));
    c.nazivnik = (a.nazivnik / Razlomak::NZD(b.nazivnik,a.brojnik)) * (b.brojnik / Razlomak::NZD(a.brojnik,b.nazivnik));
    if(c.nazivnik > 0 && c.brojnik < INT_MIN / c.nazivnik || c.brojnik > INT_MAX / c.nazivnik) throw overflow_error("Prekoracenje");
    if(c.nazivnik < 0 && c.brojnik == INT_MIN || (c.brojnik * -1) > INT_MAX / (c.nazivnik * -1 || (c.brojnik * -1) <INT_MIN / (c.nazivnik * -1))) throw overflow_error("Prekoracenje");
    return Razlomak(c.brojnik,c.nazivnik);
}

Razlomak operator /(Razlomak a ,Razlomak b){
    Razlomak c;
    c.brojnik = (a.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) * (b.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik));
    c.nazivnik = (a.nazivnik / Razlomak::NZD(a.nazivnik,b.nazivnik)) * (b.brojnik / Razlomak::NZD(a.brojnik,b.brojnik));
    if(c.nazivnik > 0 && c.brojnik < INT_MIN / c.nazivnik || c.brojnik > INT_MAX / c.nazivnik) throw overflow_error("Prekoracenje");
    if(c.nazivnik < 0 && c.brojnik == INT_MIN || (c.brojnik * -1) > INT_MAX / (c.nazivnik * -1 || (c.brojnik * -1) <INT_MIN / (c.nazivnik * -1))) throw overflow_error("Prekoracenje");
    return Razlomak(c.brojnik,c.nazivnik);
}

Razlomak operator -(Razlomak a){
Razlomak c;
c.brojnik = a.nazivnik;
c.nazivnik = a.brojnik;
return c;
}

Razlomak operator +(Razlomak a){
Razlomak c;
c.brojnik = a.brojnik;
c.nazivnik = a.nazivnik;
return c;
}

Razlomak operator +=(Razlomak a,Razlomak b){
a.brojnik = a.brojnik + b.brojnik;
a.nazivnik = a.nazivnik + b.nazivnik;
return a;
}

Razlomak operator -=(Razlomak a,Razlomak b){
a.brojnik = a.brojnik - b.brojnik;
a.nazivnik = a.nazivnik - b.nazivnik;
return a;
}

Razlomak operator *=(Razlomak a,Razlomak b){
a.brojnik = a.brojnik * b.brojnik;
a.nazivnik = a.nazivnik * b.nazivnik;
return a;
}

Razlomak operator /=(Razlomak a,Razlomak b){
a.brojnik = a.brojnik / b.brojnik;
a.nazivnik = a.nazivnik / b.nazivnik;
return a;
}

Razlomak operator++(Razlomak a){
a.brojnik += 1;
a.nazivnik += 1;
return a;
}

Razlomak operator++(Razlomak a,int){
a.brojnik -= 1;
a.nazivnik -= 1;
return a;
}

Razlomak operator--(Razlomak a){
a.brojnik -= 1;
a.nazivnik -= 1;
return a;
}

Razlomak operator--(Razlomak a,int){
a.brojnik += 1;
a.nazivnik += 1;
return a;
}

bool operator <(Razlomak a,Razlomak b){
    long double p = (a.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (b.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
    long double q = (b.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (a.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
if(p < q) return true;
return false;
}

bool operator >(Razlomak a,Razlomak b){
    long double p = (a.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (b.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
    long double q = (b.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (a.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
if(p > q) return true;
return false;
}

bool operator <=(Razlomak a,Razlomak b){
    long double p = (a.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (b.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
    long double q = (b.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (a.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
if(p <= q) return true;
return false;
}

bool operator >=(Razlomak a,Razlomak b){
    long double p = (a.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (b.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
    long double q = (b.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (a.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
if(p >= q) return true;
return false;
}

bool operator ==(Razlomak a,Razlomak b){
    long double p = (a.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (b.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
    long double q = (b.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (a.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
if(p == q) return true;
return false;
}

bool operator !=(Razlomak a,Razlomak b){
    long double p = (a.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (b.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
    long double q = (b.brojnik / Razlomak::NZD(a.brojnik,b.brojnik)) *  (a.nazivnik / (Razlomak::NZD(a.nazivnik,b.nazivnik)));
if(p != q) return true;
return false;
}





int main()
{
    Razlomak a (10,15);
    Razlomak b {2,3};
    cout << a;

    return 0;
}
