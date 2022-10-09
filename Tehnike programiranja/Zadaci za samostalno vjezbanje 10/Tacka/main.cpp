#include <iostream>
#include <math.h>
using namespace std;

class Tacka
{
    double x,y;
public:
    Tacka()
    {
        x = y = 0;
    }
    Tacka(double x, double y)
    {
        Tacka::x = x;
        Tacka::y = y;
    }
    Tacka(double x, double y,bool stanje)
    {
        if(stanje == 0)
        {
            Tacka::x = x;
            Tacka::y = y;
        }
        else
        {
            x= sqrt(pow(x,2) + pow(y,2));
            y= atan2(y,x);
            Tacka::x = x;
            Tacka::y = y;
        }
    }

    void Postavi(double x, double y)
    {
        Tacka::x = x;
        Tacka::y = y;
    }
    void PostaviPolarno(double ro, double theta)
    {
        x = ro * cos(theta);
        y = ro * sin(theta);
    }
    double DajX() const
    {
        return x;
    }
    double DajY() const
    {
        return y;
    }
    double DajRho() const
    {
        return sqrt(pow(x,2) + pow(y,2));
    }
    double DajTheta() const
    {
        return atan2(y,x);
    }
    void PostaviX(double x)
    {
        Tacka::x = x;
    }
    void PostaviY(double y)
    {
        Tacka::y = y;
    }
    bool DaLiJeKoordinatniPocetak() const
    {
        if(x == 0 && y == 0) return true;
        return false;
    }
    void Transliraj(double delta_x, double delta_y)
    {
        x = x + delta_x;
        y = y + delta_y;
    }
    void Rotiraj(double alpha)
    {
        x = x * cos(alpha) + y * sin(alpha);
        y = y * cos(alpha) - x * sin (alpha);
    }
    void Rotiraj(double alpha, const Tacka &centar)
    {
        x = centar.x + (x - centar.x)*cos(alpha)-(y-centar.y)*sin(alpha);
        y= centar.x + (x - centar.x)*cos(alpha)-(y-centar.y)*sin(alpha);
    }
    friend bool DaLiSuIdenticne(const Tacka &t1, const Tacka &t2)
    {
        if (t1.x == t2.x && t1.y == t2.y) return true;
        return false;
    }
    friend double Rastojanje(const Tacka &t1, const Tacka &t2)
    {
        return pow((t2.x - t1.x),2) + pow((t2.y-t1.y),2);
    }
};

int main()
{
    Tacka a(2,3);
    cout << a.DajX() << endl;
    cout << a.DajY() << endl;
    a.Rotiraj(30);
    cout << a.DajX() << endl;
    cout << a.DajY() << endl;
    Tacka b(1,2);
    a.Rotiraj(20,b);
    cout << a.DajX() << endl;
    cout << a.DajY() << endl;
    return 0;
}
