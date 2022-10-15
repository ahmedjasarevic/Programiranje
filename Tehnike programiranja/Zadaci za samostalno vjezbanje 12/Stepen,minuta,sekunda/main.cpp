#include <iostream>

using namespace std;

class StepeniMinuteSekunde{
int stepeni,minute,sekunde;
public:
StepeniMinuteSekunde(){
stepeni = minute = sekunde = 0;
}

StepeniMinuteSekunde(int s,int m,int sek){
stepeni = s;
minute = m;
sekunde = sek;

    if(stepeni > 360){
        while(stepeni > 360){
        stepeni = stepeni - 360;
        }
    }
    if(minute > 60){
        while (minute > 60){
            stepeni+=1;
            minute = minute - 60;
        }
    }
    if(sekunde > 60){
        while (sekunde > 60){
            minute+=1;
            sekunde = sekunde - 60;
        }
    }
}

void Postavi(int s,int m,int sek){
stepeni = s;
minute = m;
sekunde = sek;

    if(stepeni > 360){
        while(stepeni > 360){
        stepeni = stepeni - 360;
        }
    }
    if(minute > 60){
        while (minute > 60){
            stepeni+=1;
            minute = minute - 60;
        }
    }
    if(sekunde > 60){
        while (sekunde > 60){
            minute+=1;
            sekunde = sekunde - 60;
        }
    }
}

void PostavipomocuUgla(double ugao){
stepeni = int(ugao);
minute = (ugao - int(ugao)) * 60;
minute = (ugao - int(ugao)) * 60;
}

double DajUgao(){
return stepeni + (minute / 60.) + sekunde/3600.;
}

friend void operator --( StepeniMinuteSekunde& a);
friend void operator --(StepeniMinuteSekunde& a,int);
friend StepeniMinuteSekunde operator +(const StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b);
friend StepeniMinuteSekunde operator -(const StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b);
friend ostream& operator<<(ostream& os, const StepeniMinuteSekunde& dt);
friend StepeniMinuteSekunde operator *( StepeniMinuteSekunde &a,int broj);
friend StepeniMinuteSekunde operator *(int broj, StepeniMinuteSekunde &a);
friend StepeniMinuteSekunde operator +=(StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b);
friend StepeniMinuteSekunde operator -=(StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b);
friend StepeniMinuteSekunde operator *=(StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b);
friend StepeniMinuteSekunde operator ++(StepeniMinuteSekunde &c);
friend StepeniMinuteSekunde operator ++(StepeniMinuteSekunde &c, int);
friend bool operator<(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b);
friend bool operator<=(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b);
friend bool operator>(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b);
friend bool operator>=(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b);
friend bool operator==(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b);
friend bool operator!=(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b);
friend istream& operator>> (istream& is, StepeniMinuteSekunde& dt);
};

void operator --( StepeniMinuteSekunde& a){
a.stepeni = 360 - a.stepeni;
a.minute = 60 - a.minute;
a.sekunde = 60 - a.sekunde;
if(a.sekunde < 60){
    a.minute-=1;
}
if(a.sekunde > 60){
   while (a.sekunde > 60){
            a.minute+=1;
            a.sekunde = a.sekunde - 60;
        }
}
if(a.minute < 60){
    a.stepeni-=1;
}
if(a.minute > 60){
   while (a.minute > 60){
            a.stepeni+=1;
            a.minute = a.minute - 60;
        }
}
}

void operator --(StepeniMinuteSekunde& a,int){
a.stepeni = 360 - a.stepeni;
a.minute = 60 - a.minute;
a.sekunde = 60 - a.sekunde;
if(a.sekunde < 60){
    a.minute-=1;
}
if(a.sekunde > 60){
   while (a.sekunde > 60){
            a.minute+=1;
            a.sekunde = a.sekunde - 60;
        }
}
if(a.minute < 60){
    a.stepeni-=1;
}
if(a.minute > 60){
   while (a.minute > 60){
            a.stepeni+=1;
            a.minute = a.minute - 60;
        }
}
}

StepeniMinuteSekunde operator +(const StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b){
    StepeniMinuteSekunde c;
    c.stepeni = a.stepeni + b.stepeni;
    c.minute = a.minute + b.minute;
    c.sekunde = a.sekunde + b.sekunde;
      if(c.stepeni > 360){
        while(c.stepeni > 360){
        c.stepeni = c.stepeni - 360;
        }
    }
    if(c.minute > 60){
        while (c.minute > 60){
            c.stepeni+=1;
            c.minute = c.minute - 60;
        }
    }
    if(c.sekunde > 60){
        while (c.sekunde > 60){
            c.minute+=1;
            c.sekunde = c.sekunde - 60;
        }
    }
    return c;
}

StepeniMinuteSekunde operator -(const StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b){
    StepeniMinuteSekunde c;
    c.stepeni = a.stepeni - b.stepeni;
    c.minute = a.minute - b.minute;
    c.sekunde = a.sekunde - b.sekunde;
 if(c.stepeni > 360){
        while(c.stepeni > 360){
        c.stepeni = c.stepeni - 360;
        }
    }
    if(c.minute > 60){
        while (c.minute > 60){
            c.stepeni+=1;
            c.minute = c.minute - 60;
        }
    }
    if(c.sekunde > 60){
        while (c.sekunde > 60){
            c.minute+=1;
            c.sekunde = c.sekunde - 60;
        }
    }
    return c;
}

StepeniMinuteSekunde operator *(StepeniMinuteSekunde &a,int broj){
    a.stepeni = a.stepeni * broj;
     if(a.stepeni > 360){
        while(a.stepeni > 360){
        a.stepeni = a.stepeni - 360;
        }
    }
    return a;
}

StepeniMinuteSekunde operator *(int broj, StepeniMinuteSekunde &a){
  a.stepeni = a.stepeni * broj;
     if(a.stepeni > 360){
        while(a.stepeni > 360){
        a.stepeni = a.stepeni - 360;
        }
    }
    return a;
}

StepeniMinuteSekunde operator +=(StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b){
a.stepeni = a.stepeni + b.stepeni;
a.minute = a.minute + b.minute;
a.sekunde = a.sekunde + b.sekunde;
return a;
}

StepeniMinuteSekunde operator -=(StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b){
a.stepeni = a.stepeni - b.stepeni;
a.minute = a.minute - b.minute;
a.sekunde = a.sekunde - b.sekunde;
return a;
}

StepeniMinuteSekunde operator *=(StepeniMinuteSekunde &a,const StepeniMinuteSekunde &b){
a.stepeni = a.stepeni * b.stepeni;
a.minute = a.minute * b.minute;
a.sekunde = a.sekunde * b.sekunde;
return a;
}

StepeniMinuteSekunde operator ++(StepeniMinuteSekunde &c){
c.sekunde += 1;
 if(c.stepeni > 360){
        while(c.stepeni > 360){
        c.stepeni = c.stepeni - 360;
        }
    }
    if(c.minute > 60){
        while (c.minute > 60){
            c.stepeni+=1;
            c.minute = c.minute - 60;
        }
    }
    if(c.sekunde > 60){
        while (c.sekunde > 60){
            c.minute+=1;
            c.sekunde = c.sekunde - 60;
        }
    }
    return c;
}

StepeniMinuteSekunde operator ++(StepeniMinuteSekunde &c, int){
c.sekunde += 1;
 if(c.stepeni > 360){
        while(c.stepeni > 360){
        c.stepeni = c.stepeni - 360;
        }
    }
    if(c.minute > 60){
        while (c.minute > 60){
            c.stepeni+=1;
            c.minute = c.minute - 60;
        }
    }
    if(c.sekunde > 60){
        while (c.sekunde > 60){
            c.minute+=1;
            c.sekunde = c.sekunde - 60;
        }
    }
    return c;
}

bool operator<(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b){
if(a.DajUgao() < b.DajUgao()) return true;
return false;
}

bool operator<=(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b){
if(a.DajUgao() <= b.DajUgao()) return true;
return false;
}

bool operator>=(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b){
if(a.DajUgao() >= b.DajUgao()) return true;
return false;
}

bool operator>(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b){
if(a.DajUgao() > b.DajUgao()) return true;
return false;
}

bool operator==(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b){
if(a.DajUgao() == b.DajUgao()) return true;
return false;
}

bool operator!=(StepeniMinuteSekunde &a,StepeniMinuteSekunde &b){
if(a.DajUgao() != b.DajUgao()) return true;
return false;
}


ostream& operator<<(ostream& os, const StepeniMinuteSekunde& dt){
 os << "<" << dt.stepeni << ">"<< "<" << dt.minute << ">"<< "<" <<dt.sekunde << ">" << endl;
    return os;
}

istream& operator>> (istream& is, StepeniMinuteSekunde& dt){
    is >> dt.stepeni >> dt.minute >> dt.sekunde;
    return is;
}

class Kontejnerskaklasa{
StepeniMinuteSekunde** pok;
int brojUglova;
int kapacitet ;
int brojac = 0;
public:
    explicit Kontejnerskaklasa(int maxbr){
    pok = new StepeniMinuteSekunde*[maxbr];
    kapacitet = maxbr;
    }

    ~Kontejnerskaklasa(){
    delete [] pok;
    }

    Kontejnerskaklasa(const Kontejnerskaklasa& objekat){
    kapacitet = objekat.kapacitet;
        for(int i = 0; i<kapacitet; i++){
            *pok[i] = *objekat.pok[i];
        }
    }

    Kontejnerskaklasa& operator=(Kontejnerskaklasa objekat){
    swap(pok,objekat.pok);
    swap(kapacitet,objekat.kapacitet);
    return *this;
    }

    void DodajNoviUgao(int s,int m,int sek){
    pok[brojac] = new StepeniMinuteSekunde(s,m,sek);
    brojac++;
    if(brojac > kapacitet ) throw logic_error("Dostignut max.");
    }

    void IzbrisiSve(){
        for(int i = 0; i <brojac; i++){
            delete pok[i];
        }
    }

    void IspisiSve(){
        for(int i = 0; i <brojac; i++){
        cout << *pok[i];
        }
    }

    int vratiNajmanjiugao(){
        int minUgao = INT_MAX;
          for(int i = 0; i <brojac; i++){
                if(pok[i]->DajUgao() < minUgao){
                    minUgao = pok[i]->DajUgao();
                }
        }
        return minUgao;
    }


    int vratiNajveciugao(){
        int maxUgao = INT_MIN;
          for(int i = 0; i <brojac; i++){
                if(pok[i]->DajUgao() > maxUgao){
                    maxUgao = pok[i]->DajUgao();
                }
        }
        return maxUgao;
    }

    int vratiUkupanbrUglova(){
    return brojac;
    }

    int vratiBrojOstrihUglova(){
         int brojac2 = 0;
         for(int i = 0; i <brojac; i++){
             if(pok[i]->DajUgao() < 90) brojac2++;
         }
    return brojac2;
    }

    int operator[](int indeks){
        if(indeks < 0 || indeks > kapacitet) throw logic_error("Neispravan indeks");
    return pok[indeks]->DajUgao();
    }
};



int main()
{
    StepeniMinuteSekunde a(110,20,45);
    StepeniMinuteSekunde b(220,13,34);
    cout << 3*a;
    Kontejnerskaklasa c(5);
    c.DodajNoviUgao(5,3,4);
    c.DodajNoviUgao(1,3,4);
    c.IspisiSve();
    cout << c.vratiUkupanbrUglova() <<endl;
    cout << c[0];
    return 0;
}
