#include <iostream>

using namespace std;

class Sat
{
    int sati,minute,sekunde;
public:
    Sat (){
    sati = minute = sekunde = 0;
    }
    Sat (double sekunde2){
    sekunde2 = sekunde2 / 3600.;
    sati = sekunde2;
    sekunde2 = (sekunde2 - int(sekunde2)) * 60;
    minute = sekunde2;
     sekunde2 = (sekunde2 - int(sekunde2)) * 60;
     sekunde = sekunde2+1;
    }
    Sat(int sati1, int minute1, int sekunde1){
    sati = sati1;
    minute = minute1;
    sekunde = sekunde1;
    }
    bool DaLiJeIspravno(int sati,int minute, int sekunde) const
    {
        if(sati > 24 || sati < 0 || minute > 60 || minute < 0 || sekunde < 0 || sekunde > 60)
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
  Sat v1(5000);
  v1.Postavi(70,64,62);
  v1.Ispisi();

    return 0;
}
