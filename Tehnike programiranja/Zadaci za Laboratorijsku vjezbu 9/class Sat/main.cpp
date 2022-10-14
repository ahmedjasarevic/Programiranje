#include <iostream>

using namespace std;

class Sat
{
    int sati,minute,sekunde;
public:
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
        Ispisi();
        cout << endl;
    }
    Sat &Sljedeci()
    {
        sekunde+=1;
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
        Ispisi();
        return *this;
    }
    Sat &Prethodni()
    {

        sekunde-=1;
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
        Ispisi();
        return *this;
    }
    Sat &PomjeriZa(int a){
        sekunde += a;
        if(sekunde > 60){
        while(sekunde > 60){
                sekunde = sekunde - 60;
        }
        minute += 1;
        }
        Ispisi();
        return *this;

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
    void Ispisi() const
    {
        cout << sati << ":" << minute << ":"<< sekunde << endl;
    }
     void IspisiRazliku() const
    {
        cout << sekunde << endl;
    }
    static Sat Razmak( Sat v1, Sat v2){
        Sat v3;
        v3.sekunde = v1.sekunde - v2.sekunde;
        return v3;
    }
    friend Sat BrojSekundiIzmedju(Sat v1,Sat v2){
        Sat v3;
        v3.sekunde = v1.sekunde - v2.sekunde;
        return v3;
    }
};

int main()
{
    Sat v1,v2,v3;
    int sat,min,sek;
    cin >> sat >> min >> sek;
   v1.DaLiJeIspravno(sat,min,sek);
    v1.Postavi(sat,min,sek);
    v2.Postavi(12,23,45);
    v1.PostaviNormalizirano(sat,min,sek);
    v1.Sljedeci().Sljedeci();
    cout << endl;
    v1.Prethodni().Prethodni();
cout << endl;
   cout <<  v1.DajSate() << endl;
    cout <<  v1.DajMinute() << endl;
     cout <<  v1.DajSekunde() << endl;
v1.PomjeriZa(45);
   v1.Postavi(12,23,35);
   v2.Postavi(12,23,45);
v3 = BrojSekundiIzmedju(v1,v2);
v3.IspisiRazliku();
cout << endl;
v3 = Sat::Razmak(v1,v2);
v3.IspisiRazliku();

    return 0;
}
