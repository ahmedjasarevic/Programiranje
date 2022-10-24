#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Berza
{
    vector<int> cijenaDionica;
    int maxC,minC;
public:
    Berza(int mins,int maxs)
    {
        if(mins < 0 || maxs < 0) throw range_error("Ilegalne granicne cijene");
        minC = mins;
        maxC = maxs;
    }

    explicit Berza(int maxs)
    {
        maxC = maxs;
        minC = 0;
    }

    void RegistrirajCijenu(int nova)
    {
        if(nova < minC || nova > maxC) throw range_error("Ilegalna cijena");
        cijenaDionica.push_back(nova);
    }

    int DajBrojRegistriranihCijena()
    {
        return cijenaDionica.size();
    }

    void BrisiSve()
    {
        for(int i = 0; i <cijenaDionica.size(); i++)
        {
            cijenaDionica[i] = 0;
        }
    }

    int DajMinimalnuCijenu()
    {
        if(cijenaDionica.size() == 0) throw range_error("Nema registriranih cijena");
        return  *min_element(cijenaDionica.begin(),cijenaDionica.end());

    }

    int DajMaksimalnuCijenu()
    {
        if(cijenaDionica.size() == 0) throw range_error("Nema registriranih cijena");
        return  *max_element(cijenaDionica.begin(),cijenaDionica.end());

    }

    int DajBrojCijenaVCecihOd(int broj)
    {
        if(cijenaDionica.size() == 0) throw range_error("Nema registriranih cijena");
        int brojac = count_if(cijenaDionica.begin(), cijenaDionica.end(), [broj](int n)
        {
            return n > broj;
        } );
        return brojac;
    }

    void Ispisi()
    {
        sort(cijenaDionica.begin(),cijenaDionica.end());
        vector<double> cijenauKM;
        transform (cijenaDionica.begin(), cijenaDionica.end(), back_inserter(cijenauKM),
                   bind(divides<double>(), placeholders::_1, 100));
        for(auto a : cijenauKM)
        {
            cout << a << " KM" << endl;
        }
    }

    double operator[](int i)
    {
        if(i < 0 || i > cijenaDionica.size()) throw range_error("Neisrpavan indeks");
        return double(cijenaDionica[i]) / 100;
    }

    friend bool operator !(Berza &obj);
    friend Berza operator++(Berza & obj);
    friend Berza operator++(Berza & obj,int);
    friend Berza operator--(Berza & obj);
    friend Berza operator--(Berza & obj,int);



};

bool operator !(Berza &obj)
{
    if(obj.cijenaDionica.size() == 0) return true;
    return false;
}

 Berza operator++(Berza & obj){
for(int i = 0; i < obj.cijenaDionica.size(); i++){
    obj.cijenaDionica[i] += 100;
}
return obj;
 }

 Berza operator++(Berza & obj,int){
for(int i = 0; i < obj.cijenaDionica.size(); i++){
    obj.cijenaDionica[i] += 100;
}
return obj;
 }

  Berza operator--(Berza & obj){
for(int i = 0; i < obj.cijenaDionica.size(); i++){
    obj.cijenaDionica[i] -= 100;
}
return obj;
 }

   Berza operator--(Berza & obj,int){
for(int i = 0; i < obj.cijenaDionica.size(); i++){
    obj.cijenaDionica[i] -= 100;
}
return obj;
 }

int main()
{
    Berza a(2,100);
    a.RegistrirajCijenu(5);
    a.RegistrirajCijenu(50);
    a.Ispisi();
    cout << a[0] << endl;
    ++a;
    a.Ispisi();
    --a;
    a.Ispisi();

    return 0;
}
