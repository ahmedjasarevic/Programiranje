#include <iostream>
#include <math.h>


using namespace std;

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka tjeme;
    double x1,x2,x3;
    double y1,y2,y3;
public:

    Trougao(Tacka t1, Tacka t2 , Tacka t3){
    x1 = t1.first ;
    x2 = t2.first;
    x3 = t3.first;
    y1 = t1.second;
    y2 = t2.second;
    y3 = t3.second;
    }

    void PostaviTrougao(Tacka t1, Tacka t2, Tacka t3){
     x1 = t1.first;
    x2 = t2.first;
    x3 = t3.first;
    y1 = t1.second;
    y2 = t2.second;
    y3 = t3.second;
    }

    void PostaviTjeme(int orijentacija,Tacka t){
    if(orijentacija == 1){
            x1 = t.first;
            y1 = t.second;
    }
     else if(orijentacija == 2){
            x2 = t.first;
            y2 = t.second;
    }
      else if(orijentacija == 3){
            x3 = t.first;
            y3 = t.second;
    }
    else throw range_error("Nekorektan indeks");
    }

    static bool Orijentacija(Tacka t1, Tacka t2, Tacka t3){
     double test = 0;
     test = t1.first*(t2.second - t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);
        if(test > 0) return 1;
        if(test < 0) return -1;
        if(test == 0) return 0;
    }

    Tacka DajTjeme(int orijentacija){
        if(orijentacija == 1){
            tjeme.first = x1;
            tjeme.second = y1;
            return tjeme;
        }
        else if(orijentacija == 2){
            tjeme.first = x2;
            tjeme.second = y2;
            return tjeme;
        }
        else if(orijentacija == 3){
            tjeme.first = x3;
            tjeme.second = y3;
            return tjeme;
        }
           else throw range_error("Nekorektan indeks");
    }

    double dajStranicu(int orijentacija){
         if(orijentacija == 1){
                return sqrt(double(pow((x2-x1),2)+pow((y2-y1),2)));
        }
        else if(orijentacija == 2){
                return sqrt(pow(x3-x2,2)+pow(y3-y2,2));
        }
        else if(orijentacija == 3){
                return sqrt(pow(x3-x1,2)+pow(y3-y1,2));
        }
        else throw range_error("Nekorektan indeks");
    }

    double DajUgao(int orijentacija){
     if(orijentacija == 1){
            double prvi = pow(dajStranicu(2),2)+pow(dajStranicu(3),2)-pow(dajStranicu(1),2);
            double drugi = 2 * dajStranicu(2) * dajStranicu(3);
            double ukupno = prvi / drugi;
            return acos(ukupno);
        }
        else if(orijentacija == 2){
            double prvi = pow(dajStranicu(1),2)+pow(dajStranicu(3),2)-pow(dajStranicu(2),2);
            double drugi = 2 * dajStranicu(1) * dajStranicu(3);
            double ukupno = prvi / drugi;
            return acos(ukupno);
        }
        else if(orijentacija == 3){
            double prvi = pow(dajStranicu(1),2)+pow(dajStranicu(2),2)-pow(dajStranicu(3),2);
            double drugi = 2 * dajStranicu(2) * dajStranicu(1);
            double ukupno = prvi / drugi;
            return acos(ukupno);
        }
        else throw range_error("Nekorektan indeks");
    }

    Tacka DajCentar(){
        Tacka teziste;
        double xt = x1 + x2 +x3 / 3;
        double yt = y1+y2+y3 / 3;
        teziste.first = xt;
        teziste.second =yt;
        return teziste;
    }

    double DajPovrsinu(Tacka t1, Tacka t2, Tacka t3){
        double ugao = abs(Orijentacija(t1,t2,t3));
       return ugao/2;
    }
    double DajPovrsinu2(double x1,double x2,double x3,double y1,double y2,double y3){
         return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
    }

    double DajObim(Tacka t1, Tacka t2, Tacka t3){
        return dajStranicu(1)+dajStranicu(2)+dajStranicu(3);
    }

    bool DaLiJePozitivnoOrijentiran(){
        if(x1> 0 && y1 > 0 && x2 > 0 && y2 > 0 && x3 > 0 && y3 > 0 ) return true;
            return false;
    }

    bool DaLiJeUnutra(Tacka t){
    double povrsinaABC = DajPovrsinu2(x1,x2,x3,y1,y2,y3);
     double povrsinaPBC= DajPovrsinu2(t.first,x2,x3,t.second,y2,y3);
    double povrsinaPAC= DajPovrsinu2(x1,t.first,x3,y1,t.second,y3);
    double povrsinaPAB = DajPovrsinu2(x1,x2,t.first,y1,y2,t.second);
    return(povrsinaABC == povrsinaPAB + povrsinaPAC + povrsinaPBC);
    }

    void Ispisi(){
    cout << "((" << x1 << "," << y1 << "),(" << x2 << ","<< y2 << "),(" << x3 << "," << y3 << "))";
    }

    void Transliraj(double x , double y){
    x1 += x;
    x2 += x;
    x3 += x;
    y1 += y;
    y2 += y;
    y3 += y;
    }

    Tacka Centriraj(){
    return DajCentar();
    }

    void Rotiraj(Tacka centar,double ugao){
    x1 =(centar.first+(x1-centar.first)*cos(ugao)-(y1-centar.second)*sin(ugao));
    y1 =(centar.second+(x1-centar.first)*sin(ugao)+(y1-centar.second)*cos(ugao));
    x2 =(centar.first+(x2-centar.first)*cos(ugao)-(y2-centar.second)*sin(ugao));
    y2 =(centar.second+(x2-centar.first)*sin(ugao)+(y2-centar.second)*cos(ugao));
    x3 =(centar.first+(x3-centar.first)*cos(ugao)-(y3-centar.second)*sin(ugao));
    y3 =(centar.second+(x3-centar.first)*sin(ugao)+(y3-centar.second)*cos(ugao));
    }

      void Rotiraj(double ugao){
    x1 =(DajCentar().first+(x1-DajCentar().first)*cos(ugao)-(y1-DajCentar().second)*sin(ugao));
    y1 =(DajCentar().second+(x1-DajCentar().first)*sin(ugao)+(y1-DajCentar().second)*cos(ugao));
    x2 =(DajCentar().first+(x2-DajCentar().first)*cos(ugao)-(y2-DajCentar().second)*sin(ugao));
    y2 =(DajCentar().second+(x2-DajCentar().first)*sin(ugao)+(y2-DajCentar().second)*cos(ugao));
    x3 =(DajCentar().first+(x3-DajCentar().first)*cos(ugao)-(y3-DajCentar().second)*sin(ugao));
    y3 =(DajCentar().second+(x3-DajCentar().first)*sin(ugao)+(y3-DajCentar().second)*cos(ugao));
    }

    void Skaliraj(Tacka centar,double k){
        if(k==0) throw domain_error("Nekorektan faktor skaliranja");
    x1=centar.first+k*(x1-centar.first);
    y1=centar.second+k*(y1-centar.second);
    x2=centar.first+k*(x2-centar.first);
    y2=centar.second+k*(y2-centar.second);
    x3=centar.first+k*(x3-centar.first);
    y3=centar.second+k*(y3-centar.second);
    }

     void Skaliraj(double k){
        if(k==0) throw domain_error("Nekorektan faktor skaliranja");
    x1=DajCentar().first+k*(x1-DajCentar().first);
    y1=DajCentar().second+k*(y1-DajCentar().second);
    x2=DajCentar().first+k*(x2-DajCentar().first);
    y2=DajCentar().second+k*(y2-DajCentar().second);
    x3=DajCentar().first+k*(x3-DajCentar().first);
    y3=DajCentar().second+k*(y3-DajCentar().second);
    }

    friend bool DaLiSuIdenticni(Trougao a,Trougao b){
    if(a.dajStranicu(1) == b.dajStranicu(1) && a.dajStranicu(2) == b.dajStranicu(2) && a.dajStranicu(3) == b.dajStranicu(3)) return true;
    return false;
    }

    friend bool DaLiSuPodudarni(Trougao a,Trougao b){
    if((a.dajStranicu(1) == b.dajStranicu(1) && a.dajStranicu(2) == b.dajStranicu(2) && a.dajStranicu(3) == b.dajStranicu(3)) && (a.DajUgao(1) == b.DajUgao(1) && a.DajUgao(2) == b.DajUgao(2) && a.DajUgao(3) == b.DajUgao(3))  ) return true;
    return false;
    }

    friend bool DaLiSuSlicni(Trougao a,Trougao b){
    if((a.dajStranicu(1) / b.dajStranicu(1)) == (a.dajStranicu(2) / b.dajStranicu(2)) == (a.dajStranicu(3) / b.dajStranicu(3))) return true;
    return false;

    }
};


int main()
{
    pair<double, double> prva = {3,4} ;
    pair<double, double> druga = {2,4} ;
    pair<double, double> treca = {1,3} ;
    Trougao a(prva,druga,treca);
    Trougao b(prva,druga,treca);
    a.PostaviTrougao({1,2},{2,3},{2,1});
    b.PostaviTrougao({1,2},{2,3},{2,1});
     a.DajTjeme(2);
     cout << a.dajStranicu(1) << endl;
     cout << a.DajUgao(1) << endl;
    cout << a.DajPovrsinu(prva,druga,treca) << endl;
    a.Ispisi();
    cout << DaLiSuIdenticni(a,b);
    return 0;
}
