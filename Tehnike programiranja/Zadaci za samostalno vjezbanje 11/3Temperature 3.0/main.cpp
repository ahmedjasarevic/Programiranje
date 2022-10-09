#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Temperature
{
    vector<double> vecTemp;
    int brojac = 0;
public:
    explicit Temperature()
    {
        vecTemp.push_back(0);
    }
    void  RegistrujTemp (double a)
    {
        vecTemp.push_back(a);
        brojac++;
    }
    void IzbrisiSveTemp()
    {
        delete this;
    }
    double prosjek(Temperature &a)
    {
        double suma = 0;
        for(int i = 0; i<brojac; i++)
        {
            suma += vecTemp[i];
        }
        return suma/brojac;
    }
    double minimalna(Temperature &a)
    {
        double min = INT_MAX;
        for(int i = 0; i<brojac; i++)
        {
            if(vecTemp[i] < min)
            {
                min = vecTemp[i];
            }
        }
        return min;
    }
    double maksimalna(Temperature &a)
    {
        double max = INT_MIN;
        for(int i = 0; i<brojac; i++)
        {
            if(vecTemp[i] > max)
            {
                max = vecTemp[i];
            }
        }
        return max;
    }
    void ispisTemp()
    {
        sort(vecTemp.begin(),vecTemp.end(), greater<int>());
        for(int i = 0; i<brojac; i++)
        {
            cout << vecTemp[i];
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
