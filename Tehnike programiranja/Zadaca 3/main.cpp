#include <iostream>
#include <map>
#include <vector>
#include <sstream>

using namespace std;


multimap<string,int> KreirajIndeksPojmova(string ind)
{
    multimap<string,int> mymap;
    stringstream ss(ind);
    string rijec;
    vector<string> rijeci;
    while(ss >> rijec)
    {
        rijeci.push_back(rijec);
    }
    int brojac = 4;
    for(int i = 0; i<rijeci.size(); i++)
    {
        if(i == 0)
        {
            mymap.insert(pair<string,int>(rijeci[0],0));
            continue;
        }
        mymap.insert(pair<string,int>(rijeci[i],brojac));
        brojac = brojac + rijeci[i].size() + 1 ;

    }
    return mymap;
}

multimap<string,int> PretraziIndeksPojmova(string nekarijec,multimap<string,int> mymap)
{
    bool flag = false;
    for (auto itr = mymap.find(nekarijec); itr != mymap.end(); itr++)
    {
        if(itr->first == nekarijec)
        {
            flag = true;
            cout << itr->first<< '\t' << itr->second << '\n';
        }
        else
        {
            continue;
        }
    }
    if(flag == false)
    {
        throw logic_error("Pojam nije pronadjen");
    }
    return mymap;

}

void IspisiIndeksPojmova(multimap<string,int> mymap)
{
    for (auto i = mymap.begin(); i != mymap.end(); )
    {
        auto group = i->first;
        cout << group <<" : ";
        do
        {
            cout << i->second << " ";
        }
        while (++i != mymap.end() && i->first == group);
        cout << endl;
    }
}


int main()
{
    string tekst,rijec;
    cout << "Unesite tekst: ";
    getline(cin,tekst);
    KreirajIndeksPojmova(tekst);
    while(rijec != "."){
    cout << "Unesite rijec: " ;
    cin >> rijec;
    PretraziIndeksPojmova(rijec,KreirajIndeksPojmova(tekst));
    }

    return 0;
}
