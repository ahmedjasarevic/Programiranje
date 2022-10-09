#include <iostream>
#include <math.h>

using namespace std;

class Sat
{
    float ukupneSekunde;
    float temp;
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
       sati = sati * 3600;
       minute = minute * 60;
       sekunde = sekunde + minute + sati;
       Sat::ukupneSekunde = sekunde;
    }
    void PostaviNormalizirano(int sati,int minute, int sekunde)
    {
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
        sati = sati * 3600;
       minute = minute * 60;
       sekunde = sekunde + minute + sati;
       Sat::ukupneSekunde = sekunde;
    }
    Sat Sljedeci()
    {
    ukupneSekunde += 1;
    Ispisi();
    }
    Sat Prethodni()
    {
    ukupneSekunde -= 1;
    Ispisi();
    }
    Sat PomjeriZa(int a){

    ukupneSekunde += a;
    Ispisi();
    }
    void Ispisi()
    {
        float pomocna;
        pomocna = ukupneSekunde;
       pomocna = pomocna / 3600;
       cout << int(pomocna) << ":";
       pomocna = (pomocna - int(pomocna)) * 60;
       cout << int(pomocna) << ":";
       pomocna = (pomocna - int(pomocna)) * 60;
       cout << int(pomocna) << endl;
    }
       int DajSate(){
        temp = ukupneSekunde;
        temp = temp / 3600;
        return int(temp);
    }
    int DajMinute()
    {
        temp = (temp - int(temp));
        temp *= 60;
        return temp;

    }
    int DajSekunde()
    {
         temp = (temp - int(temp));
      return temp * 60;
    }
   static Razmak(Sat v1,Sat v2){
        v1.ukupneSekunde -= v2.ukupneSekunde;
        return v1.ukupneSekunde;
    }

};

int main()
{
    Sat v1,v2;
    int sat,min,sek;
    cin >> sat >> min >> sek;
    v1.DaLiJeIspravno(sat,min,sek);
  v1.Postavi(sat,min,sek);
    v1.PostaviNormalizirano(sat,min,sek);
    v1.Ispisi();
      cout << v1.DajSate() << endl;
        cout << v1.DajMinute() << endl;
    cout << v1.DajSekunde() <<endl;
    v1.Sljedeci() ;
    cout << endl;
    v1.Prethodni();
    cout << endl;
    v1.PomjeriZa(10);
   v1.Postavi(12,23,35);
   v2.Postavi(12,23,45);
   cout << Sat::Razmak(v1,v2);
    return 0;
}
