#include <iostream>

using namespace std;

int main()
{
    char recenica[1000] = {'n','a',' ',' ','v', 'r','h',' ', ' ', 'b'};
    char *pokNaPrvi = &recenica[0];
    while (*pokNaPrvi == ' ') pokNaPrvi++;
    while (*pokNaPrvi != ' ') pokNaPrvi++;
    while (*pokNaPrvi == ' ') pokNaPrvi++;
    cout << pokNaPrvi;
    return 0;
}
