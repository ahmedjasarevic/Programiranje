#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    vector<int> vektorA ;
        ifstream file("test.bin", ios::binary);
    for(auto a : vektorA){
         file.read((char *)&a, sizeof(a));
    }
    file.close();

    return 0;
}
