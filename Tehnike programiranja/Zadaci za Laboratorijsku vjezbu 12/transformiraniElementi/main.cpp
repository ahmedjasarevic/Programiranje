#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>


using namespace std;

int main()
{
    double n,a;
    vector<double> vektor;
    cout << "Koliko zelite elemenata: " << endl;
    cin >> n;
    for(auto i = 0; i<n; i++){
            cin >> a;
       vektor.push_back(a);
    }
   transform(vektor.begin(),vektor.end(),vektor.begin(),
bind(divides<double>(),1.0,std::placeholders::_1));
    for(auto b : vektor){
        cout << b << " ";

    }

    return 0;
}
