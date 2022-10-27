#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    double niz[5] = {1,2,3,4,5};
    ofstream novifajl("data.dat", ios::out | ios::binary);
    for (auto&& i : niz)
        novifajl << i;
    novifajl.close();
    ifstream citaj("data.dat", ios::in | ios::binary);
    citaj.seekg(-1, ios::end);
    char ch;
    for(; citaj.get(ch); citaj.seekg(-2, ios::cur))
    {
        cout << ch;
    }

    return 0;
}
