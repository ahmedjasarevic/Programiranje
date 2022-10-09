#include <iomanip>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrica;

using namespace std;

Matrica PascalovTrougao (int n)
{
    Matrica v(n);
    for(int i = 0; i <n; i++)
    {
        v[i].resize(i+1);
    }

    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            if(   v[i][j] == v[i][0]  || v[i][j] == v[i][i]   )
            {
                v[i][0] = v[i][i] =  1;
            }
            else
            {
                v[i][j]= v[i-1][j-1] + v[i-1][j];
            }
        }
    }


    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] <<" " ;
        }
        cout << endl;
    }
    return v;
}


int main()
{
    int brRedova;
    cout << "Unesite broj redova: " ;
    cin >> brRedova;
    PascalovTrougao(brRedova);
    return 0;
}
