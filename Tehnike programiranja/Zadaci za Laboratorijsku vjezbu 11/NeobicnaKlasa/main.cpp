#include <iostream>

using namespace std;

 class NeobicnaKlasa{
public:
 explicit NeobicnaKlasa(const int &&a){
cout << "Direktna inicijalizacija" << endl;
}

 NeobicnaKlasa(const int &a){
cout << "Kopirajuca inicijalizacija"<< endl;
}
};

int main()
{

    NeobicnaKlasa k1(5); // ispise direktna inicijalizacija
   NeobicnaKlasa k2 = 5;  // ispise kopirajuca inicijalizacija
    return 0;
}
