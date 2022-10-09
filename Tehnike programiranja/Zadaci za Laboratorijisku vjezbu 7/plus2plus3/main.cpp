#include <iostream>

using namespace std;

double plus2 (double x, double y){
return x+y;
}

double plus3 (double x, double y,double z){
return x+y+z;
}


int main()
{
    int a = 2;
    int b = 2;
    int c = 3;
    plus2([]())
   cout <<  plus2(a,b) << endl;
   cout <<  plus3(a,b,c);
    return 0;
}
