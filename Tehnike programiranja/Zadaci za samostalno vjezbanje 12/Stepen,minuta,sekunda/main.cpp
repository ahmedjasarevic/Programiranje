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

ostream& operator<<(ostream& os, const StepeniMinuteSekunde& dt){
 os << "<" << dt.stepeni << ">"<< "<" << dt.minute << ">"<< "<" <<dt.sekunde << ">" << endl;
    return os;
}

int main()
{
    StepeniMinuteSekunde a(110,20,45);
    StepeniMinuteSekunde b(220,13,34);
    cout << a-b;
    return 0;
}
