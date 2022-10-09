#include <iostream>
#include <math.h>
using namespace std;

class Tacka
{
    double polA,polB;
public:
    Tacka()
    {
        polA = polB = 0;
    }
    Tacka(double x, double y)
    {
       polA = x;
       polB = y;
    }
    Tacka(double x, double y,bool stanje)
    {
        if(stanje == 0)
        {
            polA = x * cos(y);
       polB = x * sin(y);
        }
        else
        {
          polA = x;
          polB = y;
        }
    }
    void Postavi(double x, double y)
    {
        polA = sqrt(pow(x,2) + pow(y,2));
         polB = atan2(y,x);
    }
    void PostaviPolarno(double ro, double theta)
    {
       polA = ro;
       polB = theta;
    }
    double DajX() const
    {
        return polA * cos(polB);
    }
    double DajY() const
    {
       return polA * sin(polB);
    }
    double DajRho() const
    {
        return polA;
    }
    double DajTheta() const
    {
        return polB;
    }
    void PostaviX(double x)
    {
        polA = DajX();
    }
    void PostaviY(double y)
    {
         polA = DajY();
    }
    bool DaLiJeKoordinatniPocetak() const
    {
        if(DajX() == 0 && DajY() == 0) return true;
        return false;
    }
    void Transliraj(double delta_x, double delta_y)
    {
        polA = DajX() + delta_x;
        polB = DajY() + delta_y;
    }
    void Rotiraj(double alpha)
    {
        polA = cos(polB);
        polB = sin(polB);
    }
    void Rotiraj(double alpha, const Tacka &centar)
    {
        Tacka();
        polA = centar.DajX() + (DajX() - centar.DajX())*cos(alpha)-(DajY()-centar.DajY())*sin(alpha);
          polB = centar.DajX() + (DajX() - centar.DajX())*cos(alpha)-(DajY()-centar.DajY())*sin(alpha);
    }
    friend bool DaLiSuIdenticne(const Tacka &t1, const Tacka &t2)
    {
        if (t1.DajX() == t2.DajX() && t1.DajY() == t2.DajY()) return true;
        return false;
    }
    friend double Rastojanje(const Tacka &t1, const Tacka &t2)
    {
        return pow((t2.DajX() - t1.DajX()),2) + pow((t2.DajY()-t1.DajY()),2);
    }
};

int main()
{
      Tacka b,a;
    Tacka c(2,3,0);
    cout << c.DajX();
    a.PostaviX(3);
    cout << a.DajX();
      a.Postavi(2,3);
    b.Postavi(2,3);
    cout << endl;
    cout << Rastojanje(a,b) << endl;
    cout << DaLiSuIdenticne(a,b);
    return 0;
}
