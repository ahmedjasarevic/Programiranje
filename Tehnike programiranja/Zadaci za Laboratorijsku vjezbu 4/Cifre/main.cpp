#include <iostream>
#include <limits.h>
using namespace std;

int Cifre (long long int &n, int &c_min ,int &c_max){
    int min = INT_MAX;
    int max = INT_MIN;
    int ostatak,brojac = 0;
   while(n != 0){
        ostatak = n % 10;
       if(ostatak < min){
           min = ostatak;
       }
       if(ostatak > max){
           max = ostatak;
       }
       n /= 10;
       brojac++;
   }
   n = brojac;
   c_min = min;
   c_max = max;
   return n;
}

int main()
{
    long long int n;
    int a,b;
    cin >>n;
    Cifre(n,a,b);
    cout << n <<" " << a << " " << b << endl;
    int e = Cifre(n,a,b);
    cout << e;

    return 0;
}
