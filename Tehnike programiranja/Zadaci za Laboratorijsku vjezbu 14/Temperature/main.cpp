#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits.h>

using namespace std;


int main()
{
    ifstream novifajl("TEMPERATURE.txt");
    if(novifajl.fail())
    {
        cerr << "Gteska" << endl;
    }
    string linija;
    int brojac = 0;
    char znak;
    vector<string> datumi,nazivi,stringBrojevi;
    vector<double> sumaVec;
    vector<int> maxVec,minVec;
    int brojacLinija = -1,broj;
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
            stringBrojevi.push_back(linija);
            brojac = 0;
        }
        brojacLinija++;
    }

    for(auto a :stringBrojevi)
    {
        stringstream ss(a);
        double suma = 0,brojac = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        while (ss >> broj)
        {
            suma += broj;
            brojac++;
            if(broj < min)
            {
                min = broj;
            }
            if(broj > max)
            {
                max = broj;
            }
            if (ss.peek() == ',') ss.ignore();
        }
        sumaVec.push_back(double(suma)/brojac);
        minVec.push_back(min);
        maxVec.push_back(max);

    }
    fstream drugifajl("IZVJESTAJ.txt", ios::out);
    for(int i = 0; i < datumi.size(); i++)
    {
        for(int j = 0; j < (datumi.size() - i - 1); j++)
        {
            if(datumi[j] < datumi[j+1])
            {
                swap(datumi[j],datumi[j+1]);
                swap(nazivi[j],nazivi[j+1]);
                swap(minVec[j],minVec[j+1]);
                swap(maxVec[j],maxVec[j+1]);
                swap(sumaVec[j],sumaVec[j+1]);
            }
        }
    }

    for(int i = 0; i < datumi.size(); i++)
    {
        for(int j = 0; j < ( datumi.size() - i - 1); j++)
        {
            if(datumi[j] == datumi[j+1])
            {

                if(sumaVec[j] > sumaVec[j+1])
                {
                    swap(datumi[j],datumi[j+1]);
                    swap(nazivi[j],nazivi[j+1]);
                    swap(minVec[j],minVec[j+1]);
                    swap(maxVec[j],maxVec[j+1]);
                    swap(sumaVec[j],sumaVec[j+1]);
                }
            }
        }
    }
    for(auto i = 0; i < brojacLinija; i++)
    {
        if(nazivi[i] == "") break;
        drugifajl << nazivi[i] << endl;
        drugifajl << "--------------------" <<endl;
        drugifajl << "Datum mjerenja : " << datumi[i] << endl;
        drugifajl << "Minimalna temperatura: " << minVec[i] << endl;
        drugifajl << "Maksimalna temperatura: " << maxVec[i] << endl;
        drugifajl << "Prosjecna temperatura : "  <<  sumaVec[i] << endl;
        drugifajl << endl;

    }




    return 0;
}
