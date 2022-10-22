#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string s;
    ifstream novifajl("TEMPERATURE.txt");
    if(novifajl.fail())
    {
        cerr << "Gteska" << endl;
    }
    string datumMjerenja,meteoStanica,temperature;
    int tempBroj,brojac = 0,suma = 0;
    double prosjecnaTemp;
    char znak;
    int minTemp = INT_MAX;
    int maxTemp = INT_MIN;
    getline(novifajl,datumMjerenja);
    getline(novifajl,meteoStanica);
    while(novifajl >> tempBroj >> znak)
    {
        brojac++;
        suma += tempBroj;
        if(tempBroj < minTemp)
        {
            minTemp = tempBroj;
        }
        if(tempBroj > maxTemp)
        {
            maxTemp = tempBroj;
        }
    }
    prosjecnaTemp = double(suma) / brojac;
    fstream drugifajl("IZVJESTAJ.txt", ios::out);
    if(drugifajl.is_open())
    {
        drugifajl << meteoStanica << endl;
        drugifajl << "--------------------" <<endl;
        drugifajl << "Datum mjerenja : " << datumMjerenja << endl;
        drugifajl << "Minimalna temperatura : " << minTemp << endl;
        drugifajl << "Maksimalna temperatura : " << maxTemp << endl;
        drugifajl << "Prosjecna temperatura : " << prosjecnaTemp << endl;
    }



    return 0;
}
