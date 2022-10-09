#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Temperature{
    vector<float> vec;
    int brojac = 0;
public:
    explicit Temperature(){
        vec.push_back(0);
        }
        void RegistrujTemp (double b){
            vec.push_back(b);
    brojac++;
        }
        void IzbrisiSveTemp(){
         delete this;
        }
        double prosjek(Temperature &a){
            double suma = 0;
         for(int i = 0; i<brojac; i++){
            suma = suma + vec[i];
    }
    return suma/brojac;
        }
        double minimalna(Temperature &a){
            double min = INT_MAX;
         for(int i = 0; i<brojac; i++){
            if(vec[i] < min){
                min = vec[i];
            }
    }
    return min;
        }
         double maksimalna(Temperature &a){
            double max = INT_MIN;
         for(int i = 0; i<brojac; i++){
            if(vec[i] > max){
                max = vec[i];
            }
    }
    return max;
        }
    void ispisTemp(){
        sort(vec.begin(),vec.end(), greater<int>());
    for(int i = 0; i<brojac; i++){
            cout << vec[i];
    }
    cout << endl;
    }

};

int main()
{

    Temperature a;
   a.RegistrujTemp(1);
    a.RegistrujTemp(4);
 a.RegistrujTemp(3);
 a.ispisTemp();
 cout << a.prosjek(a) << endl;
 cout << a.minimalna(a) << endl;
 cout << a.maksimalna(a);
    return 0;
}
