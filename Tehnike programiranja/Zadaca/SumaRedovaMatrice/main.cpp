#include <iostream>
#include <vector>
using namespace std;

int SortirajPoSumiRedova (vector<vector<int>> mat){}

int main()
{
    vector<vector<int>> mat;
    int input;
    cout << "Unesi elemente (* za kraj reda, * na pocetku reda za kraj unosa*)" << endl;
    int i = 0;
    while(cin >> input){
        if(input == '*') break;
        mat.push_back(input);
    }

    return 0;
}
