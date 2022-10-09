#include <iostream>
#include <math.h>
#include <new>
using namespace std;

void GenerirajStepeneDvojke (int n){
     int *niz;
     int i;
   try{
       if(n < 0){
        throw domain_error("Broj elemenata mora biti pozitivan");
       }
              if(n > 30){
        throw overflow_error("Izuzetak: Prekoracen dozvoljeni opseg");
       }
   }
         catch(overflow_error greska){
       cout  << greska.what();
       }
          catch(domain_error greska){
   cout << greska.what() << endl;
   }

       try{
       niz = new int[n];
       }
       catch(bad_alloc& greska){
       cout << "Alokacija nije uspjela" <<greska.what();
       }
       try{
       for(int i = 0; i<n; i++){
         niz[i]= pow(2,i);
          cout <<  niz[i] <<endl;
       }
       }
                catch(...){
   cout << "be" << endl;
   }




}

int main()
{
    int n;
    cin >>n;
    GenerirajStepeneDvojke(n);
    return 0;
}
