#include <iostream>

using namespace std;

class Ugao{
double ugaoUradijanima;
public:
    Ugao(double ugao = 0){
    ugaoUradijanima = ugao;
    if(ugaoUradijanima > 360){
        while(ugaoUradijanima > 360){
        ugaoUradijanima = ugaoUradijanima - 360;
        }
    }
    }

    Ugao(int step,int m,int sek){
        if(step < 0 || m < 0 || sek < 0) throw logic_error("Negativan broj");
         if(step > 360){
            while(step > 360){
                step = step - 360;
            }
        }
        if(m > 60){
            while (m > 60){
                step+=1;
                m = m - 60;
            }
        }
        if(sek > 60){
            while (sek > 60){
                m+=1;
                sek = sek - 60;
            }
        }
        ugaoUradijanima = step + (m / 60.) + sek/3600.;
        if(ugaoUradijanima > 360){
            while(ugaoUradijanima > 360){
            ugaoUradijanima = ugaoUradijanima - 360;
            }
        }
    }

    void PostaviUgao(int ugao){
        ugaoUradijanima = ugao;
        if(ugaoUradijanima > 360){
            while(ugaoUradijanima > 360){
            ugaoUradijanima = ugaoUradijanima - 360;
            }
        }
    }

    void PostaviUgao(int step,int m,int sek){
        if(step < 0 || m < 0 || sek < 0) throw logic_error("Negativan broj");
         if(step > 360){
            while(step > 360){
                step = step - 360;
            }
        }
        if(m > 60){
            while (m > 60){
                step+=1;
                m = m - 60;
            }
        }
        if(sek > 60){
            while (sek > 60){
                m+=1;
                sek = sek - 60;
            }
        }
        ugaoUradijanima = step + (m / 60.) + sek/3600.;
        if(ugaoUradijanima > 360){
            while(ugaoUradijanima > 360){
            ugaoUradijanima = ugaoUradijanima - 360;
            }
        }
    }

    int DajRadijane(){
    return ugaoUradijanima;
    }

    int DajStepene() const{
    return  int(ugaoUradijanima);
    }

    int DajMinute() const{
    return int((ugaoUradijanima - DajStepene()) * 60);
    }

    int DajSekunde() const{
    return (ugaoUradijanima - DajStepene() - (DajMinute()/60.)) * 3600;
    }

friend Ugao operator --(Ugao &c);
friend Ugao operator +(const Ugao &a,const Ugao &b);
friend Ugao operator -(const Ugao &a,const Ugao &b);
friend Ugao operator *( Ugao &a,int broj);
friend Ugao operator *(int broj, Ugao &a);
friend Ugao operator +=(Ugao &a,const Ugao &b);
friend Ugao operator -=(Ugao &a,const Ugao &b);
friend Ugao operator *=(Ugao &a,const Ugao &b);
friend Ugao operator ++(Ugao &c);
friend Ugao operator ++(Ugao &c, int);
friend bool operator < (Ugao &a,Ugao &b);
friend ostream& operator<<(ostream& os, const Ugao& dt);
friend istream& operator>> (istream& is, Ugao& dt);
};

Ugao operator --(Ugao &c){
if(c.ugaoUradijanima > 360){
        while(c.ugaoUradijanima > 360){
        c.ugaoUradijanima = c.ugaoUradijanima - 360;
        }
    }
    return c;
}

Ugao operator +(const Ugao &a,const Ugao &b){
Ugao c;
c.ugaoUradijanima = a.ugaoUradijanima + b.ugaoUradijanima;
if(c.ugaoUradijanima > 360){
        while(c.ugaoUradijanima > 360){
        c.ugaoUradijanima = c.ugaoUradijanima - 360;
        }
    }
return c;
}

Ugao operator -(const Ugao &a,const Ugao &b){
Ugao c;
c.ugaoUradijanima = a.ugaoUradijanima - b.ugaoUradijanima;
if(c.ugaoUradijanima > 360){
        while(c.ugaoUradijanima > 360){
        c.ugaoUradijanima = c.ugaoUradijanima - 360;
        }
    }
return c;
}

Ugao operator *( Ugao &a,int broj){
a.ugaoUradijanima *= broj;
    if(a.ugaoUradijanima > 360){
        while(a.ugaoUradijanima > 360){
        a.ugaoUradijanima = a.ugaoUradijanima - 360;
        }
    }
return a;
}

Ugao operator *(int broj, Ugao &a){
a.ugaoUradijanima *= broj;
    if(a.ugaoUradijanima > 360){
        while(a.ugaoUradijanima > 360){
        a.ugaoUradijanima = a.ugaoUradijanima - 360;
        }
    }
return a;
}

Ugao operator +=(Ugao &a,const Ugao &b){
a.ugaoUradijanima += b.ugaoUradijanima;
   if(a.ugaoUradijanima > 360){
        while(a.ugaoUradijanima > 360){
        a.ugaoUradijanima = a.ugaoUradijanima - 360;
        }
    }
return a;
}

Ugao operator -=(Ugao &a,const Ugao &b){
a.ugaoUradijanima -= b.ugaoUradijanima;
   if(a.ugaoUradijanima > 360){
        while(a.ugaoUradijanima > 360){
        a.ugaoUradijanima = a.ugaoUradijanima - 360;
        }
    }
return a;
}

Ugao operator *=(Ugao &a,const Ugao &b){
a.ugaoUradijanima *= b.ugaoUradijanima;
   if(a.ugaoUradijanima > 360){
        while(a.ugaoUradijanima > 360){
        a.ugaoUradijanima = a.ugaoUradijanima - 360;
        }
    }
return a;
}

Ugao operator ++(Ugao &c){
    c.ugaoUradijanima += 1;
    if(c.ugaoUradijanima > 360){
        while(c.ugaoUradijanima > 360){
        c.ugaoUradijanima = c.ugaoUradijanima - 360;
        }
    }
return c;
}

Ugao operator ++(Ugao &c, int){
    c.ugaoUradijanima += 1;
    if(c.ugaoUradijanima > 360){
        while(c.ugaoUradijanima > 360){
        c.ugaoUradijanima = c.ugaoUradijanima - 360;
        }
    }
return c;
}

bool operator < (Ugao &a,Ugao &b){
if(a.ugaoUradijanima < b.ugaoUradijanima) return true;
return false;
}

ostream& operator<<(ostream& os, const Ugao& dt){
os << dt.DajStepene() << "d " << dt.DajMinute() << "m " << dt.DajSekunde() <<"s"<<endl;
}

istream& operator>> (istream& is, Ugao& dt){
is >> dt.ugaoUradijanima;
}




int main()
{
    Ugao a(23.56);
    cout << a;
    return 0;
}
