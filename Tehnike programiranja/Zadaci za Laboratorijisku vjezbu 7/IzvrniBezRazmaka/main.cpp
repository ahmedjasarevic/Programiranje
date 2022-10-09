#include <iostream>
#include <algorithm>
#include <ostream>
#include <iterator>
using namespace std;

string IzvrniBezRazmaka (string v){
    string pomocni;
for(auto it = v.rbegin(); it != v.rend(); it++){
        if(*it == ' ') continue;
pomocni += *it ;
        }
return pomocni;
}

int main()
{
    string v = "Evo pada kisa";
   string pomocni = IzvrniBezRazmaka(v);
  cout << pomocni;
    return 0;
}
