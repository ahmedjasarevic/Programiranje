#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, const set<int> set1)
{
    for(auto a : set1)
    {
        os << a <<",";
    }
    cout << endl;
    return os;
}
template <typename t1,typename t2>
ostream& operator << (std::ostream &os,const vector<pair<t1,t2>> &p){
for(auto a: p){
    os << "(" << a.first << "," <<  a.second << ")"<<",";

}
return os;

}





set<int> operator+(set<int> a,set<int> b)
{
    set<int> unija;
    for(auto it = a.begin(); it != a.end(); it++)
    {
        unija.insert(*it);
    }
    for(auto it2 = b.begin(); it2 != b.end(); it2++)
    {
        unija.insert(*it2);
    }
    return unija;

}

set<int> operator* (set<int> a, set<int> b)
{
    set<int> presjek;
    for(auto it = a.begin(); it != a.end(); it++)
    {
        for(auto it2 = b.begin(); it2 != b.end(); it2++)
        {
            if(*it == *it2)
            {
                presjek.insert(*it2);
            }
        }
    }
    return presjek;
}


template <typename t1,typename t2>
 vector<pair<t1,t2>> operator %(set<t1> a, set<t2> b){
    vector<pair<t1,t2>> c;
for(auto it = a.begin(); it != a.end(); it++){
for(auto it2 = b.begin(); it2 != b.end(); it2++){
    c.push_back(make_pair(*it,*it2));
}
}
return c;
}



int main()
{
    set<int> s1{3, 5, 1, 2, 8}, s2{7, 2, 8, 4};
    cout << s1+s2;
    cout << s1*s2;
    set<char> s3{'A', 'B'};
    set<int> s4{1, 2, 3};
     cout << s3 % s4;




    return 0;
}
