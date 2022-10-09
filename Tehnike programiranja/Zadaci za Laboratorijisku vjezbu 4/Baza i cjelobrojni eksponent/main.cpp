#include <iostream>
#include <algorithm>

using namespace std;
double v;
template <typename Tip>

Tip UnosBroja (string obavijestzaBroj = "greska" , string upozorenje ="upozorenje",Tip &n = v){
    cout << obavijestzaBroj;
    while(!(cin >> n && isspace(cin.peek()))){
        cout << upozorenje << endl;
        cout << obavijestzaBroj << endl;
        cin.clear();
        cin.ignore(1000000, '\n');
        }

    return n;
}

double Stepen (double &b, int &e){
    double stepen = 1;
    if(e > 0){
    for(int i = 0; i<e; i++){
    stepen *= b;
   }
   return stepen;
    }
    else{
        e *= -1;
        for(int i = 0; i<e; i++){
    stepen *= b;
    }
    return 1.0/ stepen;
    }
}

int main()
{
    double baza;
    int eksponent;
   double b = UnosBroja("Unesi bazu: ","Neispravan unos, pokusajte ponovo",baza);
   int e = UnosBroja("Unesi cjelobrojni eksponent: ","Neispravan unos, pokusajte ponovo",eksponent);
   cout <<b << " na " << e << " iznosi " << Stepen(b,e);
    return 0;
}
