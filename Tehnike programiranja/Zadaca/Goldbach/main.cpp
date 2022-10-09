#include <vector>
#include <iostream>

using namespace std;

bool Prost (int n)
{
    for(int i = 2; i<n; i++)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int GoldBach (int &n,int &p,int &q)
{
    try
    {
        if(n <= 2)
        {
            throw logic_error("Rastava ne postoji");
        }
        for (int i=2; i <= n; i++)
        {
            if ((Prost(i)) && (Prost(n-i)))
            {
                p = i;
                q = n - i;
                if(q == 0)
                {
                    throw logic_error(" nije zbir dva prosta broja!");
                }
                cout << n << " je zbir prostih brojeva " << i << " i " << n-i << endl;
                break;
            }
        }


    }
    catch(logic_error greska)
    {
        cout <<n << greska.what() ;
    }
    return n;
}

int main()
{
    int n,p,q;
    cout << "Unesi broj: ";
    cin >>n;
    GoldBach(n,p,q);
    return 0;
}
