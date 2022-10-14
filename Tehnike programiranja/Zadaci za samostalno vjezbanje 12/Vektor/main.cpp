#include <iostream>
#include <tuple>
#include <math.h>

using namespace std;

class Vektor
{
    double x,y,z;
public:
    Vektor()
    {
        x = y = z = 0;
    }

    Vektor(double a,double b)
    {
        x = a;
        y = b;
        z = 0;
    }

    Vektor(double a,double b,double c)
    {
        x = a;
        y = b;
        z = c;
    }

    void PostaviVektor(double a,double b,double c)
    {
        x = a;
        y = b;
        z = c;
    }

    tuple<double,double,double> Ocitaj()
    {
        tuple<double,double,double> a;
        a = make_tuple(x,y,z);
        return a;
    }

    int vratiDuzinu()
    {
        return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    }

    bool DaLiJeRavanskiVektor()
    {
        if(z == 0) return true;
        return false;
    }

    friend ostream& operator<<(ostream& os, const Vektor& dt);

    friend Vektor operator+(Vektor& a,const Vektor& b)
    {
        Vektor c;
        c.x = a.x + b.x;
        c.y = a.y + b.y;
        c.z = a.z + b.z;
        return c;
    }

    friend Vektor operator-(Vektor& a,const Vektor& b)
    {
        Vektor c;
        c.x = a.x - b.x;
        c.y = a.y - b.y;
        c.z = a.z - b.z;
        return c;
    }
    friend Vektor operator+=(Vektor& a,int broj)
    {
        Vektor c;
        a+=broj;
        c = a;
        return c;
    }

    friend Vektor operator-=(Vektor& a,int broj)
    {
        Vektor c;
        a-=broj;
        c = a;
        return c;
    }

    friend int operator*(Vektor& a,int broj)
    {
        int skalarniProdukt = 0;
        skalarniProdukt = a.x * broj+ a.y * broj+a.z * broj;
        return skalarniProdukt;
    }


    friend int operator*(Vektor& a,const Vektor& b)
    {
        int skalarniProdukt = 0;
        skalarniProdukt = a.x * b.x+ a.y * b.y+a.z * b.z;
        return skalarniProdukt;
    }


    friend Vektor operator%(Vektor& a,const Vektor& b)
    {

        Vektor c;
        c.x = (a.y * b.z)-(b.y*a.z);
        c.y = (a.z * b.x)-(a.x*b.z);
        c.z = (a.x * b.y)-(b.x*a.y);
        return c;
    }

    friend double operator|(Vektor& a,const Vektor& b){
    int formula = a * b / (sqrt(pow(a.x,2)+pow(a.y,2)+pow(a.z,2))) * (sqrt(pow(b.x,2)+pow(b.y,2)+pow(b.z,2)));
    double ugao = cos(formula);
    return ugao;
    }
};

ostream& operator<<(ostream& os, const Vektor& dt)
{
    os << "{" << dt.x << "," << dt.y << "," << dt.z << "}";
    return os;
}

int main()
{
    Vektor a(3,4,5);
    Vektor b(3,4,5);
    cout << a+b;
    return 0;
}
