#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

class Kompleksni {
    double re, im;
public:
    Kompleksni(double re = 0, double im = 0) : re(re), im(im) {}

    friend Kompleksni operator +(const Kompleksni &a){
        return a;
    }

    friend Kompleksni operator -(const Kompleksni &a) {
        return {-a.re, -a.im};
    }

    friend Kompleksni operator +(const Kompleksni &a, const Kompleksni &b) {
        return {a.re + b.re, a.im + b.im};
    }

    friend Kompleksni operator -(const Kompleksni &a, const Kompleksni &b) {
        return {a.re - b.re, a.im - b.im};
    }

    friend Kompleksni operator *(const Kompleksni &a, const Kompleksni &b) {
        return {a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
    }

    friend Kompleksni operator /(const Kompleksni &a, const Kompleksni &b) {
        double pomocna = b.re * b.re + b.im * b.im;
        return {(a.re * b.re + a.im * b.im) / pomocna,
                (a.im * b.re - a.re * b.im) / pomocna};
    }

    friend bool operator ==(const Kompleksni &a, const Kompleksni &b) {
        return a.re == b.re && a.im == b.im;
    }

    friend bool operator !=(const Kompleksni &a, const Kompleksni &b) {
        return !(a == b);
    }

    friend Kompleksni &operator +=(Kompleksni &a, const Kompleksni &b) {
        a.re += b.re;
        a.im += b.im;
        return a;
    }

    friend Kompleksni &operator -=(Kompleksni &a, const Kompleksni &b) {
        a.re -= b.re;
        a.im -= b.im;
        return a;
    }

    friend Kompleksni &operator *=(Kompleksni &a, const Kompleksni &b) {
        double pomocna = a.re * b.im + a.im * b.re;
        a.re = a.re * b.re - a.im * b.im;
        a.im = pomocna;
        return a;
    }

    friend Kompleksni &operator /=(Kompleksni &a, const Kompleksni &b) {
        double pom1 = a.im * b.re - a.re * b.im, pom2 = b.re * b.re + b.im * b.im;
        a.re = (a.re * b.re + a.im * b.im) / pom2;
        a.im = pom1 / pom2;
        return a;
    }

    friend std::ostream &operator <<(std::ostream &tok, const Kompleksni &a);
    friend std::istream &operator >>(std::istream &tok, Kompleksni &a);

    friend double real(const Kompleksni &a) {
        return a.re;
    }

    friend double imag(const Kompleksni &a) {
        return a.im;
    }

    friend double abs(const Kompleksni &a) {
        return std::sqrt(a.re * a.re + a.im * a.im);
    }

    friend double arg(const Kompleksni &a) {
        return std::atan2(a.im, a.re);
    }

    friend Kompleksni conj(const Kompleksni &a) {
        return {a.re, -a.im};
    }

    friend Kompleksni sqrt(const Kompleksni &a) {
        double rho = std::sqrt(abs(a)), phi = arg(a) / 2;
        return {rho * std::cos(phi), rho * std::sin(phi)};
    }

};

istream &operator >>(std::istream &tok, Kompleksni &a) {
    string kompleksniString,realni,imaginarni;
    bool znakRealnog,znakImaginarnog,nemaREALdio,nemaIMGdio;
    tok >> kompleksniString; // unos kompleksnog broja kao string ( format: a + bi)
    if(kompleksniString[0] == '-') znakRealnog = true;  // prvi znak stringa predstavlja znak realnog dijela
    else znakRealnog = false;
    for(int i = 0; i < kompleksniString.size(); i++){
        if(kompleksniString[0] == '+' || kompleksniString[0] == '-')i++;
        if(kompleksniString[i] != '+' || kompleksniString[i] != '-' && kompleksniString[i] == 'i') nemaREALdio = false;
        else nemaREALdio = true;
    }
    for(int i = 0; i < kompleksniString.size(); i++){
        if(kompleksniString[0] == '+' || kompleksniString[0] == '-')i++;
        if(kompleksniString[i] != '+' || kompleksniString[i] != '-' && kompleksniString[i] != 'i') nemaIMGdio = false;
        else nemaIMGdio = true;
    }
    if(znakRealnog == false){ // realni dio ima znak '+'
        for(int i = 0; i<kompleksniString.size(); i++){
            while(kompleksniString[i] != '+' && kompleksniString[i] != '-'){  // prolazak kroz petlju sve dok ne dodjemo do znaka imaginarnog dijela
                realni += kompleksniString[i]; // smjestamo realni dio
                i++;

            }
            while(kompleksniString[i] != 'i'){ // prolazak kroz petlju sve do kraja tj. do 'i'
                if(kompleksniString[i] == '-') znakImaginarnog = true; // znak imaginarnog dijela
                else znakImaginarnog = false;
                if(kompleksniString[i] == '+' || kompleksniString[i] == '-') i++; // i++ da znak imaginarnog dijela ne ulazi u dio imaginarnog dijela
                    imaginarni += kompleksniString[i];  // smjestamo imaginarni dio
                    i++;
            }
        }
    }

    if(znakRealnog == true){ // realni dio ima znak '-'
        for(int i = 1; i<kompleksniString.size(); i++){
            while(kompleksniString[i] != '+' && kompleksniString[i] != '-'){ // prolazak kroz petlju sve dok ne dodjemo do znaka imaginarnog dijela
                realni += kompleksniString[i]; // smjestamo realni dio
                i++;
            }
            while(kompleksniString[i] != 'i'){ // prolazak kroz petlju sve do kraja tj. do 'i'
                if(kompleksniString[i] == '-') znakImaginarnog = true; // znak imaginarnog dijela
                else znakImaginarnog = false;
                if(kompleksniString[i] == '+' || kompleksniString[i] == '-') i++; // i++ da znak imaginarnog dijela ne ulazi u dio imaginarnog dijela
                    imaginarni += kompleksniString[i];  // smjestamo imaginarni dio
                    i++;
            }

        }
    }
    int realDio,imgDio;
    try{
        if(nemaREALdio == true){
            realDio = 0;
        }
        else{
     realDio = stoi(realni); // pretvaranje stringa u int
        }
    }
    catch(...){
    cout << "realnidio";
    }
    try{
        if(nemaIMGdio == true){
            imgDio = 0;
        }
        else{
     imgDio = stoi(imaginarni); // pretvaranje stringa u int
        }
    }
    catch(...){
    cout << "imgdio";
    realDio = 0;
    }
    if(znakRealnog == true){ // realni dio ima znak '-'
        a.re = realDio * (-1) ;
    }
    else{
        a.re = realDio;
    }
    if(znakImaginarnog == true){ // imaginarni dio ima znak '-'
        a.im = imgDio * (-1);
    }
    else{
        a.im = imgDio;
    }
    return tok;
}

ostream &operator <<(std::ostream &tok, const Kompleksni &a) {
        if (a.re > 0 && a.im > 0 && a.im != 1)  return tok << a.re << "+" << a.im << "i" <<endl;
        if (a.re > 0 && a.im == 0)  return tok << a.re <<endl;
        if (a.re > 0 && a.im < 0 && a.im != 1 && a.im != -1)  return tok << a.re << "-" << abs(a.im) << "i"<<endl;
        if (a.re > 0 && a.im == 1)  return tok << a.re << "+" << "i"<<endl;
        if (a.re > 0 && a.im == -1)  return tok << a.re << "-" << "i"<<endl;
        if (a.re == 0 && a.im > 0 && a.im != 1)  return tok << a.im << "i"<<endl;
        if (a.re == 0 && a.im < 0 && a.im != 1)  return tok << a.im << "i"<<endl;
        if (a.re == 0 && a.im == 1)  return tok << "i"<<endl;
        if (a.re == 1 && a.im == 0)  return tok << a.re<<endl;
        if (a.re < 0 && a.im == 0)  return tok << a.re<<endl;
        if (a.re < 0 && a.im < 0 && a.im != 1 && a.im != -1)  return tok << a.re << a.im << "i" <<endl;
        if (a.re < 0 && a.im < 0 && a.im != 1 && a.im != -1)  return tok << a.re << a.im << "i" <<endl;
    }



int main()
{
    Kompleksni a(2,3);
    Kompleksni a1(2,-3);
    Kompleksni a2(3,1);
    Kompleksni a3(1,-1);
    Kompleksni a4(0,2);
    Kompleksni a5(0,-5);
    Kompleksni a6(0,1);
    Kompleksni a7(3,0);
    cout << a;
    cout << a1;
    cout << a2;
    cout << a3;
    cout << a4;
    cout << a5;
    cout << a6;
    cout << a7;
 cout << real(a);
    return 0;
}
