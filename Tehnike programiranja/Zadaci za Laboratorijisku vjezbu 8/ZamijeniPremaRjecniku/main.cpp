#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

string ZamijeiPremaRjecniku (string a, map<string,string> mapa){
    stringstream ss(a);
string word;
while (getline(ss, word, ' '))
    {
        auto findResult = (mapa.find(word));
       if(findResult == mapa.end()) {
            cout << "Nema";
       }
       else{
        cout <<  findResult->second << " ";
        }
    }

}

int main()
{
   map<std::string, std::string> moj_rjecnik{{"jabuka", "apple"}, {"da", "yes"},
{"kako", "how"}, {"ne", "no"}, {"majmun", "monkey"}};
   ZamijeiPremaRjecniku("kako da ne", moj_rjecnik);
    return 0;
}
