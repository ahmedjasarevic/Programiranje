#include <iostream>

using namespace std;

void IzvrniString ( string recenica){
for(int i = recenica.size() - 1; i >= 0; i--){
    cout << recenica[i];
}

}

int main()
{
    string recenica;
    getline(cin, recenica);
    IzvrniString(recenica);
    return 0;
}
