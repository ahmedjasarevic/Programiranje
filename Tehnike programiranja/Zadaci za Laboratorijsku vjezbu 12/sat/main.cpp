#include <iostream>

using namespace std;

class Sat
{
    int sati,minute,sekunde;
public:
    Sat ()
    {
        sati = minute = sekunde = 0;
    }
    bool DaLiJeIspravno(int sati,int minute, int sekunde) const
    {
        if(sati > 24 || minute > 60 || sekunde > 60)
        {
            return false;
        }
        return true;
    }
    void Postavi(int sati, int minute, int sekunde)
    {

        if(!DaLiJeIspravno(sati,minute,sekunde))
        {
            throw domain_error("Neispravno vrijeme");
        }
        Sat::sati = sati;
        Sat::minute = minute;
        Sat::sekunde = sekunde;
    }
    void PostaviNormalizirano(int sati,int minute, int sekunde)
    {
        Sat::sati = sati;
        Sat::minute = minute;
        Sat::sekunde = sekunde;
        int brojac = 0;
        int brojac2 = 0;
        if (sati >= 24)
        {
            sati = sati-24;
        }
        if(minute > 60)
        {
            while (minute > 60)
            {
                brojac2++;
                minute = minute - 60;
            }
        }
        if(sekunde > 60)
        {
            while (sekunde > 60)
            {
                brojac++;
                sekunde = sekunde - 60;
            }
        }
        sati = sati + brojac2;
        minute = minute + brojac;
        Sat::sati = sati;
        Sat::minute = minute;
        Sat::sekunde = sekunde;
    }
    int DajSate()
    {
        return sati;
    }
    int DajMinute()
    {
        return minute;
    }
    int DajSekunde()
    {
        return sekunde;
    }
    void IspisiRazliku() const
    {
        cout << sekunde << endl;
    }
    void operator ++()
    {
        sekunde++;
        if(sekunde == 60)
        {
            minute += 1;
        }
        if(minute == 60)
        {
            sati += 1;
        }
        if(sekunde == 60)
        {
            sekunde = 0;
        }
    }
    void operator ++(int)
    {
        sekunde++;
        if(sekunde == 60)
        {
            minute += 1;
        }
        if(minute == 60)
        {
            sati += 1;
        }
        if(sekunde == 60)
        {
            sekunde = 0;
        }
    }
    void operator --()
    {
        sekunde--;
        if(sekunde <= 0)
        {
            minute -= 1;
        }
        if(minute <= 0)
        {
            sati -= 1;
            minute = 0;
        }
        if(sekunde <= 0)
        {
            sekunde = 0;
        }
    }
    void operator --(int)
    {
        sekunde--;
        if(sekunde <= 0)
        {
            minute -= 1;
        }
        if(minute <= 0)
        {
            sati -= 1;
            minute = 0;
        }
        if(sekunde <= 0)
        {
            sekunde = 0;
        }
    }
    void operator +=(int a)
    {
        sekunde = sekunde + a;
    }
    void operator -=(int a)
    {
        sekunde = sekunde + a;
    }

    friend Sat operator+(Sat& a,int broj)
    {
        Sat c;
        a+=broj;
        c = a;
        return c;
    }

    friend Sat operator-(Sat& a,int broj)
    {
        Sat c;
        a.sekunde = a.sekunde - broj;
        if(a.sekunde <= 0)
        {
            a.minute -= 1;
        }
        if(a.minute <= 0)
        {
            a.sati -= 1;
            a.minute = 0;
        }
        if(a.sekunde <= 0)
        {
            a.sekunde = 0;
        }
        c = a;
        return c;
    }

    friend Sat operator-(Sat& a,const Sat& b)
    {
        Sat c;
        c.sati = a.sati - b.sati;
        c.minute = a.minute - b.minute;
        c.sekunde = a.sekunde - b.sekunde;
        return c;
    }
    friend ostream& operator<<(ostream& os, const Sat& sat);
};

ostream& operator<<(ostream& os, const Sat& sat)
{
    os << sat.sati  << ":" << sat.minute << ":" << sat.sekunde <<endl;
    return os;
}


int main()
{
    Sat v1;
    v1++;
    v1--;
    v1.Postavi(3,4,59);
    v1++;
    v1++;
    v1+=3;
    cout << v1;
    Sat v2;
    v2.Postavi(1,2,3);
    cout << v1;
    cout << v2;
    cout << v1-v2;
    cout << v1;
    v1-5;
    cout << v1;

    return 0;
}
