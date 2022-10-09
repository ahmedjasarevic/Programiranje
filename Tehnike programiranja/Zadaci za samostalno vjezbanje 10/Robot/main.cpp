#include <iostream>
#include <type_traits>

using namespace std;
    enum Pravci {Sjever, Istok, Jug, Zapad};
ostream &operator << ( ostream& strm, Pravci tt )
{
   const string nameTT[] = { "Sjever","Istok","Jug","Zapad"};
   return strm << nameTT[tt];
}

class Robot{
    Pravci smjer;
    int a,b;
public:
    Robot(){
    a = b = 0;
    smjer = Pravci (1);
    }
      explicit Robot(Pravci smjer1){
    a = b = 0;
    smjer = smjer1;
    }
       Robot(int x,int y,Pravci p){
    a = x;
    b = y;
    smjer = p;
    }
void Postavi(int x, int y, Pravci p){
a = x;
b = y;
smjer = p;
}
void PomjeriSe(int korak){
a = a+korak;
b = b+korak;
}
void OkreniSeNalijevo(){
smjer=Pravci(int(smjer)-1);
}
void OkreniSeNadesno(){
smjer=Pravci(int(smjer)+1);
}
int DajPozicijuX() const{
return a;
}
int DajPozicijuY() const{
return b;
}
Pravci DajOrijentaciju() const{
return smjer;
}
void Ispisi() const{
cout << "Robot se nalazi na poziciji (" << a << "," << b << ") i gleda na " << DajOrijentaciju() << endl;
}
};

int main()
{
    Robot a(2,3,Zapad);
  a.Ispisi();
    return 0;
}
