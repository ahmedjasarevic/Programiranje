#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits.h>

using namespace std;


int main()
{
    string s;
    ifstream novifajl("TEMPERATURE.txt");

    if(novifajl.fail())
    {
        cerr << "Gteska" << endl;
    }
    string linija;
    int tempBroj,brojac = 0,suma = 0;
    double prosjecnaTemp;
    char znak;
    int minTemp = INT_MAX;
    int maxTemp = INT_MIN;
    vector<string> datumi;
    vector<string> nazivi;
    vector<string> temperature;
    vector<int> TempToINT;
    int brojacLinija = 0,brojacProsjeka = 0;
    int broj = 0;
    while(getline(novifajl,linija))
    {
        if(brojac == 1)
        {
            nazivi.push_back(linija);
            brojac++;
        }
        else if(brojac == 0)
        {
            datumi.push_back(linija);
            brojac++;
        }
        else if(brojac == 2)
        {
            temperature.push_back(linija);
            brojac = 0;
        }
        brojacLinija++;
    }




    for(auto a : temperature)
    {

        stringstream ss(a);
        int current_num;
        while (true)
        {
            int d;
            if (ss >> d )
                TempToINT.push_back(d);

            else
            {

                ss.clear(); break;

            }
        }

    }



    for(auto a : TempToINT)
    {
        cout <<a  <<endl;

    }

    fstream drugifajl("IZVJESTAJ.txt", ios::out);
    for(auto i = 0; i < brojacLinija-1; i++)
    {
        drugifajl << nazivi[i] << endl;
        drugifajl << "--------------------" <<endl;
        drugifajl << "Datum mjerenja : " << datumi[i] << endl;
        drugifajl << "Temperature mjerenja : " << temperature[i] << endl;
        drugifajl << endl;

    }




    return 0;
}
