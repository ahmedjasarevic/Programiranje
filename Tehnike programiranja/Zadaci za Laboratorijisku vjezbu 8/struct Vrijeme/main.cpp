#include <iostream>
#include <iomanip>

using namespace std;

struct Vrijeme{
int sati;
int minute;
int sekunde;
};

void IspisiVrijeme (Vrijeme sat){
cout <<setfill('0') <<setw(2) << sat.sati << ":";
cout << sat.minute <<":";
cout << sat.sekunde;
}

void SaberiVrijeme(Vrijeme p,Vrijeme d){
Vrijeme t;
t.sati = p.sati + d.sati;
t.minute = p.minute + d.minute;
t.sekunde = p.sekunde + d.sekunde;
if(t.minute > 60){
    t.minute = t.minute - 60;
    t.sati +=1;
}
if(t.sekunde > 60){
    t.sekunde -= 60;
    t.minute += 1;
}
cout <<setfill('0') <<setw(2) << t.sati << ":";
cout << t.minute <<":";
cout << t.sekunde;
}

int main()
{
    Vrijeme prvo,drugo;
   cout << "Uneisite prvo vrijeme: ";
   cin >> prvo.sati >> prvo.minute >> prvo.sekunde;
   if(prvo.sati > 24|| prvo.minute > 60 || prvo.sekunde > 60 ) {
        cout << "Neisrpavno";
   return 0;
   }
    cout << "Uneisite drugo vrijeme: ";
   cin >> drugo.sati >> drugo.minute >> drugo.sekunde;
   if(drugo.sati > 24|| drugo.minute > 60 || drugo.sekunde > 60 ) {
        cout << "Neisrpavno";
   return 0;
   }
    cout << "Prvo vrijeme: ";
   IspisiVrijeme(prvo);
   cout << endl;
cout << "Drugo vrijeme: ";
   IspisiVrijeme(drugo);
   cout << endl;
   cout << "Zbir vremena: ";
   SaberiVrijeme(prvo,drugo);

   return 0;
}
