#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
   ifstream F ("input.txt");
   string s,k,l;
   int ind;
   ind = 0;
   getline (F,s);
   k+=s[0];
   int maxl = 1, tekl = 1;
   for(int i=1;i < s.length();i++)
   if((s[i]) != (s[i-1])){
    tekl++;
    k+=s[i];
    if(tekl>maxl){
        maxl = tekl;
        l=k;
    }
   }
   else{
    tekl = 1;
    k.clear();
    ind = 1;
   }
   if (ind = 1)
        cout<<l<<' '<<maxl;
   else
        cout<<"0";
    
}
