#include <iostream>

using namespace std;


class Robot{
    double x1,y1,ugao1;
    public:
        Robot(){
        x1 = y1 =  ugao1 =0;
        }
        explicit Robot(double ugao){
        x1 = y1 =0;
        ugao1 = ugao;
        }
        Robot(double x,double y,double ugao){
        x1 =x;
        y1 = y;
        ugao1 = ugao;
        }
void Postavi(double x, double y, double ugao){
x1 = x;
y1 = y;
ugao1 = ugao;
}
void IdiNaprijed(double pomak){
x1 = x1+pomak;
y1 = y1+pomak;
}
void IdiNazad(double pomak){
x1 = x1-pomak;
y1 = y1-pomak;
}
void OkreniSeNaijevo(double ugao){
    ugao1 = ugao1 - ugao;
}
void OkreniSeNadesno(double ugao){
    ugao1 = ugao1 + ugao;
}
double DajPozicijuX() const{
return x1;
}
double DajPozicijuY() const{
return y1;
}
double DajOrijentaciju() const{
return ugao1;
}

void Ispisi() const{
cout << "Robot se nalazi na poziciji (" << x1 << "," <<y1 << ") i gleda pod uglom " << ugao1 << " stepeni u odnosu na " << " x osu";
}
};

int main()
{
    Robot v(1,2,56);
    v.Ispisi();

    return 0;
}
