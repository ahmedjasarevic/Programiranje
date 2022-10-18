#include <iostream>
#include <math.h>
#include <vector>
#include <memory>

using namespace std;

class Lik{
public:
void IspisiSpecificnosti();
double DajObim();
double DajPovrsinu();
virtual void Ispisi() = 0;


};


class Krug : public Lik{
double poluprecnik;
public:
    Krug(){
    poluprecnik = 0;
    }

    Krug(double a){

    poluprecnik = a;
    }

    double DajObim() const {
        return 2 * 3.1415 * poluprecnik;
    }

    double DajPovrsinu() const {
        return poluprecnik * poluprecnik * 3.14;
    }

    void Ispisi(){
    cout <<"Krug poluprecnika " <<  poluprecnik << endl;
    cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu() << endl;

    }

};

class Pravougaonik : public Lik{
double a,b;
public:
    Pravougaonik(){
    a = b = 0;
    }

    Pravougaonik(double a,double b){
    if(b <= 0 || a <= 0) throw domain_error("Neispravni parametri");
    Pravougaonik::a = a;
    Pravougaonik::b = b;
    }

    double DajObim() const {
        return 2 * a + 2 * b;
    }

    double DajPovrsinu() const {
        return a * b;
    }

    void Ispisi(){
        cout << "Pravougaonik sa stranicama duzine " << a << " i " <<b << endl;
        cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu() << endl;
    }

};

class Trougao : public Lik{
double a,b,c;
public:
    Trougao(){
     a = b = c = 0;
    }

    Trougao(double a,double b,double c){
    if(b <= 0 || a <= 0 || c <= 0) throw domain_error("Neispravni parametri");
    Trougao::a = a;
    Trougao::b = b;
    Trougao::c = c;
    }

    double DajObim() const {
        return a+b+c;
    }

    double DajPovrsinu() const {
     double HeronovaFormulaS = (a + b + c) / 2;
        return sqrt(HeronovaFormulaS*(HeronovaFormulaS - a)*(HeronovaFormulaS - b)*(HeronovaFormulaS - c));
    }

    void Ispisi(){
        cout << "Trougao sa stranicama duzine " << a << "," <<b << " i " <<c <<endl;
        cout << "Obim: " << DajObim() << " Povrsina: " << DajPovrsinu() << endl;
    }


};

int main()
{
    int n;
    char unos;
    char znak = ',';
    int a,b,c;
    vector<shared_ptr<Lik>> vec;
    cout <<"Koliko zelite likova: ";
    cin >> n;
    shared_ptr<Lik> pok[n];
    for(int i = 0; i <n; i++){
        cout <<"Lik " << i+1 << ":";
        cin >> unos ;
       if(unos != 'K' && unos != 'P' && unos != 'T'){
            cout <<"Pogresni podaci, ponovite unos !" << endl;
                   cout <<"Lik " << i+1 << ":";
         while (unos != 'K' && unos != 'P' && unos != 'T'){
            cin >> unos;
         }
       }
        if(unos == 'K'){
                cin >> a;
                               if(cin.fail()){
                    cout << "bosmna";
                }
         pok[i] = make_shared<Krug>(a);
                vec.push_back(pok[i]);
     }
        if(unos == 'P'){
                 cin >> a >> znak >> b;
               pok[i] = make_shared<Pravougaonik>(a,b);
                vec.push_back(pok[i]);
     }
        if(unos == 'T'){
                cin >> a >> znak >> b >> znak >>c;
                pok[i] = make_shared<Trougao>(a,b,c);
                 vec.push_back(pok[i]);
     }
    }

    for(int i = 0; i < n; i++) {
vec[i]->Ispisi();
 std::cout << endl;
}

    return 0;
}
