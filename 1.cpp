#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int p,n,k,m,a,b;
    k=0;
    m=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        p=abs(i);
        n=0;
        while(p>0){
            if (p%2 == 0)
                n++;
            p = p/2;
        }
        if ((abs(i)%2 == 1) and (abs(i)%3 == 0) and (abs(i)%11 == 0) and (n == 5)){
            k++;
            if (abs(i)>m)
                m=i;
        }

    }
        cout<<k<<' '<<m;
}
